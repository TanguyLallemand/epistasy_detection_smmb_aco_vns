#ifndef SMMB_ACO_HPP
#define SMMB_ACO_HPP
#include "global.hpp"
#include <list>
#include "parameters_parsing.hpp"
using namespace std;

class smmb_aco
{
public:
    // constructeur
    smmb_aco(boost_matrix _genotype, boost_matrix _phenotype, parameters_parsing _params);

    //fait tourner l'algo
    void run();

    //test TODO a remove
    boost_vector return_tau();
    //TODO voir pour un destructeur

private:
    //objets récupérés en argument
    boost_matrix _genos_matrix;
    boost_matrix _phenos_matrix;
    parameters_parsing _params;

    //variables initialisée par le constructeur à partir de params
    int _n_it; // nombre d'itérations ACO
    int _n_ant; // nb de fourmis
    int _subset_size; // taille du subset de variables echantillonnees à partir de _genos_matrix pour chaque fourmis (on echantillone donc les SNPs pas les individus)
    int ; //TODO nomme le comme tu veux elle c'est k //taille d'une combinaison de variables echantillonnées parmi _subset_size
    int _n_it_n; // nombre d'itération maximales pour explorer l'espace de recherche
    double _alpha_stat; // seuil de significativité
    double _tau_0; // valeur initiale de phéromone de chaque variable, au debut des temps egalite parfaite car on a pas de connaissance. A traiter comme un vecteur
    //Mise a jour du taux de phéromones
    double _rho; // taux d'évaporation
    double _lambda; // values used in evaporation rates updates
    boost_vector _eta; // vecteur de poids indiquant des connaissances a priori pour les variables. A traiter comme un vecteur. Car on a peut etre une idee sur certain SNP, ces connaissances viendraient de publis, si on ne sais rien on met eta en uniforme. eta pourrait tres bien etre un fichier texte avec des connaissances a priori qui serait vectorisé
    double _alpha_phero; //TODO peut etre a rennomer // Deux constantes utilisées pour ajuster les poids respectifs entre les taux de phéromones et les connaissances a priori. Y a peut etre des SNPs qu on connait et donc on lui donne une bonne note. Ca permet donc de regler le cursuer entre importance des phéromones et importance des connaissances a priori
    double _beta_phero;

    //variables modifiées pendant le run
    boost_vector _tau;//tau doit etre un vecteur de la taille du nombre de SNP

    // fonctions données par la prof
    list<unsigned> learn_MB(list<unsigned> mem_a/*, P*/);
    void forward(bool markov_blanket_modified, list<unsigned> markov_blanket_a, int j/*, P*/);
    void backward(list<unsigned> markov_blanket_a);

    //fonctions qui pourrait rendre le code lisible et modulaire (by JON)
    void add_pheromon(int SNP_pos); //add pheromone on a good SNP
    void evaporate(); //substract rho to all SNP pheromones
};
#endif
