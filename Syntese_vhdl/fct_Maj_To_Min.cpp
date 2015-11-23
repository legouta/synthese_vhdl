#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
using namespace std;


string fct_Maj_To_Min(string path_fichier) {
    
  char caractere;
  stringstream fich_min;
  
  
    ifstream fichier(path_fichier.c_str(), ios::in);  // on ouvre le fichier en lecture
    
 

        if(fichier)  // si l'ouverture a réussi

        {                    
                
            while(fichier.get(caractere)) 
            {
             if (caractere >= 0x41 and caractere <= 0x5A)  // valeur decimale code ascii ( majuscule)
                {
                 caractere = caractere + 0x20;
                 
                 fich_min << caractere;     //<<endl;
                }
             else
                {
                  fich_min << caractere;    //<<endl;
                }
            }
            
        fichier.close();
        }

          
         
        

        else { // sinon

                cout << "Impossible d'ouvrir le fichier" << endl;
             }

 
  return fich_min.str();
}

