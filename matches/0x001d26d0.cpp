#include "compat/ptr.h"
#include "gen/owners.h"
#include "decls/data/script.h"
// ScriptHandler (include/decls/data/script.h): removes the Function registered under `name` (0x001d04b0 sets b's key,
// 0x001d1360 deletes the matching entry of the function list).
class B_1d26d0 {
  public:
};
class D : public ScriptFunctionList {
  public:
    void FUN_001d1360(B_1d26d0*);
};
class C_1d26d0 : public ScriptHandlerFields {
  public:
    virtual void v0();
    void g(hulk_uintptr, B_1d26d0*);
};
void C_1d26d0::g(hulk_uintptr a, B_1d26d0* b) {
    ((owners::CAgent_1d04b0 *)b)->FUN_001d04b0((hulk_intptr)a);
    ((D*)&functions)->FUN_001d1360(b);
}
