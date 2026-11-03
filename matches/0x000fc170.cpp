#include "decls/data/game/global.h"
#include "gen/owners.h"

struct X_fc170 {
    void A(int);
    void B(int);
};
extern "C" void __cdecl FUN_000fc170(int param_1) {
    (*(X_fc170**)&DAT_004e0a64)->A(0);
    (*(X_fc170**)&DAT_004e0a60)->B(param_1);
    ((owners::Obj_de1d0 *)((*(X_fc170**)&DAT_004e0a64)))->FUN_000de1d0();
}