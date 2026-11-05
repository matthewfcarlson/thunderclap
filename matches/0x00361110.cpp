#include "decls/data/platform/xbox/audio.h"
// data: store = DAT_004e77c0

struct Pair {
    int a, b;
};
extern Pair __cdecl FUN_002672f0(const char*, int, int);
class Store {
  public:
    void FUN_002584d0(Pair*, Pair*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
void __cdecl FUN_00361110() {
    Pair a = FUN_002672f0("Properties", 0, 0);
    Pair b = FUN_002672f0("Meta", 0, 0);
    (*(Store*)&DAT_004e77c0).FUN_002584d0(&b, &a, 16, 8);
    atexit(cleanup);
}