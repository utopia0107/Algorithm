//
//  LockAndKey.h
//  Algorithm
//
//  Created by 민수 정  on 27/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef LockAndKey_h
#define LockAndKey_h
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> RotationKey(vector<pair<int,int>> key,int maxSize)
{
    for(int i=0;i<key.size();i++)
    {
        int first=key[i].first;
        key[i].first=key[i].second;
        key[i].second=maxSize-(first+1);
    }
    return key;
}

bool Checking(pair<int,int> direction,vector<pair<int,int>>* key,vector<pair<int,int>>* lock,int maxSize)
{
    int cnt=0;
    int count=0;
    for(int i=0;i<key->size();i++)
    {
        pair<int,int>pos;
        pos.first=key->at(i).first+direction.first;
        pos.second=key->at(i).second+direction.second;
        if((pos.first>=0&&pos.first<maxSize)
          &&(pos.second>=0&&pos.second<maxSize))
        {
            if(find(lock->begin(),lock->end(),pos)!=lock->end())cnt++;
            else return false;
        }
    }
    return cnt==lock->size();
}
bool CheckDirection(vector<pair<int,int>>* key,vector<pair<int,int>>* lock,int maxSize)
{
    pair<int,int> direction;
    
    for(int i=0;i<key->size();i++)
    {
        direction.first=lock->at(0).first-key->at(i).first;
        direction.second=lock->at(0).second-key->at(i).second;
        int cnt=0;
        for(int j=0;j<lock->size();j++)
        {
            if(find(key->begin(),key->end(),
                    make_pair(lock->at(j).first-direction.first
                              ,lock->at(j).second-direction.second))
              !=key->end())
            {
                cnt++;
            }
        }
        if(cnt==lock->size())
        {
            if(Checking(direction,key,lock,maxSize))
            {
                return true;
            }else{
                continue;
            }
        }
    }
    return false;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int maxSize=lock.size();
    vector<vector<vector<int>>>keys;
    //시계 방향으로 0,90,180,270도 회전 경우
    vector<vector<pair<int,int>>> keyPositions;
    keyPositions.resize(4);
    vector<pair<int,int>> positions;
    for(int i=0;i<lock.size();i++)
    {
        for(int j=0;j<lock[0].size();j++)
        {
            if(lock[i][j]==0)positions.push_back(make_pair(i,j));
        }
    }
    //그냥 열리는 경우
    if(positions.size()==0)return true;
    //key로 부터 1(튀어나온)의 위치 정보를 구한다.
    for(int i=0;i<key.size();i++)
    {
        for(int j=0;j<key[0].size();j++)
        {
            if(key[i][j]==1)keyPositions[0].push_back(make_pair(i,j));
        }
    }
    
    //구한 값을 로테이션으로 돌린다.
    vector<pair<int,int>> temp=keyPositions[0];
    for(int i=1;i<4;i++)
    {
        temp= RotationKey(temp,key.size());
        keyPositions[i].resize(temp.size());
        copy(temp.begin(),temp.end(),keyPositions[i].begin());
    }
    for(int i=0;i<4;i++)
    {
        if(CheckDirection(&keyPositions[i],&positions,maxSize))
        {
            answer=true;
        }
    }
    return answer;
}

#endif /* LockAndKey_h */
