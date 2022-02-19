// Shadok/main.cpp
// Shadok convertisseur
// BODIN Maxime C2
// 22/19/02

#include <iostream>

#include "functions.h"

using std::cout, std::cin;


/* Base Shadok principes :
* GA = 0
* BU = 1
* ZO = 2
* MEU = 3
* BU GA = 1 0 (4)
* BU BU = 1 1 (5)
* BU ZO = 1 2 (6)
* ZO GA = 2 0 (8)
* BU GA GA = 1 0 0 (16)
*/

// shadok vers dec -> MEU BU ZO ZO GA  = 3 1 2 2 0 (3*4**4 1*4**3 2*4**2 2*4**1 0*4**0 = 872)

/* dec vers shadok -> division sucessive par 4
* exemple : 1618/4=404 r=2 | 404/4=101 r=0 | 101/4=25 r=1 | 25/4=6 r=1 | 6/4=1 r=2 | 1/4=0 r=1
* puis conversion des restes en shadok dans l'ordre inverse :
* 1 2 1 1 0 2 = BU ZO BU BU GA ZO
*/



int main()
{
    cout << "BODIN Maxime C2" << "\n\n";

    int choice, dec; string sha;

    do{
        cout << "[0]: dec to shad " << '\n'
             << "[1]: shad to dec " << '\n'
             << "[2]: stop "<< '\n';
        cin >> choice;cin.ignore();

        if(choice == 0)
        {
            cout << '\n' << "dec = ";
            cin >> dec;cin.ignore();
            if(dec >= 0)
                dectoshad(dec);
            else
                cout << "Conversion impossible de : " << dec << '\n';
        }
        else if(choice == 1)
        {
            cout << '\n' << "shad = ";
            getline(cin,sha);
            shadtodec(sha);
        }
        else if(choice < 0 || choice > 2)
            cout << "No operation existing for : " << choice << '\n';
    }while(choice != 2);

    testsFunctions();

    return 0;
}
