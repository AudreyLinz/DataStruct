#ifndef GRAPH_HPP
#define GRAPH_HPP
#include<vector>

template<typename T>
class Edge{
public:
    int neighbor;
    int weight;

    Edge(int n, int w) : neighbor(n), weight(w);
private:
};

template<typename T>
class WeightedGraph{
public:
    void insertVertex(const T& value);
    
    void insertEdge(const T& v1, const T& v2, int weight = 1);
     
    void print() const;

    //void DFS() const;
    //void BFS(int start=0) const;
    int shortestPath(const T& src, const T& dest) const;
    //bool isConnected() const; //yes or no disconnected
    
private:
    std::vector<T> vertices;
    std::vector<std::vector<int>> edges;
    
    int getVertexIndex(const T& value) const;
    //void DFS(int i, std::vector<bool>& visited) const;
    
};
#include "Graph.tpp"
#endif