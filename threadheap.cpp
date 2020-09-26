#include "threadheap.h"

void searvInThr(avt avt_t, key_frame frame_v, std::ofstream fileOut, bool open_file)
{
    std::mutex m;

    if(avt_t.search(frame_v.MD5) != MAX_UINT32_AVT)
    {
        if(open_file)
        {
            m.lock();
               fileOut << "Key: " << frame_v.key << "\t hash MD5: " << frame_v.MD5 << std::endl;
            m.unlock();
        }
        else
        {
            m.lock();
                std::cout << "Key: " << frame_v.key << "\t hash MD5: " << frame_v.MD5 << std::endl;
            m.unlock();
        }
    }
}

void threadHeap::def_max_thread()
{
    std::ifstream cmdLineFile("/proc/sys/kernel/pid_max");
    std::string cmdLinee;
    std::getline(cmdLineFile, cmdLinee);

    if(cmdLineFile.is_open())
    {
        cmdLineFile.close();
        count_thread_sys = std::stoi(cmdLinee);

        count_thread_sys = count_thread_sys - (count_thread_sys/10);//10% for systems
    }

    std::cout << "Number of thread = " << cmdLinee << std::endl;
}

void threadHeap::start_theard(avt& avt_t, key_frame& frame_v, std::ofstream fileOut)
{
    size_t i = 0;
    std::thread* temp_tr = nullptr;
    //std::thread* temp_thread = NULL;

    //if(!heap_thread.empty())
    //{
        //while(i<heap_thread.size() && i<count_thread_sys)
        //{
            //temp_tr = new std::thread(searvInThr, avt_t, frame_v, std::move(fileOut), fileOut.is_open());

            heap_thread.push_back(std::thread(searvInThr, avt_t, frame_v, std::move(fileOut), fileOut.is_open()));
            temp_tr = nullptr;

            std::cout << "Size heap = " << heap_thread.size() << std::endl;

            if(heap_thread.size() >= count_thread_sys)
            {
                end_thread();
            }
        //}
           //heap_thread[i].join();

            //++i;

        //heap_thread[i]
    //}
}

void threadHeap::end_thread()
{
    unsigned long i = 0;

    while(i < heap_thread.size())
    {
        heap_thread[i].join();
        //delete heap_thread[i];
        //heap_thread.erase(heap_thread.begin() + i);
        ++i;

    }
    heap_thread.clear();
}


