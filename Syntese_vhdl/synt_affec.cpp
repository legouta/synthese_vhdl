#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;

tree<string>::iterator synt_affec(tree<string> &tr, tree<string>::iterator it, string path_synthese, string path_signaux_interm,string path_portes_interm,list<string> &portes_util, 
list<string> &liste_nom, list<string> &liste_type, list<string> &liste_taille)
{
    int rootdepth=tr.depth(it); //au niveau de "affectation"
    tree<string>::iterator a;
    stringstream a_ecrire;
    a_ecrire.clear();
    int nb_fils_affec=0;
    string destination;
    bool fait=false;
    
    a=it;
    a++;
    destination=*a;
    a++;
    a++;
    a++;
    //cout<<*a<<endl;
    while(tr.depth(a)-rootdepth>=1)
    {
        if(*a=="sources_bis")
	{
            //cout<<"on lit source bis"<<endl;
            synth_source_bis(tr,a,path_signaux_interm, path_portes_interm, portes_util, liste_nom, liste_type,liste_taille);
            a=it;
            a++;
            a++;
            a++;
        }
        a++;
    }
    
    a=it;
    a++;
    a++;
    a++;
    a++;
    while(tr.depth(a)-rootdepth>=1)
    {
        if(tr.depth(a)-rootdepth==2)
	{
            nb_fils_affec++;
	}

	a++;
    }
   // cout<<"nb fils affec = "<<nb_fils_affec<<endl;
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
    a++;
    a++;
    a++;
    a++;
    nb_fils_affec=0;
        while(tr.depth(a)-rootdepth>=1)
        {
            if(tr.depth(a)-rootdepth==2)
            {
                nb_fils_affec++;
            }
            a++;
        }
    //cout<<"nb_fils_affec "<<nb_fils_affec<<endl;
    
    a=it;
    if(nb_fils_affec==3)
    {
        a++;
        a++;
        a++;
        a++;
        a++;
        synth_bis(tr, a, path_signaux_interm, path_portes_interm, portes_util,liste_nom,liste_type,liste_taille,destination);
        
    }
    else
    {
        if(nb_fils_affec==1)
        {
            a++;
            a++;
            a++;
            a++;
            fct_append_file(destination,path_portes_interm);
            fct_append_file(" <= ",path_portes_interm);
            fct_append_file(*a,path_portes_interm);
            fct_append_file(" ;",path_portes_interm);
            a_ecrire.str("");
            a_ecrire<<endl;
            fct_append_file(a_ecrire.str(),path_portes_interm);
        }
        else
        {
            cout<<"probleme dams"<<endl;
        }

    }
    a=it;
    tr.insert_after(a,"inutile");
    it=tr.erase(it);
    return it;

}

