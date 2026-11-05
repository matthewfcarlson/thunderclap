#include "decls/data/engine/audio.h"
// data: name1 = DAT_004292a0, name2 = DAT_00429270, registry = DAT_004e6038

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
extern "C" int __cdecl atexit(void(__cdecl*)());
void FUN_00364200();
class Registry {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
void function() {
    unsigned __int64 a = FUN_002672f0(DAT_004292a0, 0, 0);
    unsigned __int64 b = FUN_002672f0(DAT_00429270, 0, 0);
    (*(Registry*)((char*)&DAT_004e5ff0 + 72)).FUN_002584d0((__int64*)&b, (__int64*)&a, 64, 4);
    atexit(FUN_00364200);
}