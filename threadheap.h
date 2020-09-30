#ifndef THREADHEAP_H
#define THREADHEAP_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include <shared_mutex>

#include "md5.h"
#include "avt.h"
#include "struct_frame.h"

class threadHeap
{
private:
    unsigned long count_thread_sys = 0;//maximun number of threads in OS
    void def_max_thread();//definition max number thread
    //void input_answer(avt avt_t, key_frame frame_v, /*std::ofstream fileOut,*/ bool open_file);

    std::vector<std::thread> heap_thread;


public:
    threadHeap(std::ofstream &file); //{fileOut.swap(file); def_max_thread();};
    //void get_fileOut(std::ofstream file_Out){fileOut = std::move(file_Out);}
    void start_theard(avt& avt_t, key_frame& frame_v/*, std::ofstream fileOut*/);
    void end_thread();

    //temp
    void write_file();
};

#endif // THREADHEAP_H
