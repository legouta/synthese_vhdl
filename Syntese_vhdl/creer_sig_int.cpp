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

string creer_sig_int(string path_signaux_interm, list<string> &liste_nom,list<string> &liste_type, string type_sig_int, string taille_sig_int)
{
    stringstream sig_int;
    stringstream a_ecrire;
    int nb=0;
    bool egal=true;
    list<string>::iterator itl;
    a_ecrire.clear();
    a_ecrire<<" ;"<<endl;
    
    
    while(egal==true)
    {
        sig_int.str("");
        sig_int<<"sig_int_"<<nb;
        itl=liste_nom.begin();
        egal=false;
        while(itl!=liste_nom.end())
        {
            if(*itl==sig_int.str())
            {
                egal=true;
            }
            itl++;
        }
        //parcourt le tableau et met egal à true si le signal existe deja
        
        nb++;
    }
    liste_nom.push_back(sig_int.str());
    fct_append_file("signal ",path_signaux_interm);    
    fct_append_file(sig_int.str(),path_signaux_interm);
    fct_append_file(" : ",path_signaux_interm);
    fct_append_file(type_sig_int,path_signaux_interm);
    if(type_sig_int=="std_logic_vector")
    {
        fct_append_file(" ( ",path_signaux_interm);
        fct_append_file(taille_sig_int,path_signaux_interm);
        fct_append_file(" ) ",path_signaux_interm);        
    }
    fct_append_file(a_ecrire.str(),path_signaux_interm);
    return sig_int.str();
}