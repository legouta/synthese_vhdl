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


list<string>::iterator detection_parenthese_envers(list<string>::iterator i,tree<string>& tr)
{
    string lexem;
    lexem=*i;
    list<string>::iterator a;
    
    a=i;
    a--;
    
    while(*a!="(")
    {
        
        if(*a==")")
        {
            a=detection_parenthese_envers(a,tr);
        }
        a--;
    }
        
    return a;
}
