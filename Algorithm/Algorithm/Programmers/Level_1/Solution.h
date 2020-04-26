//
//  Solution.hpp
//  Algorithm
//
//  Created by 정민수 on 19/03/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp
#include <stdio.h>
#include <stack>
#include<vector>
#include <string>
#include<algorithm>
using namespace std;
class Solution {
//private:
//   const char vowels[]={'A','E','I','O','U','a','e','i','o','u'};
public:
    string reverseVowels(string s);
    vector<int> plusOne(vector<int>& digits);
    vector<int> twoSum(vector<int>& nums, int target);
};
#endif /* Solution_hpp */
