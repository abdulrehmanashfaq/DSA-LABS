#ifndef Lgraph_H
#define Lgraph_H   




#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>


using namespace std;


struct Edge {
    int dest;
    int weight;
};

class Lgraph {

private:
    int V;
    bool directed;
    
    
    list<Edge> *adj;

public:

    // Constructor
    Lgraph(int V, bool directed = false) {
        this->V = V;
        this->directed = directed;
        // Allocate array of lists
        adj = new list<Edge>[V];
    }

    
    ~Lgraph() {
        delete[] adj;
    }

    
    void addEdge(int u, int v, int weight) {
        
        adj[u].push_back({v, weight});

        
        if (!directed) {
            adj[v].push_back({u, weight});
        }
    }

    
    void bfs(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        cout << "BFS: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            
            for (auto i : adj[u]) {
                
                if (!visited[i.dest]) {
                    visited[i.dest] = true;
                    q.push(i.dest);
                }
            }
        }
        cout << endl;
    }

    
    void dfsHelper(int start, vector<bool> &visited) {
        visited[start] = true;
        cout << start << " ";

        for (auto i : adj[start]) {
            if (!visited[i.dest]) {
                dfsHelper(i.dest, visited);
            }
        }
    }

    void dfs(int start) {
        vector<bool> visited(V, false);
        cout << "DFS: ";
        dfsHelper(start, visited);
        
        
        for(int i=0; i<V; i++) {
            if(!visited[i]) dfsHelper(i, visited);
        }
        cout << endl;
    }

    
    void topoHelper(int start, vector<bool> &visited, stack<int> &s) {
        visited[start] = true;

        for (auto i : adj[start]) {
            if (!visited[i.dest]) {
                topoHelper(i.dest, visited, s);
            }
        }
        s.push(start);
    }

    void topologicalSort() {
        if (!directed) {
            cout << "Topological Sort skipped (Graph is Undirected)" << endl;
            return;
        }

        stack<int> s;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i])
                topoHelper(i, visited, s);
        }

        cout << "Topological Sort: ";
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    
    

    
    
};






#endif
