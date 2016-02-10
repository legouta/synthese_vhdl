#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;


void creer_liste(tree<string> &tr,list<string> &liste_nom,list<string> &liste_sous_type, list<string> &liste_type, list<string> &liste_taille)
{

    
    list<string>::const_iterator x=liste_nom.begin();
    stringstream nom_dans_tr;
    string chaine_nom_dans_tr;
    
    tree<string>::iterator it;
    tree<string>::iterator it_tempo;

    tree<string>::iterator tempo;
    int a=0;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
     //////////////////////////////////////CREER_LISTE_NOM///////////////////////////////////////////////////
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    it=tr.begin();
    int rootdepth=tr.depth(it);
    
    nom_dans_tr.clear();
    liste_nom.clear();
    
    while(it!=tr.end())
    {
        if(*it=="entity")
        {      
            it++;
            it++; // sur le premier nom
            
            while(*it != "architecture")
            {
                if(tr.depth(it)==2)
                {
                  nom_dans_tr<<*it;
                  chaine_nom_dans_tr=nom_dans_tr.str();
                  liste_nom.push_back(chaine_nom_dans_tr);
                  chaine_nom_dans_tr.clear();
                  nom_dans_tr.str("");                 
                }
               
                it++;
            }
            it++;
            it++;
            it++;
            if(*it=="declaration")
            {
                while(tr.depth(it)-rootdepth !=4)
                {
                    it++ ; 
                }
                while(tr.depth(it)-rootdepth !=2)
                {
                    if(tr.depth(it)==4)
                    {
                        nom_dans_tr<<*it;
                        chaine_nom_dans_tr=nom_dans_tr.str();
                        liste_nom.push_back(chaine_nom_dans_tr);
                        chaine_nom_dans_tr.clear();
                        nom_dans_tr.str("");
                    }
                it++;
                }
            }
            
        }
        if(*it=="process")
        {
            while(tr.depth(it)-rootdepth !=5)
            {
                it++ ; 
            }
            while(tr.depth(it)-rootdepth !=3)
            {
                if(tr.depth(it)==5)
                {
                    nom_dans_tr<<*it;
                    chaine_nom_dans_tr=nom_dans_tr.str();
                    liste_nom.push_back(chaine_nom_dans_tr);
                    chaine_nom_dans_tr.clear();
                    nom_dans_tr.str("");
                }
            it++;
            }   
        }
        it++;
    }
    for(x=liste_nom.begin();x!=liste_nom.end();x++)
    {cout<<*x<<endl;}
    cout <<endl;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
     //////////////////////////////////////CREER_LISTE_SOUS_TYPE///////////////////////////////////////////////////
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    it=tr.begin();
    
    rootdepth=tr.depth(it);
    
    nom_dans_tr.clear();
    liste_sous_type.clear();
    
    while(it!=tr.end())
    {
        if(*it=="entity")
        {      
            it++;
            it++; // sur le premier nom
            
            while(*it != "architecture")
            {
                if(tr.depth(it)==3)
                {
                  nom_dans_tr<<*it;
                  chaine_nom_dans_tr=nom_dans_tr.str();
                  liste_sous_type.push_back(chaine_nom_dans_tr);
                  chaine_nom_dans_tr.clear();
                  nom_dans_tr.str("");
                }
               
                it++;
            }
            it++;
            while(tr.depth(it)-rootdepth !=3)
            {
                it++ ; 
            }
            while(tr.depth(it)-rootdepth !=2)
            {
                if(tr.depth(it)==3)
                {
                    tempo=it;
                }
                if(tr.depth(it)==4)
                {
                    nom_dans_tr<<*tempo;
                    chaine_nom_dans_tr=nom_dans_tr.str();
                    liste_sous_type.push_back(chaine_nom_dans_tr);
                    chaine_nom_dans_tr.clear();
                    nom_dans_tr.str(""); 
                }
                it++;
            }
        }
        if(*it=="process")
        {
            while(tr.depth(it)-rootdepth !=5)
            {
                it++ ; 
            }
            it--;
            while(tr.depth(it)-rootdepth !=3)
            {
                if(tr.depth(it)==4)
                {
                    tempo=it;
                }
                if(tr.depth(it)==5)
                {
                    nom_dans_tr<<*tempo;
                    chaine_nom_dans_tr=nom_dans_tr.str();
                    liste_sous_type.push_back(chaine_nom_dans_tr);
                    chaine_nom_dans_tr.clear();
                    nom_dans_tr.str("");
                }
            it++;
            }   
        }
        it++;
    }
    for(x=liste_sous_type.begin();x!=liste_sous_type.end();x++)
    {cout<<*x<<endl;}
    cout<<endl;
    
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
     //////////////////////////////////////CREER_LISTE_TYPE///////////////////////////////////////////////////
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    it=tr.begin();
    
    rootdepth=tr.depth(it);
    
    nom_dans_tr.clear();
    liste_type.clear();
    
    while(it!=tr.end())
    {
        if(*it=="entity")
        {      
            it++;
            it++; // sur le premier nom
            
            while(*it != "architecture")
            {
                if(tr.depth(it)==4)
                {
                  nom_dans_tr<<*it;
                  chaine_nom_dans_tr=nom_dans_tr.str();
                  liste_type.push_back(chaine_nom_dans_tr);
                  chaine_nom_dans_tr.clear();
                  nom_dans_tr.str("");
                }
               
                it++;
            }
            it++;
            while(tr.depth(it)-rootdepth !=4)
            {
                it++ ; 
            }
            while(tr.depth(it)-rootdepth !=2)
            {
                if(tr.depth(it)==5)
                {
                    nom_dans_tr<<*it;
                    chaine_nom_dans_tr=nom_dans_tr.str();
                    liste_type.push_back(chaine_nom_dans_tr);
                    chaine_nom_dans_tr.clear();
                    nom_dans_tr.str("");
                }
                it++;
            }
        }
        if(*it=="process")
        {
            while(tr.depth(it)-rootdepth !=5)
            {
                it++ ; 
            }
            while(tr.depth(it)-rootdepth !=3)
            {
                if(tr.depth(it)==6)
                {
                    nom_dans_tr<<*it;
                    chaine_nom_dans_tr=nom_dans_tr.str();
                    liste_type.push_back(chaine_nom_dans_tr);
                    chaine_nom_dans_tr.clear();
                    nom_dans_tr.str("");
                }
            it++;
            }   
        }
        it++;
    }
    for(x=liste_type.begin();x!=liste_type.end();x++)
    {cout<<*x<<endl;}
    cout <<endl;
      
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
     //////////////////////////////////////CREER_LISTE_TAILLE///////////////////////////////////////////////////
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    it=tr.begin();
    
    rootdepth=tr.depth(it);
    
    nom_dans_tr.clear();
    liste_taille.clear();
    
    while(it!=tr.end())
    {
        if(*it=="entity")
        {      
            while(tr.depth(it) !=4)
            {
                it++;
            }
            while(*it != "architecture")
            {
                if(tr.depth(it)==4)
                {
                    it++;
                }
                if(tr.depth(it)==5)
                {
                    while(tr.depth(it) !=2) 
                        {
                            if(a==0)
                            {
                                nom_dans_tr<<*it;
                                chaine_nom_dans_tr=nom_dans_tr.str(); 
                            }
                            it++;
                            it_tempo=it;
                            it_tempo++;
                            if(tr.depth(it_tempo)-rootdepth==1)
                            {
                                a=1;
                            }

                        }
                    if(a==1)
                    {
                        it--;
                        it--;
                        it--;
                        it--;
                        a=0;
                    }
                        liste_taille.push_back(chaine_nom_dans_tr);
                        chaine_nom_dans_tr.clear();
                        nom_dans_tr.str("");
                        it++;
                }
                    if(tr.depth(it)==2)
                    {
                        while(tr.depth(it) !=3)
                        {
                            it++;
                        }
                        liste_taille.push_back("0");
                        chaine_nom_dans_tr.clear();
                        nom_dans_tr.str("");
                    }
                if (*it=="architecture")
                {
                    it--;
                    liste_taille.push_back("0");
                    chaine_nom_dans_tr.clear();
                    nom_dans_tr.str("");
                }
                it++;
            }
            it++;
            while(tr.depth(it)-rootdepth !=5)
                {
                    it++ ; 
                }
            while(tr.depth(it)-rootdepth!=2)
            {
                if(tr.depth(it)==5)
                {
                    it++;
                }
                if(tr.depth(it)==6)
                {
                    while(tr.depth(it) !=4) 
                        {
                            if(a==0)
                            {
                                nom_dans_tr<<*it;
                                chaine_nom_dans_tr=nom_dans_tr.str(); 
                            }
                            it++;
                            it_tempo=it;
                            it_tempo++;
                            if(tr.depth(it_tempo)-rootdepth==2)
                            {
                                a=1;
                            }

                        }
                    if(a==1)
                    {
                        it--;
                        it--;
                        it--;
                        it--;
                        a=0;
                    }
                        liste_taille.push_back(chaine_nom_dans_tr);
                        chaine_nom_dans_tr.clear();
                        nom_dans_tr.str("");
                        it++;
                }
                if(tr.depth(it)==4)
                {
                    while(tr.depth(it) !=5)
                    {
                        it++;
                    }
                    liste_taille.push_back("0");
                    chaine_nom_dans_tr.clear();
                    nom_dans_tr.str("");
                    it--;
                }
                if (tr.depth(it)==2)
                {
                    it--;
                    liste_taille.push_back("0");
                    chaine_nom_dans_tr.clear();
                    nom_dans_tr.str("");
                }
             it++;   
            }
            
        }
        if(*it=="process")
        {
            while(tr.depth(it)-rootdepth !=3)
            {
                while(tr.depth(it)-rootdepth !=6)
                {
                    it++ ; 
                }
                if(tr.depth(it)==6)
                {
                    it++;
                }
                if(tr.depth(it)==7)
                {
                    while(tr.depth(it) !=5) 
                        {
                            if(a==0)
                            {
                                nom_dans_tr<<*it;
                                chaine_nom_dans_tr=nom_dans_tr.str(); 
                            }
                            it++;
                            it_tempo=it;
                            it_tempo++;
                            if(tr.depth(it_tempo)-rootdepth==3)
                            {
                                a=1;
                            }

                        }
                    if(a==1)
                    {
                        it--;
                        it--;
                        it--;
                        it--;
                        a=0;
                    }
                        liste_taille.push_back(chaine_nom_dans_tr);
                        chaine_nom_dans_tr.clear();
                        nom_dans_tr.str("");
                        //it++;
                }
                if(tr.depth(it)==5)
                {
                    while(tr.depth(it) !=6)
                    {
                        it++;
                    }
                    liste_taille.push_back("0");
                    chaine_nom_dans_tr.clear();
                    nom_dans_tr.str("");
                }
                if (tr.depth(it)==3)
                {
                    it--;
                    liste_taille.push_back("0");
                    chaine_nom_dans_tr.clear();
                    nom_dans_tr.str("");
                }
            it++;    
            }
            
        }
     it++; 
     
    }
    for(x=liste_taille.begin();x!=liste_taille.end();x++)
    {cout<<*x<<endl;}
}