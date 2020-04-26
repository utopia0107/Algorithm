//
//  BadUsers .h
//  Algorithm
//
//  Created by 정민수 on 2020/04/26.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef BadUsers__h
#define BadUsers__h
#include <string>
#include <vector>
#include <set>
using namespace std;
bool banneds[8];
set<string> s;
bool CheckIdBaaned(string user_id,string banned_id)
{
    if(user_id.size()!=banned_id.size())return false;
    for(int i=0;i<user_id.size();i++)
    {
        if(!(banned_id[i]=='*'||user_id[i]==banned_id[i]))
        {
            return false;
        }
    }
    return true;
}

void DFS(vector<string> user_id,vector<string> banned_id,int depth)
{
    if(depth==banned_id.size())
    {
        string str="";
        for(int i=0;i<8;i++)
        {
            if(banneds[i])str+=i;
        }
        s.insert(str);
        return ;
    }
    for(int i=0;i<user_id.size();i++)
    {
        if(!banneds[i]
           &&CheckIdBaaned(user_id[i],banned_id[depth]))
        {
            banneds[i]=true;
            DFS(user_id,banned_id,depth+1);
            banneds[i]=false;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    DFS(user_id,banned_id,0);
    answer=s.size();
    return answer;
}

#endif /* BadUsers__h */
