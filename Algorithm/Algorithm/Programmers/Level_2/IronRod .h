//
//  IronRod .h
//  Algorithm
//
//  Created by 민수 정  on 05/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef IronRod__h
#define IronRod__h

#include <string>
#include <vector>
#include<stack>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    char pre='a';
    int dirty=0;
    stack<int> s,temp;
    for(int i=0;i<arrangement.size();i++){
        switch(arrangement[i]){
            case '(':
                s.push(dirty);
                pre='(';
                break;
            case ')':
                if(pre=='('){
                    dirty++;
                    s.pop();
                }else{
                    answer+=dirty-s.top()+1;
                    s.pop();
                }
                pre=')';
                break;
        }
            
    }
    return answer;
}
#endif /* IronRod__h */
