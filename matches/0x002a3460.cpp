// Same code shape as 0x00085d70 (propagated; names are from that function)
#include "decls/data/engine/pure3d.h"
// data: globalObj_2a3460 = DAT_00554bb4

class Obj_2a3460 {
  public:
    virtual void f();
    virtual void g();
};
void target() {
    if ((*(Obj_2a3460**)&DAT_00554bb4)) {
        (*(Obj_2a3460**)&DAT_00554bb4)->g();
        (*(Obj_2a3460**)&DAT_00554bb4) = 0;
    }
}