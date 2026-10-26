#include "decls/data/game/global.h"
// data: g_obj_fc3a0 = DAT_004e0a60

class Obj_fc3a0 {
  public:
    void Fn(int x);
};


void FUN_000fc3a0(int x) {
    (*(Obj_fc3a0**)&DAT_004e0a60)->Fn(x);
}
