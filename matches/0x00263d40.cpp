#include "decls/data/engine/unknown.h"
#include "compat/ptr.h"

struct Pair_263d40 {
    int a, b;
};
extern "C" void * __cdecl FUN_00263970(void *, const void *);
extern Pair_263d40 __cdecl FUN_00263c90();
extern "C" void __cdecl FUN_00263bb0(void *, void *);
extern void __cdecl FUN_002639c0(void*, void*, Pair_263d40*);
class Obj_263d40 {
    char pad[0x18];
    Pair_263d40 value;

  public:
    void Fn(int a, int b);
};
void Obj_263d40::Fn(int a, int b) {
    Pair_263d40 local;
    local.a = a;
    local.b = b;
    Pair_263d40 result = local;
    if (((int)(hulk_uintptr)FUN_00263970(((int*)&DAT_004cd4cc), (Pair_263d40 *)(&local))))
        result = FUN_00263c90();
    FUN_00263bb0(((int*)&DAT_004cd4cc), this);
    value = result;
    FUN_002639c0(((int*)&DAT_004cd4cc), this, &value);
}