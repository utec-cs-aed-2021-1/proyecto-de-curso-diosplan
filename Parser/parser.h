//
// Created by jlr on 7/2/21.
//

#ifndef PROYECTO_DE_CURSO_DIOSPLAN_PARSER_H
#define PROYECTO_DE_CURSO_DIOSPLAN_PARSER_H
#include "../Graph/DirectedGraph.h"
#include "../Graph/UndirectedGraph.h"

#include <../rapidjson/document.h>
#include <../rapidjson/writer.h>
#include <../rapidjson/stringbuffer.h>



#include <fstream>
#include <math.h>

using namespace rapidjson;

struct Parser{
    Document doc;
    void clear(); // Clears parser saved atributes

    void readJSON(string path); // Parses JSON file and saves data into class
    // NOTE: each derived class has its own readJSON method

    void uGraphMake(UnDirectedGraph<string, double> &tempGraph); // Adds the parsed data into the specified undirected graph

    void dGraphMake(DirectedGraph<string, double> &tempGraph); // Adds the parsed data into the specified directed graph

    void printJSON();

};

void Parser::clear(){

}

void Parser::readJSON(string path){
    std::ifstream is (path, std::ifstream::binary);
    if (is) {
        is.seekg(0, is.end);
        int length = is.tellg();
        is.seekg(0, is.beg);

        char *json = new char[length];

        std::cout << "Reading " << length << " chars... ";
        is.read(json, length);

        doc.Parse(json);
    }
    is.close();
}


void Parser::uGraphMake(UnDirectedGraph<string, double> &tempGraph){

}

void Parser::dGraphMake(DirectedGraph<string, double> &tempGraph){

}

void Parser::printJSON(){
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    doc.Accept(writer);

    std::cout << buffer.GetString() << std::endl;
}

#endif //PROYECTO_DE_CURSO_DIOSPLAN_PARSER_H
