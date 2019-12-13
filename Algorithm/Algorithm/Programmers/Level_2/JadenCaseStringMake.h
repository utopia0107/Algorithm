//
//  JadenCaseStringMake.h
//  Algorithm
//
//  Created by 민수 정  on 13/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef JadenCaseStringMake_h
#define JadenCaseStringMake_h
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    if(s[0]>='a'&&s[0]<='z')
    {
        s[0]=s[0]-32;
    }
    for(int i=1;i<s.size();i++)
    {
        if(s[i-1]==' ')
        {
         if(s[i]>='a'&&s[i]<='z')
        {
            s[i]=s[i]-32;
        }
        }else if(s[i]>='A'&&s[i]<='Z')
        {
            s[i]=s[i]+32;
        }
    }
    answer=s;
    return answer;
}

#endif /* JadenCaseStringMake_h */
