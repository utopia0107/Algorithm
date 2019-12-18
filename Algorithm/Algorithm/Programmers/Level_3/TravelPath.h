//
//  TravelPath.h
//  Algorithm
//
//  Created by 민수 정  on 18/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef TravelPath_h
#define TravelPath_h


#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> DFS(string startName, map<string,vector<string>> ticket,vector<string> path,int maxLevel)
{
    path.push_back(startName);
    if(path.size()==maxLevel)
    {
        return path;
    }
    for(int i=0;i<ticket[startName].size();i++)
    {
        string nextName= ticket[startName][i];
        ticket[startName].erase(ticket[startName].begin()+i);
        vector<string> tempPath= DFS(nextName,ticket,path,maxLevel);
        if(tempPath.size()==maxLevel)return tempPath;
        ticket[startName].insert(ticket[startName].begin()+i,nextName);
    }
    return path;
}
using namespace std;
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    map<string,vector<string>> ticket;
    for(int i=0;i<tickets.size();i++)
    {
        if(ticket.find(tickets[i][0])!=ticket.end())
        {
            ticket[tickets[i][0]].push_back(tickets[i][1]);
        }else{
            vector<string> temp;
            temp.push_back(tickets[i][1]);
            ticket.insert(make_pair(tickets[i][0],temp));
        }
    }
    map<string,vector<string>>::iterator iter;
    for (iter = ticket.begin(); iter != ticket.end(); ++iter)
    {
        sort((*iter).second.begin(),(*iter).second.end());
    }
    answer=DFS("ICN",ticket,answer,tickets.size()+1);
    return answer;
}


#endif /* TravelPath_h */
