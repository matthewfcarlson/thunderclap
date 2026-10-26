#include "decls/data/engine/audio.h"
// data: holder = DAT_004e6208

typedef __int64 I64;
extern "C" I64 __cdecl find(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Holder {
  public:
    void init(I64*, I64*, int, int);
};
void __cdecl FUN_0035f900() {
    I64 a = find("HalPositionalInfo", 0, 0);
    I64 b = find("Runtime_Hal", 0, 0);
    (*(Holder*)&DAT_004e6208).init(&b, &a, 100, 4);
    atexit(cleanup);
}