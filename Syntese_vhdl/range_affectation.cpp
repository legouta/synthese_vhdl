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
    int b=0, c=0, d=0;
    list<string>::iterator a;
    list<string>::iterator x;
    tree<string>::iterator i_destination;
    tree<string>::iterator i_source;
    tree<string>::iterator i_source_a;
    tree<string>::iterator i_source_b;
    tree<string>::iterator i_operator;
    tree<string>::iterator i_symbole_affectation;

    a=i;
    i_destination=tr.append_child(i_affectation,*a);
    a++;
    i_symbole_affectation=tr.append_child(i_affectation,*a);
    a++;
    
    while(*a!=";")
    {
        d++;
        if(*a=="(")
        {
           // cout << " en compte ou pas ? : " << *a<<endl;
            a=detection_parenthese(a,tr);
            a++;
            b=1;
         //   cout <<"blabla----- " << *a << endl;
            
        }
        if(*a=="+" || *a=="-" || *a=="and" || *a=="or" || *a=="nand" || *a=="nor" || *a=="xor" || *a=="xnor" || *a=="*")
        {
            a--;
          //  cout<< "ski----"<<*a<<endl;
            if(c==0)
            { 
                i_source=tr.append_child(i_affectation,"sources");
                range_source_A(a,tr,i_source);
            }
            a++;
            i_operator=tr.append_child(i_source,*a);
            a++;
            c=1;
            a=range_source_B(a,tr,i_source);
        }
        if(*a==";" && b==1 && c==0)
        {
          a=i;
          a++;
          a++;
          
          
        }
        if(*a=="not")
        {
            
        }
        
    a++;
    }
    x=a;
    x--;
    x--;
    if(d==1 && (*x=="<=" || *x==":="))
    {
        x++;
        i_source=tr.append_child(i_affectation,"source");
        i_source_a=tr.append_child(i_source,*x);
    }
   /* if(d==1 && (*x==":="))
    {
        x++;
        i_source=tr.append_child(i_affectation,"source");
        i_source_a=tr.append_child(i_source,*x);
    }*/
   
        /*
        if (*a=="+" || *a=="-" || *a=="and" || *a=="not" || *a=="or" || *a=="nand" || *a=="nor" || *a=="xor" || *a=="xnor" || *a=="abs")
        {
            cout << "dans le while a vaut : " << *a << endl;
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
    cout << "dans fonction a vaut : " << *a << endl;
    }
    
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
    */ 
    
    return a;
        
    
        
           
}