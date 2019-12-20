//
//  N-Queen.h
//  Algorithm
//
//  Created by 민수 정  on 20/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef N_Queen_h
#define N_Queen_h

#include <string>
#include <vector>
using namespace std;
bool Check(vector<pair<int,int>> v, pair<int,int> pos)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i].second==pos.second
            ||v[i].first==pos.first
          ||(abs(v[i].first-pos.first)==abs(v[i].second-pos.second)))
            return false;
    }
    return true;
}
void GetQueenCount(int n,int nQueen, vector<pair<int,int>> v,int*out)
{
    if(n==nQueen)
    {
        (*out)++;
        return;
    }
    for(int i=0;i<n;i++)
    {
       if(Check(v,make_pair(i,nQueen)))
       {
           v.push_back(make_pair(i,nQueen));
           GetQueenCount(n,nQueen+1,v,out);
           v.erase(v.begin()+nQueen);
       }
    }
    
}
int solution(int n) {
    int answer = 0;
    vector<pair<int,int>> v;
    GetQueenCount(n,0,v,&answer);
    
    return answer;
}
#endif /* N_Queen_h */
