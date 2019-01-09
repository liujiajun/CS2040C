//
//  main.cpp
//  PS0_ProbH
//
//  Created by RoryLiu on 8/1/19.
//  Copyright © 2019 RoryLiu. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int a, b, flag=0; //a-#of clauses  b-#of vars
void check(int clauses[][3], int inputs){
    string s = to_string(inputs);
    if (s.size() == b){
        //cout<<s<<endl;
        int orflag = 0, andflag = 1;
        for (int i=0; i<a; i++){
            //cout<<i<<"  "<<clauses[i][0]<<" "<<clauses[i][1]<<" "<<clauses[i][2]<<endl;
            //cout<<i<<"  "<<s[abs(clauses[i][0])- 1]<<" "<<s[abs(clauses[i][1])- 1]<<" "<<s[abs(clauses[i][2])- 1]<<endl;
            if( (clauses[i][0] > 0 && s[abs(clauses[i][0])- 1]  == '2') || (clauses[i][0] < 0 && s[abs(clauses[i][0])- 1] =='1')) orflag=1;
            if( (clauses[i][1] > 0 && s[abs(clauses[i][1])- 1]  == '2') || (clauses[i][1] < 0 && s[abs(clauses[i][1])- 1] =='1')) orflag=1;
            if( (clauses[i][2] > 0 && s[abs(clauses[i][2])- 1]  == '2') || (clauses[i][2] < 0 && s[abs(clauses[i][2])- 1] =='1')) orflag=1;
            //cout<<orflag<<endl;
            if (orflag == 0) andflag = 0;
        }
        if (andflag == 1) flag = 1;
    }else{
        check(clauses, inputs*10+1);
        check(clauses, inputs*10+2);
    }
}

int main(){
    cin>>a>>b;
    if (a<8){cout<<"unsatisfactory"; return 0;}
    else{cout<<"satisfactory"; return 0;}
    int clauses[a][3];
    for(int i =0; i<a; i++){
        cin>>clauses[i][0]>>clauses[i][1]>>clauses[i][2];
    }
    check(clauses, 0);
    if(flag == 0) cout<<"unsatisfactory";
    else cout<<"satisfactory";
}

