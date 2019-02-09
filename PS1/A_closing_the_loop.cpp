//A0177869B
//LIU JIAJUN
//LAB [10] Teh Nian Fei

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    for (int i=0; i<n; i++){
        int s; cin>>s;
        vector<int> red, blue;
        for (int j = 0; j<s; j++){
            int a; char b;
            cin>>a>>b;
            if (b == 'B') blue.push_back(a);
            else red.push_back(a);
        }
        sort(red.begin(), red.end(), greater<int>());
        sort(blue.begin(), blue.end(), greater<int>());
        int m=0, length = 0;
        while(m<red.size() && m<blue.size()){
            length += red[m] + blue[m] - 2;
            m++;
        }
        cout<<"Case #"<<i+1<<": "<<length<<endl;
    }
}
