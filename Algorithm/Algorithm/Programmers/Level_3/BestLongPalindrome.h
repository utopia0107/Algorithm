//
//  BestLongPalindrome.h
//  Algorithm
//
//  Created by 민수 정  on 20/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef BestLongPalindrome_h
#define BestLongPalindrome_h
#include <string>
#include <algorithm>
using namespace std;

//0을 포함하는 자연수.
int solution(string s)
{
    int answer=1;
    int size=s.size();
    if(size==0)return 0;
    if(size==1)return 1;

        for(int i=0;i<size-1;i++)
        {
            for(int j=0;j<=i;j++)
            {
                int length=size-i;
                int range=length/2;
                int start=j;
                int end=j+length-1;
                int k;
                for(k=0;k<range;k++)
                {
                    if(s[start+k]!=s[end-k])break;
                }
                if(k==range)
                {
                    return length;
                }
            }
        }
    
    return answer;
}

#endif /* BestLongPalindrome_h */
