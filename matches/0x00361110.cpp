#include "decls/data/platform/xbox/audio.h"
// data: store = DAT_004e77c0

struct Pair {
    int a, b;
};
extern Pair __cdecl make(const char*, int, int);
class Store {
  public:
    void Init(Pair*, Pair*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
void __cdecl FUN_00361110() {
    Pair a = make("Properties", 0, 0);
    Pair b = make("Meta", 0, 0);
    (*(Store*)&DAT_004e77c0).Init(&b, &a, 16, 8);
    atexit(cleanup);
}