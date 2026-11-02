#include "compat/ptr.h"
struct Obj_2135a0 {
    char pad[8];
    int offset;
};
typedef unsigned int size_t;
extern "C" size_t strlen(const char*);
extern "C" int __fastcall find(int, Obj_2135a0*);
extern "C" int FUN_00219430(Obj_2135a0*, const char*, hulk_intptr);
extern "C" void __cdecl FUN_00217830(void *, void *, void *, void *);
extern "C" void FUN_002135a0(Obj_2135a0* obj, int type, const char* str) {
    int tmp[2];
    int id = find(type, obj);
    tmp[1] = FUN_00219430(obj, str, strlen(str));
    tmp[0] = 4;
    FUN_00217830((Obj_2135a0 *)obj, (void *)(hulk_uintptr)(int)id, (int *)tmp, (void *)(hulk_uintptr)(int)(obj->offset));
    obj->offset += 8;
}