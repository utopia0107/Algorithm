//
//   CorrectParenthesis.h
//  Algorithm
//
//  Created by 민수 정  on 09/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _CorrectParenthesis_h
#define _CorrectParenthesis_h
#include <string>
#include <vector>
using namespace std;

int GetUprightBracketCnt(int barcketCnt,string str,int openCnt,int closeCnt)
{
    if(openCnt<closeCnt)return 0;
    if(openCnt>barcketCnt)return 0;
    if(openCnt==closeCnt&&barcketCnt*2==openCnt+closeCnt)
    {
        return 1;
    }
    return GetUprightBracketCnt(barcketCnt,str+"(",openCnt+1,closeCnt)+GetUprightBracketCnt(barcketCnt,str+")",openCnt,closeCnt+1);
}
int solution(int n) {
   
    int answer = GetUprightBracketCnt(n,"",0,0);
    return answer;
}

#endif /* _CorrectParenthesis_h */
