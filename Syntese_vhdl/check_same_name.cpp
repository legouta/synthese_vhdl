#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;


int check_same_name(list<string> &liste_nom,int erreur)
{
    
    
    list<string>::iterator i=liste_nom.begin();
    list<string>::iterator j=liste_nom.begin();
    
 
    while(i!=liste_nom.end() && erreur==0)
    {
        j=liste_nom.begin();
        while(j!=liste_nom.end() && erreur==0)
        {
            if(i !=j)
            {
                if(*i == *j)
                {
                    cout<<"meme nom déclaré '"<<*j<<"'"<<endl;
                    erreur=1;
                }
                else
                {
                    
                }                
            }
            
        j++;
        }
        i++;
    }

 return erreur;   
}
