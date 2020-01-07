//
//  RamenFactory .h
//  Algorithm
//
//  Created by 민수 정  on 07/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef RamenFactory__h
#define RamenFactory__h
#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int,vector<int>,less<int>> q;
    int index=0;
    
    while(stock<k){
            for(;index<dates.size();index++)
            {
                //버틸수 없는 날
               if(stock<dates[index]){
                   break;
               }else{
                   q.push(supplies[index]);
               }
            }
            stock+=q.top();
            answer++;
            q.pop();
    }
    return answer;
}

#endif /* RamenFactory__h */
