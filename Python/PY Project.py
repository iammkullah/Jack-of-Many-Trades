'''
Importing json for file Reading
'''

import json

'''
Loading and printing json file 
'''

with open('/home/mudassir/Downloads/Test.json', 'r') as file:
    data = json.load(file)
    print(data)

'''
Appending children key with list as value to each node.
'''

for node in data:
    node['children'] = []

'''
Appending root nodes(where parentId is Null)  in a list .
'''

roots = []
for node in data:
    if (((node.get('parentId')) == None)):
        roots.append(node)
print(roots)

'''
Arranging root nodes on the basis of previous Sibling Id
'''

NODES = []
index = 0
for x in roots:
    if (x['previousSiblingId'] == None):
        NODES.append(x)
for i in range(0, 2):
    for x in roots:
        if (x['previousSiblingId'] != None):
            if (x['previousSiblingId'] == NODES[i]['nodeId']):
                NODES.insert(i + 1, x)
print(NODES)

'''
Appending nodes into Children list on the basis of its ParentId and previousSiblingId
'''

for node in data:
    if (node['parentId'] != None):
        id = node['parentId']
        for x in data:
            if (x['previousSiblingId'] == None):
                if (x['nodeId'] == str(id)):
                    if ((x['nodeId'] not in x['children'])):
                        x['children'].insert(0, node)
            else:
                if (x['nodeId'] == str(id)):
                    if ((x['nodeId'] not in x['children'])):
                        x['children'].append(node)

print(NODES)

'''
Saving Our Output to a Json File 
'''

result = "our_output.json"
f = open(result, 'w')
json.dump(NODES, f, indent=4)
f.close()
