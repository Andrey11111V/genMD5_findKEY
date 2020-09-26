#ifndef GENERATEMD5_H
#define GENERATEMD5_H

#include <cstdint>
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <mutex>

#include "md5.h"
#include "avt.h"
#include "struct_frame.h"
#include "threadheap.h"

#define SIZE_PIN 8

class generateMD5
{

private:
    void count_step(uint32_t value, int32_t* step);

    void search(avt avt_t, std::vector <key_frame> frame_v);
    std::ofstream fileOut;

public:    
    generateMD5();    
    void generate(uint32_t begin_wind, uint32_t end_wind, avt& avtomat);
    void getFileOut(std::ofstream& file);

    bool setFileOut_is_open(){return fileOut.is_open();}
};

#endif // GENERATEMD5_H
