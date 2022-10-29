#This program calculates the city block distance, which tells that how much
#you are far away from your goal 


def cityBlockDistance(goal,state):
    h2=0
    for i in range(len(goal)):
        if goal[i]!='-' and goal[i]!=state[i] :
           l1=i
           l2=state.index(goal[i])
           x1=l1//3
           y1=l1%3
           x2=l2//3
           y2=l2%3
           h2+=abs(x2-x1)+abs(y2-y1)
    print(h2)


#method invokation   
goal=[1,2,3,6,5,4,8,7,'-']
state=[1,2,3,5,6,'-',4,7,8]
cityBlock(goal,state)

 
