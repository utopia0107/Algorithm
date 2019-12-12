//
//  MaximumMinimum.h
//  Algorithm
//
//  Created by 민수 정  on 12/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef MaximumMinimum_h
#define MaximumMinimum_h
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    istringstream iss(s);
    string token;
    vector<int> v;
    while (getline(iss, token, ' '))
    {
        v.push_back( atoi(token.c_str()));
    }
    sort(v.begin(),v.end());
    answer=to_string(v[0])+" "+ to_string(v[v.size()-1]);
    return answer;
}

#endif /* MaximumMinimum_h */
