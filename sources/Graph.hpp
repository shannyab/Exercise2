/*
323858324
shannya08@gmail.com
 */
#pragma once
#include <vector>
#include <iostream>

namespace ariel
{
    class Graph
    {
        public:
            std::vector<std::vector<int>> _graph;

            void loadGraph(std::vector<std::vector<int>> graph);

            void printGraph() const;

            std::size_t size() const{
                return _graph.size();
            
            }

            bool validateGraph() const;

            Graph operator+(const Graph &other) const;

            Graph &operator+=(const Graph &other);
            
            Graph &operator+();

            Graph operator-(const Graph &other) const;

            Graph &operator-();

            Graph &operator-=(const Graph &other);

            Graph &operator*=(const int x);

            Graph &operator++();//prefix
            Graph operator++(int v);//postfix
            Graph &operator--();//prefix
            Graph operator--(int v);//postfix
            Graph operator*(const Graph &other) const;

            friend std::ostream &operator<<(std::ostream &os, const Graph &graph);

            bool operator==(const Graph& other) const;

            bool operator!=(const Graph &other) const;

            bool operator>(const Graph& other) const;

            bool operator>=(const Graph &other) const;

            bool operator<(const Graph& other) const;

            bool operator<=(const Graph& other) const;

            int countEdges() const;
    };
}
