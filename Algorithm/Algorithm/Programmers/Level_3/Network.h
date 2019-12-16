//
//  Network.h
//  Algorithm
//
//  Created by 민수 정  on 16/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef Network_h
#define Network_h
#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool bvisited[200];
int pathCnt=0;
int maxNum=0;
vector<vector<int>> tree;

//깊이 우선 탐색으로 방문한 컴퓨터 체크
void DFS(int curIndex)
{
    if(curIndex==maxNum)return ;
    for(int i=0;i<tree[curIndex].size();i++)
    {
        int nextIndex=tree[curIndex][i];
        if(!bvisited[nextIndex])
        {
            bvisited[nextIndex]=true;
            DFS(nextIndex);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    maxNum=n;
    //인접 리스트를 만든다.
    for(int i=0;i<computers.size();i++)
    {
        vector<int> v;
        for(int j=0;j<computers[i].size();j++)
        {
            if(i!=j
              &&computers[i][j]==1)
            {
               v.push_back(j);
            }
        }
        tree.push_back(v);
    }
    //깊이 탐색을 하면서 갯수를 센다.
    for(int i=0;i<n;i++)
    {
        if(!bvisited[i])
        {
            DFS(i);
            pathCnt++;
        }
    }
    answer=pathCnt;
    return answer;
}

#endif /* Network_h */
