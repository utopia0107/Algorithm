//
//  CorrectParenthesis .h
//  Algorithm
//
//  Created by 정민수 on 14/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef CorrectParenthesis__h
#define CorrectParenthesis__h
#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int stack_cnt=0;
    for(int i=0;i<s.length();i++){
        switch(s[i]){
            case '(':
                stack_cnt++;
                break;
            case ')':
                stack_cnt--;
                break;
        }
        if(stack_cnt<0)return false;
    }
    
    return stack_cnt==0;
}

#endif /* CorrectParenthesis__h */
