//
//  origami.h
//  Algorithm
//
//  Created by 민수 정  on 24/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef origami_h
#define origami_h
#include <string>
#include <vector>
#include <cmath>
using namespace std;
vector<vector<int>> nodes;
//증위 순회
void InOrderTraversal(int curNode,vector<int>* path)
{
    if(nodes[curNode].size()>0)
    {
        InOrderTraversal(nodes[curNode][0],path);
        if(curNode==0)
        {
            path->push_back(curNode);
        }else{
            path->push_back((curNode+1)%2);
        }
        InOrderTraversal(nodes[curNode][1],path);
    }else{
        if(curNode==0)
        {
            path->push_back(curNode);
        }else{
            path->push_back((curNode+1)%2);
        }

    }
}

vector<int> solution(int n) {
    vector<int> answer;
    //노드 갯수
    int nodeNum= pow(2,n)-1;
    nodes.resize(nodeNum);
    
    //트리 구성
    for(int i=1;i<nodeNum;i++)
    {
        nodes[(i-1)/2].push_back(i);
    }
    
    InOrderTraversal(0,&answer);
    
    return answer;
}

#endif /* origami_h */
