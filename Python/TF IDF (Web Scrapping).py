import re
import requests
import pandas as pd
from bs4 import BeautifulSoup
from nltk.corpus import stopwords
from nltk import word_tokenize, PorterStemmer
from sklearn.metrics.pairwise import cosine_similarity

'''
Scrapping website using BeautifulSoup  
'''


def web_scrapper(url):
    Content = requests.get(url)
    soup = BeautifulSoup(Content.content, 'html.parser')
    text = soup.get_text()
    text = str(text).lower()
    return text


'''
[ Pre-processing ]
===> Remove all the special symbols like punctuation mark, question mark using the
     character deletion step of translate
===> Remove all stop words (Search for Stop word Lists or Python or R Libs)
===> Do Stemming to Reduce inflected (or sometimes derived) words to their word
     stem.
===> Convert uppercase to lowercase
'''


def handle_bigrams(data):
    data = data.replace("deep learning", "deep_learning")
    data = data.replace("machine learning", "machine_learning")
    data = data.replace("data mining", "data_mining")
    return data


stemmer = PorterStemmer()


def preprocessing_text(text):
    # Make all the strings lowercase and remove non alphabetic characters
    text = re.sub("[^-9A-Za-z ]", "", text)
    # Tokenize the text; this is, separate every sentence into a list of words
    # Since the text is already split into sentences you don't have to call sent_tokenize
    tokenized_text = word_tokenize(text)
    # Remove the stopwords and stem each word to its root
    clean_text = []
    for word in tokenized_text:
        if (word not in stopwords.words('english')) and (word.endswith("ing")):
            clean_text.append(stemmer.stem(word))
        else:
            clean_text.append(word)
    # Remember, this final output is a list of words
    return clean_text


'''
Counting term-frequencies and building dictionaries 
'''


def build_dict(research, data, mining, analytics, data_mining, machine_learning, deep_learning):
    return {
        'research': research,
        'data': data,
        'mining': mining,
        'analytics': analytics,
        'data_mining': data_mining,
        'machine_learning': machine_learning,
        'deep_learning': deep_learning
    }


def count_TF(words):
    research = data = mining = deep_learning = machine_learning = analytics = data_mining = 0

    for item in words:
        if ((item == stemmer.stem('research')) or (item == stemmer.stem('researching')) or (item == 'research') or (
                item == 'researched')):
            research += 1
        elif ((item == 'data') or (item == stemmer.stem("data"))):
            data += 1
        elif ((item == stemmer.stem("mining")) or (item == "mining")):
            mining += 1
        elif (item == stemmer.stem('analytics')):
            analytics += 1
        elif (item == stemmer.stem('datamining')):
            data_mining += 1
        elif (item == stemmer.stem("machinelearning")):
            machine_learning += 1
        elif (item == stemmer.stem('deeplearning')):
            deep_learning += 1

    return research, data, mining, analytics, data_mining, machine_learning, deep_learning


'''
Scrapping websites and saving text in (.txt) files and Loading files.
'''
url1 = 'https://www.edx.org/course/data-science-machine-learning'
url2 = 'https://en.wikipedia.org/wiki/Engineering'
url3 = 'http://my.clevelandclinic.org/research'
url4 = 'https://en.wikipedia.org/wiki/Data_mining'
url5 = 'https://en.wikipedia.org/wiki/Data_mining#Data_mining'
url6 = 'http://eecs.csuohio.edu/~sschung/'

print("[INFO] Scrapping websites.....")
text1 = web_scrapper(url1)
text2 = web_scrapper(url2)
text3 = web_scrapper(url3)
text4 = web_scrapper(url4)
text5 = web_scrapper(url5)
file6 = open("./files/web6.txt", 'r')
content = file6.read()
soup = BeautifulSoup(str(content), 'html.parser')
text6 = soup.get_text()
text6 = str(text6).lower()

print("[INFO] Writing website content in files.....")
with open("./files/document1.txt", 'w') as doc1:
    doc1.write(str(text1))
with open("./files/document2.txt", 'w') as doc2:
    doc2.write(str(text2))
with open("./files/document3.txt", 'w') as doc3:
    doc3.write(str(text3))
with open("./files/document4.txt", 'w') as doc4:
    doc4.write(str(text4))
with open("./files/document5.txt", 'w') as doc5:
    doc5.write(str(text5))
with open("./files/document6.txt", 'w') as doc6:
    doc6.write(str(text6))

print("[INFO] Loading website content from files.....")
with open("./files/document1.txt", 'r') as doc1:
    text1 = str(doc1.readlines())
with open("./files/document2.txt", 'r') as doc2:
    text2 = str(doc2.readlines())
with open("./files/document3.txt", 'r') as doc3:
    text3 = str(doc3.readlines())
with open("./files/document4.txt", 'r') as doc4:
    text4 = str(doc4.readlines())
with open("./files/document5.txt", 'r') as doc5:
    text5 = str(doc5.readlines())
with open("./files/document6.txt", 'r') as doc6:
    text6 = str(doc6.readlines())

print("[INFO] Preprocessing Text....")
text_1 = handle_bigrams(text1)
text_2 = handle_bigrams(text2)
text_3 = handle_bigrams(text3)
text_4 = handle_bigrams(text4)
text_5 = handle_bigrams(text5)
text_6 = handle_bigrams(text6)

text_1 = preprocessing_text(text_1)
text_2 = preprocessing_text(text_2)
text_3 = preprocessing_text(text_3)
text_4 = preprocessing_text(text_4)
text_5 = preprocessing_text(text_5)
text_6 = preprocessing_text(text_6)

research, data, mining, analytics, data_mining, machine_learning, deep_learning = count_TF(text_1)
tf_idf_doc1 = build_dict(research, data, mining, analytics, data_mining, machine_learning, deep_learning)

research, data, mining, analytics, data_mining, machine_learning, deep_learning = count_TF(text_2)
tf_idf_doc2 = build_dict(research, data, mining, analytics, data_mining, machine_learning, deep_learning)

research, data, mining, analytics, data_mining, machine_learning, deep_learning = count_TF(text_3)
tf_idf_doc3 = build_dict(research, data, mining, analytics, data_mining, machine_learning, deep_learning)

research, data, mining, analytics, data_mining, machine_learning, deep_learning = count_TF(text_4)
tf_idf_doc4 = build_dict(research, data, mining, analytics, data_mining, machine_learning, deep_learning)

research, data, mining, analytics, data_mining, machine_learning, deep_learning = count_TF(text_5)
tf_idf_doc5 = build_dict(research, data, mining, analytics, data_mining, machine_learning, deep_learning)

research, data, mining, analytics, data_mining, machine_learning, deep_learning = count_TF(text_6)
tf_idf_doc6 = build_dict(research, data, mining, analytics, data_mining, machine_learning, deep_learning)

# TODO: -----------------------------------PART 2----------------------------------------------

'''
Building Dataframe by comibining all dictionaries. 
'''
df = pd.DataFrame([tf_idf_doc1, tf_idf_doc2, tf_idf_doc3, tf_idf_doc4, tf_idf_doc5, tf_idf_doc6],
                  index=["Doc[1]-->", "Doc[2]-->", "Doc[3]-->", "Doc[4]-->", "Doc[5]-->", "Doc[6]-->"], )
df.to_csv("./files/Documnet Vectors For Keywords.csv")
print("<-----Documnet Vectors For Keywords----->")
print(df)

'''
Constructing cosine similarity matrix for all documents.
'''
similarity = pd.DataFrame(cosine_similarity(df),
                          index=["Doc[1]-->", "Doc[2]-->", "Doc[3]-->", "Doc[4]-->", "Doc[5]-->", "Doc[6]-->"],
                          columns=["Doc1", "Doc2", "Doc3", "Doc4", "Doc5", "Doc6"])
similarity.to_csv("./files/Cosine Similarity Matrix for All The Documents.csv")
print("<-----Cosine Similarity Matrix for All The Documents----->")
print(similarity)
