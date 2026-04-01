#include "Graph.hpp"
#include<iostream>
#include<vector>

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
    std::vector<int> tmp;
    edges.push_back(tmp); //empty list of neighbours for the new vertex 
}

template<typename T>
void Graph<T>::insertEdge(const T& v1, const T& v2){
    int i1 = getVertexIndex(v1);
    int i2 = getVertexIndex(v2);
    if(i1 == -1 || i2 == -1){
        std::cout << "InsertEdge: incorrect vertices\n";
        return;
    }
    edges[i1].push_back(i2);
    if(i1 != i2){
        edges[i2].push_back(i1);
    }
}

template<typename T>
void Graph<T>::print() const {
    for(int i = 0; i < vertices.size(); i++) {
        std::cout << vertices[i] << ": ";
        for(int j = 0; j < edges[i].size(); j++) {
            std::cout << vertices[edges[i][j]] << " ";
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