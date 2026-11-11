// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a2e70..0x002a30a0 (kind game, layer engine, confidence medium), dominant class pure3d::DirectionalLight
#include "tree_prelude.h"
#include "decls/address.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff411229 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff411229 {} using namespace fn_ff411229;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ff411229 {
class Light_2a2e70 {
  public:
    Light_2a2e70();
    virtual void f0();
};
struct Color {
    float x, y, z;
    Color() : x(0), y(0), z(1) {}
};
class DirectionalLight : public Light_2a2e70 {
  public:
    DirectionalLight();
    virtual void f0();
    char pad[0x50];
    int type;
    Color color;
};
struct H {
    void run();
};
class C_2a2ef0 {
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
    virtual int f9(int);
    char pad[0x54];
    H h;
    int target(int x, int y, int z);
};
extern void* Light_2a2f90_vftable[];
class Light_2a2f90 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class DirectionalLight_2a2f90 : public Light_2a2f90 {
  public:
    DirectionalLight_2a2f90* vfunc_5(signed char flags);
};
struct Point { float x,y,z; void FUN_0022d180(); };
struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(int); char pad[0x58-4]; Point position; void FUN_002a2fc0(const Point* p); };
struct LightData_2a2ff0 {
 unsigned char kind; char padding[3];
 unsigned int zero0; unsigned int color;
 float position[3]; float direction[3];
 float intensity; float extra[5]; float range;
};
} // namespace fn_ff411229
struct Gfx {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
 virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36();
 virtual void slot37(unsigned int, LightData_2a2ff0*, unsigned int);
};
namespace fn_ff411229 {
namespace pure3d {
struct DirectionalLight {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(unsigned int);
 char pad04[12]; unsigned char enabled; unsigned char kind; char pad12[2]; unsigned int color; char pad18[12]; unsigned int handle; char pad28[48]; float direction[3];
};
}


// 0x002a2e70 FUN_002a2e70 (40 B): matches/0x002a2e70.cpp
// sym: ??0DirectionalLight@fn_ff411229@@QAE@XZ
DirectionalLight::DirectionalLight() {
    type = 2;
}


// 0x002a2ef0 FUN_002a2ef0 (44 B): matches/0x002a2ef0.cpp
// sym: ?target@C_2a2ef0@fn_ff411229@@QAEHHHH@Z
int C_2a2ef0::target(int x, int y, int z) {
    *(int*)((char*)this + 0x58) = x;
    *(int*)((char*)this + 0x5c) = y;
    *(int*)((char*)this + 0x60) = z;
    h.run();
    return f9(1);
}

} // namespace fn_ff411229

// 0x002a2f20 FUN_002a2f20 (30 B): matches/0x002a2f20.cpp
// sym: ?FUN_002a2f20@C_2a2f20@owners@@QAEXPAH00@Z
void owners::C_2a2f20::FUN_002a2f20(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}

namespace fn_ff411229 {

// 0x002a2f90 pure3d::DirectionalLight::vfunc_2 (36 B): matches/0x002a2f90.cpp
// sym: ?vfunc_5@DirectionalLight_2a2f90@fn_ff411229@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
DirectionalLight_2a2f90* DirectionalLight_2a2f90::vfunc_5(signed char flags) {
    *(void***)this = Light_2a2f90_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x002a2fc0 FUN_002a2fc0 (44 B): equivalent/0x002a2fc0.cpp
// sym: ?FUN_002a2fc0@Obj@fn_ff411229@@QAEXPBUPoint@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002a2fc0 @ 0x002a2fc0
void Obj::FUN_002a2fc0(const Point* p) { position = *p; position.FUN_0022d180(); v9(1); }


// 0x002a2ff0 pure3d::DirectionalLight::vfunc_9 (175 B): equivalent/0x002a2ff0.cpp
// sym: ?vfunc_9@DirectionalLight@pure3d@fn_ff411229@@UAEXI@Z
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 2/2)
// pure3d::DirectionalLight::vfunc_9 @ 0x002a2ff0
namespace pure3d {
void DirectionalLight::vfunc_9(unsigned int index) {
 if (enabled) {
 LightData_2a2ff0 data;
 data.kind=kind; data.zero0=0; data.color=color;
 data.position[0]=0.0f; data.position[1]=0.0f; data.position[2]=0.0f;
 data.direction[0]=direction[0]; data.direction[1]=direction[1]; data.direction[2]=direction[2];
 data.intensity=1.0f;
 data.extra[0]=0.0f; data.extra[1]=0.0f; data.extra[2]=0.0f; data.extra[3]=0.0f; data.extra[4]=0.0f;
 data.range=10000000.0f;
 DAT_0052c2a8->slot37(handle, &data, index);
 }
}
}

} // namespace fn_ff411229
