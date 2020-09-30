#include "generatemd5.h"

void search_thread(avt avt_t, key_frame temp_f, bool fileOpen);//, std::ofstream fileOut);

generateMD5::generateMD5()
{

}

void generateMD5::generate(uint32_t begin_wind, uint32_t end_wind, avt& avtomat)
{    

    unsigned int gen_Number = begin_wind;
    std::string pin_cod = "00000000";

    threadHeap heap_thr(fileOut);
    key_frame temp_frame;
    int step = 1;

    while(gen_Number < end_wind)
    {

        fileOut << "Test" << std::endl;

        count_step(gen_Number, &step);
        //tuck gen_Number in string pin_cod
        pin_cod.replace((SIZE_PIN - step), step, std::to_string(gen_Number));

        temp_frame.key = pin_cod;
        temp_frame.MD5 = MDString(pin_cod.c_str());

        heap_thr.start_theard(avtomat, temp_frame/*, std::move(fileOut)*/);

        ++gen_Number;

        step = 1;
        temp_frame.MD5.clear();
        temp_frame.key.clear();


    }

    heap_thr.end_thread();
    heap_thr.write_file();
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
