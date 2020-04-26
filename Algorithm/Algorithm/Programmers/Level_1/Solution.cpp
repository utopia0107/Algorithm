//
//  Solution.cpp
//  Algorithm
//
//  Created by 정민수 on 19/03/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#include "Solution.h"

vector<int>Solution:: twoSum(vector<int>& nums, int target)
{
    int length=(int)nums.size();
    vector<int> answer;

    for(int i=0;i<length-1;i++)
    {
        for(int j=i+1;j<length;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
    }
    return answer;
}
vector<int>Solution:: plusOne(vector<int>& digits)
{
    vector<int> soultion;
    bool isCarry=true;
    for(int i=(int)digits.size()-1;i>=0;i--)
    {
        if(isCarry)
        {
            isCarry=1+digits[i]==10;
            soultion.push_back((1+digits[i])%10);
        }
        else
        {
            soultion.push_back(digits[i]);
        }
    }
    if(isCarry)soultion.push_back(1);
    reverse(soultion.begin(), soultion.end());
    return soultion;
}
string Solution:: reverseVowels(string s)
{
    char vowels[]={'A','E','I','O','U','a','e','i','o','u'};
    stack<char> vowel_s;
    int s_length=s.size();
    int vowels_length=sizeof(vowels)/sizeof(char);
    for(int i=0;i<s_length;i++)
    {
        for(int j=0;j<vowels_length;j++)
        {
            if(s[i]==vowels[j])
            {
                vowel_s.push(s[i]);
                break;
            }
        }
    }
    for(int i=0;i<s_length;i++)
    {
        for(int j=0;j<vowels_length;j++)
        {
            if(s[i]==vowels[j])
            {
                s[i]=vowel_s.top();
                vowel_s.pop();
                break;
            }
        }
    }
    return s;
    
}

