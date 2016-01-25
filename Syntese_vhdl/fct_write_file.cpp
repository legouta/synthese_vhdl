#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
using namespace std;


void fct_write_file(string chaine_de_carac, string path)
{

// Creation du fichier ou écrasement
ofstream fichier(path.c_str(), ios::trunc);
 
/* --- Cas d'erreur d'ouverture du fichier --- */
if ( !fichier ){
cerr << "Erreur de creation du fichier" << endl;
exit(1);
}
 
fichier << chaine_de_carac << endl;
 
fichier.close();


}
