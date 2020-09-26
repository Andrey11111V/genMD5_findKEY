#include <iostream>
#include "md5.h"
#include "generatemd5.h"
#include "readfile.h"
#include "threadheap.h"

/*
 * need read list to avt and generate md5list to thread? need testing this metod
 */

using namespace std;

int main(int argc, char *argv[])
{
    generateMD5 gerMD5;

    /*
    if((argc < 2) || (argc >3))
    {
        std::cout << "Entering name file for reading md5 hash \n\t or entering name file for reading md5 hash and entr write find key" << std::endl;
        return 0;
    }

    if(argc == 3)
    {
        std::ofstream fmyOut(argv[2]);

        gerMD5.getFileOut(fmyOut);

        if(!gerMD5.setFileOut_is_open())
            std::cout << "Unable to open/greate file \n";
        else
            std::cout << "Write to " << argv[2] << std::endl;
    }
    */

    avt* avt_r = nullptr;
    readFile file_read(/*argv[1]*/"exampleTest");

    if((avt_r = file_read.getAvt()) == nullptr)
    {
        std::cout << "Not create boron for serach key  an hash of MD5" << std::endl;
        return 1;
    }


    gerMD5.generate(0, 45000, *avt_r);

    //threadHeap temp;

    return 0;
}
