//
//  SkillTree.h
//  Algorithm
//
//  Created by 민수 정  on 04/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef SkillTree_h
#define SkillTree_h
#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0;i<skill_trees.size();i++){
        string str="";
        for(int j=0;j<skill_trees[i].size();j++){
            for(int k=0;k<skill.size();k++){
                if(skill_trees[i][j]==skill[k]){
                    str+=skill[k];
                }
            }
        }
        if(skill.compare(0,str.size(),str)==0||str.size()==0)answer++;
    }
    return answer;
}

#endif /* SkillTree_h */
