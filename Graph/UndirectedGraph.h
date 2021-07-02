#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE>{
    UnDirectedGraph();
    bool insertVertex(string id, TV vertex);
    bool createEdge(string id1, string id2, TE w);
    bool deleteVertex(string id);
    bool deleteEdge(string id);
    TE &operator()(string start, string end);
    float density();
    bool isDense(float threshold = 0.5);
    bool isConnected();
    bool empty();
    void clear();

    void displayVertex(string id);
    bool findById(string id);
    void display();
};

template<typename TV, typename TE>
UnDirectedGraph<TV,TE>::UnDirectedGraph<typename TV, typename TE>() {
    this->edges = 0;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    if(!findById(id)) {
        Vertex<TV, TE> *v = new Vertex<TV, TE>(string id, TV vertex);
        this->vertexes[id] = v;
        return true;
    }
    return false;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w) {
    if (findById(id1) && findById(id2)) {
        for (auto it : this->vertexes[id1]->edges) {
            if (it->vertexes[1]->data == this->vertexes[id2]->data){
                return false;
            }
        }
        Edge<TV, TE> *edge1 = new Edge<TV, TE>(this->vertexes[id1], this->vertexes[id2], w);
        this->vertexes[id1]->edges.push_back(edge1);
        Edge<TV, TE> *edge2 = new Edge<TV, TE>(this->vertexes[id2], this->vertexes[id1], w);
        this->vertexes[id1]->edges.push_back(edge2);
        this->edges++;
        return true;
    }
    return false;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteVertex(string id) {

}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdge(string id) {

}

template<typename TV, typename TE>
TE UnDirectedGraph<TV, TE>::operator()(string start, string end) {
    if(this->vertexes.count(start) == 0 || this->vertexes.count(end) == 0) {
        return numeric_limits<TE>::min();
    }
    for (auto i : this->vertexes[start]->edges) {
        if (i -> vertexes[1] == this->vertexes[end]) {
            return i->weight;
        }
    }
    return numeric_limits<TE>::min();
}

template<typename TV, typename TE>
float UnDirectedGraph<TV, TE>::density() {
    return (2.0 * this->edges) / (this->vertexes.size() * (this->vertexes.size() - 1));
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isDense(float threshold) {
    return density() >= threshold;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isConnected() {

}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::empty() {
    return this->vertexes.size() != 0;
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::clear() {
    this->vertexes.clear();
    this->edges = 0;
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::displayVertex(string id) {
    if(this->vertexes.find(id) == this->vertexes.end()) {
        return false;
    }
    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::findById(string id) {
    if (this->vertexes.find(id) == this->vertexes.end()) {
        return false;
    }
    return true;
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::display() {

}

#endif