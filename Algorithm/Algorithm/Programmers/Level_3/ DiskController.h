//
//   DiskController.h
//  Algorithm
//
//  Created by 민수 정  on 17/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef _DiskController_h
#define _DiskController_h
#include <string>
#include <vector>
#include <queue>
using namespace std;
// 현재 시간에서 실행 가능한 jobs들을 우선순위 큐에 넣고, job은 지운다.
void GetJobs(vector<vector<int>>* jobs,int time,priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >* pq)
{
    for(int i=0;i<jobs->size();i++)
    {
        if(time>=(*jobs)[i][0])
        {
            pq->push(make_pair((*jobs)[i][1],(*jobs)[i][0]));
            jobs->erase(jobs->begin() + i);
            i--;
        }
        
    }
}
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int totalTime=0;
    int size=jobs.size();
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    while(true)
    {
        if(jobs.size()==0&&pq.empty())break;
        GetJobs(&jobs,time,&pq);
        if(!pq.empty())
        {
            totalTime+=time-pq.top().second+pq.top().first;
            time+= pq.top().first;
            pq.pop();
        }else{
            time++;
        }
    }
    
    answer=totalTime/size;
    return answer;
}

#endif /* _DiskController_h */
