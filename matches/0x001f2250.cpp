// Same code shape as 0x00090eb0 (propagated; names are from that function)
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

extern void* VT_Method2[2];
extern void* VT_Closure2[2];

struct Ctor_001d0480 {
    Ctor_001d0480(void* a1, int b);
};
char __cdecl LookupFlag(const void* tbl);

class Closure2 : public Ctor_001d0480 {
  public:
    void* vfptr;    // 0x00
    char pad04[12]; // 0x04
    char mFlag10;   // 0x10
    char mFlag11;   // 0x11
    char pad12[6];  // 0x12
    char mFlag18;   // 0x18
    char pad19[3];  // 0x19
    int mA3;        // 0x1c
    int mA2;        // 0x20

    Closure2(void* a1, int a2, int a3);
};

Closure2::Closure2(void* a1, int a2, int a3) : Ctor_001d0480(a1, 2) {
    vfptr = (void*)VT_Method2;
    mA3 = a3;
    mFlag18 = LookupFlag(((void**)&DAT_0048e100));
    mFlag10 = LookupFlag(((void**)&DAT_0049cad8));
    mFlag11 = LookupFlag(((void**)&DAT_0048e128));
    vfptr = (void*)VT_Closure2;
    mA2 = a2;
}
