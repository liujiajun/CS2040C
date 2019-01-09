//
//  main.cpp
//  PS0_ProbF
//
//  Created by RoryLiu on 8/1/19.
//  Copyright © 2019 RoryLiu. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, c;
    cin>>n>>c;
    int adrs[n+1];
    for (int i=1; i<=n; i++){
        cin>>adrs[i];
    }
    for (int i = 0; i<c; i++){
        int type;
        cin>>type;
        if (type == 1){
            int no, ad;
            cin>>no>>ad;
            adrs[no] = ad;
        } else{
            int a, b;
            cin>>a>>b;
            cout<<abs(adrs[b]-adrs[a])<<endl;
        }
    }
}
