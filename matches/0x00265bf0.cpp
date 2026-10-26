#include "decls/data/engine/audio.h"
// data: gData_265bf0 = DAT_00527c28

extern "C" void Init(void*);
extern "C" void AddRef(void*);
extern "C" void Release(void*);
struct Obj_265bf0 {
    char pad0[1];
    unsigned char flag;
    char pad2[0x12];
    void* m14;
    void* m18;
    void* m1c;
    char pad20[4];
    char pad24[4];
    void* m28;
    void* m2c;
    void* m30;
};
void __fastcall Target(Obj_265bf0* self) {
    self->flag = 1;
    Init(((char(*)[16])((char*)&DAT_0051de40 + 40424)));
    void* p = self->m30;
    self->m28 = p;
    self->m2c = p;
    if (p)
        AddRef(p);
    p = self->m1c;
    self->m14 = p;
    self->m18 = p;
    if (p)
        AddRef(p);
    Release(self);
}
