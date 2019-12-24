//
//  Delivery.h
//  Algorithm
//
//  Created by 민수 정  on 24/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef Delivery_h
#define Delivery_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int maxTime;
bool visitied[51];
vector<vector<pair<int,int>>> roads;
set<int>nodes;

void DFS(int curNode,int time)
{
    visitied[curNode]=true;
    if(time<=maxTime)
    {
        nodes.insert(curNode);
        for(int i=0;i<roads[curNode].size();i++)
        {
            if(!visitied[roads[curNode][i].first])
            {
                DFS(roads[curNode][i].first,time+roads[curNode][i].second);
                visitied[roads[curNode][i].first]=false;
            }
        }
    }
}
int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    roads.resize(N+1);
    maxTime=K;
    for(int i=0;i<road.size();i++)
    {
        roads[road[i][0]].push_back(make_pair(road[i][1],road[i][2]));
        roads[road[i][1]].push_back(make_pair(road[i][0],road[i][2]));
    }
    DFS(1,0);
    answer=nodes.size();
    return answer;
}

#endif /* Delivery_h */
