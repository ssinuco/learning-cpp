#include <iostream>
#include <gtest/gtest.h>
#include "undirected-graph.cpp"
#include "depth-first-search.cpp"

/*
 *        (0)-------(1)
 *       /   \
 *      (5)  (2)
 */
TEST(DepthFirstSearch, search) {
    UndirectedGraph graph {20};
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 5);
    graph.addEdge(1, 7);
    graph.addEdge(8, 9);
    DepthFirstSearch search (&graph, 0);
    EXPECT_EQ(6, search.visitedVertices());
    EXPECT_EQ(true, search.isConnectedToSource(1));
    EXPECT_EQ(true, search.isConnectedToSource(2));
    EXPECT_EQ(true, search.isConnectedToSource(5));
    EXPECT_EQ(true, search.isConnectedToSource(7));
    EXPECT_EQ(false, search.isConnectedToSource(8));
    EXPECT_EQ(false, search.isConnectedToSource(9));
}

