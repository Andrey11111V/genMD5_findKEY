#ifndef FRAME_H
#define FRAME_H


#include <iostream>
#include <string>

struct key_frame{
    std::string MD5;
    std::string key;
};

struct list_hash{
    std::string hash;
    struct list_hash* next;
    struct list_hash* previous;
};

#endif // FRAME_H
