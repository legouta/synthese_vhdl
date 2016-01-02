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


list<string>::iterator range_instrcutions_sequentielles(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_range_instructions_sequentielles)
{
    list<string>::iterator a,b;
    a=i;
    b=a;
    b++;
    
    while((*b!="process")) 
    {
        a++;
        b++;
    }
    //cout <<" dans range instr seq a vaut: "<<*a<<endl;
    //cout <<" dans range instr seq b vaut: "<<*b<<endl;
    b++; // b sur point virgule
    b++;
    
    return b;
}