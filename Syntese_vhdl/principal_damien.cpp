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
string    chemin_8 = "/home/damien/Workspace/synthese_vhdl/fichier_test/portes_interm.txt";

list<string> a;
list<string>::const_iterator i=a.begin();
list<string> b;
list<string>::const_iterator x=b.begin();
tree<string>::iterator loc;
tree<string> tr,tr2;
int erreur=0;



//cout << fct_Maj_To_Min("/.automount/nfs5176/exports/users1/phelma2014/legouta/Bureau/test.txt");
fct_write_file(fct_Maj_To_Min(chemin_1),chemin_2); 
fct_lexem_endl(chemin_2,chemin_3);
fct_suppr_double_endl(chemin_3,chemin_4);
a=fct_liste_lexeme(chemin_4);
erreur=test_syntaxe(a);


if(erreur==0)
{
    tr=range_arbre(a);
    b=creer_liste_nom(tr);
    //print_tree(tr,tr.begin(),tr.end(), chemin_5);

    for(x=b.begin();x!=b.end();x++)
    {cout<<*x<<endl;}
    //tr2=tr;
    //print_tree(tr,tr.begin(),tr.end(), chemin_5);
    //check_assignation(tr);
    //synthese(tr,chemin_6,chemin_7, chemin_8);



    
}
return 0;
}


