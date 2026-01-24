#include <iostream>
#include "Lgraph.h" 
#include "Mgraph.h"


using namespace std;

int main() {


    Lgraph span(5,true);
    span.addEdge(4,0,10);
    span.addEdge(4,3,10);
    span.addEdge(0,1,10);
    span.addEdge(1,2,10);
    span.addEdge(2,3,10);
    span.addEdge(3,1,10);

    span.spanningtree(4);
    
    Lgraph PunjabMap(16); 

    cout << endl ;

    
    PunjabMap.addEdge("Lahore", "Gujranwala", 80);
    PunjabMap.addEdge("Gujranwala", "Wazirabad", 35);
    PunjabMap.addEdge("Wazirabad", "Gujrat", 15);
    PunjabMap.addEdge("Gujrat", "Jhelum", 60);
    PunjabMap.addEdge("Jhelum", "Rawalpindi", 115);
    PunjabMap.addEdge("Rawalpindi", "Islamabad", 20);

    
    PunjabMap.addEdge("Gujranwala", "Sialkot", 55);
    PunjabMap.addEdge("Wazirabad", "Sialkot", 40);

    
    PunjabMap.addEdge("Lahore", "Faisalabad", 180); 
    PunjabMap.addEdge("Faisalabad", "Sargodha", 95);
    PunjabMap.addEdge("Sargodha", "Mianwali", 160);
    PunjabMap.addEdge("Faisalabad", "Jhang", 80);

    
    PunjabMap.addEdge("Lahore", "Sahiwal", 170);
    PunjabMap.addEdge("Sahiwal", "Multan", 175);
    PunjabMap.addEdge("Faisalabad", "Multan", 240);
    PunjabMap.addEdge("Multan", "Bahawalpur", 100);
    PunjabMap.addEdge("Multan", "DG Khan", 95);

    
    cout << "Shortest Paths from Wazirabad " << endl;
    PunjabMap.digkstra("Wazirabad");

    cout << endl ;
    cout << "Shortest Paths from Lahore " << endl;
    PunjabMap.digkstra("Lahore");

    return 0;
}