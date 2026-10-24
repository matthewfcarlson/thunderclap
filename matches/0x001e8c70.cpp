#include "compat/ptr.h"
typedef unsigned int U_1e8c70;
extern U_1e8c70 __cdecl F40750();
extern void __cdecl F416c0(U_1e8c70, hulk_uintptr, int);
extern void __cdecl F43090(U_1e8c70, hulk_uintptr);
extern void __cdecl F42ca0(U_1e8c70, hulk_uintptr);
class Obj_1e8c70 {
  public:
    char pad[0x34];
    int field;
};
class Target_1e8c70 {
  public:
    char pad[0xc];
    Obj_1e8c70* p;
};
void __fastcall target(Target_1e8c70* self) {
    U_1e8c70 x = F40750();
    Obj_1e8c70** q = &self->p;
    F416c0(x, (hulk_uintptr)*q, 0);
    while ((*q)->field != 0) {
        F43090(F40750(), 0x3a83126f);
    }
    F42ca0(F40750(), (hulk_uintptr)q);
}