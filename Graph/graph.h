#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <unordered_map>

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
    String id;
    std::list<Edge<TV, TE>*> edges;
    Vertex(TV data, String id){
        this->data = data;
        this->id = id;
    }
};

template<typename TV, typename TE>
class Graph{
private:    
    std::unordered_map<string, Vertex<TV, TE>*>  vertexes;
    unsigned int edges;
    
public:
    bool insertVertex(string id, TV vertex) = 0;   
    bool createEdge(string id1, string id2, TE w) = 0;     
    bool deleteVertex(string id) = 0;     
    bool deleteEdge(string id) = 0;   
    TE &operator()(string start, string end)= 0;  
    float density() = 0;
    bool isDense(float threshold = 0.5) = 0;
    bool isConnected()= 0;
    bool isStronglyConnected() throw();
    bool empty();
    void clear()= 0;  
      
    void displayVertex(string id)= 0;
    bool findById(string id) = 0;
    void display() = 0;
};

#endif