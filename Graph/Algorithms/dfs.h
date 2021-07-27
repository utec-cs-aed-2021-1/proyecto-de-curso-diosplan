// depth first search
#include "../UndirectedGraph.h"
#include <stack>

template<typename TV, typename TE>
struct DFS {
    string src;
    UnDirectedGraph<TV, TE> *graph;
    UnDirectedGraph<TV, TE> gdfs;
    std::unordered_map<string, bool> v;
    DFS(UnDirectedGraph<TV, TE> *graph, string _src_);
    UnDirectedGraph<TV, TE> apply();
    void apply2(string id);
};

template<typename TV, typename TE>
DFS<TV, TE>::DFS(UnDirectedGraph<TV, TE> *_graph_, string _src_) {
    this->graph = _graph_;
    src = _src_;
}

template<typename TV, typename TE>
UnDirectedGraph<TV, TE> DFS<TV, TE>::apply() {
    int s = graph->vertexes.size();
    gdfs.clear();
    for (auto x : graph->vertexes) {
        v[x.second->id] = false; // Visitados
//        visited[x.first] = false; // Visitados
        gdfs.insertVertex(x.first , (x.second)->data, x.second->latitude, x.second->latitude);// Rellenar los vértices
    }
    apply2(src);
    return gdfs;
}


template<typename TV, typename TE>
void DFS<TV, TE>::apply2( string id) {
    v[id] = true;
    //recorro los hijos
    for (auto e : graph->vertexes[id]->edges){
        //nodo inicial, nodo final, peso
        //cout << e->vertexes[0]->id <<"  "<<e->vertexes[1]->id <<"  "<<e->weight << endl;
        //si un hijo no está visitado, le hago dfs al hijo
        if(!v[e->vertexes[1]->id]){
            gdfs.createEdge(e->vertexes[0]->id,e->vertexes[1]->id, e->weight);
            apply2(e->vertexes[1]->id);

        }
    }
}