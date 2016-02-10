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

void synth(tree<string> &tr, tree<string>::iterator &a, string &path_signaux_interm, string &path_portes_interm, list<string> &portes_util,list<string> &liste_nom,list<string> &liste_type);

void synth_source_bis(tree<string> &tr, tree<string>::iterator it, string path_signaux_interm, string path_portes_interm, list<string> &portes_util, list<string> &liste_nom, list<string> &liste_type)
{
    int rootdepth=tr.depth(it); //au niveau de "affectation"
    tree<string>::iterator a=it, b;
    stringstream a_ecrire;
    a_ecrire.clear();
    int nb_fils_affec=0;
    string source_a;
    string operateur;
    string source_b;
    string destination;
    bool fait=false;
    
    a++;
    while(tr.depth(a)-rootdepth>=1)
    {
        if(*a=="sources_bis")
	{
            synth_source_bis(tr,a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type);
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
                synth(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type);                
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
                synth(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type);                
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
                synth(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type);                
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
                synth(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type);                
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
                synth(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type);                
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
                synth(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type);               
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
                synth(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type);               
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
            
            
            
    if(nb_fils_affec==3)
    {
        a++;
        source_a=*a;
        a++;
        operateur=*a;
        a++;
        source_b=*a;
        destination=creer_sig_int(path_signaux_interm,liste_nom,liste_type);
        synth_porte(source_a,operateur,source_b, destination, path_portes_interm, portes_util, path_signaux_interm,liste_nom,liste_type);
    }
    
   // il faut remplacer source_bis par destination créée juste au dessus
    cout<<"nb fils affec bis = "<<nb_fils_affec<<endl;


}


void synth(tree<string> &tr, tree<string>::iterator &a, string &path_signaux_interm, string &path_portes_interm, list<string> &portes_util, list<string> &liste_nom,list<string> &liste_type )
{
    string destination, source_a, source_b, operateur;
    
    destination=creer_sig_int(path_signaux_interm,liste_nom,liste_type);
    a--;
    source_a=*a;
    tr.insert(a,destination);//ajoute sibling justa avant a
    tr.erase(a);
    operateur=*a;
    a=tr.erase(a);//supprime *a et incrémente
    source_b=*a;
    a=tr.erase(a);
    synth_porte(source_a,operateur,source_b, destination, path_portes_interm, portes_util, path_signaux_interm,liste_nom,liste_type);
}