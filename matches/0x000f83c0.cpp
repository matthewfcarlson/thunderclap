#include "gen/owners.h"
class Obj_f83c0 {
  public:
    char pad[0x10];
    int initArg;
    int field14;
    char pad18[8];
    int field20;
};
struct ThisCall_000f79a0 {
};
Obj_f83c0* __fastcall Copy(Obj_f83c0* self, void*, Obj_f83c0* src) {
    ((owners::Obj_f79a0 *)(((ThisCall_000f79a0*)(self))))->FUN_000f79a0((const short *)(hulk_uintptr)(int)(src->initArg), (hulk_intptr)0);
    self->field14 = src->field14;
    *(int*)self = *(int*)src;
    self->field20 = -1;
    return self;
}