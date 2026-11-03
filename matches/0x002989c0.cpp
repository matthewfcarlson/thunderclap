#include "gen/owners.h"
typedef unsigned char u8_2989c0;
typedef unsigned int u32_2989c0;
void owners::Buffer_2989c0::FUN_002989c0(u8_2989c0 value) {
    if (flags[value] != 0 && data[value] == 0xff) {
        data[value] = count;
        out[count] = value;
        ++count;
    }
}