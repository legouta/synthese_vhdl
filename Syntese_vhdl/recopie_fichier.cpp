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

void recopie_fichier(string path_cible, string path_source)
{
    char caractere;
    string a;
  
  
    ifstream fichier(path_source.c_str(), ios::in);  // on ouvre le fichier en lecture
 
        if(fichier)  // si l'ouverture a réussi

        {  
            while(fichier.get(caractere)) 
            {
                a.clear();                
                a=caractere;
                //cout<<a;
                fct_append_file(a,path_cible);
            }
        }
}