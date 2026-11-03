#include "gen/owners.h"
struct Helper_dddc0 {
};
class Obj_dddc0 {
  public:
    char pad[0x2230];
    Helper_dddc0* helper;
    void* stored;
    void f(void* a, void* b);
};
void Obj_dddc0::f(void* a, void* b) {
    ((owners::Obj_f86f0 *)helper)->FUN_000f86f0(0x8fc, (hulk_intptr)((const float*)0x27290));
    stored = b;
}