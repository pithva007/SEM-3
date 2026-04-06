#include <bits/stdc++.h>
using namespace std;

void printMatrix(int n, int mat[][100])
{
    cout << "Adjacency Matrix:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int node, int n, int mat[][100], int vis[])
{
    vis[node] = 1;
    cout << node << " ";

    for (int i = 1; i <= n; i++)
    {
        if (mat[node][i] == 1 && !vis[i])
        {
            dfs(i, n, mat, vis);
        }
    }
}

void bfs(int start, int n, int mat[][100], int vis[])
{
    queue<int> q;
    q.push(start);
    vis[start] = 1;

    cout << "\nBFS Traversal starting from node " << start << ":\n";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 1; i <= n; i++)
        {
            if (mat[node][i] == 1 && !vis[i])
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    cout << endl;
}

int main()
{
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    int mat[100][100] = {0};

    cout << "Enter each edge (u v):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        mat[u][v] = 1;
    }

    printMatrix(n, mat);

    int vis[100] = {0};

    cout << "\nDFS Traversal starting from node 1:\n";
    dfs(1, n, mat, vis);

    fill(vis, vis + n + 1, 0);

    bfs(1, n, mat, vis);

    return 0;
}
