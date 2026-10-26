#include "decls/data/engine/audio.h"

#include "compat/ptr.h"
struct Pair {
    unsigned __int64 v;
};
extern "C" unsigned __int64 __cdecl make(const char*, int, hulk_intptr);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Reg {
  public:
    void init(Pair*, Pair*, int, int);
};
void __cdecl target() {
    Pair a, b;
    a.v = make("SeqActionWait", 0, 0);
    b.v = make("Runtime_Sequence", 0, 0);
    (*(Reg*)((char*)&DAT_004e68f8 + 104)).init(&b, &a, 16, 4);
    atexit(cleanup);
}