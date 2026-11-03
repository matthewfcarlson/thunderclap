#include "gen/owners.h"
void owners::C_c6fa0::FUN_000c6fa0(int index, int a, int b, int c) {
    if (index >= 0 && index <= 16 && *((int*)this + (index + 3) * 8) != -1) {
        int* p = (int*)((char*)this + index * 32 + 100);
        p[0] = a;
        p[1] = b;
        p[2] = c;
    }
}