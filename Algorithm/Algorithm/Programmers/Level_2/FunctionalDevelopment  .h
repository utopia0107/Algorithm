//
//  FunctionalDevelopment  .h
//  Algorithm
//
//  Created by 민수 정  on 21/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef FunctionalDevelopment___h
#define FunctionalDevelopment___h
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int std_day=ceil((100-progresses[0])/(float)speeds[0]);
    int cnt=0;
    for(int i=0;i<progresses.size();i++){
        int day=ceil((100-progresses[i])/(float)speeds[i]);
        if(std_day>=day){
            cnt++;
        }else{
            answer.push_back(cnt);
            std_day=day;
            cnt=1;
        }
    }
    answer.push_back(cnt);
   
    return answer;
}

#endif /* FunctionalDevelopment___h */
