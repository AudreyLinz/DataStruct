#include "Graph.hpp"
#include<iostream>
#include<vector>
#include<queue>

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

    //create distances vector
    std::vector<int> distances(vertices.size()); //distances from source to all other nodes
    //set initial distances
    for(int i = 0; i<distances.size(); i++){
        distances[i] = (i==i_src) ? 0: -1;
    }
    //Perform BFS and update distances
    std::queue<int> q;
    q.push(i_src);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        //check the neighbors of cur node
        for(int i : edges[cur]){
            if(distances[i] == -1){
                distances[i] = distances[cur] + 1;
                q.push(i);
            }
            if(i == i_dest){
                return distances[i];
            }
        }
    }
    return -1; //no path
}

template <typename T>
int Graph<T>::countConnectedComponents() const {
    // 1. Keep track of who we've seen
    std::vector<bool> visited(vertices.size(), false);
    int count = 0;

    // 2. Iterate through every single vertex in the graph
    for (int i = 0; i < vertices.size(); i++) {
        
        // 3. If we haven't visited this vertex, we've found a new "island"
        if (!visited[i]) {
            count++;
            
            // 4. Use your existing DFS helper to mark EVERY vertex 
            // reachable from 'i' as visited.
            DFS(i, visited); 
        }
    }

    return count;
}

template <typename T>
bool Graph<T>::isCompleteGraph() const {
    int n = vertices.size();
    if (n <= 1) return true; // Handled edge case

    // Loop through every vertex's edge list
    for (int i = 0; i < n; i++) {
        // A vertex in a complete graph must have exactly n-1 neighbors
        if (edges[i].size() != (n - 1)) {
            return false; // Found someone who hasn't shaken everyone's hand!
        }
    }

    return true; // Everyone is connected to everyone else
}