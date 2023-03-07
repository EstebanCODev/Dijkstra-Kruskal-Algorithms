//
// Created by esteb on 10/27/2022.
//This program is created by Esteban Castro Oviedo on October 27, 2022. Costa Rica.
//

#ifndef CALCULOSEXAMENII_DISJOINTSETS_H
#define CALCULOSEXAMENII_DISJOINTSETS_H

#include "Tools.h"

class DisjointSets {
private:
    int * parent, *rnk;
    int n;
public:
    DisjointSets(int n);
    int find(int u);
    void merge(int x, int y);
};


#endif //CALCULOSEXAMENII_DISJOINTSETS_H
