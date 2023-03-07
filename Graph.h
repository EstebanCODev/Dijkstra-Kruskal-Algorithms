//
// Created by esteb on 10/27/2022.
//This program is created by Esteban Castro Oviedo on October 27, 2022. Costa Rica.
//

#ifndef CALCULOSEXAMENII_GRAPH_H
#define CALCULOSEXAMENII_GRAPH_H


#include "Tools.h"
#include "DisjointSets.h"
#define INF 0x3f3f3f3f

typedef pair<int, int> myPair;

class Graph {
    int V;
    list<pair<int, int> >* adj;
    vector<pair<int, myPair>> edges;
public:
    Graph(int V);
    void insertArc(int u, int v, int w);
    void insertArcKruskal(int u, int v, int w);
    void DijkstraAlgorithm(int src);
    int KruskalAlgorithm();
    void loadData();
    virtual ~Graph();
};



#endif //CALCULOSEXAMENII_GRAPH_H
