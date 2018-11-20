#ifndef TOOLS_HPP
#define TOOLS_HPP
#include <random>
#include "global.hpp"
class tools
{
public:
    static boost::numeric::ublas::vector<int> sampling(int subset_size, boost::numeric::ublas::vector<float> weight_vector, std::mt19937 rng);
};

#endif
