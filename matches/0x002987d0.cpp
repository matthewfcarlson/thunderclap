#include "gen/owners.h"
void owners::X_2987d0::FUN_002987d0(unsigned char v) {
    unsigned int i = v;
    if (entries[i * 3 + 2] && buffer[i] == 0xff) {
        buffer[i] = count;
        output[count] = v;
        ++count;
    }
}