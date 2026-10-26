#include "decls/data/engine/audio.h"
// data: name1 = DAT_004299d4, name2 = DAT_00429270, registry = DAT_004e6700

typedef unsigned __int64 U64;
extern U64 __cdecl lookup(const char*, int, int);
class Registry {
  public:
    void init(U64*, U64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
void __cdecl target() {
    U64 a = lookup(DAT_004299d4, 0, 0);
    U64 b = lookup(DAT_00429270, 0, 0);
    (*(Registry*)&DAT_004e6700).init(&b, &a, 16, 4);
    atexit(cleanup);
}