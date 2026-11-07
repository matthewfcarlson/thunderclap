#include "decls/data/engine/audio.h"

#include "compat/ptr.h"
#include "decls/address.h"
struct Pair {
    unsigned __int64 v;
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003643d0();
class Reg {
  public:
    void FUN_002584d0(Pair*, Pair*, int, int);
};
void __cdecl target() {
    Pair a, b;
    a.v = FUN_002672f0("SeqActionWait", 0, 0);
    b.v = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Reg*)((char*)&DAT_004e6960)).FUN_002584d0(&b, &a, 16, 4);
    atexit(FUN_003643d0);
}