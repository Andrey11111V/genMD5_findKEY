#include <iostream>
#include "md5.h"
#include "generatemd5.h"
#include "readfile.h"

/*
 * need read list to avt and generate md5list to thread? need testing this metod
 */

using namespace std;

int main(int argc, char *argv[])
{
    generateMD5 gerMD5;

    if(argc == 2)
    {
        std::ofstream fmyOut(argv[1]);

        gerMD5.getFileOut(fmyOut);

        if(!gerMD5.setFileOut_is_open())
            std::cout << "Unable to open/greate file \n";
        else
            std::cout << "Write to " << argv[1] << std::endl;
    }

    avt* avt_r = nullptr;
    readFile file_read("exampleTest");

    if((avt_r = file_read.getAvt()) == nullptr)
    {
        std::cout << "Not create boron for serach key  an hash of MD5" << std::endl;
        return 1;
    }


    gerMD5.generate(0, 10000000, avt_r);   

    return 0;
}
