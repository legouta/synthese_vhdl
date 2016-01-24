/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
//#include "fonction.h"
//#include "tree.hh"

using namespace std;

int test_syntaxe(list<string> a)
{
    list<string>::iterator i=a.begin();
    int erreur=0;
    int nb_parenth=0;
    bool affectation=false;
    bool condition=false;

    
    while(i!=a.end())
    {
        
        if(*i=="(")
        {
            nb_parenth++;
        }
        
        if(*i==")")
        {
            nb_parenth--;
        }
        if(*i=="if")
        {
            condition=true;
        }
        if(*i=="then")
        {
            condition=false;
        }
        
        if((*i=="<="||*i==":=") && condition==false)
        {
            affectation=true;
        }
        
        if((*i=="end"||*i=="if"||*i=="library"||*i=="use"||*i=="entity"||*i=="architecture"||
            *i=="of"||*i=="signal"||*i=="variable"||*i=="else"||*i=="then") && affectation==true)
        {
            erreur=1;
            cout<<"##erreur : plusieurs affectation manque point virgule !!! "<<*i<<endl;
            affectation=false;
        }
        
        if(*i==";")
        {
            affectation=false;
        }
        
        i++;
        
    }
    
    if(nb_parenth!=0)
    {
        erreur=1;
        cout<<"##erreur : nombre de parenthèse non correct !!!"<<endl;
    }
    
    
    return erreur;
}