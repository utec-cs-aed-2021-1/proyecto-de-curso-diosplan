#include "../UndirectedGraph.h"

template<typename TV, typename TE>
struct Kruskal {
    UnDirectedGraph<TV, TE> *graph;
    Kruskal(UnDirectedGraph<TV, TE> *graph);
    UnDirectedGraph<TV, TE> apply();
};

template<typename TV, typename TE>
struct compWeight {
    bool operator()(const Edge<TV, TE>* e1, const Edge<TV, TE>* e2) const
    {
        return e1->weight > e2->weight;
    }
};

template<typename TV, typename TE>
Kruskal<TV, TE>::Kruskal(UnDirectedGraph<TV, TE> *_graph_) {
    this->graph = _graph_;
}

template<typename TV, typename TE>
UnDirectedGraph<TV, TE> Kruskal<TV, TE>::apply() {
    std::priority_queue<Edge<TV, TE>*, std::vector<Edge<TV, TE>*>, compWeight<TV, TE>> pq;
    std::unordered_map<TV, std::pair<std::unordered_map<TV, int>, string>> visited;  // Para evitar que las aristas se marquen doble (A<->B == B<->A)
    UnDirectedGraph<TV, TE> g;      // Grafo para retornar

    for (auto it1 : graph->vertexes) {
        g.insertVertex2(it1.first , (it1.second)->data);
        visited[it1.second->data].second = it1.first;
        for (auto it2 : (it1.second)->edges) {
            if (visited[it1.second->data].first.count(it2->vertexes[1]->data) == 0 && visited[it2->vertexes[1]->data].first.count(it1.second->data) == 0) {
                pq.push(it2);
                (visited[it1.second->data].first)[it2->vertexes[1]->data] = 1;
                (visited[it2->vertexes[1]->data].first)[it1.second->data] = 1;
            }
        }
    }

    while (!pq.empty()) {
        string id1 = visited[pq.top()->vertexes[0]->data].second;
        string id2 = visited[pq.top()->vertexes[1]->data].second;
        if (!g.areConnected(id1, id2)) {
            g.createEdge(id1, id2, pq.top()->weight);
        }
        pq.pop();
    }

    return g;

}