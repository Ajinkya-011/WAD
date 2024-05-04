

import sys

def all_visited(visited):
    return all(visited)

def tsp(visited,current,cost,path):
    global min_cost,ans
    if(all_visited(visited)):
        if(cost+graph[current][0]<min_cost):
            min_cost=cost+graph[current][0]
            ans=path+[0]
        return

    for i in range(n):
        if not visited[i] and i!=current:
            visited[i]=True
            tsp(visited,i,cost+graph[current][i],path+[i])
            visited[i]=False


if __name__=="__main__":
    print("Enter the total number of vertices:")
    n=int(input())

    graph=[]

    for i in range(n):
        row=[]
        for j in range(n):
            if(i!=j):
                print(f"Enter the distance from {i} to {j} :")
                dist=int(input())
                row.append(dist)
            else:
                row.append(0)
        graph.append(row)

    for i in range(n):
        for j in range(n):
            print(graph[i][j], end="\t")
        print()

    path=[]
    visited=[False]*n
    min_cost=sys.maxsize    
    visited[0]=True    

    tsp(visited,0,0,[0])
    print("Shortest path:",ans)
    print("Min Cost is:",min_cost)