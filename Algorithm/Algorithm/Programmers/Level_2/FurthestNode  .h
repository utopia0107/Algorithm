//
//  FurthestNode  .h
//  Algorithm
//
//  Created by 민수 정  on 16/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef FurthestNode___h
#define FurthestNode___h
#include <string>
#include <vector>
#include <queue>
using namespace std;
bool bvisited[20001];
int BFS(vector<vector<int>> tree)
{
    queue<int> q;
    q.push(0);
    bvisited[0]=true;

    int curQueueSize=1;
    int popCnt=0;
    while(!q.empty())
    {
        int curIndex=q.front();
        q.pop();
        popCnt++;
        for(int i=0;i<tree[curIndex].size();i++)
        {
            int nextIndex=tree[curIndex][i];
            if(!bvisited[nextIndex])
            {
                bvisited[nextIndex]=true;
                q.push(nextIndex);
            }
        }
        if(popCnt==curQueueSize)
        {
            if(q.size()==0)return curQueueSize;
            curQueueSize=q.size();
            popCnt=0;
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int edgeSize=edge.size();
    vector<vector<int>> tree;
    tree.resize(n);
    for(int i=0;i<edgeSize;i++)
    {
        tree[edge[i][0]-1].push_back(edge[i][1]-1);
        tree[edge[i][1]-1].push_back(edge[i][0]-1);
    }
    answer=BFS(tree);
    
    return answer;
}

#endif /* FurthestNode___h */
