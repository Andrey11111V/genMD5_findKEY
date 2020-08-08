#include <iostream>
#include "md5.h"

using namespace std;

int main()
{

    unsigned char string[16] = {0};
    char* s = nullptr;

    string[0] = (char) 0;
    string[1] = (char) 255;
    string[2] = (char) 123;
    string[3] = (char) 89;
    string[4] = (char) 0;
    string[5] = (char) 0;
    string[6] = (char) 0;
    string[7] = (char) 255;
    string[8] = (char) 123;
    string[9] = (char) 89;
    string[10] = (char) 0;
    string[11] = (char) 0;
    string[12] = (char) 255;
    string[13] = (char) 123;
    string[14] = (char) 89;
    string[15] = (char) 0;

    s =  MDPrint(string);

    for(int i = 0; i < 32; ++i)
    {

        printf("%c%c \n", s[i], s[i+1]);
        ++i;

    }

    return 0;
}
