#include "compat/ptr.h"
struct Called {
    void F(void*);
};
struct Obj_92340 {
    char pad[0xa8];
    hulk_uintptr Target(Called* param);
};
hulk_uintptr Obj_92340::Target(Called* param) {
    param->F((char*)this + 0xa8);
    return (hulk_uintptr)param;
}