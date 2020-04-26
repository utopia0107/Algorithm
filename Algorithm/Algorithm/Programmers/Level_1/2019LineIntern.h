//
//  2019LineIntern.h
//  Algorithm
//
//  Created by 정민수 on 2020/03/28.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef _019LineIntern_h
#define _019LineIntern_h
#include <string>
#include <queue>
#include <iostream>
using namespace std;
bool checks[200000];
void solution() {
    int koni,brown;
    int answer=-1;
    queue<int> q;
    int curSize=0;
    cin>>koni>>brown;
    int level=0;
    int qSize=1;
    q.push(brown);
    checks[brown];
    while(!q.empty())
    {
        int brownPos=q.front();
        q.pop();
        qSize--;
        if(brownPos==koni)
        {
            answer=level;
            break;
        }
        if(brownPos-1>=0&&!checks[brownPos-1])
        {
            q.push(brownPos-1);
            checks[brownPos-1]=true;
        }
        if(brownPos+1<=200000&&!checks[brownPos+1])
        {
                   q.push(brownPos+1);
                   checks[brownPos+1]=true;
        }
        if(brownPos*2<=200000&&!checks[brownPos*2])
        {
                   q.push(brownPos*2);
                   checks[brownPos*2]=true;
        }
        if(qSize==0)
        {
            qSize=q.size();
            level++;
            koni+=level;
            cout<<koni<<"\n";
        }
    }
    cout<<answer;
}


#endif /* _019LineIntern_h */
