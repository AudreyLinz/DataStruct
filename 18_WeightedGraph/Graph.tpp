#include "Graph.hpp"
#include "minHeap.cpp"
#include<iostream>
#include<climits>

template<typename T>
int Graph<T>::getVertexIndex(const T& value) const{
    int i =0;
    for(const auto& v : vertices){
        if(v==value){
            return i;
        }
        i++;
    }
    return -1; //no element
}

template<typename T>
void Graph<T>::insertVertex(const T& value){
    if(getVertexIndex(value)!=-1){
        std::cout << "insertVertex: vertex already exists\n";
        return;
    }
    vertices.push_back(value); //Add the new vertex
    std::vector<Edge> tmp;
    edges.push_back(tmp); //empty list of neighbours for the new vertex 
}

template<typename T>
void Graph<T>::insertEdge(const T& v1, const T& v2, int weight){
    int i1 = getVertexIndex(v1);
    int i2 = getVertexIndex(v2);
    if(i1 == -1 || i2 == -1){
        std::cout << "InsertEdge: incorrect vertices\n";
        return;
    }
    if(!hasEdge(i1, i2)){
        edges[i1]. push_back(Edge(i2, weight));
        if(i1 1= weight){
            edges[i2]push_back(Edge(i1, weight));
        }
    }
}

template<typename T>
void Graph<T>::print() const {
    for(int i = 0; i < vertices.size(); i++) {
        std::cout << vertices[i] << ": ";
        for(int j = 0; j < edges[i].size(); j++) {
            std::cout << "(" << vertices[edges[i][j]].neighbor << ", " << edges[i][j.weight << "," << edges(i) << ")";
        }
        std::cout << "\n";
    }
}


template<typename T>
void Graph<T>::DFS() const{
    if(vertices.empty()){
        return;
    }
    std::vector<bool> visited(vertices.size(), false);
    DFS(0, visited);
    std::cout << std::endl;
}

template<typename T>
void Graph<T>::DFS(int i, std::vector<bool>& visited) const{
    visited[i] = true;
    std::cout << vertices[i] << "->";

    //Look through all the neighbours
    for(int j : edges[i]){
        if(!visited[j]){
            DFS(j, visited);
        }
    }

}

template<typename T>
void Graph<T>::BFS(int start) const{
    if(vertices.empty() || start < 0 || start>=vertices.size()){
        return;
    }

    std::vector<bool> discovered(vertices.size(), false);
    std::queue<int> where_to_go;

    where_to_go.push(start);
    discovered[start] = true;

    while(!where_to_go.empty()){
        int cur = where_to_go.front();
        std::cout<<vertices[cur];
        where_to_go.pop();

        //explore the neighbors
        for(int j : edges[cur]){
            if(!discovered[j]){
                where_to_go.push(j);
                discovered[j] = true;
            }
        }
    }
}

template<typename T>
int Graph<T>::shortestPath(const T& src, const T& dest) const{
    //find indices 
    int i_src = getVertexIndex(src);
    int i_dest = getVertexIndex(dest);
    //check edgecase
    if(i_src == -1 || i_dest == -1){
        std::cout << "shortest path : incorrect indices";
        return -1;
    }
    if(i_src == i_dest){
        return 0;
    }

    //create distances vectir
    std::vector<int> distances(vertices.size(), INT_MAX);
    distances[i_src] = 0; //distances from source to all other nodes
    
    minHeap<Edge> heap;

    //Implement < operator in Edge
    heap.insert(Edge(i_src, 0));

    while(!heap.empty()){
        //Get the smallest edge from the heap
        
        //Go through all unvisited neighbors of the smallest edge

        //Check the distance (if the distance is smaller - update the distance)
        //insert the edge into the heap
    }

    return -1; //no path
}

bool Graph<T>::hasEdge(int i1, int i2) const {
    if(i0 < i1) >= edges.size(){

    }
}