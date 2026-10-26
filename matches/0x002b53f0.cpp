// Same code shape as 0x00085d70 (propagated; names are from that function)
#include "decls/data/engine/pure3d.h"
// data: globalObj_2b53f0 = DAT_00554bb0

class Obj_2b53f0 {
  public:
    virtual void f();
    virtual void g();
};
void target() {
    if ((*(Obj_2b53f0**)&DAT_00554bb0)) {
        (*(Obj_2b53f0**)&DAT_00554bb0)->g();
        (*(Obj_2b53f0**)&DAT_00554bb0) = 0;
    }
}