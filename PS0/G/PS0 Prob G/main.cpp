//
//  main.cpp
//  PS0 Prob G
//
//  Created by RoryLiu on 8/1/19.
//  Copyright © 2019 RoryLiu. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;
int main(int argc, const char * argv[]) {
    set<int> myset;
    int n,b;
    cin>>n>>b;
    for(int i=0; i<b; i++){
        int a;
        cin>>a;
        myset.insert(a);
    }
    for(int i=0; i<n; i++){
        if (myset.find(i) == myset.end()) cout<<i<<endl;
    }
    cout<<"Mario got "<<myset.size()<<" of the dangerous obstacles.";
}
