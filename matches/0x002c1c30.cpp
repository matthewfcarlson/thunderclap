#include "gen/pure3d.h"
extern "C" char DAT_0042ec20[];
class Texture_2c1c30 {
  public:
    int v;
    char pad[12];
    int field10;
};
struct Texture_nv_2c1c30 {
    void Init();
};
Texture_2c1c30* __fastcall FUN_002c1c30(Texture_2c1c30* self) {
    ((Texture_nv_2c1c30*)(((pure3d::Texture*)(self))))->Init();
    self->v = ((int)DAT_0042ec20);
    self->field10 = 0;
    return self;
}