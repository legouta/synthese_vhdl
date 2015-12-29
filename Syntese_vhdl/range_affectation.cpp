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


list<string>::iterator range_affectation(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_affectation)
{
    
    string lexem;
    lexem=*i;
    list<string>::iterator a;
    tree<string>::iterator i_destination;
    tree<string>::iterator i_source;
    tree<string>::iterator i_source_a;
    tree<string>::iterator i_source_b;
    tree<string>::iterator i_operator;
    tree<string>::iterator i_symbole_affectation;

    a=i;
    while(*a!=";")
    {
        if (*a=="+" || *a=="-" || *a=="and" || *a=="not" || *a=="or" || *a=="nand" || *a=="nor" || *a=="xor" || *a=="xnor" || *a=="abs")
        {
            i_destination=tr.append_child(i_affectation,*i);
            i++;
            i_symbole_affectation=tr.append_child(i_affectation,*i);
            i++;
            i_source=tr.append_child(i_affectation,"source");
            i_source_a=tr.append_child(i_source,*i);
            i++;
            i_operator=tr.append_child(i_source,*i);
            i++;
            i_source_b=tr.append_child(i_source,*i);
            return a;       
        
        }
    
        else
        {
                   
        } 
    a++;       
    }
    a=i;
    i_destination=tr.append_child(i_affectation,*a);
    a++;
    i_symbole_affectation=tr.append_child(i_affectation,*a);
    a++;
    i_source=tr.append_child(i_affectation,"source");
    i_source_a=tr.append_child(i_source,*a);
    a++;
    if(*a==";")
    {
        return a;
    }
    else
    {
        cout<<"erreur affectation : manque ';'"<<endl;
        return a;
    }
     
    return a;
        
    
        
           
}