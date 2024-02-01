#include <bits/stdc++.h>

using namespace std;

stack<char> s;
stack<int> result;

int priority(char c)
{
    if (c == '^')
        return 100;
    else if (c == '*' || c=='/')
        return 50;
    else if (c=='+' || c=='-')
        return 10;
    else
        return 0;
}

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
    string infix, prefix = "";
    getline(cin, infix);

    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    for (int i = 0; i < infix.size(); i++)
    {
        char symbol = infix[i];
        if (isdigit(symbol))
            prefix = prefix + symbol;
        else if (symbol == '(')
            s.push(symbol);
        else if (symbol == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                prefix += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && priority(symbol)<priority(s.top()))
            {
                prefix += s.top();
                s.pop();
            }
            s.push(symbol);
        }
    }

    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());

    cout << prefix << endl;

    evaluate(prefix);

    return 0;
}



// (5+6/2*(8+4)-7)