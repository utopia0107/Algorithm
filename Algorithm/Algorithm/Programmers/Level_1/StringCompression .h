//
//  StringCompression .h
//  Algorithm
//
//  Created by 민수 정  on 01/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef StringCompression__h
#define StringCompression__h
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    answer=s.size();
    int startIndex=0;
    for(int wordSize=1;wordSize<=s.size()/2;wordSize++)
    {
        string str="";
        int cnt=1;
        for(startIndex=0;startIndex<s.size()-wordSize;startIndex+=wordSize)
        {
            int length=0;
            for(int i=0;i<wordSize;i++)
            {
                 if(s[startIndex+i]==s[startIndex+wordSize+i])
                 {
                     length++;
                 }
            }
            if(length==wordSize)
            {
                cnt++;
            }else
            {
                str.append(cnt==1?"":to_string(cnt));
                str.append(s.substr(startIndex,wordSize));
                cnt=1;
            }
        }
        str.append(cnt==1?"":to_string(cnt));
        str.append(s.substr(startIndex));
        if(answer>=str.size())answer=str.size();
    }
    return answer;
}

#endif /* StringCompression__h */
