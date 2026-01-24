#ifndef Mgraph_H
#define Mgraph_H   
#include<iostream>
#include<queue>
#include<stack>
using namespace std ;
class Mgraph{


    private:

    int vertex ;
    int **adj ;
    bool directed ;

    public :

    Mgraph(int vertex,bool directed = true ){

        this->directed = directed ;
        this->vertex = vertex;

        adj = new int *[vertex];

        for (int i = 0 ; i<vertex; i++){

            adj[i] = new int[vertex];
            
            for (int j = 0 ; j<vertex ; j++ ){
                adj[i][j] = 0 ;
            }

        }



    }

    void addEdge(int u, int v ,int weight){

        if (directed){

            if (adj[u][v] == 0 ){
            
                adj[u][v] = weight ;

            }
            else{

            cout << "Breaking the previous link " << endl;
            adj[u][v] = weight ;
            

            }

            return ;


        }

        if (adj[u][v] == 0 ){

            adj[u][v] = weight ;
            adj[v][u] = weight ;

        }
        else{


            cout << " Breaking the previous edge " << endl ;    
            adj[u][v] = weight;
            adj[v][u] = weight;


        }

        


    }

    ~Mgraph(){

        for (int i =0 ; i<vertex; i++){

            delete[] adj[i];
        }

        delete[] adj;

    }


    void helperDFS (int start,bool *visited){


            visited[start] = true ;
            cout << start << " " ; 

            for ( int i = 0 ;i<vertex ; i++){

                if (adj[start][i]!=0 && visited[i]==false){

                    
                    helperDFS(i,visited);


                }
            

            }
            return ;







    }

   void dfs(int start) { 
        bool *visited = new bool[vertex];

        

        for (int i = 0; i < vertex; i++) {
            visited[i] = false;
        }

        cout << "DFS Traversal: ";
        helperDFS(start, visited);
        cout << endl;

        delete[] visited;



    }

    // BFS (NOW)

 void bfs(int start) {
        
        bool *visited = new bool[vertex];
        for(int i = 0; i < vertex; i++) {
            visited[i] = false;
        }

        
        queue<int> q;

        
        visited[start] = true; 
        q.push(start); 
        
        cout << "BFS Traversal: ";

        
        while(!q.empty()) {
            int u = q.front(); 
            q.pop();          
            cout << u << " ";  

            
            for(int v = 0; v < vertex; v++) {
                
                if(adj[u][v] != 0 && visited[v] == false) {
                    visited[v] = true; 
                    q.push(v);         
                }
            }
        }
        cout << endl;

        
        delete[] visited;
    }

    void SortHelper(int start , stack<int>&s,bool *visited){


        visited[start] = true ;

        for (int i = 0 ;i<vertex;i++){

            if (adj[start][i]!=0 && visited[i]!=true){
                SortHelper(i,s,visited);
            }


        }

        s.push(start);









    }

        void topologicalSort(){


            if (!directed){
                cout << " Graph is not Directed " << endl ;
                return ; 
            }


            stack<int>s;
            bool *visited = new bool[vertex];
            for (int i = 0 ;i<vertex;i++){

                visited[i] = false;

            }

            for (int i=0;i<vertex;i++){
            if(!visited[i])
            SortHelper( i , s, visited);
            }

            
            while(!s.empty()){

                int num = s.top();
                s.pop() ;
                cout << num << " ";

            }

            cout << endl ;

            delete[] visited ;
        







        }
        void prims(int start) {

    if (directed) {
        cout << "Prim's Algorithm works only on undirected graphs." << endl;
        return;
    }

    int *key = new int[vertex];       
    int *parent = new int[vertex];    
    bool *inMST = new bool[vertex];   

    for (int i = 0; i < vertex; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        inMST[i] = false;
    }

    key[start] = 0;

    for (int count = 0; count < vertex - 1; count++) {

        int u = -1;
        int minKey = INT_MAX;

        // Pick minimum key vertex not in MST
        for (int i = 0; i < vertex; i++) {
            if (!inMST[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        if (u == -1) break; // Disconnected graph case

        inMST[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < vertex; v++) {
            if (adj[u][v] != 0 && !inMST[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;
    cout << "Edges in MST:\n";

    for (int i = 0; i < vertex; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " -> " << i
                 << " (weight = " << key[i] << ")\n";
            totalCost += key[i];
        }
    }

    cout << "Total cost of MST: " << totalCost << endl;

    delete[] key;
    delete[] parent;
    delete[] inMST;
}



void spanning_helper(int start, bool *visited) {

    visited[start] = true;

    for (int v = 0; v < vertex; v++) {
        if (adj[start][v] != 0 && !visited[v]) {
            cout << start << " -> " << v << endl;
            spanning_helper(v, visited);
        }
    }
}


void spanningtree(int start) {

    bool *visited = new bool[vertex];
    for (int i = 0; i < vertex; i++) {
        visited[i] = false;
    }

    spanning_helper(start, visited);

    // Handle disconnected graph
    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            spanning_helper(i, visited);
        }
    }

    delete[] visited;
}

void dijkstra(int src) {

    int *dist = new int[vertex];
    bool *visited = new bool[vertex];

    for (int i = 0; i < vertex; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < vertex - 1; count++) {

        int u = -1;
        int minDist = INT_MAX;

        // Pick minimum distance vertex
        for (int i = 0; i < vertex; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // Disconnected graph

        visited[u] = true;

        // Relax edges
        for (int v = 0; v < vertex; v++) {
            if (adj[u][v] != 0 && !visited[v] &&
                dist[u] != INT_MAX &&
                dist[v] > dist[u] + adj[u][v]) {

                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    cout << "Dijkstra distances from " << src << ":\n";
    for (int i = 0; i < vertex; i++) {
        cout << src << " -> " << i << " : ";
        if (dist[i] == INT_MAX)
            cout << "Unreachable\n";
        else
            cout << dist[i] << endl;
    }

    delete[] dist;
    delete[] visited;
}




};

#endif          