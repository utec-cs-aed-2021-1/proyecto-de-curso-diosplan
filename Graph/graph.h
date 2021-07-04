#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

template<typename TV, typename TE>
struct Edge;

template<typename TV, typename TE>
struct Vertex;

template<typename TV, typename TE>
class Graph;

//////////////////////////////////////////////////////

template<typename TV, typename TE>
struct Edge {
    Vertex<TV, TE>* vertexes[2];
    TE weight;
    Edge(Vertex<TV, TE>* vertex1, Vertex<TV, TE>* vertex2, TE weight){
        this->weight = weight;
        this->vertexes[0] = vertex1;
        this->vertexes[1] = vertex2;
    }
};

template<typename TV, typename TE>
struct Vertex {
    TV data;
    string id;
    double latitude = 0;
    double longitude = 0;
    std::list<Edge<TV, TE>*> edges;
    Vertex(TV data, string id, double latitude = 0, double longitude = 0){
        this->data = data;
        this->id = id;
        this->latitude = latitude;
        this->longitude = longitude;
    }
};

template<typename TV, typename TE>
struct Dijkstra;

template<typename TV, typename TE>
class Graph{
protected:
    std::unordered_map<string, Vertex<TV, TE>*>  vertexes;
    unsigned int edges;

    friend struct Dijkstra<TV, TE>;
    
public:
    virtual bool insertVertex(string id, TV vertex, double lat = 0, double lon = 0) = 0;
    virtual bool createEdge(string id1, string id2, TE w) = 0;
    virtual bool deleteVertex(string id) = 0;
    virtual bool deleteEdge(string id1, string id2) = 0;
    virtual TE operator()(string start, string end)= 0;
    virtual float density() = 0;
    virtual bool isDense(float threshold = 0.5) = 0;
    virtual bool isConnected()= 0;
//    virtual bool isStronglyConnected() throw() = 0;
    virtual bool empty() = 0;
    virtual void clear() = 0;

    virtual void displayVertex(string id)= 0;
    virtual bool findById(string id) = 0;
    virtual void display() = 0;

    virtual pair<double,double> getPositionById(string id)=0;
};

#endif