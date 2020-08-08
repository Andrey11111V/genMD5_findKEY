#include "generatemd5.h"

generateMD5::generateMD5()
{

}

void generateMD5::generate(uint32_t begin_wind, uint32_t end_wind, avt* avtomat, std::ofstream&  file)
{
    unsigned int gen_Number = begin_wind;
    std::string pin_cod = "00000000";
    key_md5_frame temp_frame;
    int step = 1;
    int i = 0;

    if(avtomat == nullptr)avtomat = new avt;

    //printf("Size of structor node = %d\n", (int)sizeof(node));

    while(gen_Number < end_wind)
    {
        count_step(gen_Number, &step);
        pin_cod.replace((SIZE_PIN - step), step, std::to_string(gen_Number));

        temp_frame.key = pin_cod;
        temp_frame.MD5 = MDString(pin_cod.c_str());

        /*
        std::transform(temp_frame.MD5.begin(), temp_frame.MD5.end(), temp_frame.MD5.begin(), toupper); //high registr symbol

        avtomat->add_md5(temp_frame.MD5, i);

        if(temp_frame.MD5.length() < 32)
             {if(file.is_open()) file << temp_frame.key << ' ' << temp_frame.MD5 << " This short length"<< std::endl;}
        else
             {if(file.is_open()) file << temp_frame.key << ' ' << temp_frame.MD5 << std::endl;}
        */
        ++gen_Number;
        ++i;
        step = 1;
        temp_frame.MD5.clear();
        temp_frame.key.clear();
    }


    //delete avtomat;

    //pin_cod.
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
