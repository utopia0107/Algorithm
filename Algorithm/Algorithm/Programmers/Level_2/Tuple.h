//
//  Tuple.h
//  Algorithm
//
//  Created by 정민수 on 2020/04/26.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef Tuple_h
#define Tuple_h
#include <string>
#include <vector>
#include <sstream>
#include<algorithm>

using namespace std;
bool compare(vector<int> a,vector<int>b)
{
    return a.size()<b.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> tuples;
    int startIndex,lastIndex;
    for(int i=1;i<s.size()-1;i++)
    {
        if(s[i]=='{')
        {
            startIndex=i;
        }else if(s[i]=='}')
        {
            lastIndex=i;
            string subStr = s.substr(startIndex+1, lastIndex-startIndex+1);
            
            vector<int> tokens;
            string token;
            istringstream tokenStream(subStr);
            while (std::getline(tokenStream, token, ','))
            {
                  tokens.push_back(stoi(token));
            }
            tuples.push_back(tokens);
        }
    }
    sort(tuples.begin(),tuples.end(),compare);
    for(int i=0;i<tuples.size();i++)
    {
        for(int j=0;j<tuples[i].size();j++)
        {
            if(find(answer.begin(),answer.end(),tuples[i][j])==answer.end())
            {
                answer.push_back(tuples[i][j]);
                break;
            }
        }
    }
    return answer;
}

#endif /* Tuple_h */
