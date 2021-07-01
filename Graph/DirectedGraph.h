#ifndef NONDIRECTEDGRAPH_H
#define NONDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class DirectedGraph : public Graph<TV, TE>{
    DirectedGraph();
    bool insertVertex(string id, TV vertex);
    bool createEdge(string id1, string id2, TE w);
    bool deleteVertex(string id);
    bool deleteEdge(string id);
    TE &operator()(string start, string end);
    float density();
    bool isDense(float threshold = 0.5);
    bool isConnected();
    bool isStronglyConnected() throw();
    bool empty();
    void clear();

    void displayVertex(string id);
    bool findById(string id);
    void display();
};

template<typename TV, typename TE>
DirectedGraph<TV, TE>::DirectedGraph() {
    this->edges = 0;
}

template<typename TV, typename TE>
bool DirectedGraph<TV,TE>::insertVertex(string id, TV vertex){
    if (this->vertexes.count(id) == 0) {
        Vertex<TV, TE>* v = new Vertex<TV,TE>(vertex,id);
        this->vertexes[id] = v;
        return true;
    }
    return false;
}

template<typename TV, typename TE>
bool DirectedGraph<TV,TE>::createEdge(string id1, string id2, TE w) {
    if (this->vertexes.count(id1) && this->vertexes.count(id2)){
        Edge<TV, TE>* e = new Edge<TV, TE>(this->vertexes[id1], this->vertexes[id2], w);
        this->vertexes[id1]->edges.push_back(e);
        this->edges++;
        return true;
    }
    return false;
}

template<typename TV, typename TE>
bool DirectedGraph<TV,TE>::deleteVertex(string id) {

}

template<typename TV, typename TE>
bool DirectedGraph<TV,TE>::deleteEdge(string id) {

}

template<typename TV, typename TE>
TE DirectedGraph<TV,TE>::operator()(string start, string end){

}

template<typename TV, typename TE>
float DirectedGraph<TV,TE>::density() {
    return (1.0 * this->edges) / (this->vertexes.size() * (this->vertexes.size() - 1));
}

template<typename TV, typename TE>
bool DirectedGraph<TV,TE>::isDense(float threshold) {
    return density() >= threshold;
}

template<typename TV, typename TE>
bool DirectedGraph<TV,TE>::isConnected() {

}

template<typename TV, typename TE>
bool DirectedGraph<TV,TE>::isStronglyConnected() throw() {

}

template<typename TV, typename TE>
bool DirectedGraph<TV,TE>::empty() {
    return this->vertexes.size() == 0;
}

template<typename TV, typename TE>
void DirectedGraph<TV,TE>::clear() {
    this->vertexes.clear();
    this->edges = 0;
}

template<typename TV, typename TE>
void DirectedGraph<TV,TE>::displayVertex(string id) {

}

template<typename TV, typename TE>
bool DirectedGraph<TV,TE>::findById(string id) {
    if (this->vertexes.find(id) == this->vertexes.end())
        return false;
    return true;
}


template<typename TV, typename TE>
void DirectedGraph<TV,TE>::display() {

}

#endif