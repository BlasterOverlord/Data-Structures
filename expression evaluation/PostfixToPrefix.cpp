#include <bits/stdc++.h>

using namespace std;

stack<string> s;
stack<int> result;

void evaluate(string prefix)
{
    reverse(prefix.begin(), prefix.end());
    for (int i = 0; i < prefix.size(); i++)
    {
        char symbol = prefix[i];
        if (symbol>='0' && symbol<='9')
            result.push(symbol-'0');
        else
        {
            int a = result.top();
            result.pop();
            int b = result.top();
            result.pop();
            int c = 0;
            if (symbol == '*')
                c = a*b;
            else if (symbol == '/')
                c = a/b;
            else if (symbol == '^')
                c = pow(a,b);
            else if (symbol == '+')
                c = a + b;
            else if (symbol == '-')
                c = a-b;

            result.push(c);
        }
    }
    cout << result.top() << endl;
}

int main (void)
{
    string postfix, prefix = "";
    getline(cin, postfix);


    for (int i = 0; i < postfix.size(); i++)
    {
        char symbol = postfix[i];
        if (symbol >= '0' && symbol <= '9')
            s.push(string(1,symbol));
        else
        {
            string c1 = s.top();
            s.pop();
            string c2 = s.top();
            s.pop();
            string temp = symbol + c2 + c1;
            s.push(temp);
        }
    }

    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }

    cout << prefix << endl;

    evaluate(prefix);

    return 0;
}

// 562/84+*+7-
