#ifndef PARAMETERS_PARSING_HPP
#define PARAMETERS_PARSING_HPP

#include "global.hpp"

class parameters_parsing
{
public:
    parameters_parsing();
    void import_line(std::string const& line);

// Reachable from any class that include the current header (Option_file_parsing.hpp)
    int header;
    char separator;
    float alpha;
    float precision;

    unsigned n_smmb_aco_runs;

    unsigned aco_n_iterations;

//    unsigned subset_size_large;
    unsigned aco_n_ants;
    unsigned aco_set_size;
    unsigned subset_size_small;

    unsigned n_trials_to_learn_mbs;
    unsigned n_trials_to_learn_1_mb;

    float aco_tau_init;
    float aco_rho;
    float aco_lambda;
    float aco_eta;
    float aco_alpha;
    float aco_beta;

    unsigned n_mbs;

    string genos_file;
    string phenos_file;

    string output_directory;
    string output_prefix;


private:
    std::vector<std::string> split(std::string const& s, char delim);

};

#endif // PARAMETERS_FILE_PARSING_H
