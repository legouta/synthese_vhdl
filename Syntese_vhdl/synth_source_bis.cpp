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

void synth_source_bis(tree<string> &tr, tree<string>::iterator it)
{
    int rootdepth=tr.depth(it); //au niveau de "affectation"
    tree<string>::iterator a=it;
    stringstream a_ecrire;
    a_ecrire.clear();
    int nb_fils_affec=0;
    string source_a;
    string operateur;
    string source_b;
    string destination;
    
    a++;
    while(tr.depth(a)-rootdepth>=1)
    {
        if(*a=="sources_bis")
	{
            synth_source_bis(tr,a);
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
    if(nb_fils_affec==3)
    {
        destination=creer_sig_int();
        a++;
        source_a=*a;
        a++;
        operateur=*a;
        a++;
        source_b=*a;
        synth_porte(source_a,operateur,source_b);
        
    }
    cout<<"nb fils affec bis = "<<nb_fils_affec<<endl;


}
