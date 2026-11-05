#include "decls/data/engine/audio.h"
// data: registry = DAT_004e6ad0

typedef __int64 I64;
extern "C" I64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364410();
class Registry {
  public:
    void FUN_002584d0(I64*, I64*, int, int);
};
void __cdecl FUN_003601e0() {
    I64 first = FUN_002672f0("SeqActionExpression", 0, 0);
    I64 second = FUN_002672f0("Runtime_Sequence", 0, 0);
    (*(Registry*)&DAT_004e6ad0).FUN_002584d0(&second, &first, 16, 4);
    atexit(FUN_00364410);
}