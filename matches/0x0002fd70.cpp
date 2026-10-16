#include "decls/address.h"
extern "C" char DAT_003f42cc[];
extern "C" char DAT_003f45ec[];
extern "C" void __stdcall FUN_001d0480(void*, int);
extern const char g1_2fd70[];
extern const char g2_2fd70[];
class Target_2fd70 {
  public:
    int v;
    char p[0x24];
    Target_2fd70* Fn(void* a, int b, void* c);
};
Target_2fd70* Target_2fd70::Fn(void* a, int b, void* c) {
    FUN_001d0480(a, 1);
    v = ((int)DAT_003f42cc);
    *(int*)((char*)this + 0x1c) = (int)c;
    *((char*)this + 0x18) = FUN_001d04d0(g1_2fd70);
    *((char*)this + 0x10) = FUN_001d04d0(g2_2fd70);
    v = ((int)DAT_003f45ec);
    *(int*)((char*)this + 0x20) = b;
    return this;
}