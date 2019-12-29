//
//  Joystick.h
//  Algorithm
//
//  Created by 민수 정  on 29/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef Joystick_h
#define Joystick_h
#include <string>
#include <vector>
using namespace std;

int solution(string name) {
    int answer = 0;
    vector<bool> check;
    check.resize(name.size());
    int cnt=0;
    for(int i=0;i<name.size();i++){
        if(name[i]!='A')cnt++;
         answer+=name[i]<'N'?  name[i]-'A':  'Z'-name[i]+1;
    }
    
    int start_index=0;
    if(name[start_index]!='A')cnt--;
    check[start_index]=true;
    while(cnt){
        for(int i=1;i<=name.size()/2;i++){
            int left_num=(start_index-i)>=0?start_index-i:start_index-i+name.size();
            int right_num=start_index+i>name.size()-1?name.size()-1:start_index+i;
            if(!check[right_num]&&name[right_num]!='A'){
               
            check[right_num]=true;
                answer+=i;
                cnt--;
                start_index=right_num;
                break;
            }
            else if(!check[left_num]&&name[left_num]!='A'){

                check[left_num]=true;
                answer+=i;
                cnt--;
                start_index=left_num;
                break;
            }
        }
    }
    return answer;
}

#endif /* Joystick_h */
