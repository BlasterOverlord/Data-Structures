#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
vector <int> level;
vector <int> parent;
bool flag = false;

void BFS(int source)
{
    level[source] = 0;
    queue <int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int j = 0; j < v[u].size(); j++)
        {
            int x = v[u][j];
            if (level[x] == -1)
            {
                parent[x] = u;
                level[x] = level[u] + 1;
                q.push(x);
            }
            else if (x != parent[u] && parent[x] != u && level[x] != level[u])
            {
                flag = true;
            }
        }
    }
}

void path(int node)
{
    if (node != parent[node])
    {
        path(parent[node]);
    }
    cout << node << endl;
}

int main(void)
{
    int n,e;
    cin >> n >> e;

    v.resize(n+1);
    level.resize(n+1, -1);
    parent.resize(n+1);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int nodeA, nodeB;
    for (int i = 0; i < e; i++)
    {
        cin >> nodeA >> nodeB;
        v[nodeA].push_back(nodeB);
        v[nodeB].push_back(nodeA);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << "->";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    BFS(1);

    for (int i = 1; i <= n; i++)
    {
        cout << i << "=" << level[i] << endl;
    }

    //path(5);

    if (flag)
        cout << "Cycle Found!" << endl;
    else
        cout << "No cycle!" << endl;

    return 0;
}


/*

10 12
1 2
1 4
1 3
2 6
6 10
4 7
3 8
7 8
7 9
9 10
8 5
10 5



10 13
1 2
1 4
1 3
2 6
6 10
3 7
4 7
3 8
7 8
7 9
9 10
8 5
10 5

*/

