// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002744e0..0x00274590 (kind game, layer engine, confidence high), dominant class core::DriveMediaRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/core.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcf3df4f {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fcf3df4f {} using namespace fn_fcf3df4f;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_fcf3df4f {
class V {
  public:
    virtual void A();
    virtual void B();
};
class Obj_2744e0 {
  public:
    char pad[4];
    V sub;
    char rest[0x10];
    int count;
};
struct Obj8_274520 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};
struct Obj2_274520 {
    virtual void v0();
    virtual void v1();
};
struct Drive_274520 {
    int x;
    Obj2_274520 b;
    int pad;
    Obj8_274520* a;
    int pad2[2];
    int z;
};
struct Data_274520 {
    unsigned int v[21];
};
class pddiObject_274570 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_274570 : public pddiObject_274570 {};
class pddiBaseShader_274570 : public pddiShader_274570 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_274570 : public pddiBaseShader_274570 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};

} // namespace fn_fcf3df4f

// 0x002744e0 FUN_002744e0 (53 B): matches/0x002744e0.cpp
// sym: ?FUN_002744e0@DriveRequest@core@@QAEXXZ
void core::DriveRequest::FUN_002744e0() {
    Obj_2744e0* p = (*(Obj_2744e0 * *)&this->f_08);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b9bc);
    p->sub.A();
    --(*(int*)((char*)(*(Obj_2744e0 * *)&this->f_08) + 0x14));
    p = (*(Obj_2744e0 * *)&this->f_08);
    p->sub.B();
    p = (*(Obj_2744e0 * *)&this->f_08);
    ((V*)p)->B();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b914);
}


// 0x00274520 core::DriveMediaRequest::vfunc_1 (78 B): matches/0x00274520.cpp
// sym: ?vfunc_1@DriveMediaRequest@core@@UAEHXZ
int core::DriveMediaRequest::vfunc_1() {
    Obj8_274520* a = (*(Drive_274520 * *)&this->f_08)->a;
    a->v7();
    Data_274520* p = (Data_274520*)((unsigned int *)((owners::ProjectileMissile_2728d0 *)a)->FUN_002728d0());
    *(*(Data_274520 * *)&this->f_0c) = *p;
    (*(Drive_274520 * *)&this->f_08)->b.v0();
    (*(Drive_274520 * *)&this->f_08)->z = 0;
    (*(Drive_274520 * *)&this->f_08)->b.v1();
    return 1;
}


// 0x00274570 core::DriveMediaRequest::vfunc_4 (6 B): matches/0x00274570.cpp
// sym: ?vfunc_4@DriveMediaRequest@core@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int core::DriveMediaRequest::vfunc_4() {
    return 1;
}


// 0x00274580 core::DriveMediaRequest::vfunc_6 (6 B): matches/0x00274580.cpp
// sym: ?vfunc_6@DriveMediaRequest@core@@UAEHXZ
int core::DriveMediaRequest::vfunc_6() {
    return (int)(0xC);
}

