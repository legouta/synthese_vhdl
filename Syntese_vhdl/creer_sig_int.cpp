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

string creer_sig_int(string path_signaux_interm, list<string> &liste_nom,list<string> &liste_type)
{
    stringstream sig_int;
    int nb=0;
    bool egal;
    
    
    while(egal==true)
    {
        sig_int.clear();
        sig_int<<"sig_int_"<<nb;
        
        //parcourt le tableau et met egal à true si le signal existe deja
        
        nb++;
    }
    fct_append_file(sig_int.str(),path_signaux_interm);
    
    return sig_int.str();
}