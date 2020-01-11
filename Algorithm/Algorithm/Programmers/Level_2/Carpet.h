//
//  Carpet.h
//  Algorithm
//
//  Created by 민수 정  on 11/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef Carpet_h
#define Carpet_h
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int  i=3;
    int total=brown+red;
    while(true){
        if(total%i==0){
            int red_cnt= (i-2)*(total/i-2);
            if(red_cnt==red&&(i)>=(total/i))
            {
                answer.push_back(i);
                answer.push_back(total/i);
                break;
            }
        }
        i++;
    }
    return answer;
}

#endif /* Carpet_h */
