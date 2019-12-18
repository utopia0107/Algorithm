//
//  ConnectIsland .h
//  Algorithm
//
//  Created by 민수 정  on 18/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef ConnectIsland__h
#define ConnectIsland__h

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
bool Check(int start,int end,vector<pair<int,int>>edge)
{
    bool visisted[100];
    memset(visisted,false,sizeof(visisted));
    queue<int> q;
    q.push(start);
    visisted[start]=true;
    while(!q.empty())
    {
        int n=q.front();
        q.pop();
        if(n==end)return true;
        for(int i=0;i<edge.size();i++)
        {
            if(edge[i].first==n
              &&!visisted[edge[i].second])
            {
               visisted[edge[i].second]=true;
                q.push(edge[i].second);
            }
            else if(edge[i].second==n
                   &&!visisted[edge[i].first])
            {
                               visisted[edge[i].first]=true;
                q.push(edge[i].first);
            }
        }
    }
    
    return false;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<pair<int,pair<int,int>>> cost;
    vector<pair<int,int>> edge;
    for(int i=0;i<costs.size();i++)
    {
        cost.push_back(make_pair(costs[i][2],make_pair(costs[i][0],costs[i][1])));
    }
    sort(cost.begin(),cost.end());
    
    for(int i=0;i<cost.size();i++)
    {
        if(!Check(cost[i].second.first,cost[i].second.second,edge))
        {
            answer+=cost[i].first;
            edge.push_back(make_pair(cost[i].second.first,cost[i].second.second));
        }
    }
    
    return answer;
}
#endif /* ConnectIsland__h */
