//
//  ExpressAsN  .h
//  Algorithm
//
//  Created by 민수 정  on 06/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef ExpressAsN___h
#define ExpressAsN___h
#include <string>
#include <vector>
#include <cmath>

using namespace std;
int Number;
int GetMinNCount(int target,int num,int answer)
{
   
    if(answer>8)return 9;
    if(num==target)return answer;
    int minAnswer=9;
    int temp=0;
    int cnt=8-answer;
    for(int i=0;i<cnt;i++)
    {
        temp+=pow(10,i)*Number;
        minAnswer=min(minAnswer,GetMinNCount(target-num,temp,answer+i+1));
        minAnswer=min(minAnswer,GetMinNCount(target-num,-temp,answer+i+1));
        
        minAnswer=min(minAnswer,GetMinNCount(target,num+temp,answer+i+1));
        minAnswer=min(minAnswer,GetMinNCount(target,num*temp,answer+i+1));
        minAnswer=min(minAnswer,GetMinNCount(target,num/temp,answer+i+1));
        minAnswer=min(minAnswer,GetMinNCount(target,num-temp,answer+i+1));
    }
    return minAnswer;

}
int solution(int N, int number) {
    int answer = 10;
    int num= N*number;
    Number=N;
    int temp=0;
    for(int i=0;i<8;i++)
    {
        temp+=pow(10,i)*Number;
        answer=min(answer,GetMinNCount(number,temp,i+1));
    }
    if(answer==9)answer=-1;
    return answer;
}
#endif /* ExpressAsN___h */
