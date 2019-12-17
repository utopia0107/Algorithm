//
//  DualPriorityQueue .h
//  Algorithm
//
//  Created by 민수 정  on 17/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef DualPriorityQueue__h
#define DualPriorityQueue__h

#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    answer.resize(2);
    int size=operations.size();
    bool bcurMaxQ=true;
    priority_queue< int, vector<int>, less<int> > maxQ;
    priority_queue< int, vector<int>, greater<int> > minQ;
    for(int i=0;i<size;i++)
    {
        if(operations[i][0]=='I')
        {
            if(bcurMaxQ){
                maxQ.push(atoi(operations[i].substr(2).c_str()));

            }else{
                minQ.push(atoi(operations[i].substr(2).c_str()));
            }
        }
        else
        {
            //최솟값 삭제
            if(operations[i][2]=='-')
            {
                if(bcurMaxQ)
                {
                    while(!maxQ.empty())
                    {
                        minQ.push(maxQ.top());
                        maxQ.pop();
                    }
                }
                 if(!minQ.empty()) minQ.pop();
                bcurMaxQ=false;
            }//최대값 삭제
            else{
                 if(!bcurMaxQ)
                 {
                    while(!minQ.empty())
                    {
                        maxQ.push(minQ.top());
                        minQ.pop();
                    }
                 }
                 if(!maxQ.empty())maxQ.pop();
                bcurMaxQ=true;
            }
        }
    }

    if(maxQ.empty()&&minQ.empty()){
        answer[0]=answer[1]=0;
    }
    else
    {
        if(bcurMaxQ)
        {
            answer[0]=maxQ.top();
            while(!maxQ.empty())
            {
                minQ.push(maxQ.top());
                maxQ.pop();
            }
            answer[1]=minQ.top();
        }
        else
        {
            answer[1]=minQ.top();
            while(!minQ.empty())
            {
                maxQ.push(minQ.top());
                minQ.pop();
            }
            answer[0]=maxQ.top();
        }
    }
    return answer;
}

#endif /* DualPriorityQueue__h */
