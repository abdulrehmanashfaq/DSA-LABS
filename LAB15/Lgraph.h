#ifndef Lgraph_H
#define Lgraph_H   




#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <queue>
#include <string>
#include <map>

using namespace std;


struct Edge {
    int dest;
    int weight;
};

class Lgraph {

private:
    int V;
    bool directed;

    map<string,int> str_to_id ;
    vector<string>str_cont;
    list<Edge> *adj;
    int id = 0 ;

public:

    // Constructor
    Lgraph(int V, bool directed = false) {
        this->V = V;
        this->directed = directed;
        // Allocate array of lists
        adj = new list<Edge>[V];
        str_cont.resize(V);
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

    int find_id(string s){

        if (str_to_id.find(s) == str_to_id.end() ){
            str_to_id[s] = id ;
            id++;
        }
        return str_to_id[s];

    }

    void addEdge(string s , string t ,int weight){

        int u = find_id(s);
        int v = find_id(t);
        str_cont[u] = s;
        str_cont[v] = t; 

        adj[u].push_back({v,weight});
        
        if (!directed){
            adj[v].push_back({u,weight});
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

    void digkstra(string n){

        int src = find_id(n);
        input_validated_digkstra(src,true);

    }
    void digkstra(int n){
        input_validated_digkstra(n,false);

    }
    void input_validated_digkstra( int src ,bool str){


        vector<int>dis(V,INT_MAX);
        priority_queue<pair<int,int> ,  vector<pair<int,int>> ,greater<pair<int,int>> > pq ;
        dis[src] = 0 ;
        pq.push({0,src});


        while (!pq.empty()){

            int u = pq.top().second ;
            pq.pop();

            for ( auto e : adj[u] ){

                if (dis[e.dest] > dis[u]+e.weight ){

                    dis[e.dest] = dis[u]+e.weight;
                    pq.push({dis[e.dest] , e.dest});
                }


            }





        }

        if (!str){
        for (int i=0 ;i<V ;i++){

            cout << src << " -> " << i << " : " << dis[i] << endl ;

        }
    }
        else{

            for (int i=0 ;i<id ;i++){

            if (dis[i] == INT_MAX) {
                cout << str_cont[src] << " -> " << str_cont[i] << " : Unreachable" << endl;
                continue ;
    }

            cout << str_cont[src] << " -> " << str_cont[i] << " : " << dis[i] << endl ;

        }

        }



    }


    void spanning_helper(int start ,vector<bool>&visited){

        visited[start]  = true ;
           
    
        for (auto i : adj[start]){
            if(! visited[i.dest]){
            cout << start << " -> " << i.dest << endl ;
            spanning_helper(i.dest,visited);
            }
        }


    }
    void spanningtree(int start ){

        vector<bool>visited(V,false) ;

        spanning_helper(start,visited);

        for (int i=0 ;i<V ; i++){

        if (!visited[i]){
            spanning_helper(i,visited);
        }

        }



    }

    
    
};






#endif
