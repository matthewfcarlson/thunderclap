#include "decls/data/engine/om.h"
#include "decls/data/engine/unknown.h"
// data: label = DAT_004293a4, registry = DAT_004e62d8

typedef __int64 I64;
extern "C" I64 __cdecl getid(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
class Registry {
  public:
    void init(I64*, I64*, int, int);
};
void __cdecl target() {
    I64 a = getid(((char*)&DAT_004293a4), 0, 0);
    I64 b = getid(((char*)&DAT_004293a4), 0, 0);
    (*(Registry*)&DAT_004e62d8).init(&b, &a, 12, 4);
    atexit(cleanup);
}