#include "decls/data/engine/om.h"
#include "decls/data/engine/unknown.h"
// data: label = DAT_004293a4, registry = DAT_004e62d8

typedef __int64 I64;
extern "C" I64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003642a0();
class Registry {
  public:
    void FUN_002584d0(I64*, I64*, int, int);
};
void __cdecl target() {
    HULK_SIZE32(OmEntityLoader, 0xc);
    I64 a = FUN_002672f0(((char*)&DAT_004293a4), 0, 0);
    I64 b = FUN_002672f0(((char*)&DAT_004293a4), 0, 0);
    (*(Registry*)&DAT_004e62d8).FUN_002584d0(&b, &a, (int)sizeof(OmEntityLoader), (int)__alignof(OmEntityLoader));
    atexit(FUN_003642a0);
}