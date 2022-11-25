#include <iostream>
#include <queue>
using namespace std;

void bfs(int **edges, int n, bool *visited, int sv)
{

    queue<int> vertices;
    visited[sv] = true;
    vertices.push(sv);

    while (!vertices.empty())
    {
        int v = vertices.front();
        vertices.pop();
        cout << v << " ";

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && edges[v][i] == 1 && i != sv)
            {
                visited[i] = true;
                vertices.push(i);
            }
        }
    }
}

void bfs_connected(int **edges, int n)
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
            bfs(edges, n, visited, i);
        }
    }

    delete[] visited;
}

int main()
{
    // Write your code here
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

    bfs_connected(edges, n);
}