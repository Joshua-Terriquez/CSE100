#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

//Function to add edge between vertices
void addEdge(vector <pair<int, int> > graph[], int u, int v, int w) {
   graph[u].push_back(make_pair(v, w));
   graph[v].push_back(make_pair(u, w));
}

// Implementation of Prim's Algorithm
void primMST(vector<pair<int,int> > adj[], int V) {
   priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;
   int src = 0; // Source vertex is 0
  
//Initialy all distances are Infinite
   vector<int> dist(V, INF);

   // To store parent array
   vector<int> parent(V, -1);

   // To keep track of vertices included in MST
   vector<bool> inclMST(V, false);

   //Distance of source from itself is 0
   pq.push(make_pair(0, src));
   dist[src] = 0;

   //Continue till pq is empty
   while (!pq.empty()) {
       //Extarct Min from queue
       int u = pq.top().second;
       pq.pop();

       inclMST[u] = true; // Add vertex in MST

       // Traverse all adjacent vertices of u
       for (auto x : adj[u]) {
           int v = x.first;
           int weight = x.second;
           if (inclMST[v] == false && dist[v] > weight) {
               // Updating dist of v if smaller is found
               dist[v] = weight;
               pq.push(make_pair(dist[v], v));
               parent[v] = u;
           }
       }
   }

   // Print output
   for (int i = 1; i < V; ++i)
       printf("%d\n", parent[i]);
}

int main() {
//V -> vertices
//E -> edges
//u -> start node
//v -> end node
//w -> weight
   int V, E, u, v, w;
   cin >> V;
   vector<pair<int, int> > graph[V];
cin >> E;
for(int i=0; i<E; i++){
cin >> u >> v >> w;
addEdge(graph,u,v,w);
}
   primMST(graph, V);
   return 0;
}