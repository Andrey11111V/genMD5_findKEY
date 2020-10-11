#define CATCH_CONFIG_MAIN
#include "./catch/catch.hpp"

#include <iostream>
#include "md5.h"
#include "generatemd5.h"
#include "readfile.h"
#include "threadheap.h"
#include "avt.h"

TEST_CASE("Can check generate hash MD5","[md5]")
{
    CHECK(Catch_MDString("") == "d41d8cd98f00b204e9800998ecf8427e");
    CHECK(Catch_MDString("a") == "0cc175b9c0f1b6a831c399e269772661");
    CHECK(Catch_MDString("abc") == "900150983cd24fb0d6963f7d28e17f72");
    CHECK(Catch_MDString("message digest") == "f96b697d7cb7938d525a2f31aaf161d0");
    CHECK(Catch_MDString("abcdefghijklmnopqrstuvwxyz") == "c3fcd3d76192e4007dfb496cca67e13b");
    CHECK(Catch_MDString("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789") == "d174ab98d277d9f5a5611c2c9f419d9f");
    CHECK(Catch_MDString("12345678901234567890123456789012345678901234567890123456789012345678901234567890") == "57edf4a22be3c955ac49da2e2107b67a");
}

TEST_CASE("Can chcek search in avt","[avt]")
{
    avt a;
    a.add_md5("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 1);
    a.add_md5("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB", 2);
    a.add_md5("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC", 3);
    a.add_md5("DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD", 4);
    a.add_md5("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE", 5);
    a.add_md5("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", 6);
    a.add_md5("11111111111111111111111111111111", 7);
    a.add_md5("00000000000000000000000000000000", 8);
    a.add_md5("99999999999999999999999999999999", 9);
    a.add_md5("AAALLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 10);
    a.add_md5("LLLLAAALLLLLLLLLLLLLLLLLLLLLLLLL", 11);


    std::cout << "npos = " << std::string::npos << std::endl;
}
