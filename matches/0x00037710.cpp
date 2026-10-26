#include "decls/data/game/global.h"
// data: zero_37710 = DAT_003f335c

class Obj_37710 {
  public:
    char pad[0x1c];
    int value;
    int a;
    int b;
    void init();
    void set(const float*);
};
Obj_37710* __fastcall target(Obj_37710* self) {
    self->init();
    self->value = (int)0xbf800000;
    self->set(&DAT_003f335c);
    self->pad[8] = (char)0xff;
    self->pad[9] = (char)0xff;
    self->a = 0;
    self->b = 0;
    return self;
}