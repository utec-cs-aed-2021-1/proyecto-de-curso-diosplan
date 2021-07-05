#include "../UndirectedGraph.h"

template<typename TE>
bool compWeightP(pair<string, TE> p1, pair<string, TE> p2) {
    TE temp1 = p1.second;
    TE temp2 = p2.second;
    if (temp1 == -1) {
        temp1 = temp2 + 1;
    }
    else if (temp2 == -1) {
        temp2 = temp1 + 1;
    }
    return temp1 > temp2;
}

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
    priority_queue<pair<TV, TE>, std::vector<pair<TV, TE>>, compPairs<TV, TE>> pq;
    unordered_map<TV, unordered_map<TV, bool>> visited;


    g.insertVertex(graph->vertexes[start]->key, graph->vertexes[start]->data, graph->vertexes[start]->latitud, graph->vertexes[start]->longitud);
    pq.push(make_pair(nullptr, graph->vertexes[start]));

    for (auto x : graph->vertexes) {
        for (auto y : x.second->edges) {
            if (y->vertexes[1]->key == graph->vertexes[start]->key)
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

        if (!pq.empty() && !g.areConnected(pq.top().first->vertexes[0]->key, pq.top().first->vertexes[1]->key)) {
            auto v = pq.top();
            g.insertVertex(v.second->key, v.second->data, v.second->latitud, v.second->longitud);
            g.createEdge(v.first->vertexes[0]->key, v.first->vertexes[1]->key, v.first->weight);
        }
    }

    return g;
}