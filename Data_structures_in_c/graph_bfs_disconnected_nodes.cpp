#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs_graph(vector<vector<int>> &adjList, int start_idx, vector<bool> &visited)
{
    queue<int>q;
    q.push(start_idx);
    visited[start_idx] = true;
    while(!q.empty())
    {
        int current_idx = q.front();
        q.pop();
        cout << current_idx << " ";
        for(auto negbr : adjList[current_idx])
        {
            if(visited[negbr] == false)
            {
                q.push(negbr);
                visited[negbr] = true;
            }
        }

    }
}
void bfs_sd(vector<vector<int>> &adjList, int vertices, vector<bool> &visited)
{
    for(int i = 0; i < vertices; i++)
    {
        if(visited[i] == false)
            bfs_graph(adjList, i, visited);
    }
}

void createBfs(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v);
}

int main()
{
    int vertices = 6;
    vector<vector<int>>adjList(vertices);
    vector<bool>visited(vertices, false);
    createBfs(adjList, 0, 1);
    createBfs(adjList, 0, 2);
    createBfs(adjList, 1, 3);
    createBfs(adjList, 1, 4);
    createBfs(adjList, 2, 4);
    createBfs(adjList, 3, 5);
    createBfs(adjList, 4, 5);

    cout << "vertices in order of edges :starts from zero\n ";
    bfs_sd(adjList, vertices, visited);
    
}
