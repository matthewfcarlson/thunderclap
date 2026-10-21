#include "compat/ptr.h"
extern "C" double __cdecl sqrt(double);
class Obj_35690 {
  public:
    char pad[0x74];
    float a;
    char pad2[4];
    float b;
};
hulk_freg __fastcall FUN_00035690(Obj_35690* p) {
    return (float)sqrt((double)p->b * p->b + (double)p->a * p->a);
}