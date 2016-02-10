#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;

void synt_affec(tree<string> &tr, tree<string>::iterator it, string path_synthese, string path_signaux_interm,string path_portes_interm,list<string> portes_util, list<string> &liste_nom, list<string> &liste_type)
{
    int rootdepth=tr.depth(it); //au niveau de "affectation"
    tree<string>::iterator a;
    stringstream a_ecrire;
    a_ecrire.clear();
    int nb_fils_affec=0;
    string dest;
    
    a=it;
    a++;
    dest=*a;
    a++;
    a++;
    a++;
    while(tr.depth(a)-rootdepth>=1)
    {
        if(*a=="sources_bis")
	{
            synth_source_bis(tr,a,path_signaux_interm, path_portes_interm, portes_util, liste_nom, liste_type);
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
    cout<<"nb fils affec = "<<nb_fils_affec<<endl;


}

