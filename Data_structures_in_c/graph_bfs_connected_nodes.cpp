#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//print all reacheble vertices in order
void bfs_graph(vector<vector<int>> &adjList, int start_idx, vector<bool> &visited)
{
    queue<int>q;
    q.push(start_idx);
    visited[start_idx] = true;
    while(!q.empty()) {
        int current_node = q.front();
        q.pop();
        cout<< current_node <<" ";
        for(auto neighbor : adjList[current_node]) {
            if(visited[neighbor] == false) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    
}
void createBfs(vector<vector<int>> &adjList, int u, int v)
{
    adjList[u].push_back(v);
}
int main()
{
    int vertices = 5;
    vector<vector<int>>adjList(vertices);
    createBfs(adjList, 0, 1);
    createBfs(adjList, 0, 2);
    createBfs(adjList, 1, 3);
    createBfs(adjList, 1, 4);
    createBfs(adjList, 2, 4);

    vector<bool>visited(vertices, false);
    cout << "Breadth First Traversal starting from vertex 0: ";
    bfs_graph(adjList, 0, visited);
}
