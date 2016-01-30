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

list<string>::iterator range_affectation_seq_cond(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_affectation_conditionnelle, list<string> liste)
{   
    //cout<<"on range une affectation conditionnelle"<<endl;
    list<string>::iterator a,b,d;
    int e=0,c=0 ;
    tree<string>::iterator i_source;
    tree<string>::iterator i_operator;
    tree<string>::iterator i_source_de_la_condition;
    tree<string>::iterator i_elsif;
    tree<string>::iterator i_affectation_conditionnelle_bis;
    tree<string>::iterator i_affectation, i_else;

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
            //cout<< "ski----"<<*a<<endl;
            if(c==0)
            { 
             //   i_source=tr.append_child(i_source_de_la_condition,"sources");
                range_source_A(a,tr,i_source_de_la_condition);
            }
            a++;
            i_operator=tr.append_child(i_source_de_la_condition,*a);
            a++;
            c=1;
            a=range_source_B(a,tr,i_source_de_la_condition);
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
    //cout<<"en sortie du rangement de condition on a : "<<*a<<endl;
    
   
    a++;
    b=a;
    b++;
    //cout<<"avant le rangement des affectations conditionnelles on a : "<<*a<<" et b : "<<*b<<endl;

    while(*a!="end" && *b!="if")
    {
        if(*a=="if")
        {
            i_affectation_conditionnelle_bis=tr.append_child(i_affectation_conditionnelle,"affectation_conditionnelle");
            a=range_affectation_seq_cond(a,tr,i_affectation_conditionnelle_bis, liste);
        }
        
        if(*a=="elsif")
        {
           i_elsif=tr.append_child(i_affectation_conditionnelle,"elsif");
           a=range_affectation_seq_cond(a,tr,i_elsif, liste); 
           a--;
           a--;
           a--; //car 1 seul endif, meme si elsif
        }
        
        if(*b==":="||*b=="<=")
        {
            i_affectation=tr.append_child(i_affectation_conditionnelle,"affectation");
            a=range_affectation(a,tr,i_affectation);
        }
        
        if(*a=="else")
        {
          //  i_else=tr.append_child(i_affectation_conditionnelle,"else");
          //  a=while_conditionnel(a,tr,i_else, liste);
           //a--;
        }
        a++;
        b=a;
        if(a!=liste.end())
        {
            b++;
        }
        
        
        //cout<<*a<<" "<<*b<<endl;
        
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
   
    a++;
    a++;
    //cout<<"on renvoie : "<<*a<<endl;
    return a;
   
    
}