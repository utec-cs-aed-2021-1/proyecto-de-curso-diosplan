cmake_minimum_required(VERSION 3.17)
project(proyecto_de_curso_diosplan)

set(CMAKE_CXX_STANDARD 14)

include_directories(Graph)
include_directories(Graph/Algorithms)

add_executable(proyecto_de_curso_diosplan
        Graph/Algorithms/astar.h
        Graph/Algorithms/bfs.h
        Graph/Algorithms/dfs.h
        Graph/Algorithms/dijkstra.h
        Graph/Algorithms/kruskal.h
        Graph/Algorithms/prim.h
        Graph/DirectedGraph.h
        Graph/graph.h
        Graph/UndirectedGraph.h
        main.cpp)
