#include "../UndirectedGraph.h"
#include <limits>
#define INF numeric_limits<int>::max()

template<typename TV, typename TE>
struct Dijkstra {
    string init;
    UnDirectedGraph<TV, TE> *graph;
    Dijkstra(UnDirectedGraph<TV, TE> *graph, string init);
    unordered_map<string, TE> apply();
};

template<typename TV, typename TE>
struct compPairs{
    bool operator()(const pair<TV, TE> p, const pair<TV, TE> q) const {
        return p.second > q.second;
    }
};

template<typename TV, typename TE>
Dijkstra<TV, TE>::Dijkstra(UnDirectedGraph<TV, TE> *graph, string init) {
    this->graph = graph;
    this->init = init;
}

template<typename TV, typename TE>
unordered_map<string, TE> Dijkstra<TV, TE>::apply() {
    priority_queue< pair<TV, TE>, std::vector<pair<TV, TE>>, compPairs<TV, TE> > pq;
    unordered_map<TV, TE> dist;
    // mark all vertexes as not visited
    for (auto it : graph->vertexes) {
        dist[it.first] = INF;
    }
    // visit source / init
    dist[this->init] = 0;
    // push init to queue
    pq.push(make_pair(this->init, 0));

    while ( !pq.empty() ) {
        string u = pq.top().first;
        double d = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;
        // traverse all u's edges
        for (auto it : graph->vertexes[u]->edges) {
            string v = it->vertexes[1]->id;
            TE weight = it->weight;
            //exists a path and dist is lower
            if ( dist.count(v) && dist[v] > dist[u] + weight ) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }

    cout << "\nPrint Dijkstra:\n";
    for (auto x : dist) {
        cout << this->graph->vertexes[x.first]->data << ": " << x.second << endl;
    }

    return dist;
}