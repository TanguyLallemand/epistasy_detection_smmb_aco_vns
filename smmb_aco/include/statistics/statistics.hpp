#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <list>

#include "parameters_parsing.hpp"
#include "global.hpp"

// liste des trucs à implémenter qui sont liés aux STATISTICS_H
    //test d'indépendance du chi 2
    //fonction pour trouver la pvalue d'une solution
    //test d'indépendance du chi 2 conditionnellement a une variable

class statistics
{
public:
    // constructor
    statistics(boost_matrix _genos_matrix, parameters_parsing _params);



private:

    parameters_parsing _params;

    //variables initialisée par le constructeur à partir de params
    boost_vector _eta; // vecteur de poids indiquant des connaissances a priori pour les variables. A traiter comme un vecteur. Car on a peut etre une idee sur certain SNP, ces connaissances viendraient de publis, si on ne sais rien on met eta en uniforme. eta pourrait tres bien etre un fichier texte avec des connaissances a priori qui serait vectorisé
    boost_vector _tau;//tau doit etre un vecteur de la taille du nombre de SNP
    double _alpha_phero; // Deux constantes utilisées pour ajuster les poids respectifs entre les taux de phéromones et les connaissances a priori. Y a peut etre des SNPs qu on connait et donc on lui donne une bonne note. Ca permet donc de regler le cursuer entre importance des phéromones et importance des connaissances a priori
    double _beta_phero;




};

#endif
