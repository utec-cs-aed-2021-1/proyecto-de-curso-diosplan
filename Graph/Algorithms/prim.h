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
struct Prim {
    UnDirectedGraph<TV, TE> *graph;
    string start;
    Prim(UnDirectedGraph<TV, TE> *graph, const string& start);
    UnDirectedGraph<TV, TE> apply();
};

template<typename TV, typename TE>
Prim<TV, TE>::Prim(UnDirectedGraph<TV, TE> *graph, const string& start) {
    if (!graph->findById(start)) throw invalid_argument("vertex is not on graph");

    this->graph = graph;
    this->start = start;
}

template<typename TV, typename TE>
UnDirectedGraph<TV, TE> Prim<TV, TE>::apply() {
    UnDirectedGraph<TV, TE> g;
    priority_queue<EPair<TV, TE>, std::vector<EPair<TV, TE>>, compPairs2<TV, TE>> pq;
    unordered_map<TV, unordered_map<TV, bool>> visited;


    g.insertVertex(graph->vertexes[start]->id, graph->vertexes[start]->data, graph->vertexes[start]->latitude, graph->vertexes[start]->longitude);
    pq.push(make_pair(nullptr, graph->vertexes[start]));

    for (auto x : graph->vertexes) {
        for (auto y : x.second->edges) {
            if (y->vertexes[1]->id == graph->vertexes[start]->id)
                visited[y->vertexes[1]->data][graph->vertexes[start]->data] = true;
        }
    }

    int i=1;
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();
        for (auto x : u.second->edges) {
            if (visited[u.second->data].count(x->vertexes[1]->data) == 0 && visited[x->vertexes[1]->data].count(u.second->data) == 0) {
                pq.push(make_pair(x, x->vertexes[1]));
                visited[u.second->data][x->vertexes[1]->data] = true;
                visited[x->vertexes[1]->data][u.second->data] = true;
            }
        }

        if (!pq.empty() && !g.areConnected(pq.top().first->vertexes[0]->id, pq.top().first->vertexes[1]->id)) {
            auto v = pq.top();
            g.insertVertex(v.second->id, v.second->data, v.second->latitude, v.second->longitude);
            g.createEdge(v.first->vertexes[0]->id, v.first->vertexes[1]->id, v.first->weight);
        }
    }

    return g;
}