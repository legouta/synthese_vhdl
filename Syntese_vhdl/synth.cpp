/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;

string synth(tree<string> &tr, tree<string>::iterator &a, string &path_signaux_interm, string &path_portes_interm, list<string> &portes_util, 
        list<string> &liste_nom,list<string> &liste_type, list<string> &liste_taille)
{
    string destination, source_a, source_b, operateur, type_source_a, taille_source_a;
    list<string>::iterator itl, itl2;
    int rang_signal=0, rang_type=0;

       
    a--;
    source_a=*a;
    //cout<<"source_a "<<source_a<<endl;
     itl=liste_nom.begin();
    while(*itl!=source_a)
    {
        rang_signal++;
        itl++;
    }
    
    itl=liste_type.begin();
    itl2=liste_taille.begin();
    while(rang_signal!=rang_type)
    {
        rang_type++;
        itl++;
        itl2++;
    }
    type_source_a=*itl;
    taille_source_a=*itl2;
    //cout<<"va supprimer : "<<*a<<endl;
    a=tr.erase(a);
    
    operateur=*a;
    if(operateur=="=")
    {
        type_source_a="std_logic";
    }
    destination=creer_sig_int(path_signaux_interm,liste_nom,liste_type,type_source_a,taille_source_a);
    tr.insert(a,destination);
    a=tr.erase(a);//supprime *a et incrémente
    source_b=*a;
    a=tr.erase(a);
    synth_porte(source_a,operateur,source_b, destination, path_portes_interm, portes_util, path_signaux_interm,liste_nom,liste_type,liste_taille);
    return destination;
}