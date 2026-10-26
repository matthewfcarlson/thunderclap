#include "decls/data/game/global.h"
// data: gCount_59820 = DAT_00494b30

struct ThisCall_00059510 {
    void Init();
};
class Obj_59820 {
  public:
    char pad[0x48];
    int id;
    int a4c;
    int a50;
    char gap[0x0c];
    int a60;
    char gap2[8];
    int a6c;
    int a70;
    char gap3[0x10];
    int a84;
};
Obj_59820* __fastcall Target(Obj_59820* self) {
    self->a4c = 0;
    self->a50 = 0;
    self->a60 = 0;
    self->a6c = 0;
    self->a70 = 0;
    self->a84 = 0;
    ((ThisCall_00059510*)(self))->Init();
    self->id = DAT_00494b30;
    ++DAT_00494b30;
    if (DAT_00494b30 == 0)
        DAT_00494b30 = 1;
    return self;
}