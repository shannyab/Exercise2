/*
323858324
shannya08@gmail.com
 */
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    vector<vector<int>> graph3 = {
        {0, 2, 1},
        {0, 0, -5},
        {0, 0, 0}};

    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    // Negative cycle not in path
    vector<vector<int>> graph4 = {
        {0, 0, 0, 2, 1},
        {0, 0, 0, 0, -5},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 3, 4) == "3->4");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) != "0");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 18, 4},
        {1, 0, 5, 0, 0, 2},
        {0, 5, 0, 6, 7, 0},
        {0, 0, 3, 0, 3, 0},
        {18, 0, 0, 1, 0, 10},
        {4, 2, 0, 0, 10, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0 -> 1 -> 2 -> 3 -> 4 -> 0");

// empty graph
    vector<vector<int>> graph5 = {};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The graph is empty");
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;

    // Bipartite
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    // Not bipartite
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    // Bipartite
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    vector<vector<int>> graph4 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}

TEST_CASE("Test negative cycles")
{
    ariel::Graph g;

   
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, -5},
        {2, -5, 0}};

    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains negative cycle");


    vector<vector<int>> graph2 = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 2},
        {0, 0, -5, 0, 0}};

    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains negative cycle");

    
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, -10, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains negative cycle");

    
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 9, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, -8, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph contains negative cycle");

    
    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {0, 0, 2},
        {-3, 0, 0}};

    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph does not contain negative cycle");
}
TEST_CASE("Test operator+") {
    ariel::Graph graphA;
    vector<vector<int>> matrixA = {
        {5, 0, 5},
        {0, 5, 0},
        {5, 0, 5}};
    graphA.loadGraph(matrixA);

    ariel::Graph graphB;
    vector<vector<int>> matrixB = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    graphB.loadGraph(matrixB);

    ariel::Graph expectedResult;
    vector<vector<int>> result = {
        {5, 2, 5},
        {2, 5, 2},
        {5, 2, 5}};
    expectedResult.loadGraph(result);

    CHECK(graphA + graphB == expectedResult);
}
TEST_CASE("Test unary operator+") {
    ariel::Graph graph;
    vector<vector<int>> matrix = {
        {1, 2, 1},
        {2, 1, 2},
        {1, 2, 1}};
    graph.loadGraph(matrix);

    ariel::Graph copy = +graph;

    CHECK(graph == copy);
}
TEST_CASE("Test operator+=(const Graph &other)") {
    ariel::Graph graphA;
    vector<vector<int>> matrixA = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    graphA.loadGraph(matrixA);

    ariel::Graph graphB;
    vector<vector<int>> matrixB = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    graphB.loadGraph(matrixB);

    ariel::Graph expected;
    vector<vector<int>> expectedMatrix = {
        {2, 1, 2},
        {1, 2, 1},
        {2, 1, 2}};
    expected.loadGraph(expectedMatrix);

    graphA += graphB;

    CHECK(graphA == expected);
}
TEST_CASE("Test operator++ (pre-increment)") {
    ariel::Graph graph1;
    vector<vector<int>> matrix1 = {
        {3, 3, 0},
        {3, 0, 3},
        {0, 3, 3}};
    graph1.loadGraph(matrix1);

    ariel::Graph expected;
    vector<vector<int>> expectedMatrix = {
        {4, 4, 0},
        {4, 0, 4},
        {0, 4, 4}};
    expected.loadGraph(expectedMatrix);

    ariel::Graph& graph2 = ++graph1;

    CHECK(graph1 == expected);
    CHECK(graph2 == graph1);
}

TEST_CASE("Test operator++ (postfix increment)") {
    ariel::Graph graph;
    vector<vector<int>> matrix = {
        {3, 2, 3},
        {2, 3, 2},
        {3, 2, 3}};
    graph.loadGraph(matrix);

    ariel::Graph originalGraph = graph;

    ariel::Graph result = graph++;

    ariel::Graph expected;
    vector<vector<int>> expectedMatrix = {
        {4, 3, 4},
        {3, 4, 3},
        {4, 3, 4}};
    expected.loadGraph(expectedMatrix);

    CHECK(result == originalGraph);
    CHECK(graph == expected);
}

TEST_CASE("Test operator-") {
    ariel::Graph graph1;
    vector<vector<int>> matrix1 = {
        {2, 1, 2},
        {1, 2, 1},
        {2, 1, 2}};
    graph1.loadGraph(matrix1);

    ariel::Graph graph2;
    vector<vector<int>> matrix2 = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    graph2.loadGraph(matrix2);

    ariel::Graph expectedResult;
    vector<vector<int>> result = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    expectedResult.loadGraph(result);

    CHECK(graph1 - graph2 == expectedResult);
}
TEST_CASE("Test operator- (unary)") {
    ariel::Graph graph;
    vector<vector<int>> matrix = {
        {2, 1, 2},
        {1, 2, 1},
        {2, 1, 2}};
    graph.loadGraph(matrix);

    ariel::Graph negativeGraph = -graph;

    vector<vector<int>> expectedMatrix = {
        {-2, -1, -2},
        {-1, -2, -1},
        {-2, -1, -2}};
    ariel::Graph expected;
    expected.loadGraph(expectedMatrix);

    CHECK(negativeGraph == expected);
}


TEST_CASE("Test operator-=(const Graph &other)") {
    
    ariel::Graph graphA;
    vector<vector<int>> matrixA = {
        {3, 2, 3},
        {2, 3, 2},
        {3, 2, 3}};
    graphA.loadGraph(matrixA);

    ariel::Graph graphB;
    vector<vector<int>> matrixB = {
        {2, 1, 2},
        {1, 2, 1},
        {2, 1, 2}};
    graphB.loadGraph(matrixB);

    
    ariel::Graph expected;
    vector<vector<int>> expectedMatrix = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    expected.loadGraph(expectedMatrix);
    graphA -= graphB;
    CHECK(graphA == expected);
}



TEST_CASE("Test operator-- (pre-decrement)") {
    ariel::Graph graph1;
    vector<vector<int>> matrix1 = {
        {3, 2, 3},
        {2, 3, 2},
        {3, 2, 3}};
    graph1.loadGraph(matrix1);

    ariel::Graph expected;
    vector<vector<int>> decrementedMatrix = {
        {2, 1, 2},
        {1, 2, 1},
        {2, 1, 2}};
    expected.loadGraph(decrementedMatrix);

    ariel::Graph& graph2 = --graph1;

    CHECK(graph1 == expected);
    CHECK(graph2 == graph1);
}
TEST_CASE("Test operator-- (postfix decrement)") {
    ariel::Graph graph;
    vector<vector<int>> matrix = {
        {3, 2, 3},
        {2, 3, 2},
        {3, 2, 3}};
    graph.loadGraph(matrix);

    ariel::Graph originalGraph = graph;

    ariel::Graph result = graph--;

    ariel::Graph expected;
    vector<vector<int>> expectedMatrix = {
        {2, 1, 2},
        {1, 2, 1},
        {2, 1, 2}};
    expected.loadGraph(expectedMatrix);

    CHECK(result == originalGraph);
    CHECK(graph == expected);
}


TEST_CASE("Test operator*=(int c)") {
    ariel::Graph graph;
    vector<vector<int>> matrix = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    graph.loadGraph(matrix);

    int c = 2;
    graph *= c;

    vector<vector<int>> expectedMatrix = {
        {0, 4, 0},
        {4, 0, 4},
        {0, 4, 0}};
    ariel::Graph expected;
    expected.loadGraph(expectedMatrix);

    CHECK(graph == expected);
}

TEST_CASE("Test operator*(const Graph& other)") {
    ariel::Graph graphA;
    vector<vector<int>> matrixA = {
        {1, 9, 3},
        {6, 5, 6},
        {7, 7, 8}};
    graphA.loadGraph(matrixA);

    ariel::Graph graphB;
    vector<vector<int>> matrixB = {
        {9, 8, 0},
        {8, 5, 4},
        {2, 2, 1}};
    graphB.loadGraph(matrixB);

    ariel::Graph result = graphA * graphB;

    vector<vector<int>> expectedMatrix = {
        {87, 59, 39},
        {106, 85, 26},
        {135, 107, 36}};
    ariel::Graph expected;
    expected.loadGraph(expectedMatrix);

    CHECK(result == expected);
}


TEST_CASE("Test operator==") {
    ariel::Graph graphA;
    vector<vector<int>> matrixA = {
        {9, 1, 1},
        {1, 9, 1},
        {1, 1, 1}};
    graphA.loadGraph(matrixA);

    ariel::Graph graphB;
    vector<vector<int>> matrixB = {
        {9, 1, 1},
        {1, 9, 1},
        {1, 1, 1}};
    graphB.loadGraph(matrixB);

    CHECK(graphA == graphB);
}

TEST_CASE("Test operator!=") {
    ariel::Graph graphA;
    vector<vector<int>> matrixA = {
        {2, 1, 2},
        {1, 2, 1},
        {2, 1, 2}};
    graphA.loadGraph(matrixA);

    ariel::Graph graphB;
    vector<vector<int>> matrixB = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    graphB.loadGraph(matrixB);

    CHECK(graphA != graphB);
}
TEST_CASE("Test operator>")
{
    ariel::Graph graph1;
    vector<vector<int>> matrix1 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    graph1.loadGraph(matrix1);

    ariel::Graph graph2;
    vector<vector<int>> matrix2 = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    graph2.loadGraph(matrix2);

    CHECK(graph1 > graph2);

    ariel::Graph graph3;
    vector<vector<int>> matrix3 = {
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0}};
    graph3.loadGraph(matrix3);

    CHECK(graph3 > graph1);
}
TEST_CASE("Test operator>=") {
    ariel::Graph graph1;
    vector<vector<int>> matrix1 = {
        { 7,6, 5, 6},
        { 8 ,5, 6, 5},
        {0,6, 5, 6},
        {0,6, 5, 6}};
    graph1.loadGraph(matrix1);

    ariel::Graph graph2;
    vector<vector<int>> matrix2 = {
        {7, 6, 5},
        {8, 5, 6},
        {0, 6, 5}};
    graph2.loadGraph(matrix2);

    CHECK(graph1 >= graph2);

    ariel::Graph graph3;
    vector<vector<int>> matrix3 = {
       {6, 6, 6},
        {6, 6, 6},
        {6, 6, 6}};
    graph3.loadGraph(matrix3);

    ariel::Graph graph4;
    vector<vector<int>> matrix4 = {
        {6, 6, 6},
        {6, 6, 6},
        {6, 6, 6}};
    graph4.loadGraph(matrix4);

    CHECK(graph4 >= graph3);
}

TEST_CASE("Test operator<")
{
    ariel::Graph graph1;
    vector<vector<int>> matrix1 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    graph1.loadGraph(matrix1);

    ariel::Graph graph2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0, 0},
        {2, 0, 2, 2},
        {0, 2, 0, 0},
        {0, 2, 0, 0}};
    graph2.loadGraph(matrix2);

    CHECK(graph1 < graph2);
}


TEST_CASE("Test operator<=") {
    ariel::Graph graph1;
    vector<vector<int>> matrix1 = {
        {6, 5, 6},
        {5, 6, 5},
        {6, 5, 6}};
    graph1.loadGraph(matrix1);

    ariel::Graph graph2;
    vector<vector<int>> matrix2 = {
        {6, 5, 6},
        {5, 6, 5},
        {6, 5, 6}};
    graph2.loadGraph(matrix2);

    CHECK(graph1 <= graph2);

    ariel::Graph graph3;
    vector<vector<int>> matrix3 = {
        {6, 6, 6, 6},
        {6, 6, 6, 6},
        {6, 6, 6, 6},
        {6, 6, 6, 6}};
    graph3.loadGraph(matrix3);

    CHECK(graph1 <= graph3);
}
TEST_CASE("Invalid operation")
{
    ariel::Graph g1;
    vector<vector<int>> matrix1 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(matrix1);

    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 1},
        {1, 0}};
    g2.loadGraph(matrix2);

    CHECK_THROWS(g1 + g2);
    CHECK_THROWS(g1 * g2);
}
