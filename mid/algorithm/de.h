#ifndef DE_H_
#define DE_H_

#include "algo.h"

class DE : Algorithm {
public:
    vector<double> run(int iterations);
};

#endif // DE_H_