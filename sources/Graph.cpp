/*
323858324
shannya08@gmail.com
 */

#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

namespace ariel
{
    void Graph::loadGraph(std::vector<std::vector<int>> graph)
    {
        // Clear the graph before loading the new one.
        this->_graph.clear();

        // Copy the new graph.
        for (size_t i = 0; i < graph.size(); i++)
        {
            std::vector<int> row;
            for (size_t j = 0; j < graph[i].size(); j++)
            {
                row.push_back(graph[i][j]);
            }
            this->_graph.push_back(row);
        }

        this->validateGraph();
    }

    void Graph::printGraph() const
    {
        size_t vertices = this->_graph.size();
        size_t edges = 0;
        for (size_t i = 0; i < vertices; i++)
        {
            for (size_t j = 0; j < vertices; j++)
            {
                if (this->_graph[i][j] != 0)
                {
                    edges++;
                }
            }
        }
        std::cout << "Graph with " << vertices << " vertices and " << edges << " edges." << std::endl;
    }

    bool Graph::validateGraph() const
    {
        size_t vertices = this->_graph.size();
        for (size_t i = 0; i < vertices; i++)
        {
            if (this->_graph[i].size() != vertices)
            {
                throw std::invalid_argument("Invalid graph.");
                return false;
            }
        }
        return true;
    }

    Graph Graph::operator+(const Graph &other) const
    {
        if (this->size() != other.size())
        {
            throw std::invalid_argument("Graphs must be of the same size to add.");
        }
        Graph g3;
        std::size_t sizeofg3 = this->size();
        g3._graph.resize(sizeofg3, std::vector<int>(sizeofg3));
        for (int i = 0; i < sizeofg3; i++)
        {
            for (int j = 0; j < sizeofg3; j++)
            {
                g3._graph[i][j] = this->_graph[i][j] + other._graph[i][j];
            }
        }
        return g3;
    }

    Graph Graph::operator-(const Graph &other) const
    {
        if (this->size() != other.size())
        {
            throw std::invalid_argument("Graphs must be of the same size to sub");
        }
        std::size_t size = this->size();
        Graph g4;
        g4._graph.resize(size, std::vector<int>(size));
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                g4._graph[i][j] = this->_graph[i][j] - other._graph[i][j];
            }
        }
        return g4;
    }

    Graph Graph::operator*(const Graph &other) const
    {
        int i = 0;
        if (this->size() != other.size())
        {
            throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }
        std::size_t size = this->size();
        Graph g4;
        g4._graph.resize(size, std::vector<int>(size));
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int sum = 0;
                for (int k = 0; k < size; k++)
                {
                    sum += this->_graph[i][k] * other._graph[k][j];
                }
                g4._graph[i][j] = sum;
            }
        }

        return g4;
    }

    std::ostream &operator<<(std::ostream &os, const Graph &graph)
    {
        std::vector<std::vector<int>> GraphMatrix = graph._graph;
        for (int i = 0; i < GraphMatrix.size(); i++)
        {
            os << "[";
            for (int j = 0; j < GraphMatrix.size(); j++)
            {
                os << " " << GraphMatrix[i][j];
            }
            os << "]" << std::endl;
        }
        return os;
    }

    bool Graph::operator==(const Graph& other) const 
    {
        if (this->size() != other.size())
        {
            return false;
        }
        std::size_t size = this->size();
        for (std::size_t i = 0; i < size; ++i)
        {
            for (std::size_t j = 0; j < size; ++j)
            {
                if (this->_graph[i][j] != other._graph[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool Graph::operator!=(const Graph& other) const 
    {
        return !(*this == other);
    }

    Graph Graph::operator--(int v)
    {
        std::size_t size = this->size();
        Graph afterpostfix = *this;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (this->_graph[i][j] != 0)
                {
                    this->_graph[i][j] = (this->_graph[i][j]) - 1;
                }
            }
        }
        return afterpostfix;
    }

    Graph &Graph::operator--()
    {
        std::size_t size = this->size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (this->_graph[i][j] != 0)
                {
                    this->_graph[i][j] = (this->_graph[i][j]) - 1;
                }
            }
        }
        return *this;
    }

    Graph Graph::operator++(int v)
    {
        std::size_t size = this->size();
        Graph afterpostfix = *this;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (this->_graph[i][j] != 0)
                {
                    this->_graph[i][j] = (this->_graph[i][j]) + 1;
                }
            }
        }
        return afterpostfix;
    }

    Graph &Graph::operator++()
    {
        std::size_t size = this->size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (this->_graph[i][j] != 0)
                {
                    this->_graph[i][j] = (this->_graph[i][j]) + 1;
                }
            }
        }
        return *this;
    }

    bool Graph::operator>(const Graph &other) const 
    {
        size_t size1 = this->_graph.size();
        size_t size2 = other._graph.size();

        // implementation that verifies if this contains other
        bool thisContainsOther = false;
        if (size2 <= size1) 
        {
            bool OtherIsContained = true;
            for (size_t i = 0; i < size2; ++i) 
            {
                for (size_t j = 0; j < size2; ++j) 
                {
                    if (other._graph[i][j] && !this->_graph[i][j]) 
                    {
                        OtherIsContained = false;
                        break;
                    }
                }
                if (!OtherIsContained) 
                {
                    break;
                }
            }
            thisContainsOther = OtherIsContained;
        }

        if (thisContainsOther) 
        {
            return true;
        }

        // implementation that verifies if other contains this 
        bool otherContainsThis = false;
        if (size1 <= size2) 
        {
            bool ThisIsContained = true;
            for (size_t i = 0; i < size1; ++i) 
            {
                for (size_t j = 0; j < size1; ++j) 
                {
                    if (this->_graph[i][j] && !other._graph[i][j]) 
                    {
                        ThisIsContained = false;
                        break;
                    }
                }
                if (!ThisIsContained) 
                {
                    break;
                }
            }
            otherContainsThis = ThisIsContained;
        }
        if (this->countEdges() != other.countEdges()) 
        {
            return this->countEdges() > other.countEdges();
        }

        if (otherContainsThis) 
        {
            return false;
        }
        return size2 < size1;
    }

    bool Graph::operator>=(const Graph &other) const 
    {
        return (*this > other || *this == other);
    }

    bool Graph::operator<(const Graph &other) const 
    {
        return other > *this;
    }

    bool Graph::operator<=(const Graph &other) const 
    {
        return (*this < other || *this == other);
    }

    int Graph::countEdges() const 
    {
        size_t vertices = this->size();
        size_t edges = 0;
        for (size_t i = 0; i < vertices; i++)
        {
            for (size_t j = 0; j < vertices; j++)
            {
                if (this->_graph[i][j] != 0)
                {
                    edges++;
                }
            }
        }
        return edges;
    }

    Graph &Graph::operator+=(const Graph &other)
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

    Graph &Graph::operator+()
    {
        return *this;
    }

    Graph &Graph::operator-()
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

    Graph &Graph::operator-=(const Graph &other)
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

    Graph &Graph::operator*=(const int x)
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
}
