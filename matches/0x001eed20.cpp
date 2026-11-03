#include "gen/owners.h"
class Sub_1eed20 {
  public:
};
class Obj_1eed20 {
  public:
    char pad[8];
    int a;
    int b;
    int c;
    unsigned char d;
    char pad2[11];
    float f;
    int g;
};
void __fastcall FUN_001eed20(Obj_1eed20* self) {
    self->a = 0;
    self->b = 0;
    self->c = 0;
    self->d = 0;
    self->f = 100.0f;
    self->g = 0;
    ((owners::Target_27b040 *)(((Sub_1eed20*)((char*)self + 0x18))))->FUN_0027b040((hulk_uintptr)0);
}