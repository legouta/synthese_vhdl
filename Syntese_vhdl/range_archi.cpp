
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;


list<string>::iterator range_archi(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_archi)
{
    
    string lexem;
    lexem=*i;
    list<string>::iterator j;
    tree<string>::iterator i_nom_archi;
    tree<string>::iterator i_process;
    tree<string>::iterator nom_entity;
    tree<string>::iterator loc;
    tree<string>::iterator i_declaration;
    tree<string>::iterator i_type_declaration;
    tree<string>::iterator i_nom_signal;
    tree<string>::iterator i_range_instructions_concurentes;
    tree<string>::iterator i_range_instructions_sequentielles;
    
    i++;
    
    i_nom_archi=tr.append_child(i_archi,*i);
    i++;
    if(*i=="of")
    {
        i++;
        
        loc=find(tr.begin(), tr.end(), "entity" );
        loc++;
        if (*loc==*i)
        {
        nom_entity=tr.append_child(i_nom_archi,*i);
        }
        else
        {
            cout << "l'architecture "<< *i <<" ne correspond à aucune entity" << endl;
        }
        
        i++;
        if(*i=="is")
        {
            i++;
                    if(*i !="begin")
                    {
                        i_declaration=tr.append_child(i_nom_archi,"declaration");
                        i_type_declaration=tr.append_child(i_declaration,*i);
                        if(*i=="signal" )
                        {
                            j=i;
                            j++;
                            while(*i=="signal")
                            {
                                i++;
                                j=i;
                                j++;
                                if(*j==":")
                                {
                                    i_nom_signal=tr.append_child(i_type_declaration,*i);                                
                                    i++;                                
                                    i=range_signal(i,tr,i_nom_signal);
                                    if(*i==";")
                                    {
                                       i++;
                                    }
                                    else
                                    {
                                        cout<<"erreur architecture : manque ';' dans la declaration"<<endl;
                                        return i;
                                    }
                                }
                                else if (*j==",")
                                {                                    
                                    i=range_multi_signaux(i,tr,i_nom_signal,i_type_declaration); //retourne le point virgule de la ligne sur laquelle il est
                                    i++;
                                }
                            } 
                        }
                        
                        
                    }
            //cout <<"ici range archi"<<*i<< endl;
            cout << *i<< endl;
            
                    if(*i=="begin")
                    {
                        i++;
                        j=i;
                        j++;
                        //cout<<"i vaut: " << *i << endl <<"j vaut: "<<*j <<endl;
                        //cout<<"ici debut begin"<<endl;
                        
                        
                        while((*i!="end") && (*j!=*i_nom_archi))
                        //while(*j!=*i_nom_archi)    
                        {
                            if(*i != "process")
                            {
                                loc=find(tr.begin(), tr.end(), "instructions_concurentes" );                                
                                if (*loc!="instructions_concurentes")
                                {                                
                                    i_range_instructions_concurentes=tr.append_child(i_nom_archi,"instructions_concurentes");
                                }                                
                                    i=range_instructions_concurentes(i,tr,i_range_instructions_concurentes,*i_nom_archi);                                
                            }
                            else
                            {
                                cout<< " vue process i vaut : "<< *i << endl;
                                i_process=tr.append_child(i_nom_archi,"process");
                                i_range_instructions_sequentielles=tr.append_child(i_process,"instructions_sequentielles");
                                i=range_instrcutions_sequentielles(i,tr,i_range_instructions_sequentielles,i_process);
                                
                            }
                         //i++;
                         j=i;
                         j++;
                         cout<<"i vaut: " << *i << endl <<"j vaut: "<<*j <<endl;
                        }
                       
                        //*/
                    }
                             
                    else
                    {
                        cout<<"erreur architecture : manque 'begin'"<<endl;
                        return i;                            
                    }
                    
        }
        else
        {
            cout<<"erreur architecture : manque 'is'"<<endl;
            return i;
        }
    }   
    else
    {
       cout<<"erreur architecture : manque 'of'"<<endl;
       return i;
    }
    
    return i;
}