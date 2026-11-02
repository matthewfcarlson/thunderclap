#include "decls/data/game/global.h"
// data: enabled = DAT_0049caa0, manager_1eda90 = DAT_004e36d8

struct Triple_1eda90 {
    int a, b, c;
};
struct Manager_1eda90 {
    void Run(Triple_1eda90, Triple_1eda90, Triple_1eda90);
};
void __stdcall FUN_001eda90(Triple_1eda90 a, Triple_1eda90 b, Triple_1eda90 c) {
    if (DAT_0049caa0)
        (*(Manager_1eda90**)&DAT_004e36d8)->Run(a, b, c);
}