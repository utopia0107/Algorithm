//
//  Phonketmon.h
//  Algorithm
//
//  Created by 민수 정  on 12/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef Phonketmon_h
#define Phonketmon_h

using namespace std;
int GetCount(int n)
{
    int cnt=0;
    while(n>0){
        if(n%2==1)cnt++;
        n/=2;
    }
    return cnt;
}
int solution(int n) {
    int answer = 0;
    int cnt=GetCount(n);
    while(cnt!=GetCount(++n)){
        
    }
    answer=n;
    return answer;
}


#endif /* Phonketmon_h */
