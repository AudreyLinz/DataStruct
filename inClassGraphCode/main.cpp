#include "SLList.hpp"
#include "Graph.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>


void printCommonFriends(const Graph<std::string>& friends) {
    int n = friends.size();

    // Iterate through all unique pairs of people (i, j)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::vector<std::string> common;

            // Get names for the current pair
            std::string person1 = friends[i];
            std::string person2 = friends[j];

            // In this Graph implementation, we need to find which 
            // vertices are connected to both i and j.
            // We iterate through all possible vertices 'k' to see if 
            // they are friends with both 'i' and 'j'.
            for (int k = 0; k < n; ++k) {
                // A common friend cannot be one of the two people in the pair
                if (k == i || k == j) continue;

                if (friends.hasEdge(i, k) && friends.hasEdge(j, k)) {
                    common.push_back(friends[k]);
                }
            }

            // Only print if there is at least one common friend
            if (!common.empty()) {
                std::cout << person1 << " and " << person2 << ": ";
                for (size_t m = 0; m < common.size(); ++m) {
                    std::cout << common[m] << (m == common.size() - 1 ? "" : " ");
                }
                std::cout << std::endl;
            }
        }
    }
}

int main(void) {
    std::ifstream input("input.txt");
    SLList<std::string> list;
    
    std::string word;
    while (input >> word) {  
        list.push_back(word);
    }
    
    input.close();
    
    //list.rotate_right(47);
    
    Graph<std::string> graph;
    while (!list.empty()) {
        auto data = list.pop_front();
        graph.insertVertex(data);
    }

    for (int i = 0; i < 250; i++) {
        graph.insertEdge(graph[i % graph.size()], graph[i % graph.size()]); // This is made on purpose
        graph.insertEdge(graph[rand() % graph.size()], graph[rand() % graph.size()]);
    }

    //graph.removeSelfEdges();
    graph.print();
    std::cout << "==================COMMON FRIENDS========================\n";
    printCommonFriends(graph);
  
    return 0;
}