// depth first search
#include "../UndirectedGraph.h"
#include <stack>

template<typename TV, typename TE>
struct DFS {
    string src;
    UnDirectedGraph<TV, TE> *graph;
    DFS(UnDirectedGraph<TV, TE> *graph, string _src_);
    UnDirectedGraph<TV, TE> apply();
};


template <typename TV, typename TE>
using EPair = pair<Edge<TV, TE>*, Vertex<TV, TE>*>;

template<typename TV, typename TE>
struct compPairs2{
    bool operator()(const EPair<TV, TE> p1, const EPair<TV, TE> p2) const {
        return p1.first->weight > p2.first->weight;
    }
};

template<typename TV, typename TE>
DFS<TV, TE>::DFS(UnDirectedGraph<TV, TE> *_graph_, string _src_) {
    this->graph = _graph_;
    src = _src_;
}

template<typename TV, typename TE>
UnDirectedGraph<TV, TE> DFS<TV, TE>::apply() {
    UnDirectedGraph<TV, TE> g;
    int s = graph->vertexes.size();
    std::stack<EPair<TV, TE>> S;
    std::unordered_map<TV, std::pair<bool, string>> visited;
    for (auto x : graph->vertexes) {
        visited[x.second->id].first = false;          // Visitados
        visited[x.second->id].second = x.first;       // id
        g.insertVertex(x.first , (x.second)->data, x.second->latitude, x.second->latitude);     // Rellenar los vértices
    }

    visited[graph->vertexes[src]->id].first = true;
    S.push(make_pair(nullptr, graph->vertexes[src]));

    while(!S.empty()) {
        Vertex<TV, TE>* v = S.top().second;
        S.pop();
        priority_queue<EPair<TV, TE>, std::vector<EPair<TV, TE>>, compPairs2<TV, TE>> pq;
        for (auto unions : v->edges) {
            pq.push(make_pair(unions, unions->vertexes[1]));
        }

        while ( !pq.empty() ) {
            if (!visited[pq.top().second->id].first) {
                S.push(pq.top());
            }
            pq.pop();
        }

        if ( !S.empty() ) {
            EPair<TV, TE> u = S.top();
            if (!visited[u.first->vertexes[1]->id].first) {
                g.createEdge(u.first->vertexes[0]->id, u.first->vertexes[1]->id, u.first->weight);
                visited[u.first->vertexes[0]->id].first = true;
                visited[u.first->vertexes[1]->id].first = true;
            }
        }
    }
    return g;
}