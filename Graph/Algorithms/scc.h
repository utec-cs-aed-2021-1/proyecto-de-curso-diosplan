//
// Created by jlr on 7/25/21.
//

#ifndef PROYECTO_DE_CURSO_DIOSPLAN_SCC_H
#define PROYECTO_DE_CURSO_DIOSPLAN_SCC_H

template<typename TV, typename TE>
struct SCC {
    DirectedGraph<TV, TE> *graph;
    SCC(DirectedGraph<TV, TE> *graph);
    void apply();
};


template<typename TV, typename TE>
SCC<TV, TE>::SCC(DirectedGraph<TV, TE> *_graph_) {
    this->graph = _graph_;
}

template<typename TV, typename TE>
void SCC<TV, TE>::apply() {
    unordered_map<Vertex<TV, TE>*, unordered_map<Vertex<TV, TE>*, bool>> m;
    for ( auto vertex : this->graph->vertexes )
    {
        unordered_map<Vertex<TV, TE>*, bool> hood;
        queue<Vertex<TV, TE>*> q;
        q.push(vertex.second);
        while ( !q.empty() )
        {
            auto u = q.front();
            q.pop();
            for (auto edge : u->edges)
            {
                if ( hood.count(edge->vertexes[1])==0 && edge->vertexes[1]->id != vertex.second->id )
                {
                    hood[edge->vertexes[1]] = true;
                    q.push(edge->vertexes[1]);
                }
            }
        }
        m[vertex.second] = hood;
    }

    for (auto x : m)
    {
        cout << x.first->data << ":\n";
        for (auto y : x.second)
        {
            cout << "\t" << y.first->data << " ";
        }
        cout << "\n";
    }


    vector<vector<Vertex<TV, TE>*>> Components;
    unordered_map<string, bool> visited;
    for (auto k : this->graph->vertexes)
        visited[k.first] = false;

    for (auto vertex : m)
    {
        vector<Vertex<TV, TE>*> Component;
        if ( !visited[vertex.first->id] )
        {
            Component.push_back(vertex.first);
            visited[vertex.first->id] = true;
            for (auto x : vertex.second)
            {
                if ( m[x.first].count(vertex.first) )
                {
                    Component.push_back(x.first);
                    visited[x.first->id] = true;
                }
            }
        }
        if (!Component.empty())
        {
            Components.push_back(Component);
        }
    }

    cout << "Components: " << Components.size() << "\n";
    for (auto x : Components)
    {
        for (auto y : x)
        {
            cout << y->data << " ";
        }
        cout << "\n";
    }
}


#endif //PROYECTO_DE_CURSO_DIOSPLAN_SCC_H
