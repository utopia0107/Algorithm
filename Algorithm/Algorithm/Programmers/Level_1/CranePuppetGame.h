//
//  CranePuppetGame.h
//  Algorithm
//
//  Created by 정민수 on 2020/04/26.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef CranePuppetGame_h
#define CranePuppetGame_h
#include <string>
#include <vector>
#include<stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int H=board.size(),W=board[0].size();
    
    stack<int> s;
    for(int i=0;i<moves.size();i++)
    {
        int index=moves[i]-1;
        for(int j=0;j<H;j++)
        {
            int num=board[j][index];
            if(num!=0)
            {
                if(!s.empty()
                   &&s.top()==num)
                {
                    answer++;
                    s.pop();
                }
                else
                {
                    s.push(num);
                }
                board[j][index]=0;
                break;
            }
        }
    }
    
    return answer*2;
}
#endif /* CranePuppetGame_h */
