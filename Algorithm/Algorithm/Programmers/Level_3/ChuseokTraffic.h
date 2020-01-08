//
//  ChuseokTraffic.h
//  Algorithm
//
//  Created by 민수 정  on 08/01/2020.
//  Copyright © 2020 Minsu Jeong. All rights reserved.
//

#ifndef ChuseokTraffic_h
#define ChuseokTraffic_h
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> Split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }

    return internal;
}
struct Time
{
    int hour,minute;
    float second;
    Time(int h,int m,float s):hour(h),minute(m),second(s){}
  
};
int CompareTo(Time A,Time B)
{
    //A가 더 클때,
    if((A.hour==B.hour
             &&A.minute==B.minute
             &&A.second>B.second)
             ||(A.hour>B.hour)
             ||(A.hour==B.hour&&A.minute>B.minute))
    {
        return 1;
    }
    //B가 더 클때
    if((B.hour==A.hour&&B.minute==A.minute &&B.second>A.second)
             ||(B.hour>A.hour)
             ||(B.hour==A.hour&&B.minute>A.minute))
    {
        return -1;
    }
    //같을때
    return 0;
}
int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<Time,Time>> v;
    for(int i=0;i<lines.size();i++)
    {
        vector<string> splits=Split(lines[i],' ');
        vector<string> times=Split(splits[1],':');
        float workTime= stof(splits[2].substr(0,splits[2].size()-1));
        int hour,minute;
        float second;
        hour=stoi(times[0]);
        minute=stoi(times[1]);
        second=stof(times[2]);
        Time end(hour,minute,second);
        second+=0.001f;
        if(second<=workTime)
        {
            second=second+60.0f-workTime;
            if(minute==0)
            {
                hour--;
                minute=59;
            }else{
                minute--;
            }
        }else{
            second-=workTime;
        }
        Time start(hour,minute,second);
        v.push_back(make_pair(start,end));
    }
     for(int i=0;i<v.size();i++)
    {
        Time start=v[i].first;
        Time end=v[i].second;
     }
    for(int i=0;i<v.size();i++)
    {
        Time standardStart=v[i].second;
        Time standardEnd=v[i].second;
        standardEnd.second=  standardEnd.second-0.001f+1.0f;
        if(standardEnd.second>=60.0f)
        {
            standardEnd.second-=60.0f;
            standardEnd.minute++;
            if(standardEnd.minute>=60)
            {
                standardEnd.minute=0;
                standardEnd.hour++;
            }
        }
        int cnt=1;
        for(int j=i+1;j<v.size();j++)
        {
            Time start=v[j].first;
            Time end=v[j].second;
            if(!(CompareTo(start,standardStart)==-1&&CompareTo(end,standardStart)==-1
              ||CompareTo(standardEnd,start)==-1&&CompareTo(standardEnd,end)==-1))
            {
               
                cnt++;
            }
        }
        answer=max(answer,cnt);
    }
    return answer;
}

#endif /* ChuseokTraffic_h */
