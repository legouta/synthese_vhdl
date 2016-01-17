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

list<string>::iterator range_multi_variables(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_nom_variable, tree<string>::iterator i_type_declaration)
{
    string lexem;
    lexem=*i;
    list<string>::iterator a;
    list<string>::iterator j;
    tree<string>::iterator i_type_variable;
    tree<string>::iterator i_complement;

    a=i;
    j=i;
    j++;
    while(*j==","||*j==":")
    {
        i_nom_variable=tr.append_child(i_type_declaration,*i);
        a=i;
        while(*a!=":")
        {
            a++;
        }
        range_variable(a,tr,i_nom_variable);
        i++;
        i++;
        j=i;
        j++;
    }
    while(*i!=";")
    {
        i++;
    }
    return i;
   
}