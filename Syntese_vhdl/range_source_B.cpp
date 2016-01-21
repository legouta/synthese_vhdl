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


list<string>::iterator range_source_B(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_source)
{
    
    string lexem;
    lexem=*i;
    int b=0, c=0;
    
    
    list<string>::iterator a;
    tree<string>::iterator i_source_B;
    tree<string>::iterator i_operator;
    tree<string>::iterator i_affectation;
    
    a=i;
    if(*a=="(")
    {
        a++;
       while(*a!=")")
        {
            if(*a=="(")
            {
                //a++;
                a=detection_parenthese(a,tr);
                a++;
                b=1;
            
            }
            if(*a=="+" || *a=="-" || *a=="and" || *a=="or" || *a=="nand" || *a=="nor" || *a=="xor" || *a=="xnor" || *a=="*"
                       || *a=="=" ||*a=="/=" ||*a=="<" ||*a=="<=" ||*a==">" ||*a==">="||*a=="'")
            {
                a--;
                
                if(c==0)
                {  
                    i_source_B=tr.append_child(i_source,"sources_bis");

                    range_source_A(a,tr,i_source_B);
                }

                a++;
                i_operator=tr.append_child(i_source_B,*a);
                a++;
                c=1;
                a=range_source_B(a,tr,i_source_B);
                
            }
            if(*a==";" && b==1 && c==0)
            {
                a=i;
                a++;
                a++;
                
            }
            
            a++;
        }  
    }
    else
    {
      i_source_B=tr.append_child(i_source,*a);
    }
    return a;
    
}