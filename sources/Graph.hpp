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

            std::size_t size() const {
                return _graph.size();
            }

            bool validateGraph() const;

            Graph operator+(const Graph &other) const;

            Graph &operator+=(const Graph &other)
            {
                if (this->size() != other.size())
                {
                    throw std::invalid_argument("Graphs must be of the same size to add.");
                }
                std::size_t size = this->size();
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        this->_graph[i][j] = this->_graph[i][j] + other._graph[i][j];
                    }
                }
                return *this;
            }
            Graph &operator+()
            {
            return *this;
                 }   
         Graph operator-(const Graph &other) const;

          Graph &operator-()
            {
            std::size_t size = this->size();
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    this->_graph[i][j] = this->_graph[i][j] * (-1);
                }
            }
            return *this;
        }
        Graph &operator-=(const Graph &other)
        {
            if (this->size() != other.size())
            {
                throw std::invalid_argument("Graphs must be of the same size to sub.");
            }
            std::size_t size = this->size();
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    this->_graph[i][j] = this->_graph[i][j] - other._graph[i][j];
                }
            }
            return *this;
        }
         Graph &operator*=(const int x)
        {
        
            std::size_t size = this->size();
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    this->_graph[i][j] = this->_graph[i][j] * x;
                }
            }
            return *this;
        }

        Graph &operator++();//prefix
        Graph operator++(int v);//postfix
        Graph &operator--();//prefix
        Graph operator--(int v);//postfix
        Graph operator*(const Graph &other) const;
        friend std::ostream &operator<<(std::ostream &os, const Graph &graph);
        bool operator==(const Graph& other)const;
        bool operator!=(const Graph &other)const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph &other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        int countEdges()const;
};
}