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
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;

void synthese(tree<string> &tr, string path_synthese, string path_signaux_interm,string path_portes_interm)
{
    
    tree<string>::iterator it;
    it=tr.begin();
    int rootdepth=tr.depth(it);
    stringstream a_ecrire;
    a_ecrire.clear();
    list<string> portes_util;
    string tempo;
    string tempo2;
    string    chemin_5 = "/home/damien/Workspace/synthese_vhdl/fichier_test/arbre.txt";

    a_ecrire<<"library portes;"<<endl<<"use portes.cell.all;"<<endl;
    fct_write_file(a_ecrire.str(),path_synthese);
    
    portes_util.clear();

    while(it!=tr.end())
    {
        if(*it=="library")
        {      
            it++;
            
            while(tr.depth(it)-rootdepth==1)
            {
                a_ecrire.clear();
                a_ecrire<<"library "<<*it<<";"<<endl;
                fct_write_file(a_ecrire.str(),path_synthese);
                it++;
            }
            
            a_ecrire.clear();
            a_ecrire<<endl;
            fct_write_file(a_ecrire.str(),path_synthese);
            
            
        }
        
        if(*it=="use")
        {      
            it++;
            
            while(tr.depth(it)-rootdepth==1)
            {
                a_ecrire.clear();
                a_ecrire<<"use "<<*it;
                it++;
                while(tr.depth(it)-rootdepth==2)
                {
                    a_ecrire<<"."<<*it;
                    it++;
                }
                a_ecrire<<";"<<endl;
                fct_write_file(a_ecrire.str(),path_synthese);
                
            }
            
        }
        
        if(*it=="entity")
        {      
            it++;
            a_ecrire.clear();
            tempo=*it;
            a_ecrire<<endl<<"entity "<<*it<<" is"<<endl<<"port ("<<endl;
            fct_write_file(a_ecrire.str(),path_synthese);
            a_ecrire.clear();
            it++;
            
            while(tr.depth(it)-rootdepth==2)
            {
                a_ecrire.clear();
                a_ecrire<<*it<<" : ";
                it++;
                
                if(tr.depth(it)-rootdepth==3)
                {
                    a_ecrire<<*it<<" ";
                    it++;
                }
                else
                {
                    cout<<"erreur : manque in ou out dans arbre"<<endl;
                }
                
                if(tr.depth(it)-rootdepth==4)
                {
                    a_ecrire<<*it;
                    it++;
                }
                else
                {
                    cout<<"erreur : manque type dans arbre"<<endl;
                }
                if(tr.depth(it)-rootdepth==5)
                {
                    a_ecrire<<"(";
                    while(tr.depth(it)-rootdepth==5)
                    {
                        a_ecrire<<" "<<*it;
                        it++;
                    }
                    a_ecrire<<")";
                }
                    
                if(tr.depth(it)-rootdepth==0)
                {
                    a_ecrire<<")";
                }
                a_ecrire<<";"<<endl;
                fct_write_file(a_ecrire.str(),path_synthese);
                
            }
            a_ecrire.clear();
            a_ecrire<<"end "<<tempo<<";"<<endl;
            fct_write_file(a_ecrire.str(),path_synthese);
        }
        
        if(*it=="architecture")
        {
            it++;
            tempo2=*it;
            a_ecrire.clear();
            a_ecrire<<endl<<"architecture "<<*it<<" of ";
            it++;
            if(tr.depth(it)-rootdepth==2 && *it==tempo)
            {
                a_ecrire<<*it<<" is"<<endl;
                
            }
            else
            {
                cout<<"l'architecture n'appartient à aucune entitée déclarée"<<endl;
            }
            
            fct_write_file(a_ecrire.str(),path_synthese);
            a_ecrire.clear();
            it++;
        
        if(*it=="declaration")
        {
            it++;
            
                
                it++;
                while(tr.depth(it)-rootdepth==4)
                {
                    a_ecrire.clear();
                    a_ecrire<<"signal ";
                    a_ecrire<<*it<<" : ";
                    it++;
                                
                    if(tr.depth(it)-rootdepth==5)
                    {
                        a_ecrire<<*it;
                        it++;
                    }
                    else
                    {
                        cout<<"erreur : manque type dans arbre"<<endl;
                    }
                    if(tr.depth(it)-rootdepth==6)
                    {
                        a_ecrire<<"(";
                        while(tr.depth(it)-rootdepth==6)
                        {
                            a_ecrire<<" "<<*it;
                            it++;
                        }
                        a_ecrire<<")";
                    }
                
                    
                    a_ecrire<<";"<<endl;
                    fct_write_file(a_ecrire.str(),path_synthese);
                
                }
        }
            

    }
        if(*it=="affectation")
        {
            synt_affec(tr,it,path_synthese, path_signaux_interm, path_portes_interm, portes_util);
        }
        
        it++;
    }  
    recopie_fichier(path_synthese,path_signaux_interm);
    recopie_fichier(path_synthese,path_portes_interm);
}    
