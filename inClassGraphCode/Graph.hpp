#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>


template <typename T>
class Graph {
public:

    void insertVertex(const T& v);
    void insertEdge(const T& v1, const T& v2);
    void print() const;

    void DFS() const;
    void BFS(int start = 0) const;
    int shortestPath(const T& src, const T& dest) const;
    bool isConnected() const;

    //void removeSelfEdges();

    const T& operator[](int i) const;
    int size() const;

    friend void printCommonFriends(const Graph<std::string>& friends);

private:
    std::vector<T> vertices; 
    std::vector<std::vector<int>> edges; 

    
    int getVertexIndex(const T& vs) const;

    bool hasEdge(int i1, int i2) const;
    void DFS(int i, std::vector<bool>& visited) const;
};

#include "Graph.tpp"

#endif