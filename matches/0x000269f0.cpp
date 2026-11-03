#include "gen/owners.h"
bool owners::C_269f0::FUN_000269f0(int x, int y) {
    int i = count;
    if (i >= 0x20)
        return false;
    if (find(x, y) != -1)
        return false;
    *(int*)(slots + i * 8) = x;
    *(int*)(slots + i * 8 + 4) = y;
    count = count + 1;
    return true;
}