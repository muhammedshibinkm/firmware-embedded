#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

typedef pair<int, int>pii;

vector<int> dijikstra(int v, vector<vector<pii>> &adj, int source)
{
    vector<int>dist(v, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    //source node weight to itself
    pq.push(make_pair(0, source));
    dist[source] = 0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for(auto &i : adj[u])
        {
            //(vertices, weight)
            int v = i.first;
            int weight = i.second;
            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

int main()
{
    int v = 5;
    vector<vector<pii>>adj(v);
    adj[0].push_back({1, 10});
    adj[0].push_back({3, 5});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 2});
    adj[2].push_back({4, 4});
    adj[3].push_back({1, 3});
    adj[3].push_back({2, 9});
    adj[3].push_back({4, 2});
    adj[4].push_back({0, 7});
    adj[4].push_back({2, 6});

    vector<int> distance = dijikstra(v, adj, 0);
cout << "Vertex distances from source vertex 0:" << endl;
    for (int i = 0; i < v; i++) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }

    return 0;

    
}
