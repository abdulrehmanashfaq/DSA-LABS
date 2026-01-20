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
};

#endif          