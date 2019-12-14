//
//  OpenChatRoom.h
//  Algorithm
//
//  Created by 민수 정  on 14/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef OpenChatRoom_h
#define OpenChatRoom_h
#include <string>
#include <vector>
#include <sstream>
#include<map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> answerSplit;
    map<string,string> id2Name;
    for(int i=0;i<record.size();i++)
    {
        vector<string> result;
        istringstream iss(record[i]);
        string token;
        while (getline(iss, token,' '))
        {
            result.push_back( token);
        }
        answerSplit.push_back(result);
    }
    for(int i=0;i<answerSplit.size();i++)
    {
        if(answerSplit[i][0].compare("Enter")==0)
        {
            if(id2Name.find(answerSplit[i][1])!=id2Name.end())
            {
                            id2Name[answerSplit[i][1]]=answerSplit[i][2];

            }else{
            id2Name.insert(make_pair(answerSplit[i][1],answerSplit[i][2]));
            }
        }else if(answerSplit[i][0].compare("Change")==0)
        {
            id2Name[answerSplit[i][1]]=answerSplit[i][2];
        }
    }
    for(int i=0;i<answerSplit.size();i++)
    {
         if(answerSplit[i][0].compare("Enter")==0)
         {
             answer.push_back(id2Name[answerSplit[i][1]]+"님이 들어왔습니다.");
         }
         else if(answerSplit[i][0].compare("Leave")==0)
         {
             answer.push_back(id2Name[answerSplit[i][1]]+"님이 나갔습니다.");
         }
     }
    return answer;
}

#endif /* OpenChatRoom_h */
