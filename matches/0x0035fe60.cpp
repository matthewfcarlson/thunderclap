#include "decls/data/engine/audio.h"
// data: first = DAT_00429aac, registry = DAT_004e6800, second = DAT_00429270

#include "compat/ptr.h"
typedef __int64 I64;
extern "C" I64 __cdecl make(const char*, int, hulk_intptr);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
class Registry {
  public:
    void set(I64*, I64*, int, int);
};
void __cdecl target() {
    I64 a = make(DAT_00429aac, 0, 0);
    I64 b = make(DAT_00429270, 0, 0);
    (*(Registry*)&DAT_004e6800).set(&b, &a, 16, 4);
    atexit(cleanup);
}