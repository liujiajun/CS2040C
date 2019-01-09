//
//  main.cpp
//  PS0_ProbA
//
//  Created by RoryLiu on 8/1/19.
//  Copyright © 2019 RoryLiu. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <valarray>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    long long junk[n];
    long long min = 2000000000;
    int p =0;
    for(int i=0; i<n; i++){
        cin>>junk[i];
        if (junk[i] < min){
            min = junk[i];
            p = i;
        }
    }
    cout<<p;
    return 0;
}
