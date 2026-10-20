#include "compat/ptr.h"
extern "C" char DAT_00404b3c[];
class CGameCamera {
  public:
    void* vtable;
    void vfunc_29();
};
struct ThisCall_00098480 {
    void FUN_00098480(int);
};
void __fastcall FUN_000a9620(CGameCamera*);
void __fastcall FUN_000984e0(CGameCamera* p) {
    *(void**)p = (void*)((hulk_intptr)DAT_00404b3c);
    ((ThisCall_00098480*)(p))->FUN_00098480(0);
    p->vfunc_29();
    FUN_000a9620(p);
}