#include<iostream>
#include"Mgraph.h"
using namespace std ;
int main(void){



    Mgraph g(6,true);
    
    g.addEdge(4,0,10);
    g.addEdge(2,3,10);
    g.addEdge(5,2,10);
    g.addEdge(5,0,10);

    g.topologicalSort();

    



}