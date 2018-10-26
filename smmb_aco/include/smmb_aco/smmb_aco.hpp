#ifndef SMMB_ACO_HPP
#define SMMB_ACO_HPP

#include <list>
#include "parameters_parsing.hpp"
#include <boost/numeric/ublas/matrix.hpp>
#include "file_parsing.hpp"
class smmb_aco
{
public:
    /*
    Parametres a donner, il faut donc les filer au constructeur?
    D: Matrice de genotype
    T: Vecteur de phénotype
    n_it: nombre d'itération ACO
    n_ants: nombre de fourmis
    K: Taille du sous ensemble de variable echantilloné à partir de D, pour chaque fourmis
    n_it_n: nombre d'itération maximale qui force l'exploration de l'espace de recherche dans Markov Blanket
    global_alpha: seuil pour erreur de type I global
    Parametres liés a l'ACO:
    tau_0: valeur intiale pour un tax de phéromone de chaque variable
    rau, lambda: Deux constantes utilisees pour mettre a jour lers taux de phéromone
    tau: vecteur indiquant les poids de connaissance a priori pour les variables
    eta:
    alpha, beta: Deux constantes utilisees pour ajuster les poids respectifs entre les taux de phéromones et les connaissances a priori
    */
// Constructeur
    smmb_aco(boost::numeric::ublas::matrix<int> genotype_matrix, boost::numeric::ublas::matrix<int> phenotype_matrix, size_t n_it, size_t n_ants, int K, size_t n_it_n, double alpha, int tau_0, int rau, int tau, int eta, int alpha_stat, int beta);

    list<unsigned> learn_MB(boost::numeric::ublas::matrix<int> genotype_matrix, boost::numeric::ublas::matrix<int> phenotype_matrix, int K, size_t n_it_n, double alpha, int mem_a/*, P*/);

    void forward(bool MB_modifie, list<unsigned> MB_a, size_t n_it_n, int j/*, P*/, boost::numeric::ublas::matrix<int> genotype_matrix, int K );
    
    void backward(list<unsigned> MB_a, boost::numeric::ublas::matrix<int> phenotype_matrix, double alpha);
    
    void run(boost::numeric::ublas::matrix<int> genotype_matrix,int T, int K, size_t n_it_n, size_t n_ants);

private:
    float p_valeur;
    int s;
    int mem_a;
    // mettre les types     P;
    double alpha;
    // mettre les types     MB_A;
    int j;
    int K;
    bool MB_modified;
    // mettre les types     S;
    parameters_parsing _params;
};
#endif
