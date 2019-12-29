//
//  PhoneNumberList .h
//  Algorithm
//
//  Created by 민수 정  on 29/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef PhoneNumberList__h
#define PhoneNumberList__h
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool cmp(const string &p1, const string &p2){
    if(p1.size() < p2.size()){
        return true;
    }
    else if(p1.size() == p2.size()){
        for(int i=0;i<p1.size();i++){
            if(p1[i]!=p2[i]){
                return p1[i]<p2[i];
            }
        }
        return false;
    }
    else{
        return false;
    }
}
bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string,bool> Map;
    //first true exist
    //second true end
    sort(phone_book.begin(),phone_book.end());
    
    for(int i=0;i<phone_book.size();i++){
        string num_str=phone_book[i];
        for(int j=1;j<=num_str.length();j++){
          if(Map[num_str.substr(0,j)]){
              return false;
          }
        }
        Map[num_str]=true;
    }
    return answer;
}

#endif /* PhoneNumberList__h */
