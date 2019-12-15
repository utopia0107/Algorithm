//
//  FileNameSort.h
//  Algorithm
//
//  Created by 민수 정  on 15/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef FileNameSort_h
#define FileNameSort_h

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void GetHeadNumber(string file,string* head,int* number)
{
    int fileNameSize=file.size();
    string tempHead="";
    string tempNumber="";
    bool bheadEnd=false;
    for(int i=0;i<fileNameSize;i++)
    {
        if(file[i]>='0'&&file[i]<='9')
        {
            bheadEnd=true;
            tempNumber+=file[i];
        }
        else if(!bheadEnd)
        {
             tempHead+=file[i];
        }
        else
        {
            break;
        }
    }
    transform(tempHead.begin(), tempHead.end(),  tempHead.begin(), ::tolower);
    *head=tempHead;
    *number=atoi(tempNumber.c_str());
}
struct FileInfo
{
    string head;
    string fileName;
    int number,inputNumber;
};
bool cmp(const FileInfo &f1, const FileInfo &f2){
    if(f1.head==f2.head)
    {
        if(f1.number==f2.number)
        {
            return f1.inputNumber<f2.inputNumber;
        }else{
            return f1.number<f2.number;
        }
    }else
    {
        return f1.head<f2.head;
    }
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    //head,number,input number,fileName
    vector<FileInfo> fileInfos;
    int fileCnt=files.size();
    int number;
    string head;
    FileInfo fileInfo;
    for(int i=0;i<fileCnt;i++)
    {
        GetHeadNumber(files[i],&head,&number);
        fileInfo.head=head;
        fileInfo.number=number;
         fileInfo.fileName=files[i];
        fileInfo.inputNumber=i;
        fileInfos.push_back(fileInfo);
    }
    sort(fileInfos.begin(),fileInfos.end(),cmp);
    for(int i=0;i<fileInfos.size();i++)
    {
        answer.push_back(fileInfos[i].fileName);
    }
    return answer;
}
#endif /* FileNameSort_h */
