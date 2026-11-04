#include "gen/owners.h"
#include "compat/ptr.h"
typedef unsigned int U_23fef0;
class Obj_23fef0 {
  public:
};
extern "C" void __cdecl CopyLike(char* buf, U_23fef0 size, hulk_uintptr v, void* p);
Obj_23fef0* __cdecl Target(Obj_23fef0* a, hulk_uintptr b, ...) {
    char buf[0x1000];
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, b);
    CopyLike(buf, 0x1000, b, args);
#else
    CopyLike(buf, 0x1000, b, (void**)&b + 1);
#endif
    buf[0xfff] = 0;
    ((owners::String_23fe50 *)a)->FUN_0023fe50((const char *)buf);
    return a;
}
