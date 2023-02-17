#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

int maxsize = 1e6;

void push(deque<int> dq, int x, int rev, int sum)
{
    sum += x;
    if (rev == 0)
    {
        dq.push_back(x);
    }
    else
    {
        dq.push_front(x);
    }
}

void Pop(deque<int> dq, int rev, int sum)
{

    if (rev == 0)
    {
        sum -= dq.back;

        dq.pop_back();
    }
    else
    {
        sum -= dq.front;
        dq.pop_front();
    }
}

void print(deque<int> dq, int rev)
{

    if (rev == 0)
    {
        printf("%d\n", dq.back());
    }
    else
    {
       printf("%d\n", dq.front());

    }
}

int main()
{

    string ch;
    deque<int> dq;

    int rev = 0;
    int sum = 0;

    while (scanf("%s", ch) != EOF)
    {
        string s = ch;
        if (s == "PUSH")
        {
            int x;
            scanf("%d", &x);
            push(x, dq, rev, sum);
        }
        else if (s == "POP")
        {

            Pop(dq, rev, sum);
        }
        else if (s == "PRINT")
        {

            print(dq, rev);
        }
        else if (s == "SIZE")
        {

            printf("%d\n", dq.size());
        }
        else if (s == "SUM")
        {

            printf("%d\n", sum);
        }
        else if (s == "REPEAT")
        {

            int times;
            scanf("%d", &times);
            // S.repeat(dq, rev);
        }
        else if (s == "REVERSE")
        {

            rev = rev ^ 1;
        }
    }
}