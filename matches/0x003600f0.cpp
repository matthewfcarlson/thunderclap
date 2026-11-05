#include "decls/data/engine/audio.h"
// data: name1 = DAT_00429c74, name2 = DAT_00429270, registry = DAT_004e6a18

#include "compat/ptr.h"
struct Pair {
    unsigned a, b;
};
extern "C" Pair __cdecl FUN_002672f0(const char*, int, hulk_intptr);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Registry {
  public:
    void FUN_002584d0(Pair*, Pair*, int, int);
};
void init() {
    Pair a = FUN_002672f0(DAT_00429c74, 0, 0);
    Pair b = FUN_002672f0(DAT_00429270, 0, 0);
    (*(Registry*)&DAT_004e6a18).FUN_002584d0(&b, &a, 24, 4);
    atexit(cleanup);
}