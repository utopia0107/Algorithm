//
//  Friends4Blocks.h
//  Algorithm
//
//  Created by 민수 정  on 13/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef Friends4Blocks_h
#define Friends4Blocks_h
#include <string>
#include <vector>
#include<cstring>
#include <stack>
using namespace std;
bool checkBoard[30][30];

void DownBoard(int m, int n, vector<string> *board )
{
         for(int i=0;i<n;i++)
         {
            stack<char> v;
              for(int j=0;j<m;j++)
              {
                  if((*board)[j][i]!=' ')
                  {
                      v.push((*board)[j][i]);
                      (*board)[j][i]=' ';
                  }
              }
            int size=m-v.size();
            for(int j=m-1;j>=size;j--)
            {
                (*board)[j][i]=v.top();
                v.pop();
            }
        }
}

int GetEraserCount(int m, int n, vector<string>* board )
{
    vector<pair<int,int>> eraser;
    for(int i=0;i<m;i++)
    {
        memset(checkBoard[i],false,n);
    }
    
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if((*board)[i][j]!=' '&&!checkBoard[i][j])
            {
                if((*board)[i][j]==(*board)[i][j-1]
                    &&(*board)[i][j]==(*board)[i-1][j]
                    &&(*board)[i][j]==(*board)[i-1][j-1])
                {
                    if(!checkBoard[i][j])
                    {
                        checkBoard[i][j]=true;
                        eraser.push_back(make_pair(i,j));
                    }
                    if(!checkBoard[i][j-1])
                    {
                        checkBoard[i][j-1]=true;
                        eraser.push_back(make_pair(i,j-1));
                    }
                    if(!checkBoard[i-1][j])
                    {
                        checkBoard[i-1][j]=true;
                        eraser.push_back(make_pair(i-1,j));
                    }
                    if(!checkBoard[i-1][j-1])
                    {
                        checkBoard[i-1][j-1]=true;
                        eraser.push_back(make_pair(i-1,j-1));
                    }
                }
                    
            }
        }
    }
    
    for(int i=0;i<eraser.size();i++)
    {
        (*board)[eraser[i].first][eraser[i].second]=' ';
    }
    DownBoard(m,n,board);
    return eraser.size();
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int num=0;
    do{
        num=GetEraserCount(m,n,&board);
        answer+=num;
    }while(num!=0);

    return answer;
}

#endif /* Friends4Blocks_h */
