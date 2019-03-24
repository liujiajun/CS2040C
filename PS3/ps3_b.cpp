#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main(){
    int n, m; cin>>n>>m;
    int s = 0;
    vector < pair<int, int> > res;
    for (int i = 0; i<n; i++){
        int a, s; cin>>a>>s;
        res.push_back(make_pair(a, s));
    }
    sort(res.begin(), res.end());
    priority_queue<int, vector<int>,greater<int> > coms;
    for(auto p : res){
        while(!coms.empty() && coms.top() + m < p.first) coms.pop();
        if (coms.empty()) { coms.push(p.first+p.second); s++; continue; }
        if (coms.top() > p.first) {
            coms.push(p.first+p.second);
            s++;
            continue;
        }
        coms.pop();
        coms.push(p.first + p.second);
    }
    cout<<res.size() - s<<endl;
}