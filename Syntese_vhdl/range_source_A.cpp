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


list<string>::iterator range_source_A(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_source)
{
    
    string lexem;
    lexem=*i;
    int b=0, c=0;
    
    
    list<string>::iterator a;
    tree<string>::iterator i_source_A;
    tree<string>::iterator i_operator;
    tree<string>::iterator i_affectation;
    
    a=i;
    if(*a==")")
    {
        a--;
       while(*a!="(")
        {
            if(*a==")")
            {
                a--;
                a=detection_parenthese_envers(a,tr);
                a--;
                b=1;
            
            }
            if(*a=="+" || *a=="-" || *a=="and" || *a=="or" || *a=="nand" || *a=="nor" || *a=="xor" || *a=="xnor")
            {
                a--;
                
                if(c==0)
                {   
                                    i_source_A=tr.append_child(i_source,"source");

                    range_source_B(a,tr,i_source_A);
                }              
                a++;
                i_operator=tr.append_child(i_source_A,*a);
                a++;
                c=1;
                range_source_A(a,tr,i_source_A);
                
                
            }
            if(*a=="(" && b==1 && c==0)
            {
                a=i;
                a--;
                a--;
                
            }
            
            a--;
        }  
    }
    else
    {
      i_source_A=tr.append_child(i_source,*a);
      cout << "range source a sans parent"<< endl;
    }
    
    
}