#include <iostream>

#include "System.h"

int main()
{
    System sys;
    sys.set_pool_file("pool.txt");
    sys.set_computation_file("computation.txt");
    sys.run();
}