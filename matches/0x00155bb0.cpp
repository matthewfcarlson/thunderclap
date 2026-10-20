#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"

extern "C" void __cdecl FUN_0014c730();
extern "C" char DAT_00414ad0[];
extern "C" void* __cdecl Alloc(unsigned int);
class Param {
  public:
    void Init(const char*);
    char pad[0x20];
};
extern "C" void __cdecl Register(void*, void**, int);
extern "C" int gCount_155bb0;
extern "C" void* gSlot_155bb0;
extern "C" int gValue_155bb0;
void FUN_00155bb0() {
    if (gCount_155bb0) {
        ++gCount_155bb0;
        return;
    }
    void* tmp;
    Param* p = (Param*)Alloc(0x20);
    if (p) {
        int v = gValue_155bb0;
        p->Init("compare");
        *(int*)((char*)p + 0x14) = v;
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00414ad0);
        *(hulk_intptr*)((char*)p + 0x10) = ((hulk_intptr)((char*)&DAT_0042773c));
        *(hulk_intptr*)((char*)p + 0x18) = ((hulk_intptr)(void (__cdecl*)())&FUN_0014c730);
        tmp = p;
    } else
        tmp = 0;
    Register(&gSlot_155bb0, &tmp, 1);
    ++gCount_155bb0;
}