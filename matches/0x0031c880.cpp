#include "compat/ptr.h"
typedef unsigned int U32_31c880;
struct Obj_31c880 {
    char pad[8];
    hulk_uintptr index;
    hulk_uintptr base;
    void Copy(U32_31c880);
};
struct Temp_31c880 {
    void Run(U32_31c880, void*);
};
extern "C" void* memcpy(void*, const void*, unsigned int);
void Obj_31c880::Copy(U32_31c880 param) {
    char local[64];
    void* dst = (void*)(index * 64 + base);
    ((Temp_31c880*)local)->Run(param, dst);
    dst = (void*)(index * 64 + base);
    memcpy(dst, local, 64);
}