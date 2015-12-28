
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;


list<string>::iterator range_archi(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_archi)
{
    
    string lexem;
    lexem=*i;
    
    tree<string>::iterator nom_archi;
    tree<string>::iterator nom_entity;
    tree<string>::iterator loc;
    i++;
    
    nom_archi=tr.append_child(i_archi,*i);
    i++;
    if(*i=="of")
    {
        i++;
        
        loc=find(tr.begin(), tr.end(), "entity" );
        loc++;
        if (*loc==*i)
        {
        nom_entity=tr.append_child(nom_archi,*i);
        }
        else
        {
            cout << "l'architecture "<< *i <<" ne correspond à aucune entity" << endl;
        }
        
    }
    return i;
}