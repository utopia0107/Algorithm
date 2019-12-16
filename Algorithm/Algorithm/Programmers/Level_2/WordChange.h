//
//  WordChange.h
//  Algorithm
//
//  Created by 민수 정  on 16/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef WordChange_h
#define WordChange_h

#include <string>
#include <vector>
#include<queue>

using namespace std;
bool bvisisted[51];
int BFS(vector<vector<int>> tree, vector<string> words,string target)
{
    queue<int> q;
    q.push(0);
    int treeHight=1;
    int curQueuSize=1;
    int popCnt=0;
    while(!q.empty())
    {
        int curIndex=q.front();
        q.pop();
        popCnt++;

        for(int i=0;i<tree[curIndex].size();i++)
        {
            int nextIndex=tree[curIndex][i];
            if(!bvisisted[nextIndex])
            {
                if(words[nextIndex].compare(target)==0)
                {
                    return treeHight;
                }
                q.push(nextIndex);
                bvisisted[nextIndex]=true;
            }
        }
        if(curQueuSize==popCnt)
        {
            curQueuSize=q.size();
            treeHight++;
            popCnt=0;
        }
    }
    return 0;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    words.insert(words.begin(),begin);
    int wordSize=words.size();
    int wordLength= begin.size();
    vector<vector<int>> tree;
    //인접 리스트 생성
    for(int i=0;i<wordSize;i++)
    {
        vector<int>v;
        for(int j=0;j<wordSize;j++)
        {
            if(i!=j)
            {
                int sameCnt=0;
                for(int k=0;k<wordLength;k++)
                {
                    if(words[i][k]==words[j][k])sameCnt++;
                }
                if(wordLength-sameCnt==1)
                {
                    v.push_back(j);
                }
            }
        }
        tree.push_back(v);
    }
    answer= BFS(tree, words, target);
    return answer;
}
#endif /* WordChange_h */
