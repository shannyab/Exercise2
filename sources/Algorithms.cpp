/*
323858324
shannya08@gmail.com
 */
#include "Algorithms.hpp"
#include <queue>
#include <iostream>
#include <limits.h>  // Include for INT_MAX
#include <algorithm> // Include for std::min_element
#include <stack>

/**
 * @brief Calculate the shortest path from a source node to a destination node using Bellman-Ford algorithm.
 * returns the shortest path as a string.
 *
 */

std::string ariel::Algorithms::shortestPath(const ariel::Graph &g, int src, int dest)
{
    int V = g.size();

    // Check if the source and destination are within bounds
    if (src < 0 || src >= V || dest < 0 || dest >= V)
    {
        throw std::invalid_argument("Error: Source or destination vertex is out of bounds.");
    }

    const int INF = INT_MAX;        // Infinity value defined for unreachable paths
    std::vector<int> dist(V, INF);  // Distance from source to each vertex
    std::vector<int> parent(V, -1); // Predecessor of each vertex

    dist[src] = 0; // Distance to source is 0

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; ++i)
    {
        for (int u = 0; u < V; ++u)
        {
            for (int v = 0; v < V; ++v)
            {
                int weight = g._graph[u][v];
                if (weight != 0 && dist[u] != INF && dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < V; ++u)
    {
        for (int v = 0; v < V; ++v)
        {
            int weight = g._graph[u][v];
            if (weight != 0 && dist[u] != INF && dist[u] + weight < dist[v])
            {
                return "Negative cycle detected in the path.";
            }
        }
    }

    // Check if the destination is reachable
    if (dist[dest] == INF)
    {
        return "-1";
    }

    // Reconstruct the path from destination to source using predecessors
    std::string path = std::to_string(dest);
    int step = dest;
    while (parent[step] != -1)
    {
        path = std::to_string(parent[step]) + "->" + path;
        step = parent[step];
    }

    return path;
}

/**
 * @brief  Determines if the graph is connected using a breadth-first search approach.
 * returns true if the graph is connected, false otherwise.

*/

bool ariel::Algorithms::isConnected(const ariel::Graph &g)
{
    if (g.size() == 0)
    {
        return false;
    }

    // Basically do BFS from the first vertex.
    std::vector<bool> visited(g.size(), false);
    std::queue<int> q;
    q.push(0);

    visited[0] = true;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g.size(); i++)
        {
            if (!visited[i] && g._graph[v][i] != 0)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    // Check if all the vertices are visited
    for (int i = 0; i < g.size(); i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }

    return true;
}

/***
 * @brief  Helper function to determine if the graph contains a cycle using DFS.i used a stack to reverse the order because the output that task required was in reverse order.
 * there is another function without reverse
 */

std::string ariel::Algorithms::isContainsCycleUtil(const ariel::Graph &g, int v, std::vector<bool> &visited, std::vector<int> &parent)
{
    visited[v] = true;

    for (int i = 0; i < g.size(); i++)
    {
        if (g._graph[v][i] != 0) // There is an edge between v and i
        {
            if (!visited[i])
            {
                parent[i] = v;
                std::string result = isContainsCycleUtil(g, i, visited, parent);
                if (result != "0")
                {
                    return result;
                }
            }
            else if (parent[v] != i)
            {
                // Cycle found

                std::stack<int> stack; // Stack to store the cycle

                // Start with current node `v` and push to the stack
                for (int current = v; current != i; current = parent[current])
                {
                    stack.push(current);
                }
                stack.push(i); // Push the starting node of the cycle

                // Create the cycle string
                std::string cycle = "The cycle is: " + std::to_string(stack.top());
                stack.pop();
                while (!stack.empty())
                {
                    cycle += " -> " + std::to_string(stack.top());
                    stack.pop();
                }
                cycle += " -> " + std::to_string(i); // complete the cycle

                return cycle;
            }
        }
    }
    return "0"; // No cycle found
}

/*

std::string ariel::Algorithms::isContainsCycleUtil(const ariel::Graph &g, int v, std::vector<bool> &visited, std::vector<int> &parent)
{
       visited[v] = true;

            for (int i = 0; i < g.size(); i++) {
                if (g._graph[v][i] != 0) {  // There is an edge between v and i
                    if (!visited[i]) {
                        parent[i] = v;
                        std::string result = isContainsCycleUtil(g, i, visited, parent);
                        if (result != "0") {
                            return result;
                        }
                    } else if (parent[v] != i) {
                        // Cycle found
                        std::string cycle = "The cycle is: " + std::to_string(i);
                        for (int current = v; current != i; current = parent[current]) {
                            cycle += " -> " + std::to_string(current);
                        }
                        cycle += " -> " + std::to_string(i);
                        return cycle;
                    }
                }
            }
            return "0"; // No cycle found
        }

*/

/**
 * @brief  Checks the graph for any cycles by iterating through each vertex.
 */

std::string ariel::Algorithms::isContainsCycle(const ariel::Graph &g)
{
    if (g.size() == 0)
    {
        return "The graph is empty";
    }
    std::vector<bool> visited(g.size(), false);
    std::vector<int> parent(g.size(), -1);

    for (int i = 0; i < g.size(); i++)
    {
        if (!visited[i])
        {
            std::string result = isContainsCycleUtil(g, i, visited, parent);
            if (result != "0")
            {
                return result;
            }
        }
    }
    return "0"; // No cycle found in the graph
}

/**
 * @brief  Determines if the graph is bipartite .
 */
std::string ariel::Algorithms::isBipartite(const ariel::Graph &g)
{
    // Try to color the graph with two colors.
    // If it's possible, the graph is bipartite.

    std::vector<int> color(g.size(), -1);
    std::queue<int> q;
    q.push(0);
    color[0] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (g._graph[u][u] != 0)
        {
            return "0"; 
        }

        for (int v = 0; v < g.size(); v++)
        {
            if (g._graph[u][v] != 0 && color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (g._graph[u][v] != 0 && color[v] == color[u])
            {
                return "0"; // Not bipartite
            }
        }
    }

    std::string result = "The graph is bipartite: A={";
    for (int i = 0; i < g.size(); i++)
    {
        if (color[i] == 0)
        {
            result += std::to_string(i) + ", ";
        }
    }
    result.pop_back();
    result.pop_back();
    result += "}, B={";
    for (int i = 0; i < g.size(); i++)
    {
        if (color[i] == 1)
        {
            result += std::to_string(i) + ", ";
        }
    }
    result.pop_back();
    result.pop_back();
    result += "}";

    return result;
}

/**
 * @brief  Determines if the graph contains a negative cycle.
 */
std::string ariel::Algorithms::negativeCycle(const ariel::Graph &graph)
{
    int V = graph.size();
    for (int i = 0; i < V; i++)
    {
        if (shortestPath(graph, i, i) == "Negative cycle detected in the path.")
        {
            return "The graph contains negative cycle";
        }
    }
    return "The graph does not contain negative cycle";
}