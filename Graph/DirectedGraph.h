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
    if(findById(id)) {
        for (auto i : this->vertexes) {
            deleteEdge(i.first, id);
        }
        this->vertexes.erase(id);
        return true;
    }
    return false;
}

template<typename TV, typename TE>
bool DirectedGraph<TV,TE>::deleteEdge(string id) {
    if (findById(start) && findById(end) {
        for (auto i = this->vertexes[start]->edges.begin(); i != this->vertexes[start]->edges.end();) {
            if ((*i)->vertexes[1] == this->vertexes[end]) {
                this->vertexes[start]->edges.erase(i++);
                this->edges--;
            }
            else i++;
        }
        return true;
    }
    return false;
}

template<typename TV, typename TE>
TE DirectedGraph<TV,TE>::operator()(string start, string end){
    if(this->vertexes.count(start) == 0 || this->vertexes.count(end) == 0) {
        return numeric_limits<TE>::min();
    }
    for (auto i : this->vertexes[end]){
        return i->weight;
    }
    return numeric_limits<TE>::min();
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
    cout << this->vertexes[id]->data << " :: ";
    for (auto const& j : this->vertexes[id]->edges){
        cout << j->vertexes[1]->data << "(" << j->weight << ") ";
    }
    cout << endl;
}

template<typename TV, typename TE>
bool DirectedGraph<TV,TE>::findById(string id) {
    if (this->vertexes.find(id) == this->vertexes.end())
        return false;
    return true;
}


template<typename TV, typename TE>
void DirectedGraph<TV,TE>::display() {
    for (auto i : this->vertexes) {
        cout << i.second->data << " :: ";
        for (auto j : i.second->edges) {
            cout << j->vertexes[1]->data << "(" << j->weight << ") ";
        }
        cout << endl;
    }
}

#endif