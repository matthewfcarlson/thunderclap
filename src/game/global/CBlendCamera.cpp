// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00098460..0x000989d0 (kind game, layer game, confidence medium), dominant class CBlendCamera
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb8d9fac {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb8d9fac {} using namespace fn_fb8d9fac;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fb8d9fac {
class Obj_98480 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31(unsigned int);
};
class Owner_98480 {
  public:
    char pad[0x170];
    Obj_98480* a;
    Obj_98480* b;
    unsigned char flag;
    Obj_98480* go(hulk_uintptr);
};
class CGameCamera {
  public:
    void* vtable;
    void vfunc_29_000a91b0();
};
struct ThisCall_00098480 {
    void FUN_00098480(int);
};
extern "C" void __fastcall FUN_000a9620(CGameCamera*);
struct Vector { float x,y,z; };
extern "C" void __cdecl FUN_000a04c0(Vector*,float*,float*,float*);
struct Data_98500 { char pad0[4]; float scale; char pad8[0x1c]; float angle; char pad28[8]; Vector pos; };
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual float v8(); virtual void v9(); virtual float v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual Data_98500* v14();
 virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
 virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
 virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
 virtual Vector* v27(Vector*);
 char padding[0xd0]; unsigned int value;
};
struct Output_98500 { Vector pos; float a,b,c,d; unsigned int value; float e,f; };
typedef unsigned char byte_98990;
struct CBlendCamera {
    virtual void a();
    virtual void b();
    virtual CBlendCamera* vfunc_2(byte_98990);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    void call29_000a91b0();
    void call9620_000a9620();
};
void __cdecl thunk_FUN_00267090(CBlendCamera*);

} // namespace fn_fb8d9fac

// 0x00098460 FUN_00098460 (32 B): matches/0x00098460.cpp
// sym: ?FUN_00098460@C_98460@owners@@QAEHH@Z
int owners::C_98460::FUN_00098460(int x) {
    return a >= b;
}

namespace fn_fb8d9fac {

// 0x00098480 FUN_00098480 (93 B): matches/0x00098480.cpp
// sym: ?go@Owner_98480@fn_fb8d9fac@@QAEPAVObj_98480@2@I@Z
Obj_98480* Owner_98480::go(hulk_uintptr arg) {
    Obj_98480* result = b;
    if (a) {
        if (flag)
            a->f31(arg);
        a->f1();
        a = 0;
    }
    if (b) {
        b->f1();
        b = 0;
    }
    return result;
}


// 0x000984e0 FUN_000984e0 (31 B): matches/0x000984e0.cpp
// sym: ?FUN_000984e0@fn_fb8d9fac@@YIXPAVCGameCamera@1@@Z
void __fastcall FUN_000984e0(CGameCamera* p) {
    *(void**)p = (void*)((hulk_intptr)DAT_00404b3c);
    ((ThisCall_00098480*)(p))->FUN_00098480(0);
    p->vfunc_29_000a91b0();
    FUN_000a9620(p);
}


// 0x00098500 FUN_00098500 (171 B): equivalent/0x00098500.cpp
// sym: ?target@fn_fb8d9fac@@YGXPAUObject@1@PAUOutput_98500@1@@Z @dc9be461c73a @wf4d9cb53b6e7
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 0/0)
// FUN_00098500 @ 0x00098500
void __stdcall target(Object* obj, Output_98500* out) {
 Vector temp;
 Vector* p=obj->v27(&temp);
 out->pos.x=p->x; out->pos.y=p->y; out->pos.z=p->z;
 Data_98500* data=obj->v14();
 temp.x=data->pos.x-out->pos.x;
 temp.y=data->pos.y-out->pos.y;
 temp.z=data->pos.z-out->pos.z;
 FUN_000a04c0(&temp,&out->a,&out->b,&out->c);
 hulk_freg angle=FUN_000189c0(data->angle);
 float ratio=(float)(data->scale/cos(angle));
 out->d=FUN_000189c0(ratio);
 out->value=obj->value;
 out->e=obj->v8();
 out->f=obj->v10();
}


// 0x00098990 CBlendCamera::vfunc_2 (52 B): matches/0x00098990.cpp
// sym: ?vfunc_2@CBlendCamera@fn_fb8d9fac@@UAEPAU12@E@Z
CBlendCamera* CBlendCamera::vfunc_2(byte_98990 param) {
    CBlendCamera* self = this;
    *(hulk_intptr*)self = ((hulk_intptr)DAT_00404b3c);
    ((ThisCall_00098480*)(this))->FUN_00098480(0);
    self->call29_000a91b0();
    self->call9620_000a9620();
    if (param & 1)
        thunk_FUN_00267090(self);
    return self;
}

} // namespace fn_fb8d9fac
