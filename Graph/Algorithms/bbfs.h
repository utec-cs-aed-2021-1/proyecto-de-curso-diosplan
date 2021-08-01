//
// Created by jlr on 8/1/21.
//

#ifndef PROYECTO_DE_CURSO_DIOSPLAN_BBFS_H
#define PROYECTO_DE_CURSO_DIOSPLAN_BBFS_H

#include "../UndirectedGraph.h"

template <typename TV, typename TE>
using EPair = pair<Edge<TV, TE>*, Vertex<TV, TE>*>;

template<typename TV, typename TE>
struct compPairs2{
    bool operator()(const EPair<TV, TE> p1, const EPair<TV, TE> p2) const {
        return p1.first->weight > p2.first->weight;
    }
};

template<typename TV, typename TE>
struct BBFS{
    UnDirectedGraph<TV,TE>* graph;
    string start;
    BBFS(UnDirectedGraph<TV,TE>* graph, const string& start);
    void apply();
};

template<typename TV, typename TE>
BBFS<TV, TE>::BBFS(UnDirectedGraph<TV, TE> *graph, const string &start) {
    if (!graph->findById(start)) throw invalid_argument("vertex is not on graph");

    this->graph = graph;
    this->start = start;
}

template<typename TV, typename TE>
void BBFS<TV, TE>::apply() {
    std::priority_queue<EPair<TV,TE>, std::vector<EPair<TV, TE>>,compPairs2<TV,TE>> pq;
    unordered_map<TV, unordered_map<TV, bool>> visited;

    // TODO: BFS CON PRIORITY QUEUEUE

}

#endif //PROYECTO_DE_CURSO_DIOSPLAN_BBFS_H
