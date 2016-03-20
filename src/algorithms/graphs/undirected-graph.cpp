#include <stdio.h>
#include "graph.cpp"
#include "../datastructures/bag.cpp"

/*
 * A undirected graph where edges are nothing more than connections between vertices.
 */
class UndirectedGraph : public Graph {
    private:
        int v;
        int e;
        Bag** bags;

    public:
        UndirectedGraph(int vertices) {
            this->v = vertices;
            this->bags = new Bag*[vertices];
            for (int i = 0; i < vertices; i++) {
                bags[i] = new Bag();
            }
            this->e = 0;
        }
        ~UndirectedGraph() {
            delete [] bags;
        }
        int vertices() {
            return v;
        }
        int edges() {
            return e;
        }
        void addEdge(int v, int w) {
            bags[v]->add(w);
            bags[w]->add(v);
            e++;
        }
};
