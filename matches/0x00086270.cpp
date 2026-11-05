#include "compat/ptr.h"
struct X_86270 {
    int pad;
    unsigned int value;
};
hulk_uintptr __fastcall FUN_00086270(X_86270* p) {
    return p->value;
}