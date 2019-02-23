#include <iostream>
#include <stack>
#include <queue>
#include <list>
using namespace std;
struct Hand
{
    int player;
    int stat = 0;
};
void print2(list<Hand> l)
{
    for (Hand h : l)
    {
        cout << h.player << "|" << h.stat << "  ";
    }
    cout << endl;
}
int main()
{
    int s, n;
    cin >> s >> n;
    list<Hand> l;
    for (int i = 0; i < n; i++)
    {
        Hand h1, h2;
        h1.player = i;
        l.push_back(h1);
    }
    auto it = l.begin();
    while (l.size() > 1)
    {
        for (int i = 0; i < s - 1; i++)
        {
            if (next(it) == l.end())
                it = l.begin();
            else
                it++;
        }
        if (it->stat == 0)
        {
            Hand h;
            h.player = it->player;
            h.stat = 1;
            it->stat = 1;
            it = l.insert(it, h);
        }
        else if (it->stat == 1)
        {
            it->stat = 2;
            it++;
        }
        else if (it->stat == 2)
        {
            it = l.erase(it);
        }
        if (it == l.end())
            it = l.begin();
        //rint2(l);
    }
    for (auto h : l)
    {
        cout << h.player + 1;
    }
}