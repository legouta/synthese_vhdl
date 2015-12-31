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


list<string>::iterator range_instructions_concurentes(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_range_instructions_concurentes)
{
    string lexem;
    lexem=*i;
    int c=0, d=0;
    list<string>::iterator a, b;
    tree<string>::iterator i_affectation;
    tree<string>::iterator i_affectation_selective;
    tree<string>::iterator i_affectation_conditionelle;
 


    a=i;
        
    while(*a!="process")
            {
                if(*a=="with")
                {  
                    a++;
                    i_affectation_conditionelle=tr.append_child(i_range_instructions_concurentes,"affectation_conditionelle");
                    //a=range_affectation_conditionelle(i,tr,i_range_affectation_conditionelle);
                    c=1;
                    return a;
                }
                
                else
                {
                    if(*a=="when")
                    {
                        a++;
                        i_affectation_selective=tr.append_child(i_range_instructions_concurentes,"affectation_selective");
                        //a=range_affectation_conditionelle(i,tr,i_range_affectation_conditionelle);
                        c=1;
                        return a;
                    }                    
                }
                if(*a=="<=")
                {
                    d=1;
                }
                a++;
            }
    if(c==0 && d==1) 
    {   
        a=i;
        i_affectation=tr.append_child(i_range_instructions_concurentes,"affectation");
        a=range_affectation(i,tr,i_affectation);
        //a++;
        //while(*a!=";")
        {
        //    if(*a)
        //a=range_affectation(i,tr,i_affectation);
        }
    return a;
    }
    else 
    {
        cout << "erreur d'affectation 'pas de symbole d'affetation'"<<endl;
        return a;
    }
    
  
}