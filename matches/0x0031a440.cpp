#include "compat/ptr.h"
struct Part_31a440 {
    char data[0x60];
    void FUN_0031a830();
};
extern void* __cdecl FUN_0008d6d0(hulk_uintptr);
struct Object {
    char* base;
    char* current;
    char* end;
    unsigned int untouched;
    Part_31a440 part;
    unsigned int f70, f74, f78, f7c, flags, f84, f88, f8c, f90, f94, f98, f9c, fa0;
    Object* init();
};
Object* Object::init() {
    base = 0;
    current = 0;
    end = 0;
    part.FUN_0031a830();
    f70 = 0;
    f74 = 0;
    f78 = 0;
    f7c = 0;
    flags = 0;
    f88 = 0;
    f8c = 0;
    f90 = 0;
    f94 = 0;
    f98 = 0;
    f9c = 0;
    fa0 = 0;
    char* p = (char*)FUN_0008d6d0(1000);
    base = p;
    if (p) {
        current = p;
        end = p + 1000;
    } else {
        current = 0;
        end = 0;
    }
    if (flags & 6) {
        float* values = (float*)(part.data + 0x20);
        if (!(flags & 4)) {
            values[0] = 1.0f;
            values[1] = 0.0f;
        } else if (!(flags & 2)) {
            values[0] = 0.0f;
            values[1] = 1.0f;
        }
    }
    return this;
}