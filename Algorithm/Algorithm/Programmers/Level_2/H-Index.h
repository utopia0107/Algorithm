//
//  H-Index.h
//  Algorithm
//
//  Created by 민수 정  on 13/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef H_Index_h
#define H_Index_h
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int size=citations.size();
    sort(citations.begin(),citations.end());
    int Hindex=size;
    while(true)
    {
        int hightCnt=0;
        for(int i=0;i<size;i++)
        {
            if(Hindex<=citations[i])hightCnt++;
        }
        if(Hindex<=hightCnt
          &&Hindex>=size-hightCnt)
        {
            break;
        }
        Hindex--;
    }
    answer=Hindex;
    return answer;
}

#endif /* H_Index_h */
