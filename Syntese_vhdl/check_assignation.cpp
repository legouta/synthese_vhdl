#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;


list<string>::iterator check_assignation(tree<string> tr)
{

    tree<string>::iterator x1;
    tree<string>::iterator loc;
    x1=tr.begin();
    cout << "test debut arbre " << *x1 << " ici" <<endl;

    cout << *tr.end();
    int rootdepth=tr.depth(x1);
    int signaldepth;

    while(x1 != tr.end())
    {
        if(*x1 == ":=")
        {
            x1--;
            loc=find(tr.begin(), tr.end(), "variable" );
            loc--;
            signaldepth=tr.depth(loc);
            loc++;
            while(tr.depth(loc)-signaldepth==1)
            {
                loc++;
            }

            cout <<*x1 <<" "<<*loc <<" "<< signaldepth;
            x1++;

        }
        x1++;
    }
}