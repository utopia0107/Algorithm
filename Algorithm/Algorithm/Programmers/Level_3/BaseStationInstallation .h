//
//  BaseStationInstallation .h
//  Algorithm
//
//  Created by 민수 정  on 24/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef BaseStationInstallation__h
#define BaseStationInstallation__h
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int size=stations.size();
    vector<pair<int,int>> v;
    int minIndex=1,maxIndex=0;
    if(w==0)
    {
        answer=n-stations.size();
        return answer;
    }
    for(int i=0;i<size;i++)
    {
        int index=stations[i];
        maxIndex=stations[i]-w-1;
        if(minIndex<=maxIndex)v.push_back(make_pair(minIndex,maxIndex));
        minIndex=stations[i]+w+1;
    }
    if(minIndex<=n)v.push_back(make_pair(minIndex,n));
    for(int i=0;i<v.size();i++)
    {
        answer+=ceil((v[i].second-v[i].first+1)/(float)(w*2+1));
    }

    return answer;
}

#endif /* BaseStationInstallation__h */
