/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include "fonction.h"
using namespace std;


list<string> fct_liste_lexeme(string nom_fichier_clean)
{
    list<string> liste_lexem;
    list<string>::iterator i;
    char carac;
    string lexem;
    
    
    lexem.clear();
    liste_lexem.clear();
    i=liste_lexem.begin();
     ifstream fichier_clean(nom_fichier_clean.c_str(), ios::in);  // on ouvre le fichier en lecture
    
    if(fichier_clean)  // si l'ouverture a réussi

        {
            while(fichier_clean.get(carac))
            {
                if(carac=='\n')
                {   
                    liste_lexem.push_back(lexem);                    
                    lexem.clear();

                }
                else
                {
                    lexem=lexem+carac;
                }
                
            }
        }
     return liste_lexem;
}