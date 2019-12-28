//
//  MoveBlock .h
//  Algorithm
//
//  Created by 민수 정  on 28/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef MoveBlock__h
#define MoveBlock__h
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool visited[101][101][101][101];
//최단 시간 탐색은 BFS
int solution(vector<vector<int>> board) {
    int answer = 0;
    long long standardCnt=0;
    const int SIZE=board.size();
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push(make_pair(make_pair(0,0),make_pair(0,1)));
    standardCnt=1;
    while(!q.empty())
    {
        pair<int,int>tail=q.front().first,head=q.front().second;
        standardCnt--;
        q.pop();
        
        if((tail.first==tail.second&&tail.second+1==SIZE)
          ||(head.first==head.second&&head.second+1==SIZE))
        {
            return answer;
        }
        
        if(!visited[tail.first][tail.second][head.first][head.second]
           &&!visited[head.first][head.second][tail.first][tail.second]
          )
        {
            visited[tail.first][tail.second][head.first][head.second]=true;
            visited[head.first][head.second][tail.first][tail.second]=true;
            
            //가로모드
            if(tail.first==head.first&&tail.second+1==head.second)
            {
                //아래가 두곳다 비어있을때.
                if(tail.first+1<SIZE
                   &&board[tail.first+1][tail.second]==0
                   &&board[head.first+1][head.second]==0)
                {
                    //회전 head기준으로 반시계방향으로 회전
                    q.push(make_pair(head,make_pair(head.first+1,head.second)));
                    //회전 tail기준으로 시계방향으로 회전
                    q.push(make_pair(tail,make_pair(tail.first+1,tail.second)));
                    //아래로 이동
                    q.push(make_pair(make_pair(tail.first+1,tail.second),make_pair(head.first+1,head.second)));
                }
                //우측
                if(head.second+1<SIZE
                   &&board[head.first][head.second+1]==0)
                {
                    q.push(make_pair(head,make_pair(head.first,head.second+1)));
                    
                }
                //좌축
                if(tail.second-1>=0
                   &&board[tail.first][tail.second-1]==0)
                {
                    q.push(make_pair(make_pair(tail.first,tail.second-1),tail));
                    
                }
                //위쪽 두개가 비었을때
                if(tail.first-1>=0
                   &&board[tail.first-1][tail.second]==0
                   &&board[head.first-1][head.second]==0)
                {
                    //회전 head기준으로 시계방향으로 회전
                    q.push(make_pair(make_pair(head.first-1,head.second),head));
                    //회전 tail기준으로 반시계방향으로 회전
                    q.push(make_pair(make_pair(tail.first-1,tail.second),tail));
                    //위쪽으로 이동
                    q.push(make_pair(make_pair(tail.first-1,tail.second),make_pair(head.first-1,head.second)));
                }
            }//세로 모드
            else if(tail.second==head.second&&tail.first+1==head.first)
            {
                 //아래
                if(head.first+1<SIZE
                   &&board[head.first+1][head.second]==0)
                {
                    //아래
                    q.push(make_pair(head,make_pair(head.first+1,head.second)));
                }
                //위
                if(tail.first-1>=0
                   &&board[tail.first-1][tail.second]==0)
                {
                    //위
                    q.push(make_pair(make_pair(tail.first-1,tail.second),tail));
                }
                //우측이 비었을때
                if(tail.second+1<SIZE
                   &&board[tail.first][tail.second+1]==0
                   &&board[head.first][head.second+1]==0)
                {
                    //우측
                    q.push(make_pair(make_pair(tail.first,tail.second+1),make_pair(head.first,head.second+1)));
                    //회전 head기준으로 시계방향으로 회전
                    q.push(make_pair(head,make_pair(head.first,head.second+1)));
                    //회전 tail기준으로 반시계방향으로 회전
                    q.push(make_pair(tail,make_pair(tail.first,tail.second+1)));

                }
                //좌측이 비었을때
                if(tail.second-1>=0
                   &&board[tail.first][tail.second-1]==0
                   &&board[head.first][head.second-1]==0)
                {
                    //좌측
                    q.push(make_pair(make_pair(tail.first,tail.second-1),make_pair(head.first,head.second-1)));
                    //회전 head기준으로 반시계방향으로 회전
                    q.push(make_pair(make_pair(head.first,head.second-1),head));
                    //회전 tail기준으로 시계방향으로 회전
                    q.push(make_pair(make_pair(tail.first,tail.second-1),tail));
                }
            }
        }
        if(standardCnt<=0)
        {
            standardCnt=q.size();
            answer++;
        }
    }
    return answer;
}

#endif /* MoveBlock__h */
