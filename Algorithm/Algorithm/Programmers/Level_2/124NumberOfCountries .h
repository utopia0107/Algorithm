//
//  124NumberOfCountries .h
//  Algorithm
//
//  Created by 민수 정  on 02/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _24NumberOfCountries__h
#define _24NumberOfCountries__h
#include <string>
#include <vector>
#include<algorithm>
#include <cmath>
using namespace std;

string solution(int n) {
    int num=3;
    string answer="";
    int temp=-1;
    while(n>0)
    {
        int temp=n%num;
        if(temp==0)temp=num;
        temp=ceil((float)temp/num*3);
        answer.append(temp==3?"4":to_string(temp));
        n-=num;
        num*=3;
    }
 
    reverse(answer.begin(),answer.end());

    return answer;
}

#endif /* _24NumberOfCountries__h */
