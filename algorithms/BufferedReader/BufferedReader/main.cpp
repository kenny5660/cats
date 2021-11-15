#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <fstream>
using namespace std;



#include "buffered_reader.h"

int main() {
    int32_t package_len = 0;
    int32_t read_len = 0;
    int32_t expect_len = 0;
    int ok = true;
    int cur_byte = 0;
    std::ifstream fin("04.in");
    fin >> package_len;
    string s;
    getline(fin, s);
    getline(fin, s);
    PackageStream stream(s, package_len);
    BufferedReader reader(&stream);

    while (fin >> read_len >> expect_len) {
        std::unique_ptr<char[]> buf(new char[read_len]);

        int got_len = reader.Read(buf.get(), read_len);
        if (got_len != expect_len || memcmp(buf.get(), s.c_str() + cur_byte, expect_len) != 0) {
            ok = false;
            break;
        }

        cur_byte += read_len;
    }

    cout << (int)ok << endl;
}