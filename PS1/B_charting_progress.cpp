 //A0177869B
//LIU JIAJUN
//LAB [10] Teh Nian Fei

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string log[100];
    string s;
    while(cin){
        int i = 0;
        while(getline(cin, s), s!=""){
            log[i] = s;
            i++;
        }
        
        string cols[100] = {""};
        for(int j = 0; j<log[0].size(); j++){
            for (int k = 0; k<i; k++){
                cols[j] += log[k][j];
            }
        }

        sort(cols, cols+ log[0].size(), greater<string>());
        
        //Print
        for (int m = 0; m<i; m++){
            for(int n = 0; n<log[0].size(); n++){
                cout<<cols[n][m];
            }
            cout<<endl;
        }
        
        cout<<endl;
    }
}
