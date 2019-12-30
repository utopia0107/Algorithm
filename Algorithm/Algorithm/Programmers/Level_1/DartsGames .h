//
//  DartsGames .h
//  Algorithm
//
//  Created by 민수 정  on 30/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef DartsGames__h
#define DartsGames__h
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int solution(string dartResult) {
    int answer = 0;
    vector<pair<int,string>> v;
    int index=0;
    while(v.size()!=3)
    {
        int cnt=0;
        for(int i=index;i<dartResult.size();i++)
        {
            if(dartResult[i]>='0'&&dartResult[i]<='9')cnt++;
            else break;
        }
        v.push_back(make_pair(stoi(dartResult.substr(index,cnt)),""));
        index+=cnt;
        cnt=0;
        for(int i=index;i<dartResult.size();i++)
        {
            if(dartResult[i]>='0'&&dartResult[i]<='9')break;
            else cnt++;
        }
        v[v.size()-1].second+=dartResult.substr(index,cnt);
        index+=cnt;
    }
    int points[3];
    for(int i=0;i<3;i++)
    {
        points[i]=0;
    }
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].second.size();j++)
        {
            switch(v[i].second[j])
            {
                case 'S':
                    points[i]=v[i].first;
                    break;
                case 'D':
                    points[i]=pow(points[i]=v[i].first,2);
                    break;
                case 'T':
                    points[i]=pow(points[i]=v[i].first,3);
                    break;
                case '*':
                    points[i]*=2;
                    if(i!=0)points[i-1]*=2;
                    break;
                case '#':
                    points[i]*=-1;
                    break;
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        answer+=points[i];
    }
    return answer;
}

#endif /* DartsGames__h */
