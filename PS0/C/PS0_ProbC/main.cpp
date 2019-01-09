//
//  main.cpp
//  PS0_ProbC
//
//  Created by RoryLiu on 8/1/19.
//  Copyright © 2019 RoryLiu. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int N;
        cin>>N;
        int ld = 1;
        for(int j = 2; j<=N; j++){
            ld = (j * ld)%10;
        }
        cout<<ld<<endl;
    }
    return 0;
}
