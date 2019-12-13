//
//  FibonacciNumber.h
//  Algorithm
//
//  Created by 민수 정  on 13/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef FibonacciNumber_h
#define FibonacciNumber_h

#include <string>
#include <vector>

using namespace std;

int fibonacci[100001];
int solution(int n) {
    int answer = 0;
    fibonacci[0]=0;
    fibonacci[1]=fibonacci[2]=1;
    for(int i=3;i<=n;i++)
    {
        fibonacci[i]=(fibonacci[i-1]+fibonacci[i-2])%1234567;
    }
    answer=fibonacci[n];
    return answer;
}
#endif /* FibonacciNumber_h */
