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

void evaluate(string postfix)
{
    for (int i = 0; i < postfix.size(); i++)
    {
        char symbol = postfix[i];
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
                c = b*a;
            else if (symbol == '/')
                c = b/a;
            else if (symbol == '^')
                c = pow(b,a);
            else if (symbol == '+')
                c = b + a;
            else if (symbol == '-')
                c = b-a;

            result.push(c);
        }
    }
    cout << result.top() << endl;
}

int main (void)
{
    string infix, postfix = "";
    getline(cin, infix);


    for (int i = 0; i < infix.size(); i++)
    {
        char symbol = infix[i];
        if (symbol >= '0' && symbol <= '9')
            postfix = postfix + symbol;
        else if (symbol == '(')
            s.push(symbol);
        else if (symbol == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && priority(s.top()) >= priority(symbol))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(symbol);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    cout << postfix << endl;

    evaluate(postfix);

    return 0;
}



// (5+6/2*(8+4)-7)
