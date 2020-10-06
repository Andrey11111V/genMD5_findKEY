#include "threadheap.h"

std::ofstream fileOut;

std::vector<key_frame> temp_buff;


threadHeap::threadHeap(std::ofstream &file)
{
    fileOut.swap(file);
    def_max_thread();
}

void input_answer(avt avt_t, key_frame frame_v,/* std::ofstream fileOut,*/ bool open_file)
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
}

void threadHeap::start_theard(avt& avt_t, key_frame& frame_v/*, std::ofstream fileOut*/)
{
    bool open_file = fileOut.is_open();

    heap_thread.push_back(std::thread(input_answer, avt_t, frame_v/*, std::move(fileOut)*/, open_file));

    if(heap_thread.size() >= count_thread_sys)
        end_thread();
}

//clear heap thread
void threadHeap::end_thread()
{
    unsigned long i = 0;

    while(i < heap_thread.size())
    {
        heap_thread[i].join();
        ++i;

    }
    heap_thread.clear();
}

void threadHeap::write_file()
{

    size_t i = 0;

    if(fileOut.is_open())
    while (i < temp_buff.size())
    {
        fileOut << "Key: " << temp_buff[i].key << " \tMD5:" << temp_buff[i].MD5 << std::endl;
        ++i;
    }

}
