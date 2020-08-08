#ifndef AVT_H
#define AVT_H

#include <cstdint>
#include <iostream>
#include <string>
#include <cstring>

#define MAX_CHAR 16
#define MAX_UINT32_AVT 4294967294 //bx1111 1111 1111 1111 1111 1111 1111 1111

//std::string communication_avt = "0123456789ABCDEF";

typedef struct node_char{
    struct node_char* character[MAX_CHAR];
    uint32_t answer;
}node;

class avt
{

    node* rooot;
    std::string communication_avt = "0123456789ABCDEF";

public:
    avt();
    ~avt();
    void add_md5(std::string line_md5, unsigned int answer);
    void delete_tree(node* root);
    uint32_t search(std::string line_md5);

private:
    node* create();
};

#endif // AVT_H
