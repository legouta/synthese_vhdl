#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
using namespace std;


void fct_write_file(string code_en_min)
{
string nom_fichier_en_min = "/home/damien/Desktop/fichier_en_min.txt";
 
// Creation du fichier ou écrasement
ofstream fichier(nom_fichier_en_min.c_str(), ios::trunc);
 
/* --- Cas d'erreur d'ouverture du fichier --- */
if ( !fichier ){
cerr << "Erreur de creation du fichier" << endl;
exit(1);
}
 
fichier << code_en_min << endl;
 
fichier.close();


}
