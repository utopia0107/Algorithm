//
//  JustTheSong .h
//  Algorithm
//
//  Created by 민수 정  on 15/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef JustTheSong__h
#define JustTheSong__h

#include <string>
#include <sstream>
#include <vector>
using namespace std;
//주어진 멜로디 정보의 C#,D#,F#,G#,A# 같이 #이 붙은 음표를 c,d,f,g,a로 치환하여 멜로디 정보를 반환하는 함수
string GetChangeMusic(string music)
{
    string changeMusic="";
    for(int i=0;i<music.size()-1;i++)
    {
        if(music[i+1]=='#'){
            changeMusic+=music[i]+32;
            i++;
        }else{
            changeMusic+=music[i];
        }
    }
    if(music[music.size()-1]!='#')changeMusic+=music[music.size()-1];
    return changeMusic;
}
//musicinfo의 정보를 토대로, 플레이된 음악에 기억한 멜로디가 속하는지 검사하여 ture/false를 반환하고, 속하면 musicName에 해당 음악 이름과, playTime에 라디오에서 플레이한 시간, startTime에 라디오에서 시작한 시간을 대입해준다.
bool CheckMusic(string music, vector<string> musicinfo,string* musicName,int* playTime,int* startTime)
{
    
    int startHour= atoi(musicinfo[0].substr(0,2).c_str());
    int endHour=atoi(musicinfo[1].substr(0,2).c_str());
    int startMinute= atoi(musicinfo[0].substr(3,2).c_str());
    int endMinute=atoi(musicinfo[1].substr(3,2).c_str());
    int hour=endHour-startHour;
    int minute=endMinute-startMinute+hour*60;
    *startTime=startHour*100+startMinute;
    
    musicinfo[3]=GetChangeMusic(musicinfo[3]);
    int size=  musicinfo[3].size();
    int cnt=0;
    string playMusic="";
    if(size<minute)
    {
        while(playMusic.size()+size<minute)
        {
            playMusic.append(musicinfo[3]);
        }
        if(playMusic.size()<minute)
        {
            playMusic.append(musicinfo[3].substr(0,minute-playMusic.size()));
        }
    }
    else
    {
        playMusic.append(musicinfo[3].substr(0,minute));
    }
    if(playMusic.find(music)!=std::string::npos){
        *playTime=minute;
        *musicName=musicinfo[2];
        return true;
    }
    return false;
}

string solution(string m, vector<string> musicinfos) {
    int playTime=0,maximunPlayTime=0,startTime=0,fastStartTime=0;
    string musicName="";
    string answer="(None)";
    vector<vector<string>>musicSplits;
    m=GetChangeMusic(m);
    for(int i=0;i<musicinfos.size();i++)
    {
        vector<string>result;
        istringstream iss(musicinfos[i]);
        string token;
        while (getline(iss, token,','))
        {
            result.push_back( token);
        }
        musicSplits.push_back(result);
    }
    for(int i=0;i<musicSplits.size();i++)
    {
        if(CheckMusic(m,musicSplits[i],&musicName,&playTime,&startTime))
        {
            if(playTime>maximunPlayTime)
            {
                maximunPlayTime=playTime;
                answer=musicName;
                fastStartTime=startTime;
            }
            else if(playTime==maximunPlayTime && startTime<fastStartTime)
            {
                maximunPlayTime=playTime;
                answer=musicName;
                fastStartTime=startTime;
            }
        }
    }
    
    return answer;
}
#endif /* JustTheSong__h */
