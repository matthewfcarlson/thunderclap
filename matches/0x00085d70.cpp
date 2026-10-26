#include "decls/data/game/unknown.h"
// data: globalObj_85d70 = DAT_004dd6e4

class Obj_85d70 {
  public:
    virtual void f();
    virtual void g();
};
void target() {
    if ((*(Obj_85d70**)&DAT_004dd6e4)) {
        (*(Obj_85d70**)&DAT_004dd6e4)->g();
        (*(Obj_85d70**)&DAT_004dd6e4) = 0;
    }
}