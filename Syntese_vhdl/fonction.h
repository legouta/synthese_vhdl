#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef FONCTION_H
#define	FONCTION_H


int  principal_antoine();
int  principal_damien();
string fct_Maj_To_Min(string path_fichier);
void fct_write_file(string code_en_min);
void fct_lexem_endl(string nom_fichier_en_min);
void test_fct_lexem(string nom_fichier_lexem_endl);


#endif	/* FONCTION_H */

