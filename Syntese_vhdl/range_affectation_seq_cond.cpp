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

list<string>::iterator range_affectation_seq_cond(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_affectation_conditionnelle)
{   
    cout<<"on range une affectation conditionnelle"<<endl;
    list<string>::iterator a,b,d;
    int e=0,c=0 ;
    tree<string>::iterator i_source;
    tree<string>::iterator i_operator;
    tree<string>::iterator i_source_de_la_condition;
    
    
    i_source_de_la_condition=tr.append_child(i_affectation_conditionnelle,"source_de_la_condition");
    a=i;
    a++;
    b=a;
    b++;
    while(*a!="then")
    {
        if(*a=="(")
        {
           // cout << " en compte ou pas ? : " << *a<<endl;
            a=detection_parenthese(a,tr);
            a++;
            e=1;
         //   cout <<"blabla----- " << *a << endl;
            
        }
        if(*a=="+" || *a=="-" || *a=="and" || *a=="or" || *a=="nand" || *a=="nor" || *a=="xor" 
                   || *a=="xnor" || *a=="*" || *a=="=" ||*a=="/=" ||*a=="<" ||*a=="<=" ||*a==">" ||*a==">=" || *a=="'")
        {
            a--;
            cout<< "ski----"<<*a<<endl;
            if(c==0)
            { 
                i_source=tr.append_child(i_source_de_la_condition,"sources");
                range_source_A(a,tr,i_source);
            }
            a++;
            i_operator=tr.append_child(i_source,*a);
            a++;
            c=1;
            a=range_source_B(a,tr,i_source);
        }
        if(*a=="then" && e==1 && c==0)
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
    //x=a;
    //x--;
    //x--;
    //if(e==1 && (*x=="<=" || *x==":="))
    //{
      //  x++;
        //i_source=tr.append_child(i_affectation,"source");
        //i_source_a=tr.append_child(i_source,*x);
    //}
   
     
    
    return a;
   
    
}