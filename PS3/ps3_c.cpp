#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
using namespace std;
int32_t var[26] = {0};
int32_t get_val(string a){
    if(a[0] >= 'A' && a[0] <= 'Z') return var[a[0] - 'A'];
    else{
        return stoi(a);
    }
}

void let(string ins){
    stringstream ss(ins);
    string token;
    vector<string> v;
    while(getline(ss, token, ' ')) v.push_back(token);
    int idx = v[1][0]- 'A';
    if (v.size() == 6){
        int32_t op1 = get_val(v[3]), op2 = get_val(v[5]);
        if (v[4] == "+") var[idx] = op1 + op2;
        if (v[4] == "-") var[idx] = op1 - op2;
        if (v[4] == "*") var[idx] = op1 * op2;
        if (v[4] == "/") var[idx] = op1 / op2;
    } else {
        var[idx] = get_val(v[3]);
    }
}
int32_t do_if(string ins){
    stringstream ss(ins);
    string cmd; ss>>cmd;
    string a, b, c, then, goo; int32_t d;
    ss>>a>>b>>c>>then>>goo>>d; int32_t op1 = get_val(a), op2 = get_val(c);
    bool flag = false;
    if (b == "=" && op1 == op2) flag = true;
    if (b == ">" && op1 > op2) flag = true;
    if (b == "<" && op1 < op2) flag = true;
    if (b == "<>" && op1 != op2) flag = true;
    if (b == "<=" && op1 <= op2) flag = true;
    if (b == ">=" && op1 >= op2) flag = true;
    if (flag){
        return d;
    } else return -1;
}

void do_prtln(string ins){
    stringstream ss(ins);
    string cmd; ss>>cmd; ss.get();
    string str; getline(ss, str);
    if (!(str[0] >= 'A' && str[0] <= 'Z')) cout<<str.substr(1, str.size()-2)<<endl;
    else cout<<get_val(str)<<endl;
}

void do_prt(string ins){
    stringstream ss(ins);
    string cmd; ss>>cmd; ss.get();
    string str; getline(ss, str);
    if (!(str[0] >= 'A' && str[0] <= 'Z')) cout<<str.substr(1, str.size()-2);
    else cout<<get_val(str);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    map<int32_t, string> m;
    string s;
    while(getline(cin, s)){
        stringstream ss(s);
        int32_t lable; ss>>lable; ss.get();
        string ins;
        getline(ss, ins);
        m[lable] = ins;
    }
    bool itplus = true;
    for(auto it = m.begin(); it != m.end(); it++) {
        if (!itplus) {it--; itplus = true;}
        string ins = it->second;
        stringstream ss(ins);
        string cmd;
        ss>>cmd;
        if (cmd == "LET") let(ins);
        else if (cmd == "IF") { 
            int32_t lable; lable = do_if(ins);
            if (lable != -1){
                auto f = m.find(lable);
                it = f;
                itplus = false;
            }
        }
        else if (cmd == "PRINTLN") do_prtln(ins);
        else do_prt(ins);
        
    }
}