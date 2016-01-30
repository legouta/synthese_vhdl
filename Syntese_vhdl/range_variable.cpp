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


list<string>::iterator range_variable(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_nom_variable)
{
    string lexem;
    lexem=*i;
    list<string>::iterator a;
    tree<string>::iterator i_type_variable;
    tree<string>::iterator i_complement;

    a=i;
    
    a++;
    i_type_variable=tr.append_child(i_nom_variable,*a);
    a++;
    if(*a==";")
    {
        return a;
    }    
    else if (*a=="(")    
    {
        while(1)
            {
                a++;
                if(*a==")")
                {  
                    a++;
                    return a;
                }
                else
                {
                    i_complement=tr.append_child(i_type_variable,*a);
                   // cout<<"complement : "<<*a<<endl;               
                }
            }
    }
    else
    {
        cout<<"problème de déclaration de variable"<<endl;
    }
  
}