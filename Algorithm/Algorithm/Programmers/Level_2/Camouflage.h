//
//  Camouflage.h
//  Algorithm
//
//  Created by 민수 정  on 13/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef Camouflage_h
#define Camouflage_h
#include <string>
#include <map>
#include <vector>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,vector<string>> m;
    for(int i=0;i<clothes.size();i++)
    {
        if(m.find(clothes[i][1])!=m.end())
        {
            m[clothes[i][1]].push_back(clothes[i][0]);
        }
        else
        {
            vector<string> v;
            v.push_back(clothes[i][0]);
             m.insert(make_pair(clothes[i][1],v));
        }
    }
    map<string, vector<string>>::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter)
    {
        answer*= ((*iter).second.size()+1);
    }
       answer--;
    return answer;
}

#endif /* Camouflage_h */
