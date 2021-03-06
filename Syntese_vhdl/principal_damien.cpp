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
string    chemin_1 = "/home/damien/Workspace/synthese_vhdl/fichier_test/test_2.txt";
string    chemin_2 = "/home/damien/Workspace/synthese_vhdl/fichier_test/fichier_en_min.txt";
string    chemin_3 = "/home/damien/Workspace/synthese_vhdl/fichier_test/lexem_endl.txt";
string    chemin_4 = "/home/damien/Workspace/synthese_vhdl/fichier_test/fichier_clean.txt";
string    chemin_5 = "/home/damien/Workspace/synthese_vhdl/fichier_test/arbre.txt";
string    chemin_6 = "/home/damien/Workspace/synthese_vhdl/fichier_test/synthese.txt";
string    chemin_7 = "/home/damien/Workspace/synthese_vhdl/fichier_test/signaux_interm.txt";
string    chemin_8 = "/home/damien/Workspace/synthese_vhdl/fichier_test/portes_interm.txt";

list<string> liste_lexemes;
list<string>::iterator i=liste_lexemes.begin(),x, itl;
list<string> liste_nom,liste_sous_type,liste_type,liste_taille;
//list<string>::const_iterator x=liste_nom.begin();
tree<string>::iterator loc;
tree<string> tr;
int erreur=0, rang_signal=0, rang_type=0;

fct_write_file("",chemin_2);
fct_write_file("",chemin_3);
fct_write_file("",chemin_4);
fct_write_file("",chemin_5); 
fct_write_file("",chemin_6);
fct_write_file("",chemin_7);
fct_write_file("",chemin_8);


//cout << fct_Maj_To_Min("/.automount/nfs5176/exports/users1/phelma2014/legouta/Bureau/test.txt");
fct_write_file(fct_Maj_To_Min(chemin_1),chemin_2); 
fct_lexem_endl(chemin_2,chemin_3);
fct_suppr_double_endl(chemin_3,chemin_4);
fct_liste_lexeme(chemin_4, liste_lexemes);
erreur=test_syntaxe(liste_lexemes);


if(erreur==0)
{
    range_arbre(liste_lexemes,tr);
    creer_liste(tr,liste_nom,liste_sous_type,liste_type,liste_taille);
    erreur=check_same_name(liste_nom,erreur);
    print_tree(tr,tr.begin(),tr.end(), chemin_5);
    cout<<"arbre ecrit"<<endl;
   
    

    //for(x=liste_nom.begin();x!=liste_nom.end();x++)
    //{cout<<*x<<endl;}
    //tr2=tr;
    //print_tree(tr,tr.begin(),tr.end(), chemin_8);
    //check_assignation(tr);
    if(erreur==0)
    {
        synthese(tr,chemin_6,chemin_7, chemin_8, liste_nom, liste_type,liste_taille);
    }



    
}
return 0;
}


