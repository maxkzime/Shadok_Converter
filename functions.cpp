// Shadok/functions.cpp
// Shadok convertisseur
// BODIN Maxime C2
// 22/19/02

#include <iostream>
#include <stack>
#include <vector>
#include <random> // pour générer  un nombre aléatoire
#include <chrono> // pour la seed du générateur de nombre aléatoire

#include "functions.h"

using std::cout, std::cin, std::vector, std::stack;

vector <string> shadWords{" GA"," BU"," ZO"," MEU"};

// Convert shadok to decimal
// param : string of the number in shadok to convert in decimal
void shadtodec(string sha)
{
    string shaToConvert = sha+" end";

    string space_delimiter = " ";

    vector<string> words{};

    size_t pos = 0;

    while ((pos = shaToConvert.find(space_delimiter)) != string::npos)
    {
        words.insert(words.begin(),shaToConvert.substr(0, pos));
        shaToConvert.erase(0, pos + space_delimiter.length());
    }

    int s = 0 , p = 0;

    for (const auto &str : words)
    {
        if(str == "GA")
            s += 0*pow(4,p);
        else if(str == "BU")
            s += 1*pow(4,p);
        else if(str == "ZO")
            s += 2*pow(4,p);
        else if(str == "MEU")
            s += 3*pow(4,p);
        else if(str == "" || str == " ")
        ;
        else
            cout << "invalid word" << '\n';

        p++;
    }

    cout << sha << " = " << s << "\n\n";
}


// Convert decimal to shadok
// param : the number to convert in shadok
void dectoshad(int nb)
{
    cout << '\n' << nb << " = ";

    if(nb > 0)
    {
        int re;
        stack <int> r;

        do{
            re = nb%4;
            r.push(re);

            nb /= 4;

        }while(nb > 0);


        for(r.size();r.size() > 0;)
        {
            cout << shadWords[r.top()];
            r.pop();
        }
        cout << "\n\n";
    }
    else if (nb == 0)
        cout << shadWords[nb] << '\n';
    else
        cout << "Conversion impossible de : " << nb << '\n';
}


// tests functions
void testsFunctions()
{
    //--------TESTS--------
    cout << "\n\n\n" << " Tests : " << '\n';

    cout << '\n' << " ---- Decimal to shadok : " << '\n';

    // random number generator
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    static std::mt19937 gen(seed);

    std::uniform_int_distribution<> distribNumberDec(-1000,10000); // limites incluses du générateur de nombre aléatoire

    for (int i=0; i <11; i++)
        dectoshad(distribNumberDec(gen));


    cout << '\n' << " ---- Shadok to decimal : " << '\n';

    string shaSentence;
    std::uniform_int_distribution<> distribNumberSha(0,3); // limites incluses du générateur de nombre aléatoire

    for (int i=0; i <11; i++)
    {
        for (int i=0; i < (distribNumberSha(gen)+2)*4 ; i++)
            shaSentence+=shadWords[distribNumberSha(gen)];
        shadtodec(shaSentence);
        shaSentence = "";
    }
    //--------END OF TESTS--------
}
