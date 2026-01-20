#ifndef Mgraph_H
#define Mgraph_H   
#include<iostream>
#include<queue>
using namespace std ;
class Mgraph{


    private:

    int vertex ;
    int **adj ;

    public :

    Mgraph(int vertex){

        this->vertex = vertex;

        adj = new int *[vertex];

        for (int i = 0 ; i<vertex; i++){

            adj[i] = new int[vertex];
            
            for (int j = 0 ; j<vertex ; j++ ){
                adj[i][j] = 0 ;
            }

        }



    }

    void addEdge(int v, int u ,int weight){

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











};

#endif          