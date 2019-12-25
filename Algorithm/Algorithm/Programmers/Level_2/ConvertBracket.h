//
//  ConvertBracket.h
//  Algorithm
//
//  Created by 민수 정  on 25/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef ConvertBracket_h
#define ConvertBracket_h
#include <string>
#include <vector>
#include <iostream>
using namespace std;
pair<string,string> Separation(string p)
{
    int num=0;
    int index;
    
    for(int i=0;i<p.size();i++)
    {
         switch(p[i])
        {
            case '(':
                num++;
                break;
            case ')':
                num--;
                break;
        }
        if(num==0)
        {
            index=i;
            break;
        }
    }
    index++;
    return make_pair(p.substr(0,index),p.substr(index,p.size()-index));
}
bool PerfectCheck(string p){
    int num=0;
        int check=true;

    for(int i=0;i<p.size();i++){
        switch(p[i])
        {
            case '(':
                num++;
                break;
            case ')':
                num--;
                break;
        }
        if(num<0)check=false;
    }
    return check;
}

string Bracket(string p){
    int num=0;
    //빈 문자열.
    if(p.size()==0)return p;
    //이미 올바른 문자열
    if(PerfectCheck(p)) return p;
    pair<string,string> str=Separation(p);
    cout<<str.first<<","<<str.second<<"\n";
    if(PerfectCheck(str.first)){
        return str.first+Bracket(str.second);
    }
    else{
        string temp="(";
        temp+=Bracket(str.second);
        temp+=")";
        for(int i=1;i<str.first.size()-1;i++){
            temp+=str.first[i]=='('?")":"(";
        }
        return temp;
    }
}
string solution(string p) {
    string answer = "";
    return Bracket(p);
}

#endif /* ConvertBracket_h */
