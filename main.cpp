#include <iostream>
#include "md5.h"
#include "generatemd5.h"
#include "readfile.h"

/*
 * need read list to avt and generate md5list to thread? need testing this metod
 */

using namespace std;

int main()
{
    /*
    generateMD5 md;
    avt* at = new avt;

    md.generate(0,10000000, at);

    std::cout << "genrate md5 ending" << std::endl;

    at->~avt();
    */

    avt* avt_r = nullptr;
    readFile file_read("Test_MD5");

    if((avt_r = file_read.getAvt()) == nullptr)
    {
        std::cout << "Not create boron for serach key  an hash of MD5" << std::endl;
        return 1;
    }


    /*change function generate, change variable avt on variable vector<key_frame>*/
    generateMD5 md;
    md.generate(0,10000000, at);

    return 0;
}
