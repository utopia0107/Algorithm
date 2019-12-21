//
//  StockPrice  .h
//  Algorithm
//
//  Created by 민수 정  on 21/12/2019.
//  Copyright © 2019 Minsu Jeong. All rights reserved.
//

#ifndef StockPrice___h
#define StockPrice___h
#include <string>
#include <vector>
using namespace std;
int arr[10001];
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i=0;i<prices.size();i++){
        int cnt=0;
        for(int j=i+1;j<prices.size();j++)
        {
            if(prices[i]<=prices[j]) cnt++;
            else {
                cnt++;
                break;
            }
        }
        answer.push_back(cnt);
    }

    return answer;
}

#endif /* StockPrice___h */
