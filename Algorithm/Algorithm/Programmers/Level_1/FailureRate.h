//
//  FailureRate.h
//  Algorithm
//
//  Created by 민수 정  on 30/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef FailureRate_h
#define FailureRate_h
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float,int>> clearPercentageStages;
    int playerCnt=stages.size();
    sort(stages.begin(),stages.end());
    int index=0;
    for(int i=1;i<=N;i++)
    {
        int cnt=0;
        for(int j=index;j<stages.size();j++)
        {
            if(stages[j]==i)cnt++;
            else break;
        }
        index+=cnt;
        clearPercentageStages.push_back(make_pair(cnt==0?0:(float)cnt/playerCnt,N-i));
        playerCnt-=cnt;
    }
    sort(clearPercentageStages.begin(),clearPercentageStages.end(),greater<pair<float,int>>());
    for(int i=0;i<N;i++)
    {
        answer.push_back(N-clearPercentageStages[i].second);
    }
    return answer;
}

#endif /* FailureRate_h */
