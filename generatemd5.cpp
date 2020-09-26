#include "generatemd5.h"

void search_thread(avt avt_t, key_frame temp_f, bool fileOpen);//, std::ofstream fileOut);

generateMD5::generateMD5()
{

}

void generateMD5::generate(uint32_t begin_wind, uint32_t end_wind, avt& avtomat)
{    

    unsigned int gen_Number = begin_wind;
    std::string pin_cod = "00000000";

    std::vector <key_frame> frame_v;
    threadHeap heap_thr;
    key_frame temp_frame;
    int step = 1;

    while(gen_Number < end_wind)
    {
        count_step(gen_Number, &step);
        //tuck gen_Number in string pin_cod
        pin_cod.replace((SIZE_PIN - step), step, std::to_string(gen_Number));

        temp_frame.key = pin_cod;
        temp_frame.MD5 = MDString(pin_cod.c_str());
        //frame_v.push_back(temp_frame);

        heap_thr.start_theard(avtomat, temp_frame, std::move(fileOut));

        ++gen_Number;
        //++i;
        step = 1;
        temp_frame.MD5.clear();
        temp_frame.key.clear();
    }

    heap_thr.end_thread();
    //search(avtomat, frame_v);
}

void generateMD5::count_step(uint32_t value, int32_t* step)
{
    uint32_t mod_value = 0;

    if((mod_value = (value / 10)) != 0)
    {
        *step += 1;
        count_step(mod_value, step);
    }
}

void generateMD5::getFileOut(std::ofstream &file)
{
    fileOut.swap(file);
}

void search_thread(avt avt_t, key_frame temp_f, bool fileOpen)//, std::ofstream fileOut)
{
    std::mutex m;

    if(avt_t.search(temp_f.MD5) != MAX_UINT32_AVT)
    {
        if(fileOpen)
        {
            m.lock();
               // fileOut << "Key: " << temp_f.key << "\t hash MD5: " << temp_f.MD5 << std::endl;
            m.unlock();
        }
        else
        {
            m.lock();
            std::cout << "Key: " << temp_f.key << "\t hash MD5: " << temp_f.MD5 << std::endl;
            m.unlock();
        }
    }

}

void generateMD5::search(avt avt_t, std::vector <key_frame> frame_v)
{
    //std::vector<std::thread> threads;
    key_frame temp;

    if(frame_v.empty())
    {
        std::cout << "Search. vector is empty" << std::endl;
        return;
    }

    std::vector<std::thread> threads(frame_v.size());

    for(unsigned long i = 0; i < frame_v.size(); ++i)
    {
        threads[i] = std::thread(search_thread, avt_t, frame_v[i], fileOut.is_open());//, fileOut);
    }

    for(unsigned long i = 0; i < frame_v.size(); ++i)
    {
        threads[i].join();
    }
}

