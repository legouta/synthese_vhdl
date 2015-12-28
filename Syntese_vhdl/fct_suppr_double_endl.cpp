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
#include "fonction.h"
using namespace std;


void fct_suppr_double_endl(string nom_fichier_lexem_endl)
{
    char carac;
    char carac_preced;
    char carac_2preced;
    char carac_3preced;
    int i=0;
    
    
    ifstream fichier_lexem_endl(nom_fichier_lexem_endl.c_str(), ios::in);  // on ouvre le fichier en lecture
    
    if(fichier_lexem_endl)  // si l'ouverture a réussi

        {  
            string nom_fichier_clean = "/home/damien/Workspace/synthese_vhdl/fichier_test/fichier_clean.txt";
 
            // Creation du fichier ou écrasement
            ofstream fichier_clean(nom_fichier_clean.c_str(), ios::trunc);
 
            /* --- Cas d'erreur d'ouverture du fichier --- */
            if ( !fichier_clean )
                {
                    cerr << "Erreur de creation du fichier" << endl;
                    exit(1);
                }
            
            
            while(fichier_lexem_endl.get(carac))
            {
                if(carac_preced == '\n' and carac == '\n') // suppression double endl
                {
                    
                }
                    else 
                    {
                        //////// recup opéraeurs
                if((carac >= 0x21 and carac <= 0x2F)       // Si carac == carac speciaux
                                or (carac >=0x3A and carac <= 0x40)     // Si carac == carac speciaux
                                or ( carac >= 0x5B and carac<= 0x5E)    // Si carac == carac speciaux
                                or ( carac >= 0x7B and carac<= 0x7E)   // Si carac == carac speciaux 
                                or (carac==0x60)) 
                {
                    if ((carac_preced >= 0x21 and carac_preced <= 0x2F)       // Si carac == carac speciaux
                                or (carac_preced >=0x3A and carac_preced <= 0x40)     // Si carac == carac speciaux
                                or ( carac_preced >= 0x5B and carac_preced<= 0x5E)    // Si carac == carac speciaux
                                or ( carac_preced >= 0x7B and carac_preced<= 0x7E)   // Si carac == carac speciaux 
                                or (carac_preced==0x60))
                    {
                        if ((carac_preced=='<' and carac=='=') 
                                or  (carac_preced=='/' and carac=='=')
                                or  (carac_preced=='>' and carac=='=')
                                or  (carac_preced=='*' and carac=='*')
                                or  (carac_preced=='=' and carac=='>'))
                        {
                            fichier_clean << carac;
                        }
                        else
                        {
                            fichier_clean <<endl<< carac;       //si caractères 2 spéciaux mais pas opérateurs
                        
                        }
                    }
                    else
                    {
                        fichier_clean << carac;
                        
                    }
                }
                else
                {
                    fichier_clean << carac;
                        
                }
                    }
                carac_preced = carac;
            }
    }
}