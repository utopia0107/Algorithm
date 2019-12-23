//
//  BestAlbum.h
//  Algorithm
//
//  Created by 민수 정  on 23/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef BestAlbum_h
#define BestAlbum_h
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    //key= 음악 장르, value = play와 index를 저장하는 벡터
    map<string,vector<pair<int,int>>> m;
    int size=genres.size();
    
    //음악 장르별로 맵에 (플레이시간,고유 번호)로 저장
    for(int i=0;i<size;i++)
    {
        if(m.find(genres[i])==m.end())
        {
            vector<pair<int,int>>v;
            m.insert(make_pair(genres[i],v));
        }
        //size-i를 하는 이유는 뒤에서 내림 차순 정렬로 한번에 정렬하기 위해서
        m[genres[i]].push_back(make_pair(plays[i],size-i));
    }
    
    map<string,vector<pair<int,int>>> ::iterator iter;
    //장르별로 플레이수, 고유번호 순으로 정렬을한다.
    for(iter=m.begin();iter!=m.end();iter++)
    {
        vector<pair<int,int>> *temp= &(iter->second);
        sort(temp->begin(),temp->end(),greater<pair<int,int>>());
    }
    
    vector<pair<int,string>> totalMusicPlays;
    
    //map을 순회하면서 음악 장르별 총 플레이 수를 구한다.
    for(iter=m.begin();iter!=m.end();iter++)
    {
        vector<pair<int,int>> musicPlays=iter->second;
        int total=0;
        for(int i=0;i<musicPlays.size();i++)
        {
            total+=musicPlays[i].first;
        }
        totalMusicPlays.push_back(make_pair(total,iter->first));
    }
    //음악장르별 총 플레이수를 기준으로 내림차순 정렬한다.
    sort(totalMusicPlays.begin(),totalMusicPlays.end(),greater<pair<int,string>>());
    
    for(int i=0;i<totalMusicPlays.size();i++)
    {
        string name=totalMusicPlays[i].second;
        for(int j=0;j<2&&j<m[name].size();j++)
        {
            //정렬를 위해 바꾼 고유 번호를 원래의 고유 번호로 변환하여 정답에 추가한다.
            answer.push_back(size-m[name][j].second);
        }
    }
    return answer;
}

#endif /* BestAlbum_h */
