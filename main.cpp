#include <iostream>

#include "Tester/tester.h"
#include "Parser/parser.h"

using namespace std;

int main(int argc, char *argv[]) {
    std::cout << "================================================" << std::endl;
    std::cout << "||             MENU GRAPH TESTER              ||" << std::endl;
    std::cout << "================================================" << std::endl;
    
    Tester::executeExamples();
//    Tester::executeParserPeru("Parser/Data/pe.json");
//    Tester::executeParserMundo("Parser/Data/airports.json");

    return EXIT_SUCCESS;
}