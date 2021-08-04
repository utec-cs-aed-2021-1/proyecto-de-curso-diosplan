//
// Created by jlr on 7/2/21.
//

#ifndef PROYECTO_DE_CURSO_DIOSPLAN_PARSER_H
#define PROYECTO_DE_CURSO_DIOSPLAN_PARSER_H
#include "../Graph/DirectedGraph.h"
#include "../Graph/UndirectedGraph.h"

#include "../rapidjson/document.h"
#include "../rapidjson/writer.h"
#include "../rapidjson/stringbuffer.h"



#include <fstream>
#include <math.h>

using namespace rapidjson;

struct Parser{
    Document doc; //GetArray : lee como array el doc
    void clear(); // Clears parser saved atributes

    void readJSON(string path); // Parses JSON file and saves data into class
    // NOTE: each derived class has its own readJSON method
    void uGraphMake(UnDirectedGraph<string, double> &tempGraph); // Adds the parsed data into the specified undirected graph

    void dGraphMake(DirectedGraph<string, double> &tempGraph); // Adds the parsed data into the specified directed graph

    void printJSON();

    double getDistance(pair<double, double> posX, pair<double, double> posY);
};


void Parser::clear(){
    delete this;
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

void Parser::printJSON(){
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    doc.Accept(writer);

    std::cout << buffer.GetString() << std::endl;
}

void Parser::uGraphMake(UnDirectedGraph<string, double> &tempGraph){
    for(auto &x: doc.GetArray()) {
        tempGraph.insertVertex(x["Airport ID"].GetString(), x["Name"].GetString(),
                               atof(x["Latitude"].GetString()), atof(x["Longitude"].GetString())
        );
    }
    for(auto &x: doc.GetArray()){
        string xID = x["Airport ID"].GetString();
        pair<double, double> posX = tempGraph.getPositionById(xID);  //par de latitud y longitud de xID
        for(auto &y : x["destinations"].GetArray()) {
            string yID = y.GetString();
            if(tempGraph.findById(yID)) {//si no encontraba un destino, devolvía (0,0) lo que generaba error con la heurística
                pair<double, double> posY = tempGraph.getPositionById(yID); //par de latitud y longitud de yID
                double weight = getDistance(posX, posY);
                tempGraph.createEdge(xID, yID, weight);
                tempGraph.createEdge(yID, xID, weight);
            }
        }
    }
}

void Parser::dGraphMake(DirectedGraph<string, double> &tempGraph){
    //2 pasadas:  1ro para leer/almacenar todos los datos en vértices (ID, lat,long, nombre, destinos)
    //            2da para crear aristas

    //iteración para agregar vértices
    for(auto &x: doc.GetArray()){
        tempGraph.insertVertex(x["Airport ID"].GetString(),x["Name"].GetString(),
                               atof(x["Latitude"].GetString()), atof(x["Longitude"].GetString())
        );
    }

    //iteración para guardar aristas
    for(auto &x: doc.GetArray()){
        string xID = x["Airport ID"].GetString();
        pair<double, double> posX = tempGraph.getPositionById(xID);  //par de latitud y longitud de xID
        for(auto &y : x["destinations"].GetArray()) {
            string yID = y.GetString();
            if(tempGraph.findById(yID)) {//si no encontraba un destino, devolvía (0,0) lo que generaba error con la heurística
                pair<double, double> posY = tempGraph.getPositionById(yID); //par de latitud y longitud de yID
                double weight = getDistance(posX, posY);
                tempGraph.createEdge(xID, yID, weight);  //si fuese undirected, tendría que insertar también yID, xID
            }
        }
    }
}

double degToRad(double deg){
    return deg * (M_PI/180);
}

//distancia entre dos puntos, usando latitud y longitud (posX[latitud,longitud]) en KMs
//enlace: https://en.wikipedia.org/wiki/Haversine_formula
double Parser::getDistance(pair<double, double> posX, pair<double, double> posY){
    double R = 6371; //radio de la Tierra
    double dLat = degToRad(posX.first - posY.first);
    double dLon = degToRad(posX.second - posY.second);
    double a = sin(dLat/2) * sin(dLat/2) +
               cos(degToRad(posX.first)) * cos(degToRad(posY.first)) *
               sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double dist = R * c; //Distancia en KMs
    return dist;
}

#endif //PROYECTO_DE_CURSO_DIOSPLAN_PARSER_H
