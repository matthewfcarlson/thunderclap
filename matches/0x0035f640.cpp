#include "decls/data/engine/audio.h"
// data: name1 = DAT_004292a0, name2 = DAT_00429270, registry = DAT_004e6038

extern "C" unsigned __int64 __cdecl hash(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Registry {
  public:
    void init(unsigned __int64*, unsigned __int64*, int, int);
};
void function() {
    unsigned __int64 a = hash(DAT_004292a0, 0, 0);
    unsigned __int64 b = hash(DAT_00429270, 0, 0);
    (*(Registry*)((char*)&DAT_004e5ff0 + 72)).init(&b, &a, 64, 4);
    atexit(cleanup);
}