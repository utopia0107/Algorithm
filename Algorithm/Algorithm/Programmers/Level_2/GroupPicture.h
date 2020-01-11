//
//  GroupPicture.h
//  Algorithm
//
//  Created by 민수 정  on 11/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef GroupPicture_h
#define GroupPicture_h
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>


using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char>v;
    v.push_back('A');
    v.push_back('C');
    v.push_back('F');
    v.push_back('J');
    v.push_back('M');
    v.push_back('N');
    v.push_back('R');
    v.push_back('T');
    int cnt=0;

    cout<<"\n";
    do
    {
        int i=0;
        for(;i<n;i++){
            string str= data[i];
            char a=str[0],b=str[2];
            char condition=str[3];
            char test=str[4];
            int num=atoi(&test);
            int a_index,b_index;
            for(int j=0;j<8;j++){
                if(a==v[j])
                {
                    a_index=j;
                }
                if(b==v[j])
                {
                    b_index=j;
                }
            }
           if(condition=='=')
           {
               if(abs(a_index-b_index)-1==num)continue;
               else break;
           }
           else if(condition=='<')
           {
               if(abs(a_index-b_index)-1<num) continue;
               else break;
           }
           else if(condition=='>')
           {
               if(abs(a_index-b_index)-1>num)continue;
               else break;
           }
        }
        if(i==n)  answer++;

    }while(next_permutation(v.begin(),v.end()));

    return answer;
}

#endif /* GroupPicture_h */
