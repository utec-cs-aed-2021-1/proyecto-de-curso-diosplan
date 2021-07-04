#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE>{
public:
    UnDirectedGraph();
    bool insertVertex(string id, TV vertex);
    bool createEdge(string id1, string id2, TE w);
    bool deleteVertex(string id);
    bool deleteEdge(string id1, string id2);
    TE operator()(string start, string end);
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
UnDirectedGraph<TV,TE>::UnDirectedGraph() {
    this->edges = 0;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::insertVertex(string id, TV vertex) {
    if(!findById(id)) {
        Vertex<TV, TE> *v = new Vertex<TV, TE>(vertex, id);
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
    if(findById(id)) {
        for (auto i : this->vertexes) {
            deleteEdge(i.first, id);
        }
        this->vertexes.erase(id);
        return true;
    }
    return false;
}
/////////////u.u
template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdge(string start, string end) {
    if (findById(start) && findById(end)) {
        for (auto i = this->vertexes[start]->edges.begin(); i != this->vertexes[start]->edges.end();){
            if ((*i)->vertexes[1] == this->vertexes[end]) {
                this->vertexes[start]->edges.erase(i++);
                this->edges--;
            }
            else{
                i++;
            }
        }
        for (auto j = this->vertexes[end]->edges.begin(); j != this->vertexes[end]->edges.end();){
            if ((*j)->vertexes[1] == this->vertexes[start]) {
                this->vertexes[end]->edges.erase(j++);
            }
            else {
                j++;
            }
        }
        return true;
    }
    return false;
}
//////////////u.u
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
    auto id = this->vertexes.begin()->first;
    std::unordered_map<TV, bool> visited;
    std::queue<Vertex<TV, TE> *> q;
    for (auto it : this->vertexes) // set all nodes as not visited
        visited[(it.second)->data] = false;
    visited[this->vertexes[id]->data] = true; //visits
    q.push(this->vertexes[id]);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto it : u->edges) {
            // if not visited, add to q
            if (visited[(it->vertexes)[1]->data] == false) {
                q.push((it->vertexes)[1]);
                visited[(it->vertexes)[1]->data] = true;
            }
        }
    }
    // x = each element in visited
    return (std::all_of(visited.begin(), visited.end(), [](auto x) { return x.second; }));
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
    cout << this->vertexes[id]->data << " :: ";
    for (auto const& j : this->vertexes[id]->edges) {
        cout << j->vertexes[1]->data << "[" << j->weight << "] ";
    }
    cout << endl;
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
    for (auto i : this->vertexes) {
        cout << i.second->data << " :: ";
        for (auto j : i.second->edges) {
            cout << j->vertexes[1]->data << "[" << j->weight << "] ";
        }
        cout << endl;
    }
}

#endif