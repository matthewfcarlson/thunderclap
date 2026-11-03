#include "gen/owners.h"
typedef unsigned char byte;
bool owners::Bits_2780c0::FUN_002780c0(int a, int b) {
    if (a < 0 || b < 0)
        return true;
    byte mask = 1;
    mask = (byte)(mask << (a + b * 4));
    return (mask & value) != 0;
}