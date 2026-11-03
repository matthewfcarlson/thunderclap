#include "gen/owners.h"
struct A_36a80 {
    char pad[0x10];
    int value;
};
struct B_36a80 {
    char pad[0x11c];
    int value;
};
hulk_intptr owners::Obj_36a80::FUN_00036a80(int unused) {
    int result = 0;
    void* p = a;
    if (p)
        return ((A_36a80*)p)->value;
    p = b;
    if (p)
        result = ((B_36a80*)p)->value;
    return result;
}