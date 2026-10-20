#include "compat/ptr.h"
#include "decls/data/game/unknown.h"

class C_1d2cd0 {
  public:
    char pad[8];
    int field;
    bool Fn(int, int, int);
};
extern void __cdecl F1(int, int);
extern void __cdecl F2(int, int);
extern int __cdecl F3(int, int);
extern void __cdecl F4(int, int, hulk_intptr, int);
extern void __cdecl F5(int, int);
bool C_1d2cd0::Fn(int a, int b, int c) {
    F1(field, a);
    F2(field, -2);
    int r = F3(field, -1);
    bool ok = true;
    if (!r) {
        ok = false;
        goto done;
    }
    F4(b, c, ((hulk_intptr)((char*)&DAT_003f3f38)), r);
done:
    F5(field, -2);
    return ok;
}