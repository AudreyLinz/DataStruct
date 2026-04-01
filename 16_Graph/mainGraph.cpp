#include "Graph.hpp"
#include<string>

int main(void){
    Graph<std::string> knowledge;

    knowledge.insertVertex("A");
    knowledge.insertVertex("B");
    knowledge.insertVertex("C");
    knowledge.insertVertex("D");
    knowledge.insertVertex("E");
    knowledge.insertVertex("F");
    knowledge.insertVertex("G");
    knowledge.insertVertex("S");
    knowledge.insertVertex("H");

    knowledge.insertEdge("B", "A");
    knowledge.insertEdge("A", "S");
    knowledge.insertEdge("C", "S");
    knowledge.insertEdge("S", "G");
    knowledge.insertEdge("C", "F");
    knowledge.insertEdge("C", "D");
    knowledge.insertEdge("C", "E");
    knowledge.insertEdge("E", "H");
    knowledge.insertEdge("G", "H");
    knowledge.insertEdge("G", "F");

    knowledge.print();
    knowledge.DFS();

    /*
    TODO
    1.Created a disconnected graph
    2. Update DFS to traverse all the nodes of this graph
    */

    return 0;
}