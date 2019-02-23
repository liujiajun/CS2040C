#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
struct Car{
    int start, index;
};
int n, t, m, curt=0, curs =0;
map<int, int> res;

void l2r(queue<Car> &left, queue<Car> &right){
    if (curs == 1) { 
        //cout<<"r2l "<<curt<<endl; 
        curt+=t; curs=0;}
    int i=0, ti=left.front().start;
    //cout<<"l2r "<<curt<<endl;
    curt += t;
    while(i<n && !left.empty() && left.front().start <=curt-t){
        //cout<<"go"<<endl;
        //left.front().arrival = curt;
        res[left.front().index] = curt;
        left.pop();
        i++;
    }
    curs = 1;
}
void r2l(queue<Car> &left, queue<Car> &right){
    if (curs == 0) { 
        //cout<<"l2r "<<curt<<endl; 
        curt+=t; curs=1;}
    int i=0, ti=right.front().start;
    //cout<<"r2l "<<curt<<endl;
    curt += t;
    while(i<n && !right.empty() && right.front().start <=curt-t){
        //cout<<"go"<<endl;
        //left.front().arrival = curt;
        res[right.front().index] = curt;
        right.pop();
        i++;
    }
    curs = 0;
}
int main(){
    int N;
    cin>>N;
    while(N--){
        cin>>n>>t>>m; 
        queue<Car> left, right;
        int mymin=99999999;   
        for (int i=0; i<m; i++){
            int t; string s; cin>>t>>s;
            mymin = min(mymin, t);
            Car car; car.start=t; car.index = i;
            if (s == "left") left.push(car);
            else right.push(car);     
        }
        curt = mymin;
        while(!left.empty() && !right.empty()){
            if(curs == 0){
                if (left.front().start <= curt){
                    l2r(left, right);
                }else if(right.front().start<= curt){
                    r2l(left, right);
                }else if(right.front().start> curt){
                    curt = min(right.front().start, left.front().start);
                }
            }else{
                if (right.front().start <= curt){
                    r2l(left, right);
                }else if(left.front().start<= curt){
                    l2r(left, right);
                }else if(left.front().start> curt){
                    curt = min(right.front().start, left.front().start);
                }
            }
        } 
        while(!left.empty()){
            if(curs == 0){
                if (left.front().start <= curt){
                    l2r(left, right);
                }else{
                    curt = left.front().start;
                }
            }else{
                if(left.front().start<=curt){curs=0; curt+=t;}
                else {curt = left.front().start;}
            }
        }
        while(!right.empty()){
            if(curs == 1){
                if (right.front().start <= curt){
                    r2l(left, right);
                }else{
                    curt = right.front().start;
                }
            }else{
                if(right.front().start<=curt){curs=1; curt+=t;}
                else {curt = right.front().start;}
            }
        } 
        for(auto item : res){
            cout<<item.second<<endl;
        }
        cout<<endl;
        curt=0, curs =0; res.clear();
    }
}