#include "compat/ptr.h"
extern "C" char DAT_00421990[];
struct Item_1c6050 {
    char pad[0x23];
    char flag;
};
struct Holder_1c6050 {
    Item_1c6050* Find(int);
};
struct Obj_1c6050 {
    char pad[12];
    Holder_1c6050* h;
    void Poke(int a, int b);
};
struct Sub_1c6050 {
    char pad[8];
    void Init();
    void Set(int);
};
Obj_1c6050* __stdcall Make2();
Obj_1c6050* __stdcall Make0();
struct CRenderableCharacter_1c6050 {
    void* vf;
    char pad[4];
    Sub_1c6050 s;
    hulk_intptr b;
    CRenderableCharacter_1c6050* Target(int arg1, int arg2);
};
CRenderableCharacter_1c6050* CRenderableCharacter_1c6050::Target(int arg1, int arg2) {
    vf = (void*)((hulk_intptr)DAT_00421990);
    s.Init();
    s.Set(arg1);
    Make2()->Poke(arg1, arg2);
    Obj_1c6050* p = Make0();
    Holder_1c6050* h = p->h;
    Item_1c6050* it = h->Find(arg1);
    b = (hulk_intptr)it;
    it->flag = 1;
    return this;
}
