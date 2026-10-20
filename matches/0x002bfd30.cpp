#include "compat/ptr.h"
#include "gen/pure3d.h"
extern "C" char DAT_0042ea40[];
struct Image32_nv_2bfd30 {
    void Finish();
};
struct Image_2bfd30 {
    int vf;
    char pad[0x20];
    int m24;
};
extern void __cdecl Thunk(int);
void Image_Init(Image_2bfd30*);
void __fastcall Image_Init(Image_2bfd30* self, void*) {
    int x = self->m24;
    self->vf = ((hulk_intptr)DAT_0042ea40);
    Thunk(x);
    ((Image32_nv_2bfd30*)(((pure3d::Image32*)self)))->Finish();
}