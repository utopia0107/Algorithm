//
//  FindLargestRectangle .h
//  Algorithm
//
//  Created by 정민수 on 15/03/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef FindLargestRectangle__h
#define FindLargestRectangle__h
#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int W=board[0].size(),H=board.size();
    vector<vector<pair<int,int>>> maps;
    for(int i=0;i<H;i++)
    {
        int startIndex=-1;
        int endIndex=W-1;
        vector<pair<int,int>> v;
        for(int j=0;j<W;j++)
        {
            if(board[i][j]==1)
            {
                 if(startIndex==-1)startIndex=j;
            }else if(startIndex!=-1){
                v.push_back(make_pair(startIndex,j-1));
                startIndex=-1;
            }
        }
        if(startIndex!=-1)
        {
             v.push_back(make_pair(startIndex,endIndex));
        }
        maps.push_back(v);
    }
    
    for(int i=0;i<H;i++)
    {
         int cnt=min(W,H-i);
        for(int j=0;j<maps[i].size();j++)
        {
            pair<int,int>standard=maps[i][j];
            while(cnt>answer)
            {
                if(standard.second-standard.first+1>=cnt)
                {
                        for(int z=standard.first;z<=standard.second-cnt+1;z++)
                        {
                            int sameCnt=1;
                            pair<int,int>temp=standard;
                            temp.first=z;
                            temp.second=standard.first+cnt-1;
                            for(int k=i+1;k<i+cnt&&k<H;k++)
                            {
                               int tempCnt=sameCnt;
                               for(int l=0;l<maps[k].size();l++)
                               {
                                   if(maps[k][l].first<=temp.first
                                     &&maps[k][l].second>=temp.second)
                                   {
                                       sameCnt++;
                                       break;
                                   }
                               }
                               if(sameCnt==tempCnt)break;
                            }
                            if(sameCnt==cnt)
                            {
                                answer=sameCnt;
                            }
                        }
                }
                cnt--;
            }
        }
    }

    answer*=answer;
    return answer;
}

#endif /* FindLargestRectangle__h */
