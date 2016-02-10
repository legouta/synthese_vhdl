#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;


int check_assignation(tree<string> tr,list<string> &liste_nom, list<string> &liste_sous_type, list<string> &liste_taille, int erreur)
{
    if(erreur==1)
    {
        return erreur;
    }
    tree<string>::iterator it;
    tree<string>::iterator loc_in;
    tree<string>::iterator loc_out;

    
    list<string>::iterator i_nom=liste_nom.begin();
    list<string>::iterator i_sous_type=liste_sous_type.begin();
    list<string>::iterator i_taille=liste_taille.begin();
    string nom;
    string taille;
    
    int rang_nom=0;
    int rang_sous_type=0;
     int rang_taille_in=0;
      int rang_taille_out=0;
    
    it=tr.begin();
    

    int rootdepth=tr.depth(it);
    int affec_depth;
  
 
    while(it!=tr.end())
    {
        if(*it=="<=")
        {
            loc_in=it;
            loc_out=it;
            loc_in--;
            loc_in--;
            affec_depth=tr.depth(loc_in);
            loc_in++;
            loc_out++;
            
            i_nom=liste_nom.begin();
            while((*i_nom!=*loc_in) && (i_nom!=liste_nom.end()))
            {
                rang_nom++;
                i_nom++;
            }
            i_sous_type=liste_sous_type.begin();
            while((rang_sous_type!=rang_nom) && (i_sous_type!=liste_sous_type.end()))
            {
                
                rang_sous_type++;
                i_sous_type++;
            }
            if(*i_sous_type=="in" )
                {
                    erreur=1;
                    cout<<*i_sous_type<<endl;
                    cout<<"erreur d'affectation, vous voulez affecter une entrée ! attention, l'entrée est "<< *i_nom <<endl;
                    return erreur;
                }
                else{}
            i_taille=liste_taille.begin();
            while((rang_sous_type!=rang_nom) && (i_sous_type!=liste_taille.end()))
            {
                
                rang_taille_in++;
                i_taille++;
            }
            taille=*i_taille;
            while(tr.depth(loc_out)-affec_depth !=0)
            {
               while(tr.depth(loc_out)-affec_depth !=2)
                {
                    loc_out++;
                }
                if(*loc_out=="sources_bis")
                {
                    loc_out++;
                    nom=*loc_out;
                    i_nom=liste_nom.begin();
                    while((*i_nom!=nom) && (i_nom!=liste_nom.end()))
                    {
                        rang_nom++;
                        i_nom++;
                        if(i_nom==liste_nom.end())
                        {
                            erreur=1;
                            cout<<"vous affectez quelquechose de non declarée: "<<nom;
                            return erreur;
                        }
                    }
                    
                    i_sous_type=liste_sous_type.begin();
                    while((rang_sous_type!=rang_nom) && (i_sous_type!=liste_sous_type.end()))
                    {
                
                        rang_sous_type++;
                        i_sous_type++;
                    }
                    if(*i_sous_type=="out" )
                    {
                        erreur=1;
                        cout<<"erreur d'affectation, vous voulez affecter avec une sortie ! attention, la sortie est "<< *i_nom <<endl;
                        return erreur;
                    }
                    else{}
                    i_taille=liste_taille.begin();
                    while((rang_taille_out!=rang_taille_in) && (i_sous_type!=liste_taille.end()))
                    {
                        rang_taille_out++;
                        i_taille++;
                    }
                    if(*i_taille==taille )
                {
                    erreur=1;
                    cout<<*i_sous_type<<endl;
                    cout<<"erreur d'affectation, vous voulez affecter avec des tailles differentes , la taille de la variable "<< *i_taille <<" est differente de " <<taille<<endl;
                    return erreur;
                }
                else{}
                    
                    while(tr.depth(loc_out)-affec_depth !=0)
                    {
                        loc_out++;
                        loc_out++;
                        if(*loc_out!="sources_bis")
                        {
                            nom=*loc_out;
                            i_nom=liste_nom.begin();
                            while((*i_nom!=nom) && (i_nom!=liste_nom.end()))
                            {
                                rang_nom++;
                                i_nom++;
                                if(i_nom==liste_nom.end())
                                {
                                    erreur=1;
                                    cout<<"vous affectez quelquechose de non declarée: "<<nom;
                                    return erreur;
                                }
                            }
                    
                            i_sous_type=liste_sous_type.begin();
                            while((rang_sous_type!=rang_nom) && (i_sous_type!=liste_sous_type.end()))
                            {
                                rang_sous_type++;
                                i_sous_type++;
                            }   
                            if(*i_sous_type=="out" )
                            {
                                erreur=1;
                                cout<<"erreur d'affectation, vous voulez affecter avec une sortie ! attention, la sortie est "<< *i_nom <<endl;
                                return erreur;
                            }
                            else{}                            
                        }
                        else
                        {
                            loc_out--;
                        }
                        
                    }
                }
                else
                {
                    nom=*loc_out;
                    i_nom=liste_nom.begin();
                    while((*i_nom!=nom) && (i_nom!=liste_nom.end()))
                    {
                        rang_nom++;
                        i_nom++;
                        if(i_nom==liste_nom.end())
                        {
                            erreur=1;
                            cout<<"vous affectez quelquechose de non declarée: "<<nom;
                            return erreur;
                        }
                    }
                    
                    i_sous_type=liste_sous_type.begin();
                    while((rang_sous_type!=rang_nom) && (i_sous_type!=liste_sous_type.end()))
                    {
                
                        rang_sous_type++;
                        i_sous_type++;
                    }
                    if(*i_sous_type=="out" )
                    {
                        erreur=1;
                        cout<<"erreur d'affectation, vous voulez affecter avec une sortie ! attention, la sortie est "<< *i_nom <<endl;
                        return erreur;
                    }
                    else{}
                    while(tr.depth(loc_out)-affec_depth !=0)
                    {
                        
                        loc_out++;
                        loc_out++;
                        nom=*loc_out;
                        i_nom=liste_nom.begin();
                        while((*i_nom!=nom) && (i_nom!=liste_nom.end()))
                        {
                            rang_nom++;
                            i_nom++;
                            if(i_nom==liste_nom.end())
                            {
                                erreur=1;
                                cout<<"vous affectez quelquechose de non declarée: "<<nom;
                                return erreur;
                            }
                        }
                    
                        i_sous_type=liste_sous_type.begin();
                        while((rang_sous_type!=rang_nom) && (i_sous_type!=liste_sous_type.end()))
                        {
                            rang_sous_type++;
                            i_sous_type++;
                        }
                        if(*i_sous_type=="out" )
                        {
                            erreur=1;
                            cout<<"erreur d'affectation, vous voulez affecter avec une sortie ! attention, la sortie est "<< *i_nom <<endl;
                            return erreur;
                        }
                        else{}
                    }
                    
                }
                loc_out++;                
            }
        }
        it++;
    }

 return erreur;   
}

 
