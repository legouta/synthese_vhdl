#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;


list<string> creer_liste_nom(tree<string> tr)
{

    list<string> liste_nom;
    stringstream nom_dans_tr;
    string chaine_nom_dans_tr;
    
    tree<string>::iterator it;
    
    it=tr.begin();
    
    int rootdepth=tr.depth(it);
    
    nom_dans_tr.clear();
    liste_nom.clear();
    
    while(it!=tr.end())
    {
        if(*it=="entity")
        {      
            it++;
            it++; // sur le premier nom
            
            while(*it != "architecture")
            {
                if(tr.depth(it)==2)
                {
                  nom_dans_tr<<*it;
                  chaine_nom_dans_tr=nom_dans_tr.str();
                  liste_nom.push_back(chaine_nom_dans_tr);
                  chaine_nom_dans_tr.clear();
                  nom_dans_tr.str("");
                }
               
                it++;
            }
            it++;
            while(tr.depth(it)-rootdepth !=4)
            {
                it++ ; 
            }
            while(tr.depth(it)-rootdepth !=2)
            {
                if(tr.depth(it)==4)
                {
                    nom_dans_tr<<*it;
                    chaine_nom_dans_tr=nom_dans_tr.str();
                    liste_nom.push_back(chaine_nom_dans_tr);
                    chaine_nom_dans_tr.clear();
                    nom_dans_tr.str("");
                }
                it++;
            }
        }
        if(*it=="process")
        {
            while(tr.depth(it)-rootdepth !=5)
            {
                it++ ; 
            }
            while(tr.depth(it)-rootdepth !=3)
            {
                if(tr.depth(it)==5)
                {
                    nom_dans_tr<<*it;
                    chaine_nom_dans_tr=nom_dans_tr.str();
                    liste_nom.push_back(chaine_nom_dans_tr);
                    chaine_nom_dans_tr.clear();
                    nom_dans_tr.str("");
                }
            it++;
            }   
        }
        it++;
    }
    
    return liste_nom;
}