//
//  FineRectangle.h
//  Algorithm
//
//  Created by 민수 정  on 01/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef FineRectangle_h
#define FineRectangle_h
using namespace std;
int gcd(int a, int b){
    while(b!=0){
        int r = a%b;
        a= b;
        b= r;
    }
    return a;
}
long long solution(int w,int h)
{
    long long answer = 1;
    if(gcd(w,h)!=1){
       answer=(long long)w*h-(w+h-gcd(w,h));
    }else
    {
       answer=(long long)w*h-(w+h-1);
    }
    return answer;
}

#endif /* FineRectangle_h */
