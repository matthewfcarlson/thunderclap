// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ddbe0..0x000ddef0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f683177d {
#define TREE_TU_END }
namespace fn_f683177d {} using namespace fn_f683177d;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f683177d {
struct Helper_dddc0 {
};
class Obj_dddc0 {
  public:
    char pad[0x2230];
    Helper_dddc0* helper;
    void* stored;
    void f(void* a, void* b);
};
class Inner_dddf0 {
  public:
    void Reset_000f7110();
    bool Process_000f7a80(void*);
};
class Target_dddf0 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    char pad[0x2230 - 4];
    Inner_dddf0* inner;
    char Run(void*);
};
class Thing_dde30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void First();
    virtual void f8();
    virtual void Second();
    void Set(float x);
};
struct Handle_dde50 {
    void FUN_00293ef0();
    void FUN_00294080();
};
} // namespace fn_f683177d
struct Gfx {
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
    virtual int v25();
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
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60(int a);
    virtual int v61();
};
namespace fn_f683177d {
class Pass_dde50 {
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
    char pad04[0x2220];
    Handle_dde50 *handle;
    char hasHandle;
    char pad2229[3];
    int param;

    void FUN_000dde50();
};


// 0x000ddbe0 FUN_000ddbe0 (7 B): matches/0x000ddbe0.cpp
// sym: _FUN_000ddbe0
// data: gConstant_ddbe0 = DAT_004a0e14
extern "C" float FUN_000ddbe0() {
    return (*(const float*)&DAT_004a0e14);
}

} // namespace fn_f683177d

// 0x000ddbf0 FUN_000ddbf0 (370 B): equivalent/0x000ddbf0.cpp [wrapped: conflict: DAT_004de948; FEThings; FEThingsBase]
// sym: ??0FEThings@fn_000ddbf0@@QAE@PAVView_ddbf0@1@@Z
namespace fn_000ddbf0 {
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 8/8)
// FUN_000ddbf0 @ 0x000ddbf0
struct V3_ddbf0 { float x, y, z; };

extern "C" void* FUN_0008d690(unsigned int size);
void* FUN_00263ea0(unsigned int size);
extern "C++" __declspec(nothrow) float __cdecl FUN_000ddbe0();
extern float (__cdecl *DAT_004de948)();

class Camera {
public:
    virtual void AddRef();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void SetNear(float f);
    virtual void v8();
    virtual void SetFar(float f);
    Camera* FUN_002939a0();
    void FUN_00293af0(V3_ddbf0* v);
    void FUN_00293a90(V3_ddbf0* v);
};

class View_ddbf0 {
public:
    virtual void AddRef();
    View_ddbf0* FUN_00294880();
    void FUN_00293e90(unsigned int color);
    void FUN_00294980(Camera* cam);
    char pad4[0x1c - 4];
    unsigned int f1c;
    unsigned int f20;
    char pad24[4];
    int f28;
    int f2c;
};

class Widget_ddbf0 {
public:
    Widget_ddbf0* FUN_000f6ef0();
};

class __declspec(novtable) FEThingsBase {
public:
    virtual void vfunc_0();
    char pad4[0x1828 - 4];
    Camera* camera;
    char pad182c[0x2224 - 0x182c];
    void FUN_000f3000();
    FEThingsBase() { FUN_000f3000(); }
};

class FEThings : public FEThingsBase {
public:
    FEThings(View_ddbf0* existing);
    virtual void vfunc_0();
    View_ddbf0* screen;
    char ownsScreen;
    char pad2229[3];
    int f222c;
    Widget_ddbf0* widget;
};

FEThings::FEThings(View_ddbf0* existing)
{
    View_ddbf0* s = existing;
    if (existing != 0) {
        ownsScreen = 0;
    } else {
        void* mem = FUN_0008d690(0x140);
        if (mem != 0)
            s = ((View_ddbf0*)mem)->FUN_00294880();
        else
            s = 0;
        ownsScreen = 1;
    }
    screen = s;
    s->AddRef();
    f222c = 0;
    screen->f28 = 0;
    screen->f2c = 6;
    screen->f20 = 0xff000000;
    screen->FUN_00293e90(0xff505050);
    void* cmem = FUN_00263ea0(0xf8);
    Camera* cam;
    if (cmem != 0)
        cam = ((Camera*)cmem)->FUN_002939a0();
    else
        cam = 0;
    camera = cam;
    cam->AddRef();
    camera->SetNear(0.1f);
    camera->SetFar(100.0f);
    V3_ddbf0 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = -10.0f;
    camera->FUN_00293af0(&pos);
    V3_ddbf0 dir;
    dir.x = 0.0f;
    dir.y = 0.0f;
    dir.z = 1.0f;
    camera->FUN_00293a90(&dir);
    screen->FUN_00294980(camera);
    void* wmem = FUN_0008d690(0x120);
    if (wmem != 0)
        widget = ((Widget_ddbf0*)wmem)->FUN_000f6ef0();
    else
        widget = 0;
    DAT_004de948 = FUN_000ddbe0;
}
} // namespace fn_000ddbf0

namespace fn_f683177d {

// 0x000ddd70 FEThingsBase::vfunc_47 (1 B): matches/0x000ddd70.cpp
// sym: ?FUN_000ddd70@fn_f683177d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000ddd70() {}

} // namespace fn_f683177d

// 0x000ddd80 FEThingsBase::vfunc_63 (23 B): matches/0x000ddd80.cpp
// sym: ?vfunc_63@FEThingsBase@@UAEXII@Z
void FEThingsBase::vfunc_63(unsigned int x, unsigned int y) {
    this->f_2210 = x;
    this->f_2214 = y;
}


// 0x000ddda0 FUN_000ddda0 (30 B): matches/0x000ddda0.cpp [wrapped: conflict: CAction; CCollisionAction]
// sym: ?vfunc_2@CCollisionAction@fn_000ddda0@@UAEPAV12@E@Z
namespace fn_000ddda0 {
// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
struct ThisCall_000f6f60 {
    void FUN_000f6f60();
};
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_000f6f60*)(this))->FUN_000f6f60();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000ddda0

namespace fn_f683177d {

// 0x000dddc0 FUN_000dddc0 (38 B): matches/0x000dddc0.cpp
// sym: ?f@Obj_dddc0@fn_f683177d@@QAEXPAX0@Z
void Obj_dddc0::f(void* a, void* b) {
    ((owners::Obj_f86f0 *)helper)->FUN_000f86f0(0x8fc, (hulk_intptr)((const float*)0x27290));
    stored = b;
}


// 0x000dddf0 FUN_000dddf0 (51 B): matches/0x000dddf0.cpp
// sym: ?Run@Target_dddf0@fn_f683177d@@QAEDPAX@Z
char Target_dddf0::Run(void* arg) {
    inner->Reset_000f7110();
    bool b = inner->Process_000f7a80(arg);
    if (b)
        V6();
    return b;
}


// 0x000dde30 FUN_000dde30 (28 B): matches/0x000dde30.cpp
// sym: ?Set@Thing_dde30@fn_f683177d@@QAEXM@Z
// data: gDelta = DAT_004a0e14
void Thing_dde30::Set(float x) {
    DAT_004a0e14 = x;
    First();
    Second();
}


// 0x000dde50 FUN_000dde50 (156 B): matches/0x000dde50.cpp
// sym: ?FUN_000dde50@Pass_dde50@fn_f683177d@@QAEXXZ
// FUN_000dde50 @ 0x000dde50
// FUN_000dde50: run two virtual hooks while the device's state is saved and restored
void Pass_dde50::FUN_000dde50()
{
    if (hasHandle)
        handle->FUN_00293ef0();
    int saved = DAT_0052c2a8->v25();
    DAT_0052c2a8->v24(param);
    int mode = DAT_0052c2a8->v61();
    DAT_0052c2a8->v60(1);
    v8();
    v10();
    DAT_0052c2a8->v24(saved);
    DAT_0052c2a8->v60(mode);
    if (hasHandle)
        handle->FUN_00294080();
}

} // namespace fn_f683177d
