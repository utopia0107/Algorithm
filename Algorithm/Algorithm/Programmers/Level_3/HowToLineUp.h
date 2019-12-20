//
//  HowToLineUp.h
//  Algorithm
//
//  Created by 민수 정  on 20/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef HowToLineUp_h
#define HowToLineUp_h

#include <string>
#include <vector>

using namespace std;
void GetIndexPermutation(long long k,vector<int> v,vector<int>* out)
{
    if(v.size()==0)return;
    int n=v.size();
    long long standard=1;
    for(int i=2;i<n;i++)
    {
        standard*=i;
    }
    int index=1;
    while(k>(index*standard))
    {
        index++;
    }
    index--;
    k-=index*standard;
    out->push_back(v[index]);
    v.erase(v.begin()+index);
    GetIndexPermutation(k,v,out);
}
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        v.push_back(i);
    }
    GetIndexPermutation(k,v,&answer);
    return answer;
}

#endif /* HowToLineUp_h */
