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
UnDirectedGraph<TV, TE> BFS<TV, TE>::aplicar(string source)
{
    
}