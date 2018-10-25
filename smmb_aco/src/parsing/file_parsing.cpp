__file_name#include "file_parsing.hpp"
// on doit open les csv qui contiennent les données et les parser pour les utiliser dans les differentes techniques
#include <iostream>
#include <fstream>
#include <string>
#include <boost/numeric/ublas/matrix.hpp>
using namespace std;
//TODO voir comment on retourne les données exactement (ou on met les identifiants etc)
//TODO faire le constructeur
//TODO voir pour le type de la matrice car je comprends pas comment il fait le bon clement donc pour le moment j'ai mis du string pour que les identifiant passent, on verra bien à la compil ^^ #prepareuranus
//TODO voir si un destructeur est nécessaire
class data_parsing(string file_genotype, string file_phenotype)
{
public:
    void initialise_empty_matrix();
    void data_to_matrix();
    void get_col_nb();
    void get_line_nb();

private:
    string _file_name;
    int _header_size;
    int _row_number;
    int _col_number;
    char _separator;
    boost::numeric::ublas::matrix<string> _matrix;
}

//=================================================
// data_parsing : //TODO constructeur ici
//=================================================

//=================================================
// data_parsing : data_to_matrix
//=================================================
void data_to_matrix()
{
    ifstream file(_file_name);
    string line;
    for (size_t i = 0; i < _col_number; i++) {
        for (size_t j = 0; j < count; j++) {
            getline(file, line, ',')
            _matrix (i, j) = line;
        }
    }
}
//=================================================
// data_parsing : initialise_empty_matrix
//=================================================
void initialise_empty_matrix()
{
    get_line_nb();
    get_col_nb();
    boost::numeric::ublas::matrix<string> data_matrix(string _line_number, string _col_number);
}

//=================================================
// data_parsing : get_line_nb
//=================================================
int get_line_nb(string _file_name)
{
    ifstream file(_file_name);
    string temp;
    _row_number=0;
    if (file) {
        while (getline(file, temp)) {
            _row_number++;
        }
    }
    else
    {
        std::cout << "unable to open : "<< _file_name << '\n';
    }
}

//=================================================
// data_parsing : get_col_nb
//=================================================
void get_col_nb()
{
    ifstream file(_file_name);
    string line;
    int i;
    _col_number=1;
    getline(file, line);
    int lenght = strlen(line);
    for (i = 0; i < lenght; i++) {
        if (line[i]==separator) {
            _col_number++;
        }
    }
}
