//
//  Compression.h
//  Algorithm
//
//  Created by 민수 정  on 03/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef Compression_h
#define Compression_h
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dictionary;
    for(char i='A';i<='Z';i++)
    {
        dictionary.push_back(to_string(i));
    }
    
    for(int startIndex=0;startIndex<msg.size();startIndex++)
    {
        string subString="";
        subString.append(to_string(msg[startIndex]));
        int stack=0;
        while(find(dictionary.begin(),dictionary.end(),subString)!=dictionary.end())
        {
            stack++;
            subString.append(to_string(msg[startIndex+stack]));
        }
        dictionary.push_back(subString);
        subString="";
        for(int i=0;i<stack;i++)
        {
            subString.append(to_string(msg[startIndex+i]));
        }
        for(int i=0;i<dictionary.size();i++)
        {
            if(dictionary[i].compare(subString)==0)
            {
                answer.push_back(i+1);
                break;
            }
        }
        startIndex+=(stack-1);
    }
    return answer;
}

#endif /* Compression_h */
