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
#include "../Graph/Algorithms/bellman.h"
#include "../Graph/Algorithms/bbfs.h"
#include "../Parser/parser.h"

using namespace std;

struct Tester{
    static void executeExamples();
    static void executeParserPeru(string path);
    static void executeParserMundo(string path);
};
void Tester::executeExamples(){
    cout << "------------------------------------------------" << endl;
    cout << "|               Directed  Graph                |" << endl;
    cout << "------------------------------------------------" << endl;

    DirectedGraph<char, int> graph1;
    graph1.insertVertex2("1", 'A');
    graph1.insertVertex2("2", 'B');
    graph1.insertVertex2("3", 'C');
    graph1.insertVertex2("4", 'D');
    graph1.insertVertex2("5", 'E');

    graph1.createEdge("1", "2", 10);
    graph1.createEdge("1", "3", 5);
    graph1.createEdge("3", "4", 15);
    graph1.createEdge("2", "4", 20);
    graph1.createEdge("1", "4", 12);
    graph1.createEdge("2", "5", 25);
    graph1.createEdge("4", "5", 30);

    graph1.display();

    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "|              DGraph Methods               |" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;

    cout<< "Densidad: " << graph1.density() << endl;

    cout << "¿El grafo es denso?   ";
    if (graph1.isDense(0.6)) cout << "Sí, es grafo denso." <<endl;
    else cout << "No, el grafo no es denso." << endl;

    cout << "¿El grafo es conexo?   ";
    if(graph1.isConnected()) cout << "Es grafo conexo!!" << endl;
    else cout << "No es conexo!!" << endl;

    cout << "¿Está el vértice 4 en el grafo?   ";
    if(graph1.findById("4")) cout << "Sí!!" << endl;
    else cout << "NO!!" << endl;

    cout << "Vertex 4: ";
    graph1.displayVertex("4");

    cout << "¿El grafo es fuertemente conexo?   ";
    if(graph1.isStronglyConnected()) cout << "Sí!!" << endl;
    else cout << "No." << endl;

    cout << endl << endl;


    cout << "------------------------------------------------" << endl;
    cout << "|              Undirected  Graph               |" << endl;
    cout << "------------------------------------------------" << endl;

    UnDirectedGraph<char, int> graph2;
    graph2.insertVertex2("1", 'A');
    graph2.insertVertex2("2", 'B');
    graph2.insertVertex2("3", 'C');
    graph2.insertVertex2("4", 'D');
    graph2.insertVertex2("5", 'E');

    graph2.createEdge("1", "2", 10);
    graph2.createEdge("1", "3", 5);
    graph2.createEdge("3", "4", 15);
    graph2.createEdge("2", "4", 20);
    graph2.createEdge("1", "4", 12);
    graph2.createEdge("2", "5", 25);
    graph2.createEdge("4", "5", 30);

    graph2.display();

    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "|              UGraph Methods               |" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;

    cout<< "Densidad: " << graph1.density() << endl;

    cout << "¿El grafo es denso?   ";
    if (graph2.isDense(0.6)) cout << "Sí, es grafo denso." <<endl;
    else cout << "No, el grafo no es denso." << endl;

    cout << "¿El grafo es conexo?   ";
    if(graph2.isConnected()) cout << "Es grafo conexo!!" << endl;
    else cout << "No es conexo!!" << endl;

    cout << "¿Está el vértice 3 en el grafo?   ";
    if(graph2.findById("3")) cout << "Sí!!" << endl;
    else cout << "NO!!" << endl;

    cout << "Vertex 3: ";
    graph2.displayVertex("3");

    cout << endl << endl;
}

void Tester::executeParserPeru(string path){
    cout << "------------------------------------------------" << endl;
    cout << "|               Directed  Graph                |" << endl;
    cout << "------------------------------------------------" << endl;

    Parser parser;
    parser.readJSON(path);
    DirectedGraph<string, double> d1graph;
    parser.dGraphMake(d1graph);

    cout << "DISPLAY :" << endl;

    cout << "+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +" << endl;

    d1graph.display();

    cout << "+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +" << endl;

    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "|              DGraph Methods               |" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;

    // probando operador ()
    auto A = d1graph("2808","2812");
    cout<<"Operador (): "<<A<<endl;

    // probando densidad
    float D = d1graph.density();
    cout<<"Densidad: "<<D<<endl;

    // probando isDense
    bool dense = d1graph.isDense();
    if(dense) cout << "Es denso!!" << endl;
    else cout << "No es denso." << endl;

    // probando isConnected
    bool connected = d1graph.isConnected();
    if(connected) cout << "Es conexo!!" << endl;
    else cout << "No es conexo." << endl;

    // probando isStronglyConnected
    bool stronglyConnected = d1graph.isStronglyConnected();
    if(stronglyConnected) cout << "Es fuertemente conexo!!" << endl;
    else cout << "No es fuertemente conexo." << endl;

    // probando empty
    bool empty = d1graph.empty();
    if(empty) cout << "Empty !" << endl;
    else cout << "No Empty!" << endl;

    cout << endl << endl;

    cout << "------------------------------------------------" << endl;
    cout << "|              Undirected  Graph               |" << endl;
    cout << "------------------------------------------------" << endl;

    Parser parser2;
    parser2.readJSON(path);
    UnDirectedGraph<string, double> u1graph;
    parser2.uGraphMake(u1graph);


    cout << "DISPLAY :" << endl;

    cout << "+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +" << endl;

    u1graph.display();

    cout << "+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +" << endl;


    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "|              UGraph Methods               |" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;

    // probando operador ()
    auto B = u1graph("2808","2812");
    cout<<"Operador (): "<<B<<endl;

    // probando densidad
    float C = u1graph.density();
    cout<<"Densidad: "<<C<<endl;

    // probando isDense
    bool udense = u1graph.isDense();
    if(udense) cout << "Es denso!!" << endl;
    else cout << "No es denso." << endl;

    // probando empty
    bool uempty = u1graph.empty();
    if(uempty) cout << "Empty !" << endl;
    else cout << "No Empty!" << endl;

    // probando isConnected
    bool uconnected = u1graph.isConnected();
    if(uconnected) cout << "Es conexo!!" << endl;
    else cout << "No es conexo." << endl;



    cout << endl << endl;

    cout << "------------------------------------------------" << endl;
    cout << "|               Tests Algorithms               |" << endl;
    cout << "------------------------------------------------" << endl;

    cout<<"\n -----------> DFS:\n";
    DFS<string, double> dfs(&u1graph, "2796");
    auto m = dfs.apply();
    m.display();

    cout<<"\n -----------> BFS:\n";
    BFS<string, double> bfs(&u1graph);
    auto g=bfs.apply("2796");
    g.display();

    cout<<"\n -----------> BBFS:\n";
    BBFS<string, double> bbfs(&u1graph);
    bbfs.apply("2812","2807");


    Parser parser3;
    parser3.readJSON(path);
    UnDirectedGraph<string, double> u2graph;
    parser3.uGraphMake(u2graph);


    cout<<"\n -----------> Dijkstra:\n";
    parser.uGraphMake(u2graph);
    Dijkstra<string, double> Djks(&u2graph, "2796");
    Djks.apply();

    cout << "\n -----------> A Asterisk ( A* ): \n";
    Astar<string, double> a(&u2graph, "2812","2807");
    a.print();

    cout<<" -----------> Probando Kruskal: "<<endl;
    Kruskal<string, double> kruskal(&u2graph);
    UnDirectedGraph<string, double> result3 = kruskal.apply();

    cout<<endl;

    result3.display();



    cout << endl <<" -----------> Probando Prim" << endl;
    Prim<string, double> prim(&u1graph, "2796");
    UnDirectedGraph<string, double> result4 = prim.apply();
    cout<<endl;
    result4.display();

    cout << " -----------> FLOYD TESTS: \n";
    Floyd<string, double> floyd(&u1graph);
//    floyd.print(); //imprime la matriz de adyacencia
//u1graph.display();
    cout<<"Distancia entre 2812 y 2807: "<<floyd.distance("2812","2807");
    cout<<endl;
    cout<<"PATH:   ";
    floyd.showpath("2812","2807");
    cout<<endl;


}


void Tester::executeParserMundo(string path){
    cout << "------------------------------------------------" << endl;
    cout << "|               Directed  Graph                |" << endl;
    cout << "------------------------------------------------" << endl;

    Parser parser;
    parser.readJSON(path);
    DirectedGraph<string, double> d1graph;
    parser.dGraphMake(d1graph);

    cout << "DISPLAY :" << endl;

    cout << "+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +" << endl;

    d1graph.display();

    cout << "+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +" << endl;

    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "|              DGraph Methods               |" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;

    // probando operador ()
    auto A = d1graph("2808","2812");
    cout<<"Operador (): "<<A<<endl;

    // probando densidad
    float D = d1graph.density();
    cout<<"Densidad: "<<D<<endl;

    // probando isDense
    bool dense = d1graph.isDense();
    if(dense) cout << "Es denso!!" << endl;
    else cout << "No es denso." << endl;

    // probando isConnected
    bool connected = d1graph.isConnected();
    if(connected) cout << "Es conexo!!" << endl;
    else cout << "No es conexo." << endl;

    // probando isStronglyConnected
    bool stronglyConnected = d1graph.isStronglyConnected();
    if(stronglyConnected) cout << "Es fuertemente conexo!!" << endl;
    else cout << "No es fuertemente conexo." << endl;

    // probando empty
    bool empty = d1graph.empty();
    if(empty) cout << "Empty !" << endl;
    else cout << "No Empty!" << endl;

    cout << endl << endl;

    cout << "------------------------------------------------" << endl;
    cout << "|              Undirected  Graph               |" << endl;
    cout << "------------------------------------------------" << endl;

    Parser parser2;
    parser2.readJSON(path);
    UnDirectedGraph<string, double> u1graph;
    parser2.uGraphMake(u1graph);


    cout << "DISPLAY :" << endl;

    cout << "+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +" << endl;

    u1graph.display();

    cout << "+ + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + +" << endl;


    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "|              UGraph Methods               |" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;

    // probando operador ()
    auto B = u1graph("2808","2812");
    cout<<"Operador (): "<<B<<endl;

    // probando densidad
    float C = u1graph.density();
    cout<<"Densidad: "<<C<<endl;

    // probando isDense
    bool udense = u1graph.isDense();
    if(udense) cout << "Es denso!!" << endl;
    else cout << "No es denso." << endl;

    // probando empty
    bool uempty = u1graph.empty();
    if(uempty) cout << "Empty !" << endl;
    else cout << "No Empty!" << endl;

    // probando isConnected
    bool uconnected = u1graph.isConnected();
    if(uconnected) cout << "Es conexo!!" << endl;
    else cout << "No es conexo." << endl;



    cout << endl << endl;

    cout << "------------------------------------------------" << endl;
    cout << "|               Tests Algorithms               |" << endl;
    cout << "------------------------------------------------" << endl;

    cout<<"\n -----------> DFS:\n";
    DFS<string, double> dfs(&u1graph, "2796");
    auto m = dfs.apply();
    m.display();

    cout<<"\n -----------> BFS:\n";
    BFS<string, double> bfs(&u1graph);
    auto g=bfs.apply("2796");
    g.display();

    cout<<"\n -----------> BBFS:\n";
    BBFS<string, double> bbfs(&u1graph);
    bbfs.apply("2812","2807");


    Parser parser3;
    parser3.readJSON(path);
    UnDirectedGraph<string, double> u2graph;
    parser3.uGraphMake(u2graph);


    cout<<"\n -----------> Dijkstra:\n";
    parser.uGraphMake(u2graph);
    Dijkstra<string, double> Djks(&u2graph, "2796");
    Djks.apply();

    cout << "\n -----------> A Asterisk ( A* ): \n";
    Astar<string, double> a(&u2graph, "2812","2807");
    a.print();

    cout<<" -----------> Probando Kruskal: "<<endl;
    Kruskal<string, double> kruskal(&u2graph);
    UnDirectedGraph<string, double> result3 = kruskal.apply();

    cout<<endl;

    result3.display();



    cout << endl <<" -----------> Probando Prim" << endl;
    Prim<string, double> prim(&u1graph, "2796");
    UnDirectedGraph<string, double> result4 = prim.apply();
    cout<<endl;
    result4.display();

    cout << " -----------> FLOYD TESTS: \n";
    Floyd<string, double> floyd(&u1graph);
//    floyd.print(); //imprime la matriz de adyacencia
//u1graph.display();
    cout<<"Distancia entre 2812 y 2807: "<<floyd.distance("2812","2807");
    cout<<endl;
    cout<<"PATH:   ";
    floyd.showpath("2812","2807");
    cout<<endl;


}
#endif //PROYECTO_DE_CURSO_DIOSPLAN_TESTER_H
