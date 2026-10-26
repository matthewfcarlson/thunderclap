#include "decls/data/engine/audio.h"

extern "C" __int64 __cdecl hash(const char*, int, int);
class Table {
  public:
    void init(__int64*, __int64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl target() {
    __int64 a;
    __int64 b = hash("PointerUid", 0, 0);
    a = hash("Om", 0, 0);
    (*(Table*)&DAT_004e7be0).init(&a, &b, 32, 8);
    atexit(cleanup);
}