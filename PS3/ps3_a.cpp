#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
     ios_base::sync_with_stdio(0);
     cin.tie(NULL);
    int N, B;
    
    while(cin>>N>>B){
        if (N == -1) break;
        vector<int> v;
        int maxc = -1;
        for (int i=0; i<N; i++){
            int a; cin>>a;
            v.push_back(a);
            maxc = max(maxc, a);
        }
        int l = 1, h = maxc, ans = B;
        while(l<h){
            int box = 0;
            int mid = (l+h)/2;
            for(auto num : v){
                if (num % mid == 0) {box += num / mid;}
                else { box += num/mid + 1;}
            }
            if (box<=B){
                ans = mid; h = mid;
            } else {
                l = mid + 1;
            }
        }
        cout<<ans<<endl;
    }

}