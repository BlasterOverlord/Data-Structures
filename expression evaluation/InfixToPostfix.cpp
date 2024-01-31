#include <bits/stdc++.h>

using namespace std;

stack<char> s;
stack<int> result;
string postfix = "";

int priority(char c)
{
    if (c == '^')
        return 100;
    else if (c == '*' || c == '/')
        return 50;
    else if (c == '+' || c == '-')
        return 10;
    else
        return 0;
}

void evaluate(string postfix)
{
    for (int i = 0; i < postfix.size(); i++)
    {
        char symbol = postfix[i];
        if (isdigit(symbol))
        {
            int j, num = 0;
            for (j = i; j < postfix.size(); j++)
            {
                if (!isdigit(postfix[j]))
                    break;
                num = (num * 10) + (postfix[j] - '0');
            }
            result.push(num);
            i = j-1;
        }
        else if (symbol == ' ')
            continue;
        else
        {
            int a = result.top();
            result.pop();
            int b = result.top();
            result.pop();
            int c;
            if (symbol == '*')
                c = b * a;
            else if (symbol == '/')
                c = b / a;
            else if (symbol == '^')
                c = pow(b, a);
            else if (symbol == '+')
                c = b + a;
            else if (symbol == '-')
                c = b - a;

            result.push(c);
        }
    }
    cout << "Evaluation: " << result.top() << endl;
}

void InfixToPostfix(string infix)
{
    for (int i = 0; i < infix.size(); i++)
    {
        char symbol = infix[i];
        if (isdigit(symbol))
        {
            string num = "";
            int j;
            for (j = i; j < infix.size(); j++)
            {
                if (!isdigit(infix[j]))
                    break;
                num += infix[j];
            }
            postfix += num + ' ';
            i = j-1;
        }
        else if (symbol == '(')
            s.push(symbol);
        else if (symbol == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && priority(s.top()) >= priority(symbol))
            {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(symbol);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }
}

int main(void)
{
    string infix;
    getline(cin, infix);

    InfixToPostfix(infix);

    cout << "Postfix: " << postfix << endl;

    evaluate(postfix);

    return 0;
}

// (5+60/2*(8+4)-7)
