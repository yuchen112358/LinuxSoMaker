#include "JNIDemoInterface.h"
#include <iostream>
#include <cstdio>
int main(int argc, char const *argv[])
{
    int res = -1;
    void* p = initialize(8);
    run(p);
    res = add(p, 2);
    std::cout<<res<<std::endl;
    finalize(p);
    void* q = initializeString( (char *)"1234567890");
    const char* resStr = substrString(q, 3, 5);
    printf("%s\n", resStr );
    finalizeString(q);
    return 0;
}