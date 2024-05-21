/*
323858324
shannya08@gmail.com
 */

#include "Graph.hpp"
#include "Algorithms.hpp"
using namespace ariel;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
     Graph g1;
    vector<vector<int>> graph1 = {
        {0, 2, 0},
        {2, 0, 3},
        {0, 3, 0}};
    g1.loadGraph(graph1);
    cout<<g1<<endl;
    /*should print the matrix of the graph g1:
      [0, 2, 0]
      [2, 0, 3]
      [0, 3, 0]*/
  

    Graph g2;
    vector<vector<int>> graph2 = {
        {2, 1, 3},
        {3, 0, 4},
        {3, 1, 9}};
    g2.loadGraph(graph2);
    ariel::Graph res = g1 + g2; // Add the two graphs together.
    cout<<res<<endl; 
      /*should print the matrix of graph res:
      [2, 3, 3]
      [5, 0, 7]
      [3, 4, 9]*/
      +g2;
      cout<<g2<<endl;
      /*should print the matrix of the graph g2 without changes:
      [2, 1, 3]
      [3, 0, 4]
      [3, 1, 9]*/
          g1--;
       cout<<g1<<endl;
    /*should print the matrix of the graph after g1-- 
      [0, 1, 0]
      [1, 0, 2]
      [0, 2, 0]*/


    Graph g3;
    vector<vector<int>> graph3 = {
        {1, 3, 4},
        {1, 0, 1},
        {2, 0, 3}};
    g3.loadGraph(graph3);
     g3 *= -2;        // Multiply the graph by -2.
    cout<<g3<<endl;  /*should print the matrix of graph g3:
      [-2,-6,-8]
      [-2, 0, -2]
      [-4, 0,-6]*/
      cout<<(g2+=g3)<<endl;
       /*should print the matrix of graph g2 after the addition:
      [0,-5,-5]
      [1, 0, 2]
      [-1, 1,3]*/
      cout<<g2++<<endl;
       cout<<g2<<endl;
       /*should print the matrix of graph g2 without changes and after with changes
       [0,-5,-5]
      [1, 0, 2]
      [-1, 1,3]
      
      [0,-4,-4]
      [2, 0, 3]
      [0, 2,4]
      
      */
    Graph g4;
    vector<vector<int>> graph4 = {
        {0, 2},
        {2, 0}};
    g4.loadGraph(graph4);
      cout<<-g4<<endl; 
     /*should print the matrix of graph g4 after the minus unary:
    [0, -2]
    [-2, 0]
    */
   cout<<++g4<<endl;
     /*should print the matrix of graph g4 after the ++g4:
    [0, -1]
    [-1, 0]
    */


    Graph g5;
    vector<vector<int>> graph5 = {
        {1, 0, 1},
        {0, 2, 0},
        {1, 0, 3}};
    g5.loadGraph(graph5);
    cout<<g5*g2<<endl;
      /*should print the matrix after the mult
       [0,-2,0]
      [4, 0, 6]
      [0, 2, 8]*/


    Graph g6;
    vector<vector<int>> graph6 = {
        {0, 2, 0},
        {2, 7, 4},
        {5, 1, 0}};
    g6.loadGraph(graph6);
    ariel::Graph result=g6-g5;
    cout<<result<<endl;
     /*should print the matrix of graph result after the sub:
      [-1,2, -1]
      [2, 5, 4]
      [4, 1,-3]*/
      g5-=g1;
      cout<<g5<<endl;
      /*should print the matrix of graph g5 after the sub:
      [1,-1, 1]
      [-1, 2,-2]
      [1, -2,3]*/

      cout<<(--g5)<<endl;
      /*should print the matrix of graph g5 after the --g5
      [0,-2, 0]
      [-2, 1,-3]
      [0, -3,2]*/

    Graph g7;
    vector<vector<int>> graph7 = {
        {0, 2, 0, 1},
        {2, 0, 3, 2},
        {0, 3, 0, 4},
        {1, 2, 4, 0}};
    g7.loadGraph(graph7);

    Graph g8;
    vector<vector<int>> graph8 = {
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1}};
    g8.loadGraph(graph8);

    Graph g9;
    vector<vector<int>> graph9 = {
        {1, 0},
        {0, 1}};
    g9.loadGraph(graph9);

    Graph g10;
    vector<vector<int>> graph10 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    g10.loadGraph(graph10);
    Graph g11;
    vector<vector<int>> graph11= {
        {0, 2, 0, 1},
        {2, 0, 3, 2},
        {0, 3, 0, 4},
        {1, 2, 4, 0}};
    g11.loadGraph(graph11);
         Graph g12;
     vector<vector<int>> graph12 = {
         {0, 3, 0},
         {3, 0, 2},
         {0, 2, 0}};
     g12.loadGraph(graph12);
     
     Graph g13;
     vector<vector<int>> graph13 = {
         {2, 1, 3},
         {1, 4, 1},
         {3, 1, 5}};
     g13.loadGraph(graph13);
     
     Graph g14;
     vector<vector<int>> graph14 = {
         {0, 4, 3, 2},
         {4, 0, 2, 5},
         {0, 2, 0, 4},
         {3, 0, 4, 0}};
     g14.loadGraph(graph14);
     
     Graph g15;
     vector<vector<int>> graph15 = {
         {3, 2},
         {2, 5}};
     g15.loadGraph(graph15);
     
     Graph g16;
     vector<vector<int>> graph16 = {
         {0, 0, 3},
         {0, 0, 4},
         {3, 4, 0}};
     g16.loadGraph(graph16);
     
     Graph g17;
     vector<vector<int>> graph17 = {
         {0, 3, 2},
         {3, 0, 0},
         {2, 0, 0}};
     g17.loadGraph(graph17);
     
     Graph g18;
     vector<vector<int>> graph18 = {
         {0, 4, 0},
         {4, 0, 0},
         {0, 0, 0}};
     g18.loadGraph(graph18);
     
     
     Graph g19;
     vector<vector<int>> graph19 = {
         {0, 4, 2, 0},
         {4, 0, 3, 0},
         {2, 3, 0, 4},
         {0, 0, 4, 0}};
     g19.loadGraph(graph19);
     
     Graph g20;
     vector<vector<int>> graph20 = {
         {3, 0, 0, 2},
         {0, 4, 2, 0},
         {0, 2, 5, 0},
         {2, 0, 0, 3}};
     g20.loadGraph(graph20);
     
     // Examples for testing the comparison operators
     cout << (g6 >= g7) << endl; // should return false
     cout << (g7 > g6) << endl; // should return true
     cout << (g11 == g7) << endl; // should return true
     cout << (g13 <= g12) << endl;// should return false
     cout << (g15 < g14) << endl; // should return true
     cout << (g15 < g16) << endl;  // should return true
     cout << (g17 <= g18) << endl;  // should return false
     cout << (g7!=g9) << endl;//should return true
     cout<<(g20==g19)<<endl;//should return false
     cout<<(g18!=g17)<<endl;//should return true
     }

