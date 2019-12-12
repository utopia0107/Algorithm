//
//  N_NumberLCM.h
//  Algorithm
//
//  Created by 민수 정  on 12/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef N_NumberLCM_h
#define N_NumberLCM_h

#include <string>
#include <vector>
using namespace std;
int CommonDivisors[101];
void GetCommonDivisors(int n)
{
    int divisor=2;
    int cnt=0;
    while(n!=1)
    {
        if(n%divisor==0)
        {
            n/=divisor;
            cnt++;
        }else{
            CommonDivisors[divisor]=max(CommonDivisors[divisor],cnt);
            cnt=0;
            divisor++;
        }
    }
    CommonDivisors[divisor]=max(CommonDivisors[divisor],cnt);

}
using namespace std;
int solution(vector<int> arr) {
    int answer = 1;
    for(int i=0;i<arr.size();i++)
    {
        GetCommonDivisors(arr[i]);
    }
    for(int i=1;i<101;i++)
    {
        if(CommonDivisors[i]>0)
        {
            int num=1;
            for(int j=0;j<CommonDivisors[i];j++)
            {
                num*=i;
            }
            answer*=num;
        }
    }
    return answer;
}

#endif /* N_NumberLCM_h */
