// Shadok/functions.h
// Shadok convertisseur
// BODIN Maxime C2
// 22/19/02

#include <string>

using std::string;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H


// Return the shadok of the number
// param : number (0,1,2,3)
// return : shadok of the nb
string printshad(int nb);

// Convert shadok to decimal
// param : string of the number in shadok to convert in decimal
void shadtodec(string sha);

// Convert decimal to shadok
// param : the number to convert in shadok
void dectoshad(int nb);

// tests functions
void testsFunctions();


#endif // FUNCTIONS_H
