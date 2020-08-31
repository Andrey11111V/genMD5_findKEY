#ifndef GENERATEMD5_H
#define GENERATEMD5_H

#include <cstdint>

#include "md5.h"
#include "avt.h"
#include "struct_frame.h"

#define SIZE_PIN 8

class generateMD5
{
private:
    void count_step(uint32_t value, int32_t* step);

public:
    generateMD5();

    void generate(uint32_t begin_wind, uint32_t end_wind, avt* avtomat);
};

#endif // GENERATEMD5_H
