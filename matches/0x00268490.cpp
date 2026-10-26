#include "decls/data/platform/xbox/core.h"
// data: g_obj_268490 = DAT_00528398

class Obj_268490 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
};
void target() {
    if ((*(Obj_268490**)&DAT_00528398))
        (*(Obj_268490**)&DAT_00528398)->f2(1);
    (*(Obj_268490**)&DAT_00528398) = 0;
}