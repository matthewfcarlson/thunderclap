#include "decls/data/engine/unknown.h"

int __cdecl F1(char*, __int64*);
__int64 __cdecl F2();
void __cdecl F3(char*, void*, __int64*);
class C_263e30 {
  public:
    char pad[0x10];
    int m10;
    int pad2;
    __int64 m18;
    void Set(int a, __int64* p);
};
void C_263e30::Set(int a, __int64* p) {
    m10 = a;
    __int64 v = *p;
    __int64 t = v;
    if (F1(((char*)&DAT_004cd4cc), &t))
        v = F2();
    m18 = v;
    F3(((char*)&DAT_004cd4cc), this, &m18);
}
