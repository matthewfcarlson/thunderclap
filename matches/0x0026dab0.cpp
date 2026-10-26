#include "decls/data/platform/xbox/core.h"

extern "C" void f1();
extern "C" void f2();
void target() {
    f1();
    f2();
    (*(unsigned char*)&DAT_0052a184) = 0;
}
