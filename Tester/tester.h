//
// Created by jlr on 7/2/21.
//

#ifndef PROYECTO_DE_CURSO_DIOSPLAN_TESTER_H
#define PROYECTO_DE_CURSO_DIOSPLAN_TESTER_H

#include "../Graph/DirectedGraph.h"
#include "../Graph/UndirectedGraph.h"
#include "../Graph/Algorithms/dijkstra.h"
#include "../Graph/Algorithms/astar.h"
#include "../Graph/Algorithms/dfs.h"
#include "../Graph/Algorithms/bfs.h"
#include "../Graph/Algorithms/kruskal.h"
#include "../Graph/Algorithms/prim.h"
#include "../Graph/Algorithms/floyd.h"
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
    Parser parser, parser2, parser3;
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


    parser2.readJSON(path);
    UnDirectedGraph<string, double> u1graph;
    parser.uGraphMake(u1graph);


    cout << "------------------------------------------------" << endl;
    cout << "|               Tests Algorithms               |" << endl;
    cout << "------------------------------------------------" << endl;

//    cout<<"\nDFS:\n";
//    DFS<string, double> dfs(&u1graph, "2796");
//    auto m = dfs.apply();
//    m.display();

//    cout<<"\nBFS:\n";
//    BFS<string, double> bfs(&u1graph);
//    auto g=bfs.apply("2796");
//    g.display();

//    cout<<"\nDijkstra:\n";
//    parser.uGraphMake(u2graph);
//    Dijkstra<string, double> Djks(&u2graph, "2796");
//    Djks.apply();
//
//    cout << "\nA Asterisk ( A* ): \n";
//    Astar<string, double> a(&u2graph, "2812","2807");
//    a.print();

//    cout<<"Probando Kruskal: "<<endl;
//    UnDirectedGraph<string, double> u1graph2;
//    parser3.readJSON(path);
//
//    parser3.uGraphMake(u1graph2);
//
//    Kruskal<string, double> kruskal(&u1graph2);
//    UnDirectedGraph<string, double> result3 = kruskal.apply();
//
//    cout<<endl;
//    result3.display();


//    cout << endl <<"Probando Prim" << endl;
//    Prim<string, double> prim(&u1graph, "2796");
//    UnDirectedGraph<string, double> result4 = prim.apply();
//    cout<<endl;
//    result4.display();

    cout << "FLOYD TESTS: \n";
    Floyd<string, double> floyd(&u1graph);
//    floyd.print(); //imprime la matriz de adyacencia
u1graph.display();
cout<<"Distancia entre 2812 y 2807: "<<floyd.distance("2812","2807");
    cout<<endl;
    cout<<"PATH:   ";
    floyd.showpath("2812","2807");
    cout<<endl;


}

#endif //PROYECTO_DE_CURSO_DIOSPLAN_TESTER_H
