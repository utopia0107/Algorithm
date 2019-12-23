//
//  Budget.h
//  Algorithm
//
//  Created by 민수 정  on 23/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef Budget_h
#define Budget_h
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    long long minTotal=0,maxTotal=0;
    int min=100000,max=0;
    int size=budgets.size();
    int sub=100000;
    for(int i=0;i<size;i++)
    {
        if(budgets[i]<min)min=budgets[i];
        if(budgets[i]>max)max=budgets[i];
    }
    for(int i=0;i<size;i++)
    {
        minTotal+=min<=budgets[i]?min:budgets[i];
        maxTotal+=max<=budgets[i]?max:budgets[i];
    }
    if(maxTotal<=M)
    {
        return max;
    }else if(minTotal>M)
    {
        max=min;
        min=0;
    }
    answer=(max+min)/2;
    while(min<=max)
    {
        long long total=0;
        for(int i=0;i<size;i++)
        {
            total+=answer<=budgets[i]?answer:budgets[i];
        }
        if(total<M)
        {
           min=answer+1;
        }else if(total>M)
        {
           max=answer-1;
        }else break;
        answer=(max+min)/2;
    }
    return answer;
}

#endif /* Budget_h */
