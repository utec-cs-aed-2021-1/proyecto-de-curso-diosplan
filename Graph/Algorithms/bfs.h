// breadth first search

#include "../UndirectedGraph.h"

template<typename TV, typename TE>
struct BFS
{
    UnDirectedGraph<TV, TE> *grafo;
    BFS(UnDirectedGraph<TV, TE> *grafo_);
    UnDirectedGraph<TV, TE> aplicar(string source);
};

template<typename TV, typename TE>
BFS<TV, TE>::BFS(UnDirectedGraph<TV, TE> *grafo_)
{
    this->grafo = grafo_;
}

template<typename TV, typename TE>
UnDirectedGraph<TV, TE> BFS<TV, TE>::aplicar(string source) {
    UnDirectedGraph<TV, TE> result;
    std::queue<Vertex<TV, TE>*> Q;
    std::unordered_map<TV, std::pair<bool, string>> visitados;
    for (auto i : this->grafo->vertexes)
    {
        visitados[i.second->data].first = false;
        visitados[i.second->data].second = i.first;
        result.insertVertex(i.first, i.second->data);
    }
    visitados[this->grafo->vertexes.begin()->second->data].first = true;
    if (this->grafo->findById(source))
    {
        Q.push(this->graph->vertexes[source]);
    }
    while (!Q.empty())
    {
        auto temp = Q.front();
        Q.pop();
        for (auto j : temp->edges)
        {
            if (visitados[j->vertexes[1]->data].first == false)
            {
                Q.push(j->vertexes[1]);
                visitados[j->vertexes[1]->data].first = true;
                result.createEdge(visitados[j->vertexes[0]->data].second, visitados[j->vertexes[1]->data].second, j->weight);
            }
        }
    }

    return result;
}