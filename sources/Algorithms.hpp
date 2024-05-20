/*
323858324
shannya08@gmail.com
 */
#pragma once
#include "Graph.hpp"
#include <vector>
#include <string>
namespace ariel
{
    namespace Algorithms
    {
        bool isConnected(const Graph &g);
        std::string shortestPath(const Graph &g, int src, int dest);
        std::string isContainsCycle(const ariel::Graph &g);
        std::string isBipartite(const Graph &g);
        std::string  isContainsCycleUtil(const ariel::Graph &g, int v, std::vector<bool> &visited, std::vector<int> &parent);
        std::string negativeCycle(const Graph& graph);

       
 }
} 