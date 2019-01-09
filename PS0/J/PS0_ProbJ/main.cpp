//
//  main.cpp
//  PS0_ProbJ
//
//  Created by RoryLiu on 8/1/19.
//  Copyright © 2019 RoryLiu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    int ram[1000] ={0};
    int registers[10]={0};
    int i = 0, count = 0, stop = 0;
    while(cin>>ram[i]) i++;
    i = 0;
    while(1){
        //cout<<count<<" "<<ram[i]<<endl;
        //for (int q = 0; q<15; q++) cout<<ram[q]<<",";
        //cout<<endl;
        //for(int q = 0; q<10; q++) cout<<registers[q]<<",";
        //cout<<endl;
        if (stop == 1) break;
        count++;
        int x,y,z, tmp;
        tmp = ram[i];
        z = tmp % 10; tmp/=10;
        y = tmp % 10; tmp/=10;
        x = tmp % 10;
        switch (x) {
            case 0:
                int a,b,c, t;
                t = registers[z];
                c = t % 10; t/=10;
                b = t % 10; t/=10;
                a = t % 10;
                if (registers[z] != 0){
                    i=registers[y];
                    //cout<<"hhhhh"<<endl;
                    continue;
                    
                }
                break;
            case 1:
                stop = 1;
                break;
            case 2:
                registers[y] = z;
                break;
            case 3:
                registers[y] = (registers[y] + z) % 1000;
                break;
            case 4:
                registers[y] = (registers[y] * z) % 1000;
                break;
            case 5:
                registers[y] = registers[z];
                break;
            case 6:
                registers[y] = (registers[y] + registers[z]) % 1000;
                break;
            case 7:
                registers[y] = (registers[y] * registers[z]) % 1000;
                break;
            case 8:
                registers[y] = ram[registers[z]];
                break;
            case 9:
                ram[registers[z]] = registers[y];
                break;
            default:
                break;
        }
        i++;
    }
    cout<<count;
}
