#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_003f42cc[];
extern "C" char DAT_003f45ec[];
struct ThisCall_001d0480 {
    void FUN_001d0480(void*, int);
};
extern const char g1_2fd70[];
extern const char g2_2fd70[];
class Closure1_2fd70 {
  public:
    hulk_intptr v;
    char p[0x24];
    Closure1_2fd70* Fn(void* a, int b, void* c);
};
Closure1_2fd70* Closure1_2fd70::Fn(void* a, int b, void* c) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(a, 1);
    v = ((hulk_intptr)DAT_003f42cc);
    *(hulk_intptr*)((char*)this + 0x1c) = (hulk_intptr)c;
    *((char*)this + 0x18) = FUN_001d04d0(g1_2fd70);
    *((char*)this + 0x10) = FUN_001d04d0(g2_2fd70);
    v = ((hulk_intptr)DAT_003f45ec);
    *(int*)((char*)this + 0x20) = b;
    return this;
}