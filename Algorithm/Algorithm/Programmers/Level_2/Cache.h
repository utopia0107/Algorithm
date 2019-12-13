//
//  Cache.h
//  Algorithm
//
//  Created by 민수 정  on 13/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef Cache_h
#define Cache_h
#include <string>
#include <vector>
#include<queue>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    bool bhit=false;
    queue<string> q1,q2;
    int length=cities.size();
    if(cacheSize==0)answer=cities.size()*5;
    else{
    for(int i=0;i<length;i++)
    {
       transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    }
    for(int i=0;i<length;i++)
    {
        bhit=false;
        if(!q1.empty()||!q2.empty())
        {
            queue<string>*fullQ=!q1.empty()?&q1:&q2;
            queue<string>*emptyQ=!q1.empty()?&q2:&q1;
            while(!(fullQ->empty()))
            {
                if(cities[i].compare(fullQ->front())==0)
                {
                    bhit=true;
                }else{
                    emptyQ->push(fullQ->front());
                }
                fullQ->pop();
            }
            while( !fullQ->empty() ) fullQ->pop();
        }
        if(!bhit)
        {
            answer+=5;
            queue<string>*q=!q1.empty()?&q1:&q2;
            if(q->size()==cacheSize)
            {
                q->pop();
            }
            q->push(cities[i]);
        }else{
            answer+=1;
            queue<string>*q=!q1.empty()?&q1:&q2;
            q->push(cities[i]);
        }
    }
    }
    return answer;
}

#endif /* Cache_h */
