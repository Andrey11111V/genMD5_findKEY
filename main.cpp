#include <iostream>
#include "md5.h"
#include "generatemd5.h"

using namespace std;

int main()
{
    generateMD5 md;
    avt* at = new avt;

    md.generate(0,10000000, at);

    std::cout << "genrate md5 ending" << std::endl;

    at->~avt();

    return 0;
}
