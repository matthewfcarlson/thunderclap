#include "compat/ptr.h"
struct Pair {
    unsigned a, b;
};
extern "C" Pair __cdecl make(const char*, int, hulk_intptr);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
extern const char name1[], name2[];
class Registry {
  public:
    void add(Pair*, Pair*, int, int);
};
extern Registry registry;
void init() {
    Pair a = make(name1, 0, 0);
    Pair b = make(name2, 0, 0);
    registry.add(&b, &a, 24, 4);
    atexit(cleanup);
}