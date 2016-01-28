/* 
 * File:   main.cpp
 * Author: legouta
 *
 * Created on 8 octobre 2015, 14:05
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

void print_tree(const tree<string>& tr, tree<string>::pre_order_iterator it, tree<string>::pre_order_iterator end, string chemin_5);

/*
 * 
 */
int principal_damien() {
//string    chemin_1 = "/.automount/nfs5176/exports/users1/phelma2014/legouta/Bureau/test.txt";
//string    chemin_2 = "/.automount/nfs5176/exports/users1/phelma2014/legouta/Bureau/fichier_en_min.txt";
string    chemin_1 = "/home/damien/Workspace/synthese_vhdl/fichier_test/test.txt";
string    chemin_2 = "/home/damien/Workspace/synthese_vhdl/fichier_test/fichier_en_min.txt";
string    chemin_3 = "/home/damien/Workspace/synthese_vhdl/fichier_test/lexem_endl.txt";
string    chemin_4 = "/home/damien/Workspace/synthese_vhdl/fichier_test/fichier_clean.txt";
string    chemin_5 = "/home/damien/Workspace/synthese_vhdl/fichier_test/arbre.txt";
string    chemin_6 = "/home/damien/Workspace/synthese_vhdl/fichier_test/synthese.txt";
string    chemin_7 = "/home/damien/Workspace/synthese_vhdl/fichier_test/signaux_interm.txt";

list<string> a;
list<string>::const_iterator i=a.begin();
tree<string>::iterator loc;
tree<string> tr;
int erreur=0;


//cout << fct_Maj_To_Min("/.automount/nfs5176/exports/users1/phelma2014/legouta/Bureau/test.txt");
fct_write_file(fct_Maj_To_Min(chemin_1),chemin_2); 
fct_lexem_endl(chemin_2);
fct_suppr_double_endl(chemin_3);
a=fct_liste_lexeme(chemin_4);
erreur=test_syntaxe(a);
for(i=a.begin();i!=a.end();i++)
{cout<<*i<<endl;}
for(i=a.begin();i!=a.end();i++)
{cout<<*i<<endl;}
if(erreur==0)
{
    tr=range_arbre(a);
    print_tree(tr,tr.begin(),tr.end(), chemin_5);
    synthese(tr,chemin_6,chemin_7);
}
return 0;
}


void print_tree(const tree<string>& tr, tree<string>::pre_order_iterator it, tree<string>::pre_order_iterator end, string chemin_5)
{
    stringstream tempo;
    
    tempo.clear();
	if(!tr.is_valid(it)) return;
	int rootdepth=tr.depth(it);
        tempo.clear();
	tempo << "-----" << endl<<"   ";
        fct_write_file(tempo.str(),chemin_5);
	while(it!=end) {
            tempo.clear();
		for(int i=0; i<tr.depth(it)-rootdepth; ++i) 
                {
                    tempo << "~ "; 
                }
            tempo<<(*it) << endl << "   "<< flush;
                    fct_write_file(tempo.str(),chemin_5);
                                        
		++it;
		}
        tempo.clear();
	tempo << "-----" << endl;
        fct_write_file(tempo.str(),chemin_5);
        tempo.clear();
}