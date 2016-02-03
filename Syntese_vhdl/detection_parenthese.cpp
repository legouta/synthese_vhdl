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


list<string>::iterator detection_parenthese(list<string>::iterator i,tree<string>& tr)
{
    string lexem;
    lexem=*i;
    list<string>::iterator a;
    
    a=i;
    //cout << " en compte ou pas dans parenthese ? : " << *a<<endl;

    a++;
   // cout << " en compte ou pas bis dans parentehse? : " << *a<<endl;

    //cout <<"dans parenthese : ";
    while(*a!=")")
    {
        
        //cout <<*a;
        if(*a=="(")
        {
            a=detection_parenthese(a,tr);
        }
        a++;
        
    }
      // cout <<endl; 
    return a;
}
