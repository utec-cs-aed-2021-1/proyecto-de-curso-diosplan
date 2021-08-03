//
// Created by jlr on 8/1/21.
//

#ifndef PROYECTO_DE_CURSO_DIOSPLAN_BBFS_H
#define PROYECTO_DE_CURSO_DIOSPLAN_BBFS_H

#include "../UndirectedGraph.h"
#include "map"

//template <typename TV, typename TE>
using PQNode = pair<double, pair<string, string>>;  // current weight <nodo src, nodo father>.

struct compPQNodes{
    bool operator()(const PQNode v1, const PQNode v2) const {
        return v1.first > v2.first;
    }
};

template<typename TV, typename TE>
struct BBFS{
    UnDirectedGraph<TV,TE>* grafo;
    BBFS(UnDirectedGraph<TV,TE>* graph);//, const string& start);
    void apply(string source, string target);
};

template<typename TV, typename TE>
BBFS<TV, TE>::BBFS(UnDirectedGraph<TV, TE> *graph) {
    this->grafo = graph;
}

template<typename TV, typename TE>
void BBFS<TV, TE>::apply(string source, string target) {
    std::priority_queue<PQNode,std::vector<PQNode>, compPQNodes> Q;
    // de nodo y padre (nodo del que vino)
    std::map<string, string> m;

    std::unordered_map<string, bool> visitados;
    for (auto i : this->grafo->vertexes){
        visitados[i.first] = false;
    }
    visitados[source] = true;
    if (this->grafo->findById(source)){
        Q.push(make_pair(0,make_pair(source,"")));
    }
    while (!Q.empty()){
        auto temp = Q.top();
        auto weight = temp.first;
        auto current = temp.second.first;
        auto dad = temp.second.second;
//        cout << current <<" " <<weight<< endl;
        m[current] = dad;
        Q.pop();
        if (current == target) break;
        for (auto j : this->grafo->vertexes[current]->edges){
            if (visitados[j->vertexes[1]->id] == false){
                Q.push(make_pair(weight+j->weight, make_pair(j->vertexes[1]->id, current))); //curent = j->vertexes[0]
//                cout <<"\t"<< j->vertexes[1]->id <<" " <<weight+j->weight<< endl;
                visitados[j->vertexes[1]->id] = true;
            }
        }
    }
    auto t = target;
    vector<string> rev;
    while (t != ""){
        rev.push_back(t);
        t = m[t];
    }
    for(int i=rev.size()-1; i>=0;i--){
        // cambiar por data o id, acorde qué se quiera mostrar.
        cout << this->grafo->vertexes[rev[i]]->data;
        if(i) cout<<" -> ";
    }cout<<endl;
}

#endif //PROYECTO_DE_CURSO_DIOSPLAN_BBFS_H
