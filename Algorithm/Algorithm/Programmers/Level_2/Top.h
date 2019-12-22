//
//  Top.h
//  Algorithm
//
//  Created by 민수 정  on 22/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef Top_h
#define Top_h
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> s;
    int length=heights.size();
    for(int i=0;i<length;i++){
        s.push(heights[i]);
    }
    while(!s.empty()){
        int cur = s.top();
        bool check = false;
        for(int i=length-(answer.size()+1);i>=0;i--){
            if(heights[i]>cur){
                s.pop();
                check=true;
                answer.push_back(i+1);
                break;
            }
        }
        if(!check){
            answer.push_back(0);
            s.pop();
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}

#endif /* Top_h */
