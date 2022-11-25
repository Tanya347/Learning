#include <iostream>
#include <vector>
using namespace std;

void dfs(int **edges, int n, bool *visited, int sv)
{
    cout << sv << " ";
    visited[sv] = true;

    for (int i = 0; i < n; i++)
    {
        if (i != sv && !visited[i] && edges[sv][i] == 1)
        {
            dfs(edges, n, visited, i);
        }
    }
}

void dfs_connected(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(edges, n, visited, i);
        }
    }
    delete[] visited;
}

int main()
{
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int s, f;
        cin >> s >> f;
        edges[s][f] = 1;
        edges[f][s] = 1;
    }

    dfs_connected(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;
}