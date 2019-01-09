//
//  main.cpp
//  PS0_ProbD
//
//  Created by RoryLiu on 8/1/19.
//  Copyright © 2019 RoryLiu. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(int i =0; i<n; i++){
        unsigned int k, b, s, res=0;
        cin>>k>>b>>s;
        while(s!=0){
            int r = s%b;
            s /= b;
            res = res + r*r;
        }
        cout<<k<<" "<<res<<endl;
    }
}
