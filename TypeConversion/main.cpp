#include <iostream>
#include <memory>
#include "Integer.h"


int main()
{
    Integer a {2};
    Integer b = 5;

    a  = 7;
    int c = a;
    return 0;
}