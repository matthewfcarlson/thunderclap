#include "compat/ptr.h"
struct R {
    char pad[0xcd];
    char f;
};
struct ThisWrap_001fcb70 {
    hulk_intptr FUN_001fc7f0(unsigned int);
    char FUN_001fcb70(unsigned int x);
};
char ThisWrap_001fcb70::FUN_001fcb70(unsigned int x) {
    R* p = (R*)this->FUN_001fc7f0(x);
    if (p == 0)
        return 0;
    return p->f;
}
