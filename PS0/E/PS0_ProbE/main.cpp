//
//  main.cpp
//  PS0_ProbE
//
//  Created by RoryLiu on 8/1/19.
//  Copyright © 2019 RoryLiu. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a;
    cin>>a;
    while(true){
        int temp = a, r, sum = 0;
        while(temp != 0){
            r = temp%10;
            temp /= 10;
            sum += r;
        }
        if (a % sum == 0) {cout<<a; return 0;}
        a++;
    }
}
