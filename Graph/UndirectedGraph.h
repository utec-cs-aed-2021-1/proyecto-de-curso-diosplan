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

}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::createEdge(string id1, string id2, TE w) {

}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteVertex(string id) {

}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdge(string id) {

}

template<typename TV, typename TE>
TE UnDirectedGraph<TV, TE>::operator()(string start, string end) {

}

template<typename TV, typename TE>
float UnDirectedGraph<TV, TE>::density() {

}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isDense(float threshold) {

}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::isConnected() {

}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::empty() {

}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::clear() {

}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::displayVertex(string id) {

}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::findById(string id) {

}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::display() {

}

#endif