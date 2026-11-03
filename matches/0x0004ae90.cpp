// Same code shape as 0x00049cc0 (propagated; names are from that function)
#include "gen/owners.h"
class Obj_4ae90 {
  public:
    Obj_4ae90* b();
    int c();
};
int __stdcall vfunc_7(Obj_4ae90* p) {
    p = ((Obj_4ae90 *)((owners::Object_592a0 *)p)->FUN_000592a0());
    p = p->b();
    return p->c();
}
