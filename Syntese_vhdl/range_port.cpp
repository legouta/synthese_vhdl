
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;


list<string>::iterator range_port(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_ports, string str_nom_port)
{
    string lexem;
    lexem=*i;
    list<string>::iterator a;
    tree<string>::iterator i_sens_port;
    tree<string>::iterator i_type_port;
    tree<string>::iterator i_complement;

    a=i;
    
    a++;
    if(*a=="in" || *a=="out")
    {
        i_sens_port=tr.append_child(i_ports,*a);
        //cout<<"sens du port :"<<*a<<endl;
        a++;
        i_type_port=tr.append_child(i_sens_port,*a);
        //cout<<"type du port :"<<*a<<endl;
        a++;
        //cout<<"a vaut :"<<*a<<endl;
        if(*a==";" || *a==")")
        {
            //cout<<"on sort de range port"<<endl;
            return a;
        }
        else if(*a=="(")
        {
            while(1)
            {
                a++;
                if(*a==")")
                {  
                    a++;
                    return a;
                }
                else
                {
                    i_complement=tr.append_child(i_type_port,*a);
                    //cout<<"complement : "<<*a<<endl;                
                }
            }
        }
    }
    else
    {
        cout<<"erreur sens du port : "<<str_nom_port<<endl;
    }
    /*tree<string>::iterator nom_library;
    i++;
    nom_library=tr.append_child(i_lib,*i);
    i++;
    return i;*/
}