#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;

void synt_affec(tree<string> &tr, tree<string>::iterator it, string path_synthese)
{
    int rootdepth=tr.depth(it);
    stringstream a_ecrire;
    a_ecrire.clear();
    int nb_fils_affec=0;
    string dest;
    
	it++;
	dest=*it;
	it++;
	it++;
        it++;
	while(tr.depth(it)-rootdepth>=1)
	{
		if(tr.depth(it)-rootdepth==2)
		{
			nb_fils_affec++;
		}

		it++;
	}
cout<<"nb fils affec = "<<nb_fils_affec<<endl;


}

