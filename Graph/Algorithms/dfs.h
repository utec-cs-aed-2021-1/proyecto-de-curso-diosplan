// depth first search
#include "../UndirectedGraph.h"
using namespace std;

template<typename TV, typename TE>
struct DFS
{
    string source;
    UnDirectedGraph<TV, TE> *grafo;
    DFS(UnDirectedGraph<TV, TE> *grafo_, string source_);
    UnDirectedGraph<TV, TE> aplicar();
};

template<typename TV, typename TE>
DFS<TV, TE>::DFS(UnDirectedGraph<TV, TE> *grafo_, string source_)
{
    this->grafo = grafo_;
    source = source_;
}