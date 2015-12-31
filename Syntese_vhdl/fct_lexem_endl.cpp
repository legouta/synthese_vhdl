#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
using namespace std;


void fct_lexem_endl(string nom_fichier_en_min)
{
    char carac;
    char carac_preced;
    char carac_2preced;
    char carac_3preced;
    char carac_4preced;
    char carac_5preced;
    int Current_State = 0;
    int i=0;
    
    
    ifstream fichier_en_min(nom_fichier_en_min.c_str(), ios::in);  // on ouvre le fichier en lecture
    
    if(fichier_en_min)  // si l'ouverture a réussi

        {  
            string nom_fichier_lexem_endl = "/home/damien/Workspace/synthese_vhdl/fichier_test/lexem_endl.txt";
 
            // Creation du fichier ou écrasement
            ofstream fichier_lexem_endl(nom_fichier_lexem_endl.c_str(), ios::trunc);
 
            /* --- Cas d'erreur d'ouverture du fichier --- */
            if ( !fichier_lexem_endl )
                {
                    cerr << "Erreur de creation du fichier" << endl;
                    exit(1);
                }
            
            
            while(fichier_en_min.get(carac))
            {
                
                
                switch ( Current_State ) 
                {
                    case 0:         //début lexeme
                        if((carac >= 0x61 and carac <= 0x7A)
                          or (carac >='0' and carac <= '9'))
                        {
                            Current_State=1;
                        } 
                        else if(carac=='_')
                            {
                                Current_State=7;
                            }
                        else if((carac >= 0x21 and carac <= 0x2F)       // Si carac == carac speciaux
                                or (carac >=0x3A and carac <= 0x40)     // Si carac == carac speciaux
                                or ( carac >= 0x5B and carac<= 0x5E)    // Si carac == carac speciaux
                                or ( carac >= 0x7B and carac<= 0x7E)   // Si carac == carac speciaux 
                                or (carac==0x60))
                        {
                            Current_State=3;                            
                        }
                        
                        else if(carac=='\n')
                            {
                            fichier_lexem_endl << endl;
                                Current_State=0;
                            }
                        
                        break;
                    break;
                    
                    case 1:         //caractère==lettre
                        fichier_lexem_endl << carac_preced ;
                        
                        if((carac >= 0x61 and carac <= 0x7A)
                           or (carac >='0' and carac <= '9'))
                        {
                            Current_State=1;
                        } 
                        
                        else if (carac==32 or carac ==0x09)
                        {                     
                            fichier_lexem_endl << endl;
                            Current_State=0;
                        }
                        
                        else if(carac=='_')   
                        {
                            Current_State=2;
                        }
                        
                        else if((carac >= 0x21 and carac <= 0x2F)       // Si carac == carac speciaux
                                or (carac >=0x3A and carac <= 0x40)     // Si carac == carac speciaux
                                or ( carac >= 0x5B and carac<= 0x5E)    // Si carac == carac speciaux
                                or ( carac >= 0x7B and carac<= 0x7E)   // Si carac == carac speciaux 
                                or (carac==0x60))
                        {
                            Current_State=3;                            
                        } 
                        
                        else if(carac=='\n')
                            {
                                fichier_lexem_endl << endl;
                                Current_State=0;
                            }
                      
                        break;
                        
                    case 2:     //carac precedent == "_"
                        if((carac >= 0x61 and carac <= 0x7A)
                          or (carac >='0' and carac <= '9'))
                        {
                            fichier_lexem_endl << carac_preced;
                            Current_State=1;
                        }
                        else
                        {                            
                            Current_State=7;
                        }
                                                
                    break;
                    
                    case 3: //caractère précédent == carac special
                        i++;
                        if(((carac >= 0x61 and carac <= 0x7A) 
                          or (carac >='0' and carac <= '9'))and i==1)
                        {
                            fichier_lexem_endl << endl << carac_preced << endl;
                            Current_State=1;
                            i=0;
                        }
                        else if(((carac >= 0x61 and carac <= 0x7A) 
                          or (carac >='0' and carac <= '9'))and i==2)
                        {
                            fichier_lexem_endl << endl << carac_2preced <<  carac_preced << endl;
                            Current_State=1;
                            i=0;
                        }
                        
                        else if(((carac >= 0x61 and carac <= 0x7A) 
                          or (carac >='0' and carac <= '9'))and i==3)
                        {
                            fichier_lexem_endl << endl << carac_3preced <<  carac_2preced <<  carac_preced << endl;
                            Current_State=1;
                            i=0;
                        }
                        else if(((carac >= 0x61 and carac <= 0x7A) 
                          or (carac >='0' and carac <= '9'))and i==4)
                        {
                            fichier_lexem_endl << endl << carac_4preced  << carac_3preced <<  carac_2preced <<  carac_preced << endl;
                            Current_State=1;
                            i=0;
                        }
                        else if(((carac >= 0x61 and carac <= 0x7A) 
                          or (carac >='0' and carac <= '9'))and i==5)
                        {
                            fichier_lexem_endl << endl << carac_5preced << carac_4preced  << carac_3preced <<  carac_2preced <<  carac_preced << endl;
                            Current_State=1;
                            i=0;
                        }
                        
                        else if(((carac >= 0x61 and carac <= 0x7A) 
                          or (carac >='0' and carac <= '9'))and i==6)
                        {
                            Current_State=7;
                            i=0;
                        }
                        
                            
                        else if ((carac==32 or carac==0x09)and i==1)
                        {                     
                            fichier_lexem_endl<<endl<<carac_preced << endl;
                            Current_State=0;
                            i=0;
                            
                        }
                        
                        else if ((carac==32 or carac==0x09)and i==2)
                        {                     
                            fichier_lexem_endl << endl << carac_2preced <<  carac_preced << endl;
                            Current_State=0;
                            i=0;
                        }
                        
                        else if ((carac==32 or carac==0x09)and i==3)
                        {                     
                            fichier_lexem_endl << endl<<carac_3preced <<  carac_2preced <<  carac_preced << endl;
                            Current_State=0;
                            i=0;
                        }
                        
                         else if((carac_preced=='-') and (carac=='-'))
                        {
                             if(i==3)
                             {
                                 fichier_lexem_endl << endl <<carac_3preced <<endl;
                             }
                             else if (i==2)
                             {
                                 fichier_lexem_endl << endl <<carac_2preced <<endl;
                             }
                            Current_State=4;
                            i=0;
                        }
                        
                        else if((carac=='\n')and i==1)
                            {
                                fichier_lexem_endl <<endl<< carac_preced <<endl;
                                Current_State=0;
                                i=0;
                            }
                        
                        else if((carac=='\n')and i==2)
                            {
                                fichier_lexem_endl << endl<< carac_2preced << carac_preced <<endl;
                                Current_State=0;
                                i=0;
                            }
                        
                        else if((carac=='\n')and i==3)
                            {
                                fichier_lexem_endl << endl<< carac_3preced << carac_2preced << carac_preced <<endl;
                                Current_State=0;
                                i=0;
                            }
                        
                    break;
                                
                    case 4: //caractères précédents == "--" commentaire
                        if(carac=='\n')
                        {
                            fichier_lexem_endl <<endl;
                            Current_State=0;
                        }
                    break;            
                        
                    case 7:             //erreur
                        cout<< "Grosse erreur de porc" << endl<< carac_3preced <<carac_2preced <<carac_preced <<carac<<endl;
                        
                        return ;
                           
                    
                    break;

                    default:
                    Current_State=0;                        
                    break;
                }
                
                carac_5preced=carac_4preced;
                carac_4preced=carac_3preced;
                carac_3preced=carac_2preced;
                carac_2preced=carac_preced;
                carac_preced=carac;                    
            }
            
           
 
            fichier_lexem_endl.close();
            fichier_en_min.close();
        
        }
}