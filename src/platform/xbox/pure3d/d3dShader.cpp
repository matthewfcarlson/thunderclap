// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00333370..0x003335e0 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dShader
#include "tree_prelude.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f325dd7e {
#define TREE_TU_END }
namespace fn_f325dd7e {} using namespace fn_f325dd7e;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f325dd7e {
class T_3333a0 {
  public:
    char pad[0x28];
    char m28;
    char Fn(int* p);
};
class X_3333b0 {
  public:
    char pad[0x2c];
    void Set(int v);
};
class Obj {
  public:
    char _m_pad_0[0x40];
    int flag;
    char _m_pad_44[0x8];
    int value;
    void Set(void* p);
    void Set(int x);
};
class Obj_3333e0 {
  public:
    char pad[0x44];
    int value;
    void Set(int x);
};
class Thing_333400 {
    char pad[0x7c];
    char mFlag;

  public:
    void Set(void* p);
};
class Obj_333410 {
  public:
    char pad[0x60];
    void Set(int v);
};

} // namespace fn_f325dd7e

// 0x00333370 pure3d::d3dShader::vfunc_21 (38 B): matches/0x00333370.cpp [wrapped: conflict: pure3d::d3dShader]
// sym: ?vfunc_21@d3dShader@pure3d@fn_00333370@@UAEXPAUData_333370@3@@Z
namespace fn_00333370 {
struct Data_333370 {
    int a, b, c, d, e;
};
namespace pure3d { class d3dShader {
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
    virtual void vfunc_21(Data_333370*);
    virtual void v22();
    virtual void v23();
    virtual void v24();
    char pad[0x4c];
    Data_333370 m;
}; }
void pure3d::d3dShader::vfunc_21(Data_333370* out) {
    *out = m;
}
} // namespace fn_00333370

namespace fn_f325dd7e {

// 0x003333a0 FUN_003333a0 (15 B): matches/0x003333a0.cpp
// sym: ?Fn@T_3333a0@fn_f325dd7e@@QAEDPAH@Z
char T_3333a0::Fn(int* p) {
    char r = (p != 0);
    m28 = r;
    return r;
}


// 0x003333b0 FUN_003333b0 (10 B): matches/0x003333b0.cpp
// sym: ?Set@X_3333b0@fn_f325dd7e@@QAEXH@Z
void X_3333b0::Set(int v) {
    *(int*)((char*)this + 0x2c) = v;
}


// 0x003333c0 FUN_003333c0 (17 B): matches/0x003333c0.cpp
// sym: ?Set@Obj@fn_f325dd7e@@QAEXPAX@Z
void Obj::Set(void* p) {
    flag = p != 0;
}


// 0x003333e0 FUN_003333e0 (10 B): matches/0x003333e0.cpp
// sym: ?Set@Obj_3333e0@fn_f325dd7e@@QAEXH@Z
void Obj_3333e0::Set(int x) {
    value = x;
}


// 0x003333f0 FUN_003333f0 (10 B): matches/0x003333f0.cpp
// sym: ?Set@Obj@fn_f325dd7e@@QAEXH@Z
void Obj::Set(int x) {
    value = x;
}


// 0x00333400 FUN_00333400 (15 B): matches/0x00333400.cpp
// sym: ?Set@Thing_333400@fn_f325dd7e@@QAEXPAX@Z
void Thing_333400::Set(void* p) {
    mFlag = (p != 0);
}


// 0x00333410 FUN_00333410 (10 B): matches/0x00333410.cpp
// sym: ?Set@Obj_333410@fn_f325dd7e@@QAEXH@Z
void Obj_333410::Set(int v) {
    *(int*)((char*)this + 0x60) = v;
}

} // namespace fn_f325dd7e

// 0x00333420 pure3d::d3dShader::vfunc_12 (113 B): matches/0x00333420.cpp [wrapped: conflict: pure3d::d3dShader]
// sym: ?vfunc_12@d3dShader@pure3d@fn_00333420@@QAEXXZ
namespace fn_00333420 {

struct Context {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual unsigned char enabled();
    virtual void setColor(unsigned int, unsigned int, unsigned int);
    virtual void getValues(void*, unsigned int*, unsigned int*);
};
namespace pure3d {
struct d3dShader {
    char pad0[16];
    Context* context;
    char pad14[8];
    unsigned int mode;
    char pad20[88];
    unsigned int data;
    void vfunc_12();
};
void d3dShader::vfunc_12() {
    if (mode == 2 && context->enabled() == 1) {
        if (!(DAT_00555b90 & 1)) {
            DAT_00555b90 |= 1;
            DAT_00555b8c = 0xff000000;
        }
        unsigned int a, b;
        context->getValues(&data, &a, &b);
        context->setColor(DAT_00555b8c, a, b);
    }
}
} // namespace pure3d
} // namespace fn_00333420


// 0x003334a0 pure3d::d3dShader::vfunc_13 (124 B): matches/0x003334a0.cpp [wrapped: conflict: Context; pure3d::d3dShader]
// sym: ?vfunc_13@d3dShader@pure3d@fn_003334a0@@QAEXXZ
namespace fn_003334a0 {

typedef unsigned int U_3334a0;
struct Context {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual unsigned char query();
    virtual void set(U_3334a0 color, U_3334a0 second, U_3334a0 third);
    virtual void get(U_3334a0* color, U_3334a0* second, U_3334a0* third);
};
namespace pure3d {
struct d3dShader {
    char pad0[16];
    Context* context;
    char pad14[8];
    int mode;
    char pad20[88];
    U_3334a0 color;
    void vfunc_13();
};
void d3dShader::vfunc_13() {
    if (mode == 2 && context->query() == 1) {
        if (!((*(U_3334a0*)&DAT_00555b98) & 1)) {
            (*(U_3334a0*)&DAT_00555b98) |= 1;
            (*(U_3334a0*)&DAT_00555b94) = 0xff000000;
        }
        U_3334a0 oldColor, second, third;
        context->get(&oldColor, &second, &third);
        if (oldColor == (*(U_3334a0*)&DAT_00555b94))
            context->set(color, second, third);
    }
}
} // namespace pure3d
} // namespace fn_003334a0


// 0x003335c0 pure3d::d3dShader::vfunc_3 (30 B): matches/0x003335c0.cpp
// sym: ??_Gd3dShader@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::d3dShader::~d3dShader() {}

