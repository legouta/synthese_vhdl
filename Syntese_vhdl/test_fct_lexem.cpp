#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
using namespace std;

void test_fct_lexem(string nom_fichier_lexem_endl)
{
    char carac;
   
    
    
    ifstream fichier_lexem_endl(nom_fichier_lexem_endl.c_str(), ios::in);  // on ouvre le fichier en lecture
    
    if(fichier_lexem_endl)  // si l'ouverture a réussi

        {  
            string nom_fichier_test_lexem = "/home/damien/Workspace/synthese_vhdl/fichier_test/lexem_test.txt";
 
            // Creation du fichier ou écrasement
            ofstream fichier_test_lexem(nom_fichier_test_lexem.c_str(), ios::trunc);
 
            /* --- Cas d'erreur d'ouverture du fichier --- */
            if ( !fichier_test_lexem )
                {
                    cerr << "Erreur de creation du fichier" << endl;
                    exit(1);
                }
            
            
            while(fichier_lexem_endl.get(carac))
            {
                if (carac=='\n')
                {
                     fichier_test_lexem << ' ' ;

                }
                else if ( carac== ';')
                {
                    fichier_test_lexem << carac << endl ;
                }
                
                else
                {
                    fichier_test_lexem << carac ;
                }

            }
    }
}