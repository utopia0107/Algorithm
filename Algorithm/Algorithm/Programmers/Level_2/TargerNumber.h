//
//  TargerNumber.h
//  Algorithm
//
//  Created by 민수 정  on 10/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef TargerNumber_h
#define TargerNumber_h
#include <string>
#include <vector>

using namespace std;

int DFS(int total,int index,int target,vector<int> numbers){
    if(index==numbers.size()){
        if(total==target)return 1;
        else return 0;
    }
   return DFS(total+numbers[index],index+1,target,numbers)
        +DFS(total-numbers[index],index+1,target,numbers);
    
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer=DFS(0,0,target,numbers);
    return answer;
}

#endif /* TargerNumber_h */
