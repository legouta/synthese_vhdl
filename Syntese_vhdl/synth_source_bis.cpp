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


void synth_source_bis(tree<string> &tr, tree<string>::iterator it, string path_signaux_interm, string path_portes_interm, list<string> &portes_util, 
                        list<string> &liste_nom, list<string> &liste_type, list<string> &liste_taille)
{
    int rootdepth=tr.depth(it); //au niveau de "source_bis"
    tree<string>::iterator a=it, b;
    stringstream a_ecrire;
    a_ecrire.clear();
    int nb_fils_affec=0;
    string source_a;
    string operateur;
    string source_b;
    string destination, type_sig_int,taille_sig_int;
   
    bool fait=false;
    //cout<<"dans synth_source_bis "<<*a<<endl;
    
    //cout<<"on rentre dans source bis"<<endl;
    
    a++;
    while(tr.depth(a)-rootdepth>=1)
    {
        if(*a=="sources_bis")
	{
            synth_source_bis(tr,a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type,liste_taille);
            a=it;
            a++;
	}
        a++;
    }
    
    a=it;
    a++;
    while(tr.depth(a)-rootdepth>=1)
    {
        if(tr.depth(a)-rootdepth==1)
	{
            nb_fils_affec++;
	}

	a++;
    }
    
    while(nb_fils_affec>3)
    {
        a=it;
        a++;
        fait=false;
        while(tr.depth(a)-rootdepth>=1 and fait==false)
        {
            if(*a=="=" && fait==false)
            {
                fait=true;
                synth(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type,liste_taille);
                a=it;
                a++;
            }
            a++;
        }
        a=it;
        a++;
        while(tr.depth(a)-rootdepth>=1 and fait==false)
        {
            if(*a=="and" && fait==false)
            {
                fait=true;
                synth(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type,liste_taille);                
                a=it;
                a++;
            }
            a++;
        }
        a=it;
        a++;
        while(tr.depth(a)-rootdepth>=1 and fait==false)
        {
            if(*a=="or" && fait==false)
            {
                fait=true;
                synth(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type,liste_taille);
                a=it;
                a++;                
            }
            a++;
        }
        a=it;
        a++;
        while(tr.depth(a)-rootdepth>=1 and fait==false)
        {
            if(*a=="xor" && fait==false)
            {
                fait=true;
                synth(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type,liste_taille);
                a=it;
                a++;
            }
            a++;
        }
        a=it;
        a++;
        while(tr.depth(a)-rootdepth>=1 and fait==false)
        {
            if(*a=="*" && fait==false)
            {
                fait=true;
                synth(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type,liste_taille);
                a=it;
                a++;
            }
            a++;
        }
        a=it;
        a++;
        while(tr.depth(a)-rootdepth>=1 and fait==false)
        {
            if(*a=="+" && fait==false)
            {
                fait=true;
                synth(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type,liste_taille);
                a=it;
                a++;
            }
            a++;
        }
        a=it;
        a++;
        while(tr.depth(a)-rootdepth>=1 and fait==false)
        {
            if(*a=="-" && fait==false)
            {
                fait=true;
                synth(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type,liste_taille);
                a=it;
                a++;
            }
            a++;
        }
                   
        a=it;
        a++;
        nb_fils_affec=0;
        while(tr.depth(a)-rootdepth>=1)
        {
            if(tr.depth(a)-rootdepth==1)
            {
                nb_fils_affec++;
            }
            a++;
        }
    }
            
            
    a=it;        
    if(nb_fils_affec==3)
    {
        a++;
        a++;
        destination=synth(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type,liste_taille); 
    }
    a=it;
    tr.insert(a,destination);
    tr.erase(it);

  
}
