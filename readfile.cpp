#include "readfile.h"

readFile::readFile(std::string name_file)
{
    std::ifstream myFile(name_file);

    if(!myFile.is_open())
    {
        std::cout << "Unable to open file \n";
        return;
    }

    std::string line;
    avt_read = new avt;
    size_t i = 0; //line number from file

    while(getline(myFile, line))
    {
        if(line.empty()) //third check an empty
        {
            ++i;
            continue;
        }
        else
        {
            ++i;

            if(!check_char(line))
                line.clear();//if char of line not validate or szie of line not == MD5_SIZE_R
            else
            {
                 std::transform(line.begin(), line.end(), line.begin(), toupper);//convert char of line to high register

                 avt_read->add_md5(line, i); //add to boron
            }
        }
    }
}

readFile::~readFile()
{
    if(avt_read != nullptr) avt_read->~avt();//delet boron
}

bool readFile::check_char(std::string line)
{
    if((line.size() != MD5_SIZE_R) || line.empty())
        return false;

    size_t i = 0;

    while(i < line.size())
    {
        if(((line[i] >= '0') && (line[i] <= '9')) || ((line[i] >= 'A') && (line[i] <= 'F')) || ((line[i] >= 'a') && (line[i] <= 'f')))
        {
            ++i;
            continue;
        }
        else
            return false;
    }

    return true;
}
