
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;


list<string>::iterator range_use(list<string>::iterator i,tree<string> &tr, tree<string>::iterator i_use)
{
    
    string lexem;
    lexem=*i;
    
    tree<string>::iterator nom_library;
    tree<string>::iterator extension;

    i++;
    nom_library=tr.append_child(i_use,*i);
    i++;
    while(1)
    {
        if(*i==".")
        {
            i++;
            extension=tr.append_child(nom_library,*i);
            i++;
        }
        else
        {
            if(*i==";")
            {
                return(i++);
            }
            else
            {
                cout<<"erreur parsage USE"<<endl;
                return i++;                
            }
        }
    }
 return i;
}
