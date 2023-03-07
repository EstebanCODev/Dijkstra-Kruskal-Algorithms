//
// Created by esteb on 10/27/2022.
//This program is created by Esteban Castro Oviedo on October 27, 2022. Costa Rica.
//

#include "Tools.h"

char Tools::letterToNumber(int letterNum) {
    vector<char> letters= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    return letters[letterNum];
}

int Tools::numberToLetter(char letter) {
    switch(letter){
        case 'A' : return 0; break;
        case 'B' : return 1; break;
        case 'C' : return 2; break;
        case 'D' : return 3; break;
        case 'E' : return 4; break;
        case 'F' : return 5; break;
        case 'G' : return 6; break;
        case 'H' : return 7; break;
        case 'I' : return 8; break;
        default: return 999;break;
    }
}