//
//  MoreSpicy .h
//  Algorithm
//
//  Created by 민수 정  on 07/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef MoreSpicy__h
#define MoreSpicy__h
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long,vector<long long>,greater<long long>>q;
    for(int i=0;i<scoville.size();i++){
        q.push(scoville[i]);
    }
    int cnt=0;
    while(q.top()<K){
        int a,b;
        cnt++;
        a=q.top();
        q.pop();
        b= q.top();
        q.pop();
        q.push(a+b*2);
        if(q.size()==1&&q.top()<K){
            return -1;
        }
    }
    answer=cnt;
    return answer;
}

#endif /* MoreSpicy__h */
