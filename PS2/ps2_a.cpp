#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool iss = true, isq = true, ispq = true;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a == 1)
            {
                s.push(b);
                q.push(b);
                pq.push(b);
            }
            else
            {
                if (iss && !s.empty() && s.top() == b)
                {
                    s.pop();
                }
                else
                {
                    iss = false;
                }
                if (isq && !q.empty() && q.front() == b)
                {
                    q.pop();
                }
                else
                {
                    isq = false;
                }
                if (ispq && !pq.empty() && pq.top() == b)
                {
                    pq.pop();
                }
                else
                {
                    ispq = false;
                }
            }
        }
        if (iss && !isq && !ispq)
        {
            cout << "stack" << endl;
        }
        else if (!iss && isq && !ispq)
        {
            cout << "queue" << endl;
        }
        else if (!iss && !isq && ispq)
        {
            cout << "priority queue" << endl;
        }
        else if (!iss && !isq && !ispq)
        {
            cout << "impossible" << endl;
        }
        else
        {
            cout << "not sure" << endl;
        }
    }
}