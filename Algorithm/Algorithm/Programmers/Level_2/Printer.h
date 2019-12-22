//
//  Printer.h
//  Algorithm
//
//  Created by 민수 정  on 22/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef Printer_h
#define Printer_h
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    stack<int> s;
    queue<pair<int,int>> q;
    for(int i=0;i<priorities.size();i++){
        q.push(make_pair(i,priorities[i]));
    }
    sort(priorities.begin(),priorities.end());
    for(int i=0;i<priorities.size();i++){
        s.push(priorities[i]);
    }
    int cnt=0;
    while(!q.empty()){
        pair<int,int> temp =q.front();
        q.pop();
        if(s.top()==temp.second){
            cnt++;
            s.pop();
            if(location==temp.first){
                answer=cnt;
                break;
            }
        }else{
            q.push(temp);
        }
    }
    
    return answer;
}

#endif /* Printer_h */
