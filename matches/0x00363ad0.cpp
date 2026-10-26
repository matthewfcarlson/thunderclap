#include "decls/data/engine/movie.h"
// data: hulk_at_0055dfc0 = DAT_0055dfc0

#include "compat/ptr.h"
class Obj {
  public:
    void Init(void* a, int b);
};
extern void __cdecl _atexit(void (*f)());
extern void FUN_00364820();

void FUN_00363ad0() {
    (*(Obj*)&DAT_00565fc0).Init((void*)((hulk_intptr)((char*)&DAT_0055dfc0)), 0x8000);
    _atexit(FUN_00364820);
}
