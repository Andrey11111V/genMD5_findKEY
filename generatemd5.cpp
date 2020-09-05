#include "generatemd5.h"

generateMD5::generateMD5()
{

}

void generateMD5::generate(uint32_t begin_wind, uint32_t end_wind, avt* avtomat)
{

    if(avtomat == nullptr)
    {
        printf("Generate: erroe: variable avtomat NULL");
        return;
    }

    unsigned int gen_Number = begin_wind;
    std::string pin_cod = "00000000";

    key_frame temp_frame;
    int step = 1;    

    while(gen_Number < end_wind)
    {
        count_step(gen_Number, &step);
        //tuck gen_Number in string pin_cod
        pin_cod.replace((SIZE_PIN - step), step, std::to_string(gen_Number));

        temp_frame.key = pin_cod;
        temp_frame.MD5 = MDString(pin_cod.c_str());

        if(avtomat->search(temp_frame.MD5) != MAX_UINT32_AVT)
        {
            if(fileOut.is_open())
                fileOut << "Key: " << temp_frame.key << "\t hash MD5: " << temp_frame.MD5 << std::endl;
            else
                std::cout << "Key: " << temp_frame.key << "\t hash MD5: " << temp_frame.MD5 << std::endl;
        }

        ++gen_Number;
        //++i;
        step = 1;
        temp_frame.MD5.clear();
        temp_frame.key.clear();
    }

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
