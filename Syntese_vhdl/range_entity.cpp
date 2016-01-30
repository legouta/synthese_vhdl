
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;


list<string>::iterator range_entity(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_entity)
{
    
    string lexem;
    lexem=*i;
    
    tree<string>::iterator nom_entity;
    tree<string>::iterator i_ports;
    string entity;
    string str_nom_port;
    list<string>::iterator a;
    i++;
    
    nom_entity=tr.append_child(i_entity,*i);
    i++;
    if(*i=="is")
    {
        i++;
        if(*i=="port")
        {
            i++;
            if(*i=="(")
            
                while(1)
                {
                    i++;
                    //cout<<"nom du port : "<<*i<<endl;
                    i_ports=tr.append_child(nom_entity,*i);
                    str_nom_port=*i;
                    i++;
                    //cout<<"apres le port il y a : "<<*i<<endl;
                    if(*i==":")
                    {
                        //cout<<"entre dans port( signal:"<<endl;
                        i--;
                        //cout<<*i<<endl;
                        i++;
                        i=range_port( i,tr,i_ports,str_nom_port);
                        //cout<<"a la sortie de range_port il y a : "<<*i<<endl;
                        
                    }
                    else if (*i==",")
                    {
                        a=i;
                        while(*a!=":")
                        {
                            a++;
                        }
                        range_port(a,tr,i_ports,str_nom_port);
                    }
                    
                    if(*i==")") 
                    {
                        i++;
                        if(*(i)==";")
                        {
                            //cout<<"on sort"<<endl<<*i<<endl;

                            return i++;
                        }
                        else
                        {
                            i--;
                        }
                    }
                }
            
        }
        else
        {
            cout<<"pas de port dans l'entitée : "<<entity<<endl;
        }
            
    }
    else
    {
        cout<<"erreur entity : manque 'is'"<<endl;
       return i;
    }
    /*tree<string>::iterator nom_library;
    i++;
    nom_library=tr.append_child(i_lib,*i);
    i++;
    return i;*/
}