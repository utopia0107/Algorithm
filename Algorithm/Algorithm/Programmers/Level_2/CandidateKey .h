//
//  CandidateKey .h
//  Algorithm
//
//  Created by 민수 정  on 03/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef CandidateKey__h
#define CandidateKey__h
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int width;
int height;
bool CheckCandidateKey(vector<int> columns,vector<vector<string>> relation)
{
    set<vector<string>> s;
    for(int i=0;i<height;i++)
    {
        vector<string> v;
        for(int k=0;k<columns.size();k++)
        {
            v.push_back(relation[i][columns[k]]);
        }
        s.insert(v);
    }
    if(height==s.size())return true;
    else return  false;
}
bool CheckAddColumn(int columnNum, vector<int> columns,set<vector<int>> candidateKeys)
{
    for(int cnt=0;cnt<columns.size();cnt++)
    {
        for(int startIndex=0;startIndex<columns.size()-cnt;startIndex++)
        {
            vector<int> v;
            for(int j=startIndex;j<startIndex+cnt;)
            {
                 v.push_back(columns[j]);
            }
             v.push_back(columnNum);
             if(candidateKeys.find(v)!=candidateKeys.end())
             {
                 return false;
             }
        }
       
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    width=relation[0].size();
    height=relation.size();
    
    set<vector<int>> candidateKeys;
    vector<vector<int>> candidates;
    
    for(int i=0;i<width;i++)
    {
        vector<int> temp;
        temp.push_back(i);
        if(CheckCandidateKey(temp,relation))
        {
            candidateKeys.insert(temp);
        }else{
            candidates.push_back(temp);
        }
    }
    for(int k=1;k<width;k++)
    {
        //벡터 사이즈
        int size=candidates.size();
        while(size--)
        {
            for(int j=candidates[0][candidates[0].size()-1]+1;j<width;j++)
            {
                vector<int> checkList;
                checkList.push_back(j);
                //새로 추가될 j에 대한 검사, j가 이미 후보키거나, 부분적으로 j와 결합으로 후보키인 경우를 검사해야됨...
                vector<int> temp=candidates[0];
                temp.push_back(j);
                bool check=false;
                for(set<vector<int>>::iterator iter=candidateKeys.begin();iter!=candidateKeys.end();iter++)
                {
                     vector<int> vi;
                    //교집합 검사
                    set_intersection(temp.begin(),temp.end(),iter->begin(),iter->end(),back_inserter(vi));
                    if(iter->size()==vi.size())
                    {
                        check=true;
                        break;
                    }
                }
                if(!check)
                {
                    //후보키라면??
                    if(CheckCandidateKey(temp,relation))
                    {
                        //후보키 리스트에 등록
                        candidateKeys.insert(temp);
                    }else{
                        candidates.push_back(temp);
                    }
                }
            }
            candidates.erase(candidates.begin());
        }
    }
    answer=candidateKeys.size();
    return answer;
}

#endif /* CandidateKey__h */
