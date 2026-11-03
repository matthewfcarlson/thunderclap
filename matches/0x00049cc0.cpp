#include "gen/owners.h"
class Obj_49cc0 {
  public:
    Obj_49cc0* b();
    int c();
};
int __stdcall vfunc_7(Obj_49cc0* p) {
    p = ((Obj_49cc0 *)((owners::Object_592a0 *)p)->FUN_000592a0());
    p = p->b();
    return p->c();
}
