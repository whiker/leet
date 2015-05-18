#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "qh_vector.h"

int main(int argc, char* argv[])
{
    qh::vector<int> num_vect;
    num_vect.push_back(1);

#ifdef WIN32
    system("pause");
#endif

    return 0;
}
