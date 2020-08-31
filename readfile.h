#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "struct_frame.h"
#include "avt.h"

#define MD5_SIZE_R 32

class readFile
{
private:
    avt* avt_read = nullptr;
    std::vector<key_frame> frame_list;
    bool check_char(std::string line); //check charcter read of line from file

public:
    readFile(std::string name_file);
    ~readFile();

    avt* getAvt() {return avt_read;};


};

#endif // READFILE_H
