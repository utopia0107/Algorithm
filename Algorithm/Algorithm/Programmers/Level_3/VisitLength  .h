//
//  VisitLength  .h
//  Algorithm
//
//  Created by 민수 정  on 24/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef VisitLength___h
#define VisitLength___h
#include <string>
#include <set>
#include  <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int maxNum=5;
    set<pair<pair<int,int>,pair<int,int>>>s;
    int x=0,y=0;
    s.insert(make_pair(make_pair(1,9),make_pair(2,3)));
    for(int i=0;i<dirs.size();i++)
    {
        pair<int,int> startPos,endPos;
        startPos.first=y;
        startPos.second=x;
        switch(dirs[i])
        {
            case 'U':
                if(y<maxNum)
                {
                    y+=1;
                }
                break;
            case 'D':
                if(y>-maxNum)
                {
                    y-=1;
                }
                break;
            case 'R':
                if(x<maxNum)
                {
                    x+=1;
                }
                break;
            case 'L':
                if(x>-maxNum)
                {
                    x-=1;
                }
                break;
        }
        if(startPos.first!=y||startPos.second!=x)
        {
            endPos.first=y;
            endPos.second=x;
            s.insert(make_pair(startPos,endPos));
            s.insert(make_pair(endPos,startPos));
        }
    }

    answer=s.size()/2;
    return answer;
}

#endif /* VisitLength___h */
