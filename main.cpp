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

    avt* avt_r = nullptr;
    readFile file_read("exampleTest");

    if((avt_r = file_read.getAvt()) == nullptr)
    {
        std::cout << "Not create boron for serach key  an hash of MD5" << std::endl;
        return 1;
    }

    generateMD5 gerMD5;
    gerMD5.generate(0, 10000000, avt_r);

    /*change function generate, change variable avt on variable vector<key_frame>*/
    /*
    generateMD5 md;
    md.generate(0,10000000, nullptr);
    */

    return 0;
}
