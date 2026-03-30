#include "Graph.hpp"
#include<string>

int main(void){
    Graph<std::string> knowledge;

    knowledge.insertVertex("AVL");
    knowledge.insertVertex("BST");
    knowledge.insertVertex("Trie");
    knowledge.insertVertex("Heap");

    knowledge.insertEdge("BST", "AVL");
    knowledge.insertEdge("BST", "Trie");
    knowledge.insertEdge("BST", "Heap");

    knowledge.print();


    return 0;
}