#include<iostream>
#include"Mgraph.h"
using namespace std ;
int main(void){



    Mgraph g(5);
    g.addEdge(0,1,5);
    g.addEdge(4,3,10);
    g.addEdge(0,3,6);
    g.addEdge(0,4,2);
    g.addEdge(3,1,67);
    g.addEdge(1,2,4);
    
    g.dfs(0);
    g.bfs(0);




}