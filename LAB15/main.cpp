#include <iostream>
#include "Lgraph.h" 

using namespace std;

int main() {
    
    Lgraph PunjabMap(16); 

    

    
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