//
//  MatrixMultiplication .h
//  Algorithm
//
//  Created by 민수 정  on 13/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef MatrixMultiplication__h
#define MatrixMultiplication__h
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int length=arr2.size();
    int x=arr2[0].size(), y=arr1.size();
    answer.resize(y);
    for(int i=0;i<y;i++)
    {
        answer[i].resize(x);
    }
   for(int i=0;i<y;i++)
    {
        for(int j=0;j<x;j++)
        {
            int num=0;
           for(int k=0;k<length;k++)
           {
               num+=arr1[i][k]*arr2[k][j];
           }
            answer[i][j]=num;
        }
    }
    return answer;
}

#endif /* MatrixMultiplication__h */
