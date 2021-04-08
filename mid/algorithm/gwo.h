#ifndef GWO_H_
#define GWO_H_

#include "algo.h"

class GWO : Algorithm {
public:
    vector<double> run(int iterations);
};

#endif // GWO_H_