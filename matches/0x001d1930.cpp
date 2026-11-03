#include "gen/owners.h"
extern "C" void FUN_00213640(int, int, int);
extern int f12f00(int, int);
extern void f12d80(int, int);
bool owners::C_1d1930::FUN_001d1930(int n) {
    if (n >= 1) {
        FUN_00213640(m, -10000, n);
        if (f12f00(m, -1) == 0) {
            f12d80(m, -2);
            return false;
        }
        return true;
    }
    return false;
}
