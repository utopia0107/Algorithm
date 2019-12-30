//
//  SecretMap .h
//  Algorithm
//
//  Created by 민수 정  on 30/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef SecretMap__h
#define SecretMap__h
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ChangeBinary(int num, int length)
{
    vector<int> v;
    while(num!=0)
    {
        v.push_back(num%2);
        num/=2;
    }
    for(int i=v.size();i<length;i++)
    {
        v.push_back(0);
    }
    reverse(v.begin(),v.end());
    return v;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<int>> map1,map2;
    for(int i=0;i<arr1.size();i++)
    {
        map1.push_back(ChangeBinary(arr1[i],n));
    }
    for(int i=0;i<arr2.size();i++)
    {
        map2.push_back(ChangeBinary(arr2[i],n));
    }
    for(int i=0;i<n;i++)
    {
        string str="";
        for(int j=0;j<n;j++)
        {
            if(map1[i][j]==1||map2[i][j]==1)
            {
                str+="#";
            }else{
                str+=" ";
            }
        }
        answer.push_back(str);
    }
    return answer;
}

#endif /* SecretMap__h */
