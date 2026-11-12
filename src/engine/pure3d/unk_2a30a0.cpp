// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a30a0..0x002a34c0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3e6e6aa {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3e6e6aa {} using namespace fn_f3e6e6aa;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f3e6e6aa {
class Base_2a30a0 {
  public:
    Base_2a30a0();
};
void* Alloc(hulk_uintptr);
class Manager_2a30a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void Call(unsigned int, int);
};
class Obj_2a30a0 {
  public:
    virtual void Init();
    char pad[12];
    Manager_2a30a0* manager;
};
Obj_2a30a0* __fastcall Construct(void*);
class Target_2a30a0 : public Base_2a30a0 {
  public:
    Target_2a30a0();
    Obj_2a30a0* mObj;
};
struct Inner_2a3130 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
};
struct Shader_2a3130 {
    virtual void init();
    char pad[12];
    Inner_2a3130* inner;
    // (x64t5) the words after the service pointer as the constructor 0x0028edb0 writes them (a flag, a word) and the
    // block's last word: the object is allocated by this record's size (0x20 on 32-bit; the 0x20-byte block was 8
    // short natively)
    unsigned char flag;
    unsigned int value;
    int f1c;
    Shader_2a3130* FUN_0028edb0();   // (x64t3) the shader's constructor, by address (was `build`, unbound)
};
void* FUN_00263ea0(unsigned int);   // (x64t3) the allocator's jmp thunk 0x00263ea0 (was `alloc`, unbound)
struct VBuf_2a3250 {
    char pad00[8];
    float *pos;              // 0x08
    char pad0c[4];
    int *tag;                // 0x10
    void FUN_0008ef00();
};
} // namespace fn_f3e6e6aa
class Gfx {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24(int a);
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual VBuf_2a3250 *v30(int a, int b, int c, int d, int e);
    virtual void v31(VBuf_2a3250 *b);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54(int a);
    virtual void v55();
    virtual void v56(int a, int b, int c, int d);
    virtual void v57();
    virtual void v58(int a);
    virtual void v59();
    virtual void v60(int a);
    virtual void v61();
    virtual void v62(int a);
    virtual void v63();
    virtual void v64(int a);
    virtual void v65();
    virtual void v66(int a);
    virtual void v67();
    virtual void v68(int a);
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74(int a, int b, int c);
};
namespace fn_f3e6e6aa {
class Obj3_2a3250 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual int v7();
};
class Obj2_2a3250 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v16(int a);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int a);
};
struct Holder_2a3250 {
    Obj2_2a3250 *obj;
    void FUN_00293da0(float a, float b, float c);
};
class Probe_2a3250 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual float v8();
};
struct ProbeHolder {
    char pad00[0x18];
    Probe_2a3250 *probe;            // 0x18
};
struct ProbeOwner {
    char pad00[8];
    ProbeHolder *holder;     // 0x08
};
struct Target_2a3250 {
    char pad00[0x10];
    int handle;              // 0x10
};
class Quad_2a3250 {
public:
    Target_2a3250 *target;          // 0x00
    int tag;                 // 0x04
    int mode;                // 0x08
    void FUN_002a3250();
};
class Obj_2a3460 {
  public:
    virtual void f();
    virtual void g();
};
namespace pure3d {
class Drawable {
  public:
    virtual void f();
    char pad[12];
    Drawable();
};
}
namespace pure3d {
struct First {
    int a;
    First() {
        a = 0;
        _ReadWriteBarrier();
    }
};
}
namespace pure3d {
class DrawableHierarchy : public Drawable, public First {
  public:
    virtual void f();
    int b, c, d, e, g, h, i, j, k, l;
    DrawableHierarchy();
};
}


// 0x002a30a0 FUN_002a30a0 (113 B): matches/0x002a30a0.cpp
// sym: ??0Target_2a30a0@fn_f3e6e6aa@@QAE@XZ
Target_2a30a0::Target_2a30a0() {
    void* p = Alloc(0x20);
    Obj_2a30a0* o;
    if (p)
        o = Construct(p);
    else
        o = 0;
    mObj = o;
    mObj->Init();
    {
        Obj_2a30a0* q = mObj;
        q->manager->Call(((hulk_intptr)((char*)0x54494c)), 0);
    }
    {
        Obj_2a30a0* q = mObj;
        q->manager->Call(0x444d4853, 0);
    }
    {
        Obj_2a30a0* q = mObj;
        q->manager->Call(0x54535441, 0);
    }
    {
        Obj_2a30a0* q = mObj;
        q->manager->Call(0x444d4c42, 4);
    }
}

// 0x002a3120 thunk_FUN_002b5050 (5 B): not yet verified

// 0x002a3130 FUN_002a3130 (106 B): matches/0x002a3130.cpp
// sym: _FUN_002a3130
extern "C" void FUN_002a3130() {
    if ((*(Shader_2a3130**)&DAT_00554bb4) == 0) {
        Shader_2a3130* p = (Shader_2a3130*)FUN_00263ea0(sizeof(Shader_2a3130));
        if (p)
            (*(Shader_2a3130**)&DAT_00554bb4) = p->FUN_0028edb0();
        else
            (*(Shader_2a3130**)&DAT_00554bb4) = 0;
        (*(Shader_2a3130**)&DAT_00554bb4)->init();
        (*(Shader_2a3130**)&DAT_00554bb4)->inner->f6(0x444d4853, 0);
        (*(Shader_2a3130**)&DAT_00554bb4)->inner->f6(0x54535441, 0);
        (*(Shader_2a3130**)&DAT_00554bb4)->inner->f6(0x444d4c42, 1);
    }
}

} // namespace fn_f3e6e6aa

// 0x002a31a0 FUN_002a31a0 (10 B): matches/0x002a31a0.cpp
// sym: ?FUN_002a31a0@C_2a31a0@owners@@QAEXH@Z
// Same code shape as 0x00264860 (propagated; names are from that function)
void owners::C_2a31a0::FUN_002a31a0(int x) {
    value = x;
}

namespace fn_f3e6e6aa {

// 0x002a3250 FUN_002a3250 (501 B): equivalent/0x002a3250.cpp
// sym: ?FUN_002a3250@Quad_2a3250@fn_f3e6e6aa@@QAEXXZ @e28d4fb2bf54 @wa58daf28f899
// STATUS: equivalent (tools/equiv.py level 3: 2362 inputs, branch coverage 0/0)
// FUN_002a3250 @ 0x002a3250
void Quad_2a3250::FUN_002a3250()
{
    Gfx *dev = DAT_0052c2a8;
    dev->v54(mode);
    dev->v56(1, 1, 1, 1);
    dev->v58(0);
    dev->v64(1);
    dev->v74(1, 1, 1);
    dev->v66(2);
    dev->v68(0);
    (*(Holder_2a3250**)&DAT_0052c2ac)->obj->v21(0);
    int w = (*(Obj3_2a3250**)&DAT_0052c2a4)->v6();
    int h = (*(Obj3_2a3250**)&DAT_0052c2a4)->v7();
    (*(Holder_2a3250**)&DAT_0052c2ac)->FUN_00293da0((float)h, (float)w, 1.0f);
    dev->v24(2);
    VBuf_2a3250 *vb = dev->v30(target->handle, 1, 0x2020, 4, 0);
    float f = (*(ProbeOwner**)&DAT_0052c2b4)->holder->probe->v8() + 0.001f;
    *vb->tag = tag;
    vb->pos[0] = 0.0f;
    vb->pos[1] = 0.0f;
    vb->pos[2] = f;
    vb->FUN_0008ef00();
    *vb->tag = tag;
    vb->pos[0] = 1.0f;
    vb->pos[1] = 0.0f;
    vb->pos[2] = f;
    vb->FUN_0008ef00();
    *vb->tag = tag;
    vb->pos[0] = 0.0f;
    vb->pos[1] = 1.0f;
    vb->pos[2] = f;
    vb->FUN_0008ef00();
    *vb->tag = tag;
    vb->pos[0] = 1.0f;
    vb->pos[1] = 1.0f;
    vb->pos[2] = f;
    vb->FUN_0008ef00();
    dev->v31(vb);
    (*(Holder_2a3250**)&DAT_0052c2ac)->obj->v16(0);
    dev->v24(0);
    dev->v58(1);
    dev->v62(1);
    dev->v60(3);
    dev->v64(0);
}


// 0x002a3460 FUN_002a3460 (26 B): matches/0x002a3460.cpp
// sym: ?target@fn_f3e6e6aa@@YAXXZ
// Same code shape as 0x00085d70 (propagated; names are from that function)
// data: globalObj_2a3460 = DAT_00554bb4
void target() {
    if ((*(Obj_2a3460**)&DAT_00554bb4)) {
        (*(Obj_2a3460**)&DAT_00554bb4)->g();
        (*(Obj_2a3460**)&DAT_00554bb4) = 0;
    }
}


// 0x002a3480 FUN_002a3480 (53 B): matches/0x002a3480.cpp
// sym: ??0DrawableHierarchy@pure3d@fn_f3e6e6aa@@QAE@XZ
namespace pure3d {
DrawableHierarchy::DrawableHierarchy() {
    _ReadWriteBarrier();
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    g = 0;
    h = 0;
    i = 0;
    j = 0;
    k = 0;
    l = 0;
}
}

} // namespace fn_f3e6e6aa
