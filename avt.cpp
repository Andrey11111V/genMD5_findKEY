#include "avt.h"

node* avt::create()
{
    int i = 0;
    node* tmp = new node;

    if(tmp == NULL)
    {
        std::cerr << "Not create node" << std::endl;
        return NULL;
    }

    for(i=0;i<MAX_CHAR;++i)
            tmp->character[i] = NULL;
    tmp->answer = MAX_UINT32_AVT; //bx1111 1111 1111 1111 1111 1111 1111 1111

    return tmp;
}

avt::avt()
{
    rooot = create();
}

avt::~avt()
{
    this->delete_tree(rooot);
    //printf("Delete tree \n");
}

void avt::add_md5(std::string line_md5, unsigned int answer)
{
    unsigned int i = 0;
    node* root2 = rooot;
    node* tmp = NULL;
    unsigned short nimber_symb = 0;

    for(i=0; i < (unsigned int)line_md5.size(); ++i) //-1 = без '\n'
    {
        //char symb = line_md5[i];
        nimber_symb = communication_avt.find(line_md5[1]);
        if(root2->character[nimber_symb] != 0)   //if symbol exist
        {
            root2 = root2->character[nimber_symb];
            continue;
        }
        else //if not create new and add in array
        {
            tmp = create();
            root2->character[nimber_symb] = tmp;
            root2 = tmp;
        }

        nimber_symb = 0;
     }
     tmp->answer = answer;
}

void avt::delete_tree(node *root)
{
    uint16_t i = 0;

    for(; i < MAX_CHAR; ++i)
        if((root->character[i]) != NULL)
        {
            delete_tree(root->character[i]);           
            root->character[i] = NULL;
        }

    delete root;
    root = NULL;
}

uint32_t avt::search(std::string line_md5)
{

    if(line_md5.empty())
        return MAX_UINT32_AVT;

    node* current = rooot;
    uint32_t i = 0;
    uint32_t number_symb = 0;

    while(current != nullptr)
    {
        if(current->answer < MAX_UINT32_AVT)
            return current->answer;

        number_symb = communication_avt.rfind(line_md5[i]);
        current = current->character[number_symb];

        ++i;
    }

    return MAX_UINT32_AVT;
}


