//
// Created by esteb on 10/27/2022.
//This program is created by Esteban Castro Oviedo on October 27, 2022. Costa Rica.
//

#include "Menu.h"

void Menu::control() {
    Graph * g = new Graph(9);
    int op, weight;
    bool repeat;
    char node;

    do {
        cout << "1. Load data" << endl;
        cout << "2. Show costs from a parent node using Dijkstra's algorithm" << endl;
        cout << "3. Show minimum spanning tree using Kruskal's algorithm" << endl;
        cout << "4. Exit"<<endl;
        cin >> op;
        cout<<endl;
        switch (op) {
            case 1:
                g->loadData();
                break;
            case 2:
                cout << "Which node do you want to choose as primary? (A-B-C-D-E-F-G-H-I)  :";
                cin >> node;
                cout<<"->Using Dijkstra's algorithm, the cost to each node, being "<<node<<" the main node is: "<<endl;
                g->DijkstraAlgorithm(Tools::numberToLetter(node));
                cout<<endl<<endl;
                break;
            case 3:
                cout<<"->Minimum spanning tree: "<<endl;
                weight = g->KruskalAlgorithm();
                cout<<"Tree weight value: "<<weight;
                cout<<endl<<endl;
                break;
            default:
                repeat = true;
                break;
        }
    }while(!repeat);
    delete g;
}



