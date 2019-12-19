//
//  OvertimeIndex  .h
//  Algorithm
//
//  Created by 민수 정  on 19/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef OvertimeIndex___h
#define OvertimeIndex___h

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long total=n;
    //works의 총합이 n보다 작거나 같을 경우 0을 리턴.
    for(int i=0;i<works.size();i++)
    {
        total-=works[i];
      
    }
    if(total>=0)return 0;
    sort(works.begin(),works.end(),greater<int>());

    while(n>0){
        int maxNum,nextMaxNum;
        maxNum=nextMaxNum=works[0];
        
        //최대값, 다음 최대값
        for(int i=0;i<works.size();i++)
        {
            if(maxNum>works[i])
            {
                nextMaxNum=works[i];
                break;
            }
        }
        if(maxNum==nextMaxNum)break;
        
        for(int i=0;i<works.size();i++)
        {
            if(works[i]==maxNum)
            {
                works[i]--;
                n--;
                if(n==0)break;
            }
        }
    }
    
    
    
    if(n>0)
    {
        int quotient=n/works.size();
        int remainder=n%works.size();
        for(int i=0;i<works.size();i++)
        {
            works[i]-=quotient;
            if(i<remainder)works[i]--;
        }
    }
    
    
    for(int i=0;i<works.size();i++)
    {
        answer+=(long long)works[i]*(long long)works[i];
    }
    
    return answer;
}
#endif /* OvertimeIndex___h */
