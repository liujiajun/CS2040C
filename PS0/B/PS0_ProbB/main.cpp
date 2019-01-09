//
//  main.cpp
//  PS0_ProbB
//
//  Created by RoryLiu on 8/1/19.
//  Copyright © 2019 RoryLiu. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for (int i =0; i<n; i++){
        double b;
        double p;
        cin>>b>>p;
        cout<<fixed<<setprecision(4)<<60.0/(p/(b-1))<<" ";
        cout<<fixed<<setprecision(4)<<60*b/p<<" ";
        cout<<fixed<<setprecision(4)<<60.0/(p/(b+1))<<endl;
    }
    return 0;
}
