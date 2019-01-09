//
//  main.cpp
//  PS0_ProbI
//
//  Created by RoryLiu on 8/1/19.
//  Copyright © 2019 RoryLiu. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a;
    int y = 2016, m = 2;
    cin>>a;
    int i =0;
    while(y<=a){
        if (y == a){
            cout<<"yes";
            return 0;
        }
        if (i==5){
            y +=3;
        }else{
            y +=2;
        }
        i = (i+1) % 6;
        //cout<<i<<y<<endl;
    }
    cout<<"no";
}
