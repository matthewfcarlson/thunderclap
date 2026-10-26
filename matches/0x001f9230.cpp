#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: gText_1f9230 = DAT_00424f08, gZero_1f9230 = DAT_003f335c

extern void InitText(char*, unsigned int, const char*);
class Sub_1f9230 {
  public:
    void Init(const float*);
};
class Obj_1f9230 {
  public:
    char pad0[8];
    int value;
    char padc[0x2c];
    unsigned char a, b;
    char pad3a[6];
    int x40, x44, x48, x4c;
    unsigned char x50, x51;
    unsigned short x52;
};
void __fastcall Target(Obj_1f9230* self) {
    self->value = 0;
    InitText((char*)self + 0xc, 0x20, DAT_00424f08);
    self->x40 = 0;
    self->x44 = 0;
    self->x48 = 0;
    self->x4c = 0;
    self->a = 0xff;
    ((Sub_1f9230*)((char*)self + 0x30))->Init(&DAT_003f335c);
    self->x50 = 0;
    self->b = 0xff;
    self->x51 = 1;
    self->x52 = 0xffff;
}