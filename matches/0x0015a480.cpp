#include "compat/ptr.h"
extern "C" char DAT_004144e0[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
class Obj_15a480 {
  public:
    virtual void* A();
    virtual void* B();
    virtual void* C();
    virtual void* D();
    virtual void* E();
    virtual void* F();
    void Init();
    char pad[4];
    int x;
    int y;
    float z;
};
void* Obj_15a480::F() {
    Obj_15a480* p = (Obj_15a480*)Alloc(0x14);
    if (p) {
        p->Init();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_004144e0);
        p->y = 0;
        p->z = -1.0f;
        p->x = 1;
        return p;
    }
    return 0;
}