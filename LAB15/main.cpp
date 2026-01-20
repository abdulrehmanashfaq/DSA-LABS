#include<iostream>
#include"Mgraph.h"
#include"Lgraph.h"
using namespace std ;
int main(void){



    Lgraph g(6,true);
    
    g.addEdge(4,0,10);
    g.addEdge(2,3,10);
    g.addEdge(5,2,10);
    g.addEdge(5,0,10);

    g.topologicalSort();

    



}