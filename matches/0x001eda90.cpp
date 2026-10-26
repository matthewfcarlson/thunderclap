#include "decls/data/game/global.h"
// data: enabled = DAT_0049caa0, manager_1eda90 = DAT_004e36d8

struct Triple_1eda90 {
    int a, b, c;
};
struct Manager_1eda90 {
    void Run(Triple_1eda90, Triple_1eda90, Triple_1eda90);
};
void __stdcall FUN_001eda90(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    if (DAT_0049caa0)
        (*(Manager_1eda90**)&DAT_004e36d8)->Run(*(Triple_1eda90*)&a, *(Triple_1eda90*)&d, *(Triple_1eda90*)&g);
}