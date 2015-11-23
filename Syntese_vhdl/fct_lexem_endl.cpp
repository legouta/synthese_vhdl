#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
using namespace std;


void fct_lexem_endl(string nom_fichier_en_min)
{
    char caractere;
    char caractere_preced;
    int Current_State = 0;
    
    
    ifstream fichier_en_min(nom_fichier_en_min.c_str(), ios::in);  // on ouvre le fichier en lecture
    
    if(fichier_en_min)  // si l'ouverture a réussi

        {  
            string nom_fichier_lexem_endl = "/home/damien/Desktop/lexem_endl.txt";
 
            // Creation du fichier ou écrasement
            ofstream fichier_lexem_endl(nom_fichier_lexem_endl.c_str(), ios::trunc);
 
            /* --- Cas d'erreur d'ouverture du fichier --- */
            if ( !fichier_lexem_endl )
                {
                    cerr << "Erreur de creation du fichier" << endl;
                    exit(1);
                }
            
            
            while(fichier_en_min.get(caractere))
            {
                
                
                switch ( Current_State ) 
                {
                    case 0:         //début lexeme
                        if((caractere >= 0x61 and caractere <= 0x7A) or (caractere >='0' and caractere <= '9'))
                        {
                            Current_State=1;
                        } 
                        else
                        {
                            if(caractere=='_')
                            {
                                Current_State=7;
                            }
                        }
                    break;
                    
                    case 1:         //caractère==lettre
                        fichier_lexem_endl << caractere_preced;
                        if((caractere >= 0x61 and caractere <= 0x7A) or (caractere >='0' and caractere <= '9'))
                        {
                            Current_State=1;
                        } 
                        
                        else if (caractere==32)
                        {                     
                            fichier_lexem_endl << endl;
                            Current_State=0;
                        }
                        
                        else if(caractere=='_')   
                        {
                            Current_State=2;
                        }
                        
                        else if(caractere==('+' or '-'))
                        {
                            Current_State=4;
                        }
                        break;
                        
                    case 2:
                        if((caractere >= 0x61 and caractere <= 0x7A) or (caractere >='0' and caractere <= '9'))
                        {
                            fichier_lexem_endl << caractere_preced;
                            Current_State=1;
                        }
                        else
                        {                            
                            Current_State=7;
                        }
                    break;
                    
                    case 3:
                        
                    break;
                                
                                
                        
                    case 7:             //erreur
                        cout<< "Grosse erreur de porc" << endl<<caractere_preced <<caractere<<endl<<Current_State;
                        
                        return ;
                           
                    
                    break;

                    default:
                    Current_State=0;                        
                    break;
                }
                
                
                
                
                caractere_preced=caractere;
                
                
            }
            
           
 
            fichier_lexem_endl.close();
            fichier_en_min.close();
        
        }
}