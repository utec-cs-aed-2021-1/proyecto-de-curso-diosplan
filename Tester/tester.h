//
// Created by jlr on 7/2/21.
//

#ifndef PROYECTO_DE_CURSO_DIOSPLAN_TESTER_H
#define PROYECTO_DE_CURSO_DIOSPLAN_TESTER_H

#include "../Graph/DirectedGraph.h"
#include "../Graph/Algorithms/dijkstra.h"
#include "../Graph/UndirectedGraph.h"
#include "../Parser/parser.h"
using namespace std;
struct Tester{
    //static void executeExamples();
    static void executeParser(string path);
};
/*
void Tester::executeExamples(){
    cout << "------------------------------------------------" << endl;
    cout << "|               Directed  Graph                |" << endl;
    cout << "------------------------------------------------" << endl;

    DirectedGraph<char, int> graph1;
    graph1.insertVertex("1", 'A');
    graph1.insertVertex("2", 'B');
    graph1.insertVertex("3", 'C');
    graph1.insertVertex("4", 'D');
    graph1.insertVertex("5", 'E');

    graph1.createEdge("1", "2", 10);
    graph1.createEdge("1", "3", 5);
    graph1.createEdge("3", "4", 15);
    graph1.createEdge("2", "4", 20);
    graph1.createEdge("1", "4", 12);
    graph1.createEdge("2", "5", 25);
    graph1.createEdge("4", "5", 30);

    graph1.display();

    cout << "|              DGraph Methods               |" << endl;
    if(graph1.isConnected()) {
        cout << "is Connected!!" << endl;
    } else {
        cout << "isn't Connected!!" << endl;
    }
    if(graph1.isStronglyConnected()) {
        cout << "is StronglyConnected!!" << endl;
    } else {
        cout << "isn't StronglyConnected!!" << endl;
    }
    cout << "------------------------------------------------" << endl;
    cout << "|              Undirected  Graph               |" << endl;
    cout << "------------------------------------------------" << endl;

    UnDirectedGraph<char, int> graph2;
    graph2.insertVertex("1", 'A');
    graph2.insertVertex("2", 'B');
    graph2.insertVertex("3", 'C');
    graph2.insertVertex("4", 'D');
    graph2.insertVertex("5", 'E');

    graph2.createEdge("1", "2", 10);
    graph2.createEdge("1", "3", 5);
    graph2.createEdge("3", "4", 15);
    graph2.createEdge("2", "4", 20);
    graph2.createEdge("1", "4", 12);
    graph2.createEdge("2", "5", 25);
    graph2.createEdge("4", "5", 30);

    graph2.display(); cout << endl;
}
*/
void Tester::executeParser(string path){
    Parser parser;
    parser.readJSON(path);
    DirectedGraph<string, double> d1graph;
    parser.dGraphMake(d1graph);

    cout<<"Probando Métodos:"<<endl;
    // probando operador ()
    auto A = d1graph("2808","2812");
    cout<<"Operador (): "<<A<<endl;

    // probando densidad
    float D = d1graph.density();
    cout<<"Densidad: "<<D<<endl;


    // probando isDense, isConnected, empty
    bool dense = d1graph.isDense();
    if(dense) {cout << "Dense!" << endl;} else {cout << "No Dense!" << endl;}

    bool connected = d1graph.isConnected();
    if(connected) {cout << "Connected!" << endl;} else {cout << "No Connected!" << endl;}

    bool stronglyConnected = d1graph.isStronglyConnected();
    if(stronglyConnected) {cout << "Is Strongly Connected!" << endl;} else {cout << "No Connected!" << endl;}

    bool empty = d1graph.empty();
    if(empty) {cout << "Empty !" << endl;} else {cout << "No Empty!" << endl;}


    cout<<"\nDijkstra:\n";
    UnDirectedGraph<string, double> u2graph;
    parser.uGraphMake(u2graph);
    Dijkstra<string, double> Djks(&u2graph, "2796");
    Djks.apply();
}

#endif //PROYECTO_DE_CURSO_DIOSPLAN_TESTER_H
