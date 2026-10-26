#include "decls/data/engine/audio.h"
// data: busName = DAT_004292b8, registry = DAT_004e6080, seqName = DAT_00429270

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl lookup(const char*, int, int);
class Registry {
  public:
    void put(Pair*, Pair*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
void __cdecl init() {
    Pair a = lookup(DAT_004292b8, 0, 0);
    Pair b = lookup(DAT_00429270, 0, 0);
    (*(Registry*)&DAT_004e6080).put(&b, &a, 8, 4);
    atexit(cleanup);
}