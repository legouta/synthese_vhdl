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
#include "tree.hh"
using namespace std;


list<string>::iterator range_instrcutions_sequentielles(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_range_instructions_sequentielles, tree<string>::iterator i_process)
{
    list<string>::iterator a,b,c;
    tree<string>::iterator i_liste_sensi;
    tree<string>::iterator i_menbre_liste;
    tree<string>::iterator i_declaration;
    tree<string>::iterator i_type_declaration;
    tree<string>::iterator i_nom_signal;
    a=i;
    b=a;
    b++;
    if(*b=="(")
    {
        i_liste_sensi=tr.append_child(i_process,"liste_de_sensibilité");
        b++;
        while(*b!=")")
        {
            i_menbre_liste=tr.append_child(i_liste_sensi,*b);
            b++;
            if(*b==",")
            {
                b++;
            }
        }
    }
    else
    {
        cout << " erreur process manque liste de sensibilité"<<endl;
    }
   
     b++;   
        if(*b !="begin")
        {
            i_declaration=tr.append_child(i_process,"declaration");
            i_type_declaration=tr.append_child(i_declaration,*b);
            cout << "apres declaration signal que vaut b ? :" << *b << endl;
            if(*b=="signal" )
            {
                c=b;
                c++;
                while(*b=="signal")
                {
                    b++;
                    c=b;
                    c++;

                    if(*c==":")
                    {
                        i_nom_signal=tr.append_child(i_type_declaration,*b);                                
                        b++;                                
                        b=range_signal(b,tr,i_nom_signal);
                        if(*b==";")
                        {
                            b++;
                        }
                        else
                        {
                            cout<<"erreur architecture : manque ';' dans la declaration"<<endl;
                            return b;
                        }
                    }
                    else if (*c==",")
                    {                                    
                        b=range_multi_signaux(b,tr,i_nom_signal,i_type_declaration); //retourne le point virgule de la ligne sur laquelle il est
                        b++;
                    }
                } 
            }
        }
        
 while((*b!="process")) 
    {
        a++;
        b++;
    }
    cout <<" dans range instr seq b vaut: "<<*b<<endl;
    b++; // b sur point virgule
    b++;
    
    return b;
}