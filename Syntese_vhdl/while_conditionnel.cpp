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

list<string>::iterator while_conditionnel(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_else, list<string> liste)
{
    list<string>::iterator a,b,d;
    int e=0,c=0 ;
    tree<string>::iterator i_source;
    tree<string>::iterator i_operator;
    tree<string>::iterator i_source_de_la_condition;
    tree<string>::iterator i_elsif;
    tree<string>::iterator i_affectation_conditionnelle_bis;
    tree<string>::iterator i_affectation, i_else_bis;
    
    a=i;
    
    
while(*a!="end" && *b!="if")
    {
        if(*a=="if")
        {
            i_affectation_conditionnelle_bis=tr.append_child(i_else,"affectation_conditionnelle");
            a=range_affectation_seq_cond(a,tr,i_affectation_conditionnelle_bis, liste);
        }
        
        if(*a=="elsif")
        {
           i_elsif=tr.append_child(i_else,"elsif");
           a=range_affectation_seq_cond(a,tr,i_elsif, liste); 
           a--;
           a--;
           a--; //car 1 seul endif, meme si elsif
        }
        
        if(*b==":="||*b=="<=")
        {
            i_affectation=tr.append_child(i_else,"affectation");
            a=range_affectation(a,tr,i_affectation);
        }
        
        if(*a=="else")
        {
            i_else_bis=tr.append_child(i_else,"else");
            a=while_conditionnel(a,tr,i_else_bis, liste);
            a--;
        }
        a++;
        b=a;
        if(a!=liste.end())
        {
            b++;
        }
        
        //cout<<*a<<" "<<*b<<endl;
        
    }
    return a;
}