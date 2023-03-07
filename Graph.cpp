//
// Created by esteb on 10/27/2022.
//This program is created by Esteban Castro Oviedo on October 27, 2022. Costa Rica.
//

#include "Graph.h"

Graph::Graph(int V) {
    this->V = V;
    adj = new list<myPair>[V];
}

void Graph::insertArc(int origin, int destination, int weight) {
    adj[origin].push_back(make_pair(destination, weight));
    adj[destination].push_back(make_pair(origin, weight));
}

void Graph::DijkstraAlgorithm(int src) {
    priority_queue<myPair, vector<myPair>, greater<myPair>> pQueue;
    vector<int> distance(V, INF);
    pQueue.push(make_pair(0, src));
    distance[src] = 0;
    while (!pQueue.empty()) {
        int u = pQueue.top().second;
        pQueue.pop();
        list<pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;
            if (distance[v] > distance[u] + weight) {
                distance[v] = distance[u] + weight;
                pQueue.push(make_pair(distance[v], v));
            }
        }
    }
    for (int i = 0; i < V; ++i) {
        cout << Tools::letterToNumber(i) << "\t\t" << distance[i] << endl;
    }
}

void Graph::loadData() {
    ifstream file;

    string origin, destination, weightString;
    int weight;

    file.open("../GraphWeights.txt", ios::in);
    if (file) {
        while (!file.eof()) {
            getline(file, origin, ',');
            getline(file, destination, ',');
            getline(file, weightString, '\n');
            const char *pe = weightString.c_str();
            weight = atoi(pe);
            insertArc(Tools::numberToLetter(origin[0]), Tools::numberToLetter(destination[0]), weight);
            insertArcKruskal(Tools::numberToLetter(origin[0]), Tools::numberToLetter(destination[0]), weight);
        }
    }
    else {
        cout<<"ERROR OPENING THE FILE";
    }
    file.close();
}

void Graph::insertArcKruskal(int origin, int destination, int weight) {
    edges.push_back({weight, {origin, destination}});
}

int Graph::KruskalAlgorithm() {
    int minimumTree = 0;
    sort(edges.begin(), edges.end());
    DisjointSets ds(V);
    vector<pair <int, myPair>>::iterator it;
    for(it = edges.begin(); it!=edges.end(); it++){
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if(set_u != set_v){
            cout << Tools::letterToNumber(u) << " - " << Tools::letterToNumber(v) << endl;
            minimumTree += it->first;
            ds.merge(set_u, set_v);
        }
    }
    return minimumTree;
}


Graph::~Graph() {
    adj->clear();
    edges.clear();
}