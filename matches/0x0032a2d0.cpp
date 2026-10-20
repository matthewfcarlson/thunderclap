#include "compat/ptr.h"
#include "decls/data/platform/xbox/pure3d.h"

class Dev_32a2d0 {
    char pad[0x48];

  public:
    int state;
    void Do(unsigned char, unsigned char, char*);
};
class Obj_32a2d0 {
    char pad0[0x14];

  public:
    Dev_32a2d0* dev;
    char pad18[0x30];
    unsigned char first;
    char pad49[3];
    int value;
    char pad50[0x2c];
    unsigned char second;
};
extern void __fastcall D3DDevice_SetRenderState_Simple(const char*, int);
extern int global_32a2d0;
void __fastcall FUN_0032a2d0(Obj_32a2d0* self) {
    hulk_intptr x = self->value;
    if (x != self->dev->state) {
        self->dev->state = x;
        int v = (*(int*)(((hulk_intptr)((char*)&DAT_004d4f24)) + x * 4));
        D3DDevice_SetRenderState_Simple((const char*)0x4037c, v);
        global_32a2d0 = v;
    }
    self->dev->Do(self->first, self->second, (char*)self + 0x50);
}