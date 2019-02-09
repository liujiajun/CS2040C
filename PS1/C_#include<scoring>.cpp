//A0177869B
//LIU JIAJUN
//LAB [10] Teh Nian Fei

#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
map<int, int> scores = {
    {1,100}, {2,75}, {3,60}, {4,50}, {5,45}, {6,40}, {7,36}, {8,32}, {9,29}, {10,26}, {11,24}, {12,22}, {13,20}, {14,18}, {15,16}, {16,15}, {17,14}, {18,13}, {19,12}, {20,11}, {21,10}, {22,9}, {23,8}, {24,7}, {25,6}, {26,5}, {27,4}, {28,3}, {29,2}, {30,1}
};
struct contestant{
    int s, p, f, o;
    int score;
    int key, rank;

};

bool compare(const contestant& c1, const contestant& c2){
    if (c1.s>c2.s) return true;
    if(c1.s == c2.s){
        if (c1.p<c2.p) return true;
        if (c1.p == c2.p){
            if (c1.f <c2.f) return true;
        }
    }
    return false;
}

bool compare_keys(const contestant& c1, const contestant& c2){
    if (c1.key > c2.key) return false;
    return true;
}

int main() {
    int n; cin>>n;
    contestant contestants[n];
    for (int i=0; i<n; i++){
        contestant c;
        cin>>c.s>>c.p>>c.f>>c.o;
        c.key = i;
        contestants[i] = c;
    }
    sort(contestants, contestants+n, compare); //Sort by s, p, f
    //Sliding window
    int s=0, e=1;
    while(s<30 && s<n){
        while (contestants[e].s == contestants[e-1].s && contestants[e].p == contestants[e-1].p && contestants[e].f == contestants[e-1].f){
            e++;
        }
        double total = 0.0;
        for(int i = s; i<e; i++){
            total += scores[i+1];
        }
        int avg = ceil(total/(e-s));
        for(int i = s; i<e; i++) contestants[i].score = avg + contestants[i].o;
        s=e;
        e++;
    }
    for (int i = s; i<n; i++) contestants[i].score = contestants[i].o;
    
    sort(contestants, contestants+n, compare_keys); //Go back to the sequence in input
    
    //print scores
    for (int i=0; i<n; i++){
        cout<<contestants[i].score<<endl;
    }
    return 0;
}
