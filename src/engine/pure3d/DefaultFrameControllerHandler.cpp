// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00284a10..0x002878b0 (kind game, layer engine, confidence high), dominant class pure3d::DefaultFrameControllerHandler
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/game/global.h"
#include "gen/content.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_ff70be84 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_ff70be84 {} using namespace fn_ff70be84;
namespace fn_ff70be84 { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ff70be84 {
extern char hulk_at_0042c5bc[];
class FrameController {
  public:
    virtual void f();
    char pad[12];
    unsigned char value;
    FrameController* reset();
};
class Base_284a70 {
  public:
    void initialize_0027b070();
};
struct AnimationFrameController {
    void Init_0027b070();
    hulk_uintptr vptr;
    char pad4[0xc];
    unsigned char field10;
    char pad11[7];
    float field18;
    AnimationFrameController();
};
extern unsigned int hulk_at_0042c624;
struct Status_284b70 {
    char pad[0x18];
    char state;
};
class AnimationFrameController_284b70 {
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
    virtual float getTime();
    virtual void v14();
    virtual void getRange(float *start, float *end);
    virtual void v16();
    virtual int getMode();
    virtual void v18();
    virtual unsigned getCycles();
    virtual hulk_freg vfunc_20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual Status_284b70 *getStatus();
    virtual void v26();
};
extern "C" char DAT_0042c694[];
class SimpleFrameController {
  public:
    char pad[0x40];
};
struct ThisCall_0027b070 {
    void Init_0027b070();
};
class C_284e50 {
    char pad[0x20];

  public:
    unsigned int value;
};
class Obj {
  public:
    int value;
    void Set(int x);
};
struct Owner_284fa0 {
    char pad00[0x14];
    float rate;
    char pad18;
    hulk_freg FUN_00289db0(void* a0, void* a1, float cur, float dt, int a4, int a5, char noFlag, int a7);
};
struct Track {
    float cur;
    int a4;
    int a8;
    float remain;
    float fadeRate;
    float weight;
    int f18;
    int f1c;
    int a20;
    int f24;
    Owner_284fa0* owner;
};
class BlendFrameController {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vfunc_6(float dt, char force);
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
    char pad04[0xc];
    char busy;
    char pad11[7];
    float timeScale;
    char pad1c[0xc];
    unsigned int count;
    Track tracks[1];
    char pad58[0x108 - 0x2c - sizeof(Track)];
    char dirty;
};
} // namespace fn_ff70be84
namespace pure3d {
extern const float hulk_at_003fb868;
}
namespace fn_ff70be84 {
class C_285230 {
    char pad[0x20];

  public:
    unsigned int value;
};
} // namespace fn_ff70be84
namespace pure3d {
extern const float hulk_at_003f32e0;
}
namespace fn_ff70be84 {
class Item_285410 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Match(int);
};
class Container_285410 {
  public:
    char pad[0x14];
    unsigned int count;
    Item_285410* items[1];
    hulk_uintptr Find(int value);
};
class SimpleChunkHandler_285650 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual char vfunc_6(unsigned int);
    virtual void f7();
};
extern void* Entity_285720_vftable[];
class Entity_285720 {
  public:
    void Destroy_0027afd0(); // FUN_00236d60, __thiscall, this in ecx
};
class FrameController_285720 : public Entity_285720 {
  public:
    FrameController_285720* vfunc_5(signed char flags);
};
extern void* FrameController_285750_vftable[];
class FrameController_285750 {
  public:
    void Destroy_0027afd0(); // FUN_00236d60, __thiscall, this in ecx
};
class AnimationFrameController_285750 : public FrameController_285750 {
  public:
    AnimationFrameController_285750* vfunc_5(signed char flags);
};
extern char DAT_0042c5bc[];
extern char DAT_0042c624[];
struct Ref_285780 {
    virtual void AddRef();
    virtual void Release();
};
class SimpleFrameController_285780 {
public:
    hulk_intptr vptr;
    char pad04[0xc];
    char field_10;
    char pad11[7];
    int field_18;
    char pad1c[4];
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
    int field_30;
    int field_34;
    char field_38;
    char pad39[3];
    Ref_285780* ref;
    void FUN_0027b0b0(const SimpleFrameController_285780* src);
    SimpleFrameController_285780* FUN_00285780(const SimpleFrameController_285780* src);
};
extern void* hulk_at_0042c694[];
extern void* vFC[];
class Ref_285800 {
  public:
    virtual void F0();
    virtual void Release();
};
struct AnimationFrameController_285800 {
    void* vf;
    void Dtor_0027afd0() throw();
};
struct SimpleFrameController_285800 : AnimationFrameController_285800 {
    char pad[0x38];
    Ref_285800* p3c;
    void Dtor2() throw();
};
struct Source_285830 {
    virtual void AddRef();
    virtual void Release();
    char pad4[0xc];
    float length;           // 0x10
};
class X_285a20 {
  public:
    virtual void f0();
    virtual void f1();
};
class C_285a20 {
  public:
    char pad[0x28];
    X_285a20* p;
    void run();
};
struct Data_285a70 {
    char pad[0x10];
    float value;
};
struct Target_285a70 {
    int a;
    int b;
    float result;
    int c;
    int d;
    float one;
    float maxv;
    int e;
    int f;
    unsigned char flag;
    char pad[3];
    Data_285a70* data;
};
extern void* hulk_at_0042c7b0[];
class Ref_2863d0 {
  public:
    virtual void F0();
    virtual void Release();
};
struct FrameControllerLoader_2863d0 {
    void* vf;
    char pad[0x14];
    Ref_2863d0* arr[4];
    void Dtor() throw();
};
class Item {
  public:
    virtual void Add();
    virtual void Release();
};
class Holder {
    char pad[0x14];
    unsigned count;
    Item* slots[4];

  public:
    void Insert(Item* p);
};
typedef unsigned int u32_286470;
typedef unsigned int u32_2864a0;
class DynamicCaster_286750 {
  public:
    virtual void Fnf_00286470(void*);
    DynamicCaster_286750() {}
};
class Inventory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int load(DynamicCaster_286750*, U64);
};
struct DynamicCaster_286780 {
    virtual void cast_002864a0(void*);
};
struct Manager {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int find(DynamicCaster_286780*, __int64);
};
extern __int64 __cdecl hash_0027b020(const char*);
class BlendFrameController_287860 {
  public:
    BlendFrameController_287860();
};
extern int hulk_at_0042c81c;
class PoseAnimationController_287860 : public BlendFrameController_287860 {
  public:
    char pad[0x10f];
    PoseAnimationController_287860();
};


// 0x00284a10 FUN_00284a10 (69 B): matches/0x00284a10.cpp
// sym: ?FUN_00284a10@fn_ff70be84@@YAMM@Z
// data: kThree = DAT_003f331c, kZero_284a10 = DAT_003f32e0
hulk_freg FUN_00284a10(float x) {
    if (x <= DAT_003f32e0)
        return DAT_003f32e0;
    if (x >= DAT_003f32dc)
        return DAT_003f32dc;
    return (DAT_003f331c - (x + x)) * x * x;
}


// 0x00284a70 FUN_00284a70 (22 B): matches/0x00284a70.cpp
// sym: ?reset@FrameController@fn_ff70be84@@QAEPAV12@XZ
FrameController* FrameController::reset() {
    ((Base_284a70*)this)->initialize_0027b070();
    *(void**)this = hulk_at_0042c5bc;
    value = 0;
    return this;
}

} // namespace fn_ff70be84

// 0x00284a90 FUN_00284a90 (33 B): matches/0x00284a90.cpp [wrapped: lost its match in the tree (codegen differs (3 of 14 instructions))]
// sym: ??0FrameController@fn_00284a90@@QAE@PAX@Z
namespace fn_00284a90 {
extern void* frameVtable;
class Base_284a90 {
  public:
    void Init_0027b0b0(void*);
};
class FrameController {
  public:
    char pad[0x10];
    FrameController(void*);
};
FrameController::FrameController(void* p) {
    ((Base_284a90*)this)->Init_0027b0b0(p);
    *(void**)this = &frameVtable;
    ((char*)this)[0x10] = ((char*)p)[0x10];
}
} // namespace fn_00284a90

namespace fn_ff70be84 {

// 0x00284ac0 FUN_00284ac0 (11 B): matches/0x00284ac0.cpp
// sym: ?FUN_00284ac0@fn_ff70be84@@YIXPAVCEffectStopTrack@1@@Z
// Same code shape as 0x00060920 (propagated; names are from that function)
void __fastcall FUN_00284ac0(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)((int*)DAT_0042c5bc);
    FUN_0027afd0(self);
}

} // namespace fn_ff70be84

// 0x00284ad0 FUN_00284ad0 (10 B): matches/0x00284ad0.cpp
// sym: ?FUN_00284ad0@C_284ad0@owners@@QAEXE@Z
void owners::C_284ad0::FUN_00284ad0(unsigned char x) {
    value = x;
}


// 0x00284ae0 FUN_00284ae0 (4 B): matches/0x00284ae0.cpp
// sym: ?FUN_00284ae0@C_284ae0@owners@@QAEEXZ
unsigned char owners::C_284ae0::FUN_00284ae0() {
    return pad[0x10];
}

namespace fn_ff70be84 {

// 0x00284af0 FUN_00284af0 (29 B): matches/0x00284af0.cpp
// sym: ??0AnimationFrameController@fn_ff70be84@@QAE@XZ
AnimationFrameController::AnimationFrameController() {
    Init_0027b070();
    field10 = 0;
    vptr = (hulk_uintptr)&hulk_at_0042c624;
    field18 = 1.0f;
}

} // namespace fn_ff70be84

// 0x00284b50 pure3d::AnimationFrameController::vfunc_8 (10 B): matches/0x00284b50.cpp
// sym: ?vfunc_8@AnimationFrameController@pure3d@@UAEXH@Z
void pure3d::AnimationFrameController::vfunc_8(int x) {
    (*(int *)&this->f_18) = x;
}


// 0x00284b60 pure3d::AnimationFrameController::vfunc_9 (4 B): matches/0x00284b60.cpp
// sym: ?vfunc_9@AnimationFrameController@pure3d@@UAEMXZ
// Same code shape as 0x00069060 (propagated; names are from that function)
hulk_freg pure3d::AnimationFrameController::vfunc_9() {
    return this->f_18;
}

namespace fn_ff70be84 {

// 0x00284b70 pure3d::AnimationFrameController::vfunc_20 (302 B): equivalent/0x00284b70.cpp
// sym: ?vfunc_20@AnimationFrameController_284b70@fn_ff70be84@@UAEMXZ @757c31b81937 @w4b800fa7871b
// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 28/28)
// pure3d::AnimationFrameController::vfunc_20 @ 0x00284b70
hulk_freg AnimationFrameController_284b70::vfunc_20()
{
    float start;
    float end;
    getRange(&start, &end);
    float dur = end - start;
    unsigned cycles = getCycles();
    hulk_freg t = getTime();

    switch (getMode()) {
    case 0: {
        Status_284b70 *s = getStatus();
        if (s == 0)
            return 0.0f;
        if (s->state != 1)
            return dur;
        return 3.4028235e+38f;
    }
    case 2:
        if (cycles == 0)
            return 3.4028235e+38f;
        return (hulk_freg)cycles * dur - (t - start);
    case 3:
        if (cycles == 0)
            return 3.4028235e+38f;
        return (hulk_freg)cycles * dur - (end - t);
    case 4:
        if (cycles == 0)
            return 3.4028235e+38f;
        {
            hulk_freg v = (hulk_freg)cycles * dur;
            return (v + v) - (t - start);
        }
    case 5:
        if (cycles == 0)
            return 3.4028235e+38f;
        {
            hulk_freg v = (hulk_freg)cycles * dur;
            return (v + v) - (end - t);
        }
    default:
        return 0.0f;
    }
}

} // namespace fn_ff70be84

// 0x00284cc0 pure3d::AnimationFrameController::vfunc_23 (8 B): matches/0x00284cc0.cpp
// sym: ?vfunc_23@AnimationFrameController@pure3d@@UAEXXZ
void pure3d::AnimationFrameController::vfunc_23() {
    this->f_18 = 1.0f;
}

namespace fn_ff70be84 {

// 0x00284cd0 FUN_00284cd0 (59 B): matches/0x00284cd0.cpp
// sym: @FUN_00284cd0@4
extern "C" SimpleFrameController* __fastcall FUN_00284cd0(SimpleFrameController* p) {
    ((ThisCall_0027b070*)(p))->Init_0027b070();
    p->pad[0x10] = 0;
    *(int*)(p->pad + 0x20) = 0;
    *(int*)(p->pad + 0x24) = 0;
    *(int*)(p->pad + 0x2c) = 0;
    *(int*)(p->pad + 0x30) = 0;
    *(int*)(p->pad + 0x34) = 0;
    *(int*)(p->pad + 0x3c) = 0;
    *(int*)(p->pad + 0x18) = 0x3f800000;
    *(hulk_intptr*)p = ((hulk_intptr)DAT_0042c694);
    *(int*)(p->pad + 0x28) = 0x7f7fffff;
    p->pad[0x38] = 1;
    return p;
}

} // namespace fn_ff70be84

// 0x00284d10 pure3d::SimpleFrameController::vfunc_25 (4 B): matches/0x00284d10.cpp
// sym: ?vfunc_25@SimpleFrameController@pure3d@@UAEHXZ
// Same code shape as 0x00086340 (propagated; names are from that function)
int pure3d::SimpleFrameController::vfunc_25() {
    return (int)((*(unsigned int *)&this->f_3c));
}


// 0x00284d20 pure3d::SimpleFrameController::vfunc_6 (88 B): equivalent/0x00284d20.cpp [wrapped: conflict: pure3d::SimpleFrameController]
// sym: ?vfunc_6@SimpleFrameController@pure3d@fn_00284d20@@UAEXMD@Z @45dee052f9ff @w86c52bf71616
namespace fn_00284d20 {
// STATUS: equivalent (tools/equiv.py level 3: 15029 inputs, branch coverage 8/8)
// pure3d::SimpleFrameController::vfunc_6 @ 0x00284d20
// pure3d::SimpleFrameController::vfunc_6 @ 0x00284d20
namespace pure3d {
struct SimpleFrameController {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(float delta, char force);
    virtual void vfunc_7();
    char pad04[12];
    unsigned char flag;
    char pad11[7];
    float speed;
    char pad1c[4];
    int mode;
    int state;
    float frame;
    int range;
    int end;
    float time;
    int otherFrame;
    hulk_intptr animation;
};
}
struct ThisNote_00289db0 {
    hulk_freg FUN_00289db0(float *, int *, float, float, int, int, int, int);
};
void pure3d::SimpleFrameController::vfunc_6(float delta, char force) {
    if (animation) {
        time = ((ThisNote_00289db0*)(animation))->FUN_00289db0(&frame, &otherFrame, time, delta * speed, range, end, state == 0, mode);
        if (flag == 1 || force == 1)
            vfunc_7();
    }
}
} // namespace fn_00284d20


// 0x00284d80 pure3d::SimpleFrameController::vfunc_10 (18 B): matches/0x00284d80.cpp [wrapped: conflict: pure3d::SimpleFrameController]
// sym: ?vfunc_10@SimpleFrameController@pure3d@fn_00284d80@@UAEMXZ
namespace fn_00284d80 {
namespace pure3d {
extern const float defaultFrame;
class SimpleFrameController {
  public:
    char pad[0x38];
    struct Data {
        char pad2[0x14];
        float value;
    }* data;
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual float vfunc_10();
};
float SimpleFrameController::vfunc_10() {
    if (data)
        return data->value;
    return defaultFrame;
}
} // namespace pure3d
} // namespace fn_00284d80


// 0x00284da0 pure3d::SimpleFrameController::vfunc_11 (18 B): matches/0x00284da0.cpp [wrapped: conflict: SimpleFrameController]
// sym: ?vfunc_11@SimpleFrameController@fn_00284da0@@UAEMXZ
namespace fn_00284da0 {
// data: zero_284da0 = DAT_003f32e0

class SimpleFrameController {
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
    virtual float vfunc_11();
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
    char pad[0x3c - 4];
    struct Data {
        char pad[0x10];
        float value;
    }* data;
};
float SimpleFrameController::vfunc_11() {
    if (data)
        return data->value;
    return DAT_003f32e0;
}
} // namespace fn_00284da0


// 0x00284dc0 pure3d::SimpleFrameController::vfunc_13 (4 B): matches/0x00284dc0.cpp
// sym: ?vfunc_13@SimpleFrameController@pure3d@@UAEMXZ
// Same code shape as 0x000690d0 (propagated; names are from that function)
hulk_freg pure3d::SimpleFrameController::vfunc_13() {
    return this->f_34;
}


// 0x00284dd0 pure3d::SimpleFrameController::vfunc_15 (21 B): matches/0x00284dd0.cpp
// sym: ?vfunc_15@SimpleFrameController@pure3d@@UAEXPAX0@Z
void pure3d::SimpleFrameController::vfunc_15(void* __p0, void* __p1) { int * p = (int *)__p0; int * q = (int *)__p1;

    *p = this->f_2c;
    *q = this->f_30;
}


// 0x00284df0 pure3d::SimpleFrameController::vfunc_16 (87 B): equivalent/0x00284df0.cpp
// sym: ?vfunc_16@SimpleFrameController@pure3d@@UAEXH@Z @c918c1a91da8 @w5099d4345f02
// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 10/10)
// pure3d::SimpleFrameController::vfunc_16 @ 0x00284df0
void pure3d::SimpleFrameController::vfunc_16(int value) {
    if (value != this->f_20) {
        this->f_20 = value;
        float duration = vfunc_20();
        this->f_28 = duration;
        if (this->f_20 == 0 && duration == DAT_0042c5b0)
            this->f_24 = 0;
        this->f_38 = this->f_20 != 3 && this->f_20 != 5;
    }
}

namespace fn_ff70be84 {

// 0x00284e50 pure3d::SimpleFrameController::vfunc_17 (4 B): matches/0x00284e50.cpp
// sym: ?target@fn_ff70be84@@YIIPAVC_284e50@1@@Z
// Same code shape as 0x00086280 (propagated; names are from that function)
unsigned int __fastcall target(C_284e50* self) {
    return self->value;
}

} // namespace fn_ff70be84

// 0x00284e60 pure3d::SimpleFrameController::vfunc_18 (87 B): equivalent/0x00284e60.cpp
// sym: ?vfunc_18@SimpleFrameController@pure3d@@UAEXH@Z @1ff0c7e5d199 @w69e5949c6023
// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 10/10)
// pure3d::SimpleFrameController::vfunc_18 @ 0x00284e60
void pure3d::SimpleFrameController::vfunc_18(int value) {
    if (this->f_24 != value) {
        this->f_24 = value;
        float length = vfunc_20();
        this->f_28 = length;
        int currentMode = this->f_20;
        if (currentMode == 0 && length == (*(float*)&DAT_0042c5b0))
            this->f_24 = 0;
        this->f_38 = currentMode != 3 && currentMode != 5;
    }
}


// 0x00284ec0 pure3d::SimpleFrameController::vfunc_19 (31 B): matches/0x00284ec0.cpp
// sym: ?vfunc_19@SimpleFrameController@pure3d@@UAEHXZ
int pure3d::SimpleFrameController::vfunc_19() {
    if (this->f_20 == 0 && (*(int *)&this->f_3c) != 0)
        return (int)(*(unsigned char*)((*(hulk_intptr *)&this->f_3c) + 0x18) == 0);
    return (int)(this->f_24);
}


// 0x00284ee0 pure3d::SimpleFrameController::vfunc_21 (4 B): matches/0x00284ee0.cpp
// sym: ?vfunc_21@SimpleFrameController@pure3d@@UAEMXZ
// Same code shape as 0x000690a0 (propagated; names are from that function)
hulk_freg pure3d::SimpleFrameController::vfunc_21() {
    return this->f_28;
}


// 0x00284ef0 pure3d::SimpleFrameController::vfunc_22 (25 B): matches/0x00284ef0.cpp [wrapped: conflict: SimpleFrameController]
// sym: ?vfunc_22@SimpleFrameController@fn_00284ef0@@QAEHXZ
namespace fn_00284ef0 {
// data: threshold_284ef0 = DAT_0042c5b4

class SimpleFrameController {
  public:
    char pad[0x28];
    float value;
    int vfunc_22();
};
int SimpleFrameController::vfunc_22() {
    return value <= DAT_0042c5b4;
}
} // namespace fn_00284ef0

namespace fn_ff70be84 {

// 0x00284f40 FUN_00284f40 (9 B): matches/0x00284f40.cpp
// sym: ?Set@Obj@fn_ff70be84@@QAEXH@Z
void Obj::Set(int x) {
    value = x;
}

} // namespace fn_ff70be84

// 0x00284f50 FUN_00284f50 (4 B): matches/0x00284f50.cpp
// sym: ?FUN_00284f50@Target_284f50@owners@@QAEIXZ
// Same code shape as 0x000862a0 (propagated; names are from that function)
hulk_uintptr owners::Target_284f50::FUN_00284f50() {
    return value;
}


// 0x00284f60 FUN_00284f60 (4 B): matches/0x00284f60.cpp
// sym: ?FUN_00284f60@CJumpTrack_284f60@owners@@QAEMXZ
// Same code shape as 0x00069050 (propagated; names are from that function)
float owners::CJumpTrack_284f60::FUN_00284f60() {
    return value;
}

namespace fn_ff70be84 {

// 0x00284f70 FUN_00284f70 (3 B): matches/0x00284f70.cpp
// sym: ?FUN_00284f70@fn_ff70be84@@YIMPAM@Z
float __fastcall FUN_00284f70(float* ptr) {
    return *ptr;
}

} // namespace fn_ff70be84

// 0x00284f80 pure3d::BlendFrameController::vfunc_25 (18 B): matches/0x00284f80.cpp
// sym: ?vfunc_25@BlendFrameController@pure3d@@UAEHXZ
int pure3d::BlendFrameController::vfunc_25() {
    if (this->f_28 > 0)
        return *(int*)((char*)this + this->f_28 * 0x2c + 0x28);
    return 0;
}

namespace fn_ff70be84 {

// 0x00284fa0 pure3d::BlendFrameController::vfunc_6 (359 B): equivalent/0x00284fa0.cpp
// sym: ?vfunc_6@BlendFrameController@fn_ff70be84@@UAEXMD@Z @331d2d8c3689 @wf66917d1c8a2
// STATUS: equivalent (tools/equiv.py level 3: 287 inputs, branch coverage 22/22)
// pure3d::BlendFrameController::vfunc_6 @ 0x00284fa0
void BlendFrameController::vfunc_6(float dt, char force)
{
    hulk_freg scaled = dt * timeScale;
    dt = (float)scaled;                        // the callee gets the rounded value
    float step = scaled * 0.001f;              // the original multiplies the unrounded one
    unsigned int done = 1;
    dirty = 0;

    for (unsigned int i = 0; i < count; i++) {
        Track* t = &tracks[i];
        Owner_284fa0* owner = t->owner;
        t->cur = owner->FUN_00289db0(&t->f18, &t->f24, t->cur, dt, t->a4, t->a8, t->f1c == 0, t->a20);

        float x = t->remain - step * owner->rate;
        t->remain = x;
        if (x > 0.0f) {
            float y = 1.0f - x * t->fadeRate;
            if (y <= 0.0f) {
                t->weight = 0.0f;
                done++;
            } else if (y >= 1.0f) {
                t->weight = 1.0f;
                done++;
            } else {
                t->weight = (3.0f - (y + y)) * y * y;
                done++;
            }
        } else {
            t->weight = 1.0f;
        }
    }

    while (done < count) {
        v29();
        dirty = 1;
    }

    if (count != 0) {
        if (busy == 1 || force == 1)
            v7();
    }
}

} // namespace fn_ff70be84

// 0x00285110 pure3d::BlendFrameController::vfunc_10 (25 B): matches/0x00285110.cpp
// sym: ?vfunc_10@BlendFrameController@pure3d@@UAEMXZ
 // namespace pure3d
hulk_freg pure3d::BlendFrameController::vfunc_10() {
    unsigned int n = this->f_28;
    if (n > 0)
        return *(float*)(*(hulk_intptr*)((char*)this + 0x28 + n * 0x2c) + 0x14);
    return hulk_at_003fb868;
}


// 0x00285130 pure3d::BlendFrameController::vfunc_11 (25 B): matches/0x00285130.cpp
// sym: ?vfunc_11@BlendFrameController@pure3d@@UAEMXZ
// data: zero_285130 = DAT_003f32e0
hulk_freg pure3d::BlendFrameController::vfunc_11() {
    if (this->f_28 > 0)
        return *(float*)(*(hulk_intptr*)((char*)this + this->f_28 * 0x2c + 0x28) + 0x10);
    return DAT_003f32e0;
}


// 0x00285150 pure3d::BlendFrameController::vfunc_13 (21 B): matches/0x00285150.cpp
// sym: ?vfunc_13@BlendFrameController@pure3d@@UAEMXZ
// data: gZero_285150 = DAT_003f32e0
 // namespace pure3d
hulk_freg pure3d::BlendFrameController::vfunc_13() {
    if (this->f_28 > 0)
        return *(float*)((char*)this + this->f_28 * 0x2c);
    return DAT_003f32e0;
}


// 0x00285170 pure3d::BlendFrameController::vfunc_15 (53 B): matches/0x00285170.cpp [wrapped: conflict: pure3d::BlendFrameController]
// sym: ?vfunc_15@BlendFrameController@pure3d@fn_00285170@@QAEXPAI0@Z
namespace fn_00285170 {
namespace pure3d {
struct BlendFrameController {
    char p[0x28];
    unsigned count;
    char q[4];
    struct Item {
        unsigned a, b;
        char r[0x24];
    } items[1];
    void vfunc_15(unsigned*, unsigned*);
};
void BlendFrameController::vfunc_15(unsigned* a, unsigned* b) {
    if (count > 0) {
        unsigned i = count - 1;
        *a = items[i].a;
        *b = items[i].b;
    } else {
        *a = 0;
        *b = 0;
    }
}
} // namespace pure3d
} // namespace fn_00285170


// 0x002851b0 pure3d::BlendFrameController::vfunc_16 (114 B): equivalent/0x002851b0.cpp [wrapped: merged class would differ: BlendFrameController: array bound 0x108 - 0x2c - sizeof ( Track )]
// sym: ?vfunc_16@BlendFrameController@fn_002851b0@@UAEXH@Z @ae6f13032179 @w6380146f7e6a
namespace fn_002851b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 12/12)
// pure3d::BlendFrameController::vfunc_16 @ 0x002851b0
struct Entry_2851b0 {
    char pad0[0x14];
    float value;        // 0x14
    char pad18[4];
    int mode;           // 0x1c
    char flag;          // 0x20
    char pad21[0x2c - 0x21];
};

class BlendFrameController {
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
    virtual void vfunc_16(int mode);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual float GetEnd();             // slot 20
    char pad04[0x20 - 4];
    int mode;               // 0x20
    int f24;                // 0x24
    unsigned int count;     // 0x28
    char pad2c[4];
    Entry_2851b0 entries[1];       // 0x30
};

void BlendFrameController::vfunc_16(int newMode)
{
    if (mode == newMode)
        return;
    mode = newMode;
    if (count == 0)
        return;
    Entry_2851b0* e = &entries[count - 1];
    e->mode = newMode;
    e->value = GetEnd();
    if (e->mode == 0) {
        if (e->value == 3.4028235e38f)
            f24 = 0;
    }
    e->flag = (e->mode != 3 && e->mode != 5);
}
} // namespace fn_002851b0

namespace fn_ff70be84 {

// 0x00285230 pure3d::BlendFrameController::vfunc_17 (4 B): matches/0x00285230.cpp
// sym: ?target@fn_ff70be84@@YIIPAVC_284e50@1@@Z
// Same code shape as 0x00086280 (propagated; names are from that function)
unsigned int __fastcall target(C_285230* self) {
    return self->value;
}

} // namespace fn_ff70be84

// 0x00285240 pure3d::BlendFrameController::vfunc_18 (95 B): equivalent/0x00285240.cpp [wrapped: conflict: pure3d::BlendFrameController]
// sym: ?vfunc_18@BlendFrameController@pure3d@fn_00285240@@UAEXH@Z @7709742b51e4 @wd9cce85a525d
namespace fn_00285240 {
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 12/12)
// pure3d::BlendFrameController::vfunc_18 @ 0x00285240
namespace pure3d {
struct BlendFrameController {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(int); virtual void vfunc_19();
    virtual float vfunc_20();
    char pad[0x20];
    int frame;
    unsigned int count;
    struct Entry { char pad[0x18]; float value; int frame; int mode; unsigned char active; };
};
void BlendFrameController::vfunc_18(int newFrame) {
    if (frame == newFrame) return;
    frame = newFrame;
    if (count == 0) return;
    Entry *entry = (Entry *)((char *)this + 0x2c * (count - 1) + 0x2c);
    entry->frame = newFrame;
    if (entry->mode == 0 && *(unsigned int *)&entry->value == 0x7f7fffff) frame = 0;
    entry->value = vfunc_20();
    entry->active = entry->mode != 3 && entry->mode != 5;
}
}
} // namespace fn_00285240


// 0x002852a0 pure3d::BlendFrameController::vfunc_19 (49 B): equivalent/0x002852a0.cpp [wrapped: conflict: pure3d::Animation; pure3d::BlendFrameController]
// sym: ?vfunc_19@BlendFrameController@pure3d@fn_002852a0@@QAEIXZ @6a6184ff0170 @w80bea4eab04d
namespace fn_002852a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// pure3d::BlendFrameController::vfunc_19 @ 0x002852a0
namespace pure3d {
struct Animation { char pad[0x18]; unsigned char enabled; };
struct BlendEntry { unsigned int value; unsigned int mode; unsigned int unused; Animation* animation; char pad[0x1c]; };
struct BlendFrameController {
  virtual void vfunc_0();
  char pad[0x20];
  unsigned int defaultValue;
  unsigned int count;
  char pad2[0x1c];
  BlendEntry entries[1];
  unsigned int vfunc_19();
};
unsigned int BlendFrameController::vfunc_19() {
  if (count != 0) {
    BlendEntry& entry = entries[count - 1];
    if (entry.mode != 0) return entry.value;
    if (entry.animation != 0) return entry.animation->enabled == 0;
  }
  return defaultValue;
}
}
} // namespace fn_002852a0


// 0x002852e0 pure3d::BlendFrameController::vfunc_21 (22 B): matches/0x002852e0.cpp
// sym: ?vfunc_21@BlendFrameController@pure3d@@UAEMXZ
 // namespace pure3d
hulk_freg pure3d::BlendFrameController::vfunc_21() {
    if (this->f_28 > 0)
        return *(float*)((char*)this + this->f_28 * 0x2c + 0x18);
    return hulk_at_003f32e0;
}


// 0x00285300 pure3d::BlendFrameController::vfunc_22 (34 B): matches/0x00285300.cpp
// sym: ?vfunc_22@BlendFrameController@pure3d@@UAE_NXZ
 // namespace pure3d
bool pure3d::BlendFrameController::vfunc_22() {
    if ((*(int *)&this->f_28) == 1)
        return this->f_44 <= 0.000001f;
    return false;
}


// 0x00285330 pure3d::BlendFrameController::vfunc_7 (16 B): matches/0x00285330.cpp
// sym: ?vfunc_7@BlendFrameController@pure3d@@UAEXXZ
void pure3d::BlendFrameController::vfunc_7() {
    if ((*(int *)&this->f_28) == 1)
        vfunc_27();
    else
        vfunc_28();
}

namespace fn_ff70be84 {

// 0x00285340 FUN_00285340 (7 B): matches/0x00285340.cpp
// sym: ?FUN_00285340@fn_ff70be84@@YIEPAD@Z
unsigned char __fastcall FUN_00285340(char* object) {
    return object[0x108];
}

} // namespace fn_ff70be84

// 0x00285350 pure3d::DefaultFrameControllerHandler::vfunc_3 (116 B): matches/0x00285350.cpp
// sym: ?vfunc_3@DefaultFrameControllerHandler@pure3d@@UAEDI@Z
char pure3d::DefaultFrameControllerHandler::vfunc_3(unsigned int x) {
    switch (x) {
    case 0x4e525450U:
    case 0x584554U:
    case 0x475142U:
    case 0x4d4143U:
    case 0x505845U:
    case 0x584645U:
    case 0x44414853U:
    case 0x4554494cU:
    case 0x53595350U:
    case 0x4e525453U:
    case 0x53495650U:
    case 0x53495653U:
    case 0x54525650U:
    case 0x58545256U:
        return 1;
    default:
        return 0;
    }
}


// 0x002853f0 pure3d::FrameControllerHandler::vfunc_2 (31 B): matches/0x002853f0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002853f0@@UAEPAV123@E@Z
namespace fn_002853f0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class NonCopyable_2853f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public NonCopyable_2853f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002853f0

namespace fn_ff70be84 {

// 0x00285410 FUN_00285410 (65 B): matches/0x00285410.cpp
// sym: ?Find@Container_285410@fn_ff70be84@@QAEIH@Z
hulk_uintptr Container_285410::Find(int value) {
    unsigned int i = 0;
    while (i < count) {
        if (items[i]->Match(value) == true)
            return (hulk_uintptr)items[i];
        ++i;
    }
    return 0;
}

} // namespace fn_ff70be84

// 0x00285460 pure3d::FrameControllerLoader::vfunc_5 (263 B): equivalent/0x00285460.cpp [wrapped: conflict: pure3d::FrameControllerLoader]
// sym: ?vfunc_5@FrameControllerLoader@pure3d@fn_00285460@@UAEXPAPAXPA_KPAUChunk@3@PAX@Z @4ffad0b78b77 @w8c9140bf5b91
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00285460 {
// STATUS: equivalent (tools/equiv.py level 3: 129 inputs, branch coverage 8/8)
// pure3d::FrameControllerLoader::vfunc_5 @ 0x00285460
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

typedef unsigned int uint;
typedef unsigned __int64 uint64_285460;
struct Reader { void FUN_002647e0(void*,uint,uint,uint); };
struct Chunk { char pad[0x284]; Reader* reader; };
struct Handler_285460 {
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual unsigned char accepts(uint);
 virtual void* load(char*,uint,uint,Chunk*,void*);
};
namespace pure3d {
struct FrameControllerLoader {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void vfunc_5(void**,uint64_285460*,Chunk*,void*);
 char pad[8]; uint failed; uint spare; uint count; Handler_285460* handlers[1];
};
void FrameControllerLoader::vfunc_5(void** output,uint64_285460* key,Chunk* chunk,void* context) {
 uint first, type; unsigned char length; char name[256];
 chunk->reader->FUN_002647e0(&first,1,4,1);
 chunk->reader->FUN_002647e0(&length,1,1,1);
 chunk->reader->FUN_002647e0(name,length,1,1);
 name[length]=0;
 chunk->reader->FUN_002647e0(&type,1,4,1);
 void* result=0;
 for(uint i=0;i<count;++i) {
 if(handlers[i]->accepts(type)==1) {
 result=handlers[i]->load(name,type,first,chunk,context);
 failed=result==0;
 }
 }
 *output=result;
 *key=FUN_002672f0(name,0,0);
}
}
} // namespace fn_00285460
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00285570 pure3d::OldFrameControllerLoader::vfunc_5 (209 B): equivalent/0x00285570.cpp [wrapped: conflict: pure3d::OldFrameControllerLoader]
// sym: ?vfunc_5@OldFrameControllerLoader@pure3d@fn_00285570@@UAEXPAPAXPA_KPAUChunk@3@PAX@Z @68e747686483 @w12dd5d4b4145
namespace fn_00285570 {
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 2/2)
// pure3d::OldFrameControllerLoader::vfunc_5 @ 0x00285570
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Reader { void FUN_002647e0(void*, unsigned, unsigned, unsigned); };
struct Chunk { char pad[0x284]; Reader* reader; };
namespace pure3d {
struct OldFrameControllerLoader {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
 virtual void vfunc_5(void** output, unsigned __int64* nameId, Chunk* chunk, void* context);
 virtual unsigned char vfunc_6(unsigned type);
 virtual void* vfunc_7(char* name, unsigned type, Chunk* chunk, void* context);
};
void OldFrameControllerLoader::vfunc_5(void** output, unsigned __int64* nameId, Chunk* chunk, void* context) {
 char name[256];
 unsigned type;
 unsigned char length;
 chunk->reader->FUN_002647e0(&type,1,4,1);
 chunk->reader->FUN_002647e0(&length,1,1,1);
 unsigned n=length;
 chunk->reader->FUN_002647e0(name,n,1,1);
 name[n]=0;
 chunk->reader->FUN_002647e0(&type,1,4,1);
 unsigned savedType=type;
 void* result=0;
 if(vfunc_6(savedType)==1) result=vfunc_7(name,savedType,chunk,context);
 *output=result;
 *nameId=FUN_002672f0(name,0,0);
}
}
} // namespace fn_00285570
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00285650 pure3d::OldFrameControllerLoader::vfunc_6 (109 B): matches/0x00285650.cpp
// sym: ?vfunc_6@OldFrameControllerLoader@pure3d@@UAEDI@Z
char pure3d::OldFrameControllerLoader::vfunc_6(unsigned int x) {
    switch (x) {
    case 0x4554494c:
    case 0x584554:
    case 0x475142:
    case 0x4d4143:
    case 0x505845:
    case 0x584645:
    case 0x44414853:
    case 0x53495653:
    case 0x4e525450:
    case 0x4e525453:
    case 0x53495650:
    case 0x54525650:
    case 0x58545256:
        return 1;
    default:
        return 0;
    }
}

namespace fn_ff70be84 {

// 0x00285720 pure3d::FrameController::vfunc_2 (36 B): matches/0x00285720.cpp
// sym: ?vfunc_5@FrameController_285720@fn_ff70be84@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
FrameController_285720* FrameController_285720::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_0042c5bc);
    Destroy_0027afd0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00285750 pure3d::AnimationFrameController::vfunc_2 (36 B): matches/0x00285750.cpp
// sym: ?vfunc_5@AnimationFrameController_285750@fn_ff70be84@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
AnimationFrameController_285750* AnimationFrameController_285750::vfunc_5(signed char flags) {
    *(void***)this = ((void**)DAT_0042c5bc);
    Destroy_0027afd0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00285780 FUN_00285780 (128 B): equivalent/0x00285780.cpp
// sym: ?FUN_00285780@SimpleFrameController_285780@fn_ff70be84@@QAEPAV12@PBV12@@Z @ec3639343c80 @w1315738b93e0
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 4/4)
// FUN_00285780 @ 0x00285780
// 0x00285780: SimpleFrameController copy constructor
SimpleFrameController_285780* SimpleFrameController_285780::FUN_00285780(const SimpleFrameController_285780* src)
{
    FUN_0027b0b0(src);
    vptr = (hulk_intptr)DAT_0042c5bc;
    vptr = (hulk_intptr)DAT_0042c624;
    field_10 = src->field_10;
    field_18 = src->field_18;
    vptr = (hulk_intptr)DAT_0042c694;
    field_20 = src->field_20;
    field_24 = src->field_24;
    field_28 = src->field_28;
    field_2c = src->field_2c;
    field_30 = src->field_30;
    field_34 = src->field_34;
    field_38 = src->field_38;
    ref = 0;
    Ref_285780* r = src->ref;
    if (r != 0)
        r->AddRef();
    if (ref != 0)
        ref->Release();
    ref = r;
    return this;
}


// 0x00285800 FUN_00285800 (42 B): matches/0x00285800.cpp
// sym: ?Dtor2@SimpleFrameController_285800@fn_ff70be84@@QAEXXZ
void SimpleFrameController_285800::Dtor2() throw() {
    vf = hulk_at_0042c694;
    _ReadWriteBarrier();
    if (p3c) {
        p3c->Release();
        p3c = 0;
    }
    vf = vFC;
    _ReadWriteBarrier();
    AnimationFrameController_285800::Dtor_0027afd0();
}

} // namespace fn_ff70be84

// 0x00285830 pure3d::SimpleFrameController::vfunc_24 (148 B): equivalent/0x00285830.cpp
// sym: ?vfunc_24@SimpleFrameController@pure3d@@UAEXHHH@Z @a677f8ebb8fa @w7a094f5d5c37
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// pure3d::SimpleFrameController::vfunc_24 @ 0x00285830
void pure3d::SimpleFrameController::vfunc_24(hulk_intptr __p0, int start, int unused) { Source_285830 * src = (Source_285830 *)__p0;

    if (src == 0) {
        if ((*(Source_285830 * *)&this->f_3c) != 0)
            (*(Source_285830 * *)&this->f_3c)->Release();
        (*(Source_285830 * *)&this->f_3c) = 0;
        vfunc_14(0.0f, 0.0f);
        vfunc_12(0);
        return;
    }

    src->AddRef();
    if ((*(Source_285830 * *)&this->f_3c) != 0)
        (*(Source_285830 * *)&this->f_3c)->Release();
    (*(Source_285830 * *)&this->f_3c) = src;
    float last = src->length - 1.0f;
    if (last < 0.0f)
        last = 0.0f;
    vfunc_14(0.0f, last);
    vfunc_12(start);
}


// 0x002858d0 pure3d::SimpleFrameController::vfunc_12 (92 B): matches/0x002858d0.cpp [wrapped: conflict: pure3d::SimpleFrameController]
// sym: ?vfunc_12@SimpleFrameController@pure3d@fn_002858d0@@UAEXM@Z
namespace fn_002858d0 {
namespace pure3d {
class SimpleFrameController {
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
    virtual void vfunc_12(float);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual float v20();
    char pad[0x1c];
    int mode;
    char pad2[4];
    float current;
    float low;
    float high;
    float desired;
    unsigned char active;
};
void SimpleFrameController::vfunc_12(float frame) {
    if (!(frame >= low && frame <= high)) {
        if (frame > high)
            frame = high;
        else
            frame = low;
    }
    desired = frame;
    current = v20();
    active = (mode == 3 || mode == 5) ? 0 : 1;
}
} // namespace pure3d
} // namespace fn_002858d0


// 0x00285930 pure3d::SimpleFrameController::vfunc_14 (148 B): equivalent/0x00285930.cpp
// sym: ?vfunc_14@SimpleFrameController@pure3d@@UAEXMM@Z @2e28ad4b037e @wb236275ff30c
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 14/14)
// pure3d::SimpleFrameController::vfunc_14 @ 0x00285930
void pure3d::SimpleFrameController::vfunc_14(float newLo, float newHi) {
    if ((*(float *)&this->f_2c) == newLo && (*(float *)&this->f_30) == newHi)
        return;
    (*(float *)&this->f_2c) = newLo;
    (*(float *)&this->f_30) = newHi;
    if (this->f_34 >= (*(float *)&this->f_2c) && this->f_34 <= (*(float *)&this->f_30)) {
    } else if (this->f_34 > (*(float *)&this->f_30)) {
        this->f_34 = (*(float *)&this->f_30);
    } else {
        this->f_34 = (*(float *)&this->f_2c);
    }
    this->f_28 = vfunc_20();
    this->f_38 = !(this->f_20 == 3 || this->f_20 == 5);
}


// 0x002859d0 pure3d::SimpleFrameController::vfunc_23 (73 B): matches/0x002859d0.cpp
// sym: ?vfunc_23@SimpleFrameController@pure3d@@UAEXXZ
// data: gZero_2859d0 = DAT_003f32e0
void pure3d::SimpleFrameController::vfunc_23() {
    (*(unsigned long *)&this->f_20) = 0;
    (*(unsigned long *)&this->f_24) = 0;
    (*(unsigned long *)&this->f_2c) = 0;
    float f;
    if ((*(void * *)&this->f_3c) == 0)
        f = DAT_003f32e0;
    else {
        f = *(float*)((char*)(*(void * *)&this->f_3c) + 0x10) - DAT_003f32dc;
        if (f < DAT_003f32e0)
            f = DAT_003f32e0;
    }
    (*(float *)&this->f_30) = f;
    (*(unsigned long *)&this->f_34) = 0;
    (*(unsigned long *)&this->f_28) = 0x7f7fffff;
    (*(unsigned char (*)[4])&this->f_38)[0] = 1;
    (*(unsigned long *)&this->f_18) = 0x3f800000;
}

namespace fn_ff70be84 {

// 0x00285a20 FUN_00285a20 (24 B): matches/0x00285a20.cpp
// sym: ?run@C_285a20@fn_ff70be84@@QAEXXZ
void C_285a20::run() {
    if (p) {
        p->f1();
        p = 0;
    }
}


// 0x00285a70 FUN_00285a70 (78 B): matches/0x00285a70.cpp
// sym: ?FUN_00285a70@fn_ff70be84@@YIXPAUTarget_285a70@1@@Z
// data: gZero_285a70 = DAT_003f32e0
void __fastcall FUN_00285a70(Target_285a70* p) {
    p->a = 0;
    p->b = 0;
    hulk_freg v;
    if (p->data == 0 || (v = p->data->value - DAT_003f32dc, v < DAT_003f32e0))
        v = DAT_003f32e0;
    p->result = v;
    p->c = 0;
    p->d = 0;
    p->one = 1.0f;
    p->maxv = 3.402823466e+38F;
    p->e = 0;
    p->f = 0;
    p->flag = 1;
}

} // namespace fn_ff70be84

// 0x00285ac0 FUN_00285ac0 (679 B): equivalent/0x00285ac0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0BlendFrameController@pure3d@fn_00285ac0@@QAE@XZ @2926b1b13ce2 @w0a1b1ccb5189
namespace fn_00285ac0 {
// STATUS: equivalent (tools/equiv.py level 3: 3090 inputs, branch coverage 5/5)
// FUN_00285ac0 @ 0x00285ac0
// equiv-dead: +0xf6 not taken, +0x10c taken, +0x10c not taken, +0x13c not taken, +0x152 taken, +0x152 not taken, +0x188 not taken, +0x19e taken, +0x19e not taken, +0x1ec not taken, +0x202 taken, +0x202 not taken, +0x250 not taken, +0x266 taken, +0x266 not taken: the constructor zeroes every Entry.src (esi+0x54, +0x80, +0xac, ...) just before the inlined Reset() reads it, so the 's != 0' side and the clamp compares behind it never run
  // 1.0
  // 0.0

struct Source {
    char pad0[0x10];
    float value;
};

struct Entry {              // 0x2c bytes
    int f00;
    int f04;
    float f08;
    int f0c;
    int f10;
    float f14;
    float f18;
    int f1c;
    int f20;
    char f24;
    char pad25[3];
    Source *src;            // 0x28

    void Reset();
};

void Entry::Reset()
{
    Source *s = src;
    f00 = 0;
    f04 = 0;
    float v = (*(float*)&DAT_003f32e0);
    if (s) {
        v = s->value - (*(float*)&DAT_003f32dc);
        if (!(v >= (*(float*)&DAT_003f32e0)))
            v = (*(float*)&DAT_003f32e0);
    }
    f08 = v;
    f0c = 0;
    f10 = 0;
    f14 = 1.0f;
    f18 = 3.4028235e+38f;
    f1c = 0;
    f20 = 0;
    f24 = 1;
}

namespace pure3d {

class __declspec(novtable) BlendFrameControllerBase {
public:
    virtual void v0_00038290();
    char pad04[0xc];
    void FUN_0027b070();
    BlendFrameControllerBase() { FUN_0027b070(); }
};

class BlendFrameController : public BlendFrameControllerBase {
public:
    char f10;
    char pad11[7];
    float f18;
    char pad1c[4];
    int f20;
    int f24;
    int f28;
    Entry entries[5];       // 0x2c
    char f108;
    virtual void v1_000382a0();
    BlendFrameController();
};

BlendFrameController::BlendFrameController()
{
    f10 = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0;
    f18 = 1.0f;
    for (int i = 0; i < 5; i++) {
        entries[i].f00 = 0;
        entries[i].f04 = 0;
        entries[i].f08 = 0.0f;
        entries[i].f0c = 0;
        entries[i].f10 = 0;
        entries[i].f14 = 0.0f;
        entries[i].f18 = 3.4028235e+38f;
        entries[i].f1c = 0;
        entries[i].f20 = 0;
        entries[i].f24 = 1;
        entries[i].src = 0;
    }
    f108 = 0;
    for (int i = 0; i < 5; i++)
        entries[i].Reset();
}

}
} // namespace fn_00285ac0


// 0x00285d70 FUN_00285d70 (476 B): equivalent/0x00285d70.cpp [wrapped: conflict: pure3d::AnimationFrameController; pure3d::BlendFrameController; pure3d::Entity; pure3d::FrameController]
// sym: ??0BlendFrameController@pure3d@fn_00285d70@@QAE@ABV012@@Z @67e2e2e4ee9c @wc130020ef16b
namespace fn_00285d70 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_00285d70 @ 0x00285d70
namespace pure3d {

class __declspec(novtable) Entity {
public:
    virtual void e0_00038290();
    char pad4[4];
    int name0;
    int name1;
    void FUN_0027b0b0(const Entity* src);
    Entity(const Entity& src) throw() { FUN_0027b0b0(&src); }
};

class FrameController : public Entity {
public:
    char flag10;
    char pad11[7];
    FrameController(const FrameController& src) throw() : Entity(src) { flag10 = src.flag10; }
};

class AnimationFrameController : public FrameController {
public:
    int f18;
    AnimationFrameController(const AnimationFrameController& src) throw() : FrameController(src) { f18 = src.f18; }
};

class RefObj_285d70 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Track {
    float cur;
    int a4;
    int a8;
    float remain;
    float fadeRate;
    float weight;
    float f18;
    int f1c;
    int a20;
    char f24;
    char pad25[3];
    RefObj_285d70* owner;
};

class BlendFrameController : public AnimationFrameController {
public:
    int f1c;
    int f20;
    int f24;
    unsigned int count;
    Track tracks[5];
    char dirty;
    BlendFrameController(const BlendFrameController& src) throw();
};

BlendFrameController::BlendFrameController(const BlendFrameController& src) throw()
    : AnimationFrameController(src)
{
    f20 = src.f20;
    f24 = src.f24;
    for (int i = 0; i < 5; i++) {
        Track& t = tracks[i];
        t.cur = 0.0f;
        t.a4 = 0;
        t.a8 = 0;
        t.remain = 0.0f;
        t.fadeRate = 0.0f;
        t.weight = 0.0f;
        t.f18 = 3.4028235e+38f;
        t.f1c = 0;
        t.a20 = 0;
        t.f24 = 1;
        t.owner = 0;
    }
    dirty = 0;
    count = 0;
    while (count < src.count) {
        unsigned int idx = count;
        RefObj_285d70* o = src.tracks[idx].owner;
        if (o != 0)
            o->AddRef();
        if (tracks[idx].owner != 0)
            tracks[idx].owner->Release();
        tracks[idx].owner = o;
        tracks[count].cur = src.tracks[count].cur;
        tracks[count].a4 = src.tracks[count].a4;
        tracks[count].a8 = src.tracks[count].a8;
        tracks[count].remain = src.tracks[count].remain;
        tracks[count].fadeRate = src.tracks[count].fadeRate;
        tracks[count].weight = src.tracks[count].weight;
        tracks[count].f18 = src.tracks[count].f18;
        tracks[count].f1c = src.tracks[count].f1c;
        tracks[count].a20 = src.tracks[count].a20;
        count = count + 1;
    }
}

}
} // namespace fn_00285d70


// 0x00285f50 FUN_00285f50 (104 B): equivalent/0x00285f50.cpp [wrapped: conflict: Track; pure3d::BlendFrameController; pure3d::Entity; pure3d::FrameController]
// sym: ??1BlendFrameController@pure3d@fn_00285f50@@UAE@XZ @4aa50930a8a5 @w01a0113c13cb
namespace fn_00285f50 {
// STATUS: equivalent (tools/equiv.py level 3: 140 inputs, branch coverage 10/10)
// FUN_00285f50 @ 0x00285f50
// equiv-map: ??1Entity@pure3d@@UAE@XZ = 0x0027afd0
class RefObj_285f50 {
public:
    virtual void AddRef();
    virtual void Release();
};
struct Track {
    char pad0[0x28];
    RefObj_285f50* owner;
};
namespace pure3d {
class Entity {
public:
    virtual ~Entity() throw();
    char pad04[0x28 - 4];
};
class FrameController : public Entity {
public:
    virtual ~FrameController() throw() {}
};
class BlendFrameController : public FrameController {
public:
    virtual ~BlendFrameController() throw();
    unsigned int count;
    Track tracks[5];
};
BlendFrameController::~BlendFrameController() throw() {
    for (unsigned int i = 0; i < count; i++) {
        if (tracks[i].owner) {
            tracks[i].owner->Release();
            tracks[i].owner = 0;
        }
    }
    for (int k = 4; k >= 0; k--) {
        if (tracks[k].owner) {
            tracks[k].owner->Release();
            tracks[k].owner = 0;
        }
    }
}
}
} // namespace fn_00285f50


// 0x00285fc0 pure3d::BlendFrameController::vfunc_24 (467 B): equivalent/0x00285fc0.cpp [wrapped: conflict: BlendFrameController; Track]
// sym: ?vfunc_24@BlendFrameController@fn_00285fc0@@UAEXPAURefObj_285fc0@2@MM@Z @ef638f822291 @w744e04919e84
namespace fn_00285fc0 {
// STATUS: equivalent (tools/equiv.py level 3: 638 inputs, branch coverage 30/30)
// pure3d::BlendFrameController::vfunc_24 @ 0x00285fc0
struct RefObj_285fc0 {
    virtual void AddRef();
    virtual void Release();
    char pad04[0xc];
    float length;
};

struct Track {
    float cur;
    int a4;
    int a8;
    float remain;
    float fadeRate;
    float weight;
    int f18;
    int f1c;
    int a20;
    int f24;
    RefObj_285fc0* owner;
};

class BlendFrameController {
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
    virtual void vfunc_14(int a, float b);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void vfunc_24(RefObj_285fc0* obj, float start, float blend);
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void vfunc_29();
    char pad04[0x1c - 4];
    int pad1c;
    int f20;
    int f24;
    unsigned int count;
    Track tracks[4];
};

void BlendFrameController::vfunc_24(RefObj_285fc0* obj, float start, float blend)
{
    float len = obj->length - 1.0f;
    if (len < 0.0f)
        len = 0.0f;
    if (blend > 0.0f) {
        if (count == 5)
            vfunc_29();
        Track* t = &tracks[count];
        obj->AddRef();
        if (t->owner != 0)
            t->owner->Release();
        t->owner = obj;
        float r;
        if (start >= 0.0f && start <= len)
            r = start;
        else if (start > len)
            r = len;
        else
            r = 0.0f;
        tracks[count].cur = r;
        tracks[count].remain = blend;
        tracks[count].fadeRate = 1.0f / blend;
        tracks[count].weight = 0.0f;
        tracks[count].f1c = f24;
        tracks[count].a20 = f20;
        if (count == 0)
            tracks[0].weight = 1.0f;
        count = count + 1;
        vfunc_14(0, len);
        return;
    }
    obj->AddRef();
    if (tracks[0].owner != 0)
        tracks[0].owner->Release();
    tracks[0].owner = obj;
    float r;
    if (start >= 0.0f && start <= len)
        r = start;
    else if (start > len)
        r = len;
    else
        r = 0.0f;
    tracks[0].cur = r;
    tracks[0].f1c = f24;
    tracks[0].remain = 0.0f;
    tracks[0].fadeRate = 0.0f;
    tracks[0].weight = 1.0f;
    tracks[0].a20 = f20;
    for (unsigned int i = 1; i < count; i++) {
        if (tracks[i].owner != 0)
            tracks[i].owner->Release();
        tracks[i].owner = 0;
    }
    count = 1;
    vfunc_14(0, len);
}
} // namespace fn_00285fc0


// 0x002861a0 pure3d::BlendFrameController::vfunc_12 (103 B): equivalent/0x002861a0.cpp [wrapped: conflict: BlendFrameController; Track]
// sym: ?vfunc_12@BlendFrameController@fn_002861a0@@UAEXM@Z @03e9346d5e14 @w644e20f16cc0
namespace fn_002861a0 {
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 12/12)
// pure3d::BlendFrameController::vfunc_12 @ 0x002861a0
struct Track {
    float cur;
    float lo;
    float hi;
    char pad0c[0xc];
    float f18;
    int f1c;
    int state;
    unsigned char flag;
    char pad25[3];
    void* owner;
};

class BlendFrameController {
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
    virtual void vfunc_12(float x);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual float v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    char pad04[0x28 - 4];
    unsigned int count;
    Track tracks[4];
};

void BlendFrameController::vfunc_12(float x)
{
    if (count == 0)
        return;
    Track* t = &tracks[count - 1];
    if (x >= t->lo && x <= t->hi)
        t->cur = x;
    else if (x > t->hi)
        t->cur = t->hi;
    else
        t->cur = t->lo;
    t->f18 = v20();
    if (t->state == 3 || t->state == 5)
        t->flag = 0;
    else
        t->flag = 1;
}
} // namespace fn_002861a0


// 0x00286210 pure3d::BlendFrameController::vfunc_14 (163 B): equivalent/0x00286210.cpp [wrapped: conflict: pure3d::BlendFrameController]
// sym: ?vfunc_14@BlendFrameController@pure3d@fn_00286210@@UAEXMM@Z @739ad40f8404 @wdc8a227c770a
namespace fn_00286210 {
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 16/16)
// pure3d::BlendFrameController::vfunc_14 @ 0x00286210
struct BlendEntry {
    float cur;          // +0x00
    float lo;           // +0x04
    float hi;           // +0x08
    char pad0c[0x18 - 0x0c];
    float value;        // +0x18
    char pad1c[0x20 - 0x1c];
    int state;          // +0x20
    unsigned char active; // +0x24
    char pad25[0x2c - 0x25];
};

namespace pure3d {
class BlendFrameController {
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
    virtual void vfunc_14(float lo, float hi);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual float vfunc_20();
    char pad[0x28 - 0x4];
    unsigned int count;       // 0x28
    BlendEntry entries[1];    // 0x2c
};
}

void pure3d::BlendFrameController::vfunc_14(float lo, float hi)
{
    if (count == 0)
        return;
    BlendEntry *e = &entries[count - 1];
    if (lo != e->lo || hi != e->hi) {
        e->lo = lo;
        e->hi = hi;
        float v;
        if (e->cur >= e->lo && e->cur <= e->hi)
            v = e->cur;
        else if (e->cur > e->hi)
            v = e->hi;
        else
            v = e->lo;
        e->cur = v;
        e->value = vfunc_20();
        e->active = (e->state != 3 && e->state != 5) ? 1 : 0;
    }
}
} // namespace fn_00286210


// 0x002862c0 pure3d::BlendFrameController::vfunc_23 (60 B): matches/0x002862c0.cpp [wrapped: merged class would differ: BlendFrameController: array bound 0x108 - 0x2c - sizeof ( Track )]
// sym: ?f23@BlendFrameController@fn_002862c0@@UAEXXZ
namespace fn_002862c0 {
class Sub_2862c0 {
  public:
    void invoke_00285a70();
};
class BlendFrameController {
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
    char pad4[0x18 - 4];
    float m18;
    char pad1c[4];
    int m20;
    int m24;
    unsigned int m28;
    Sub_2862c0 sub;
};
void BlendFrameController::f23() {
    while (m28 > 1)
        f29();
    if (m28 == 1)
        sub.invoke_00285a70();
    m20 = 0;
    m24 = 0;
    m18 = 1.0f;
}
} // namespace fn_002862c0


// 0x00286300 pure3d::BlendFrameController::vfunc_29 (160 B): equivalent/0x00286300.cpp [wrapped: conflict: pure3d::BlendFrameController]
// sym: ?vfunc_29@BlendFrameController@pure3d@fn_00286300@@UAEXXZ @7b41a6f77afc @wc7d537026158
namespace fn_00286300 {
// STATUS: equivalent (tools/equiv.py level 3: 140 inputs, branch coverage 12/12)
// pure3d::BlendFrameController::vfunc_29 @ 0x00286300
// pure3d::BlendFrameController::vfunc_29 @ 0x00286300: pops the first blended entry, shifting the rest down
struct Ref_286300 {
    virtual void AddRef();
    virtual void Release();
};

struct Blend_286300 {
    int fields[9];
    char flag;
    char pad25[3];
    Ref_286300 *source;
};

namespace pure3d {
class BlendFrameController {
public:
    virtual void v0();
    char pad04[0x24];
    unsigned int count;
    Blend_286300 blends[1];
    virtual void vfunc_29();
};
}

void pure3d::BlendFrameController::vfunc_29()
{
    for (unsigned int i = 1; i < count; i++) {
        Blend_286300 &dst = blends[i - 1];
        Blend_286300 &src = blends[i];
        Ref_286300 *incoming = src.source;
        if (incoming)
            incoming->AddRef();
        if (dst.source)
            dst.source->Release();
        dst.source = incoming;
        for (int k = 0; k < 9; k++)
            dst.fields[k] = src.fields[k];
        dst.flag = src.flag;
    }
    if (count != 0) {
        count = count - 1;
        Blend_286300 &last = blends[count];
        if (last.source)
            last.source->Release();
        last.source = 0;
    }
}
} // namespace fn_00286300


// 0x002863b0 pure3d::DefaultFrameControllerHandler::vfunc_2 (31 B): matches/0x002863b0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002863b0@@UAEPAV123@E@Z
namespace fn_002863b0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class FrameControllerHandler_2863b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public FrameControllerHandler_2863b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002863b0

namespace fn_ff70be84 {

// 0x002863d0 FUN_002863d0 (52 B): matches/0x002863d0.cpp
// sym: ?Dtor@FrameControllerLoader_2863d0@fn_ff70be84@@QAEXXZ
void FrameControllerLoader_2863d0::Dtor() throw() {
    vf = hulk_at_0042c7b0;
    Ref_2863d0** p = arr;
    for (int i = 4; i; --i) {
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
        ++p;
    }
    vf = (void**)DAT_003f6098;
}


// 0x00286410 FUN_00286410 (53 B): matches/0x00286410.cpp
// sym: ?Insert@Holder@fn_ff70be84@@QAEXPAVItem@2@@Z
void Holder::Insert(Item* p) {
    if (p) {
        unsigned n = count;
        if (n < 4) {
            p->Add();
            if (slots[n])
                slots[n]->Release();
            slots[n] = p;
            ++count;
        }
    }
}

} // namespace fn_ff70be84

// 0x00286470 content::LoadInventory::DynamicCaster<pure3d::VertexOffsetExpressionMixer>::vfunc_0 (30 B): matches/0x00286470.cpp
// sym: ?vfunc_0@?$DynamicCaster@VVertexOffsetExpressionMixer@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::VertexOffsetExpressionMixer>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002864a0 content::LoadInventory::DynamicCaster<pure3d::Light>::vfunc_0 (30 B): matches/0x002864a0.cpp
// sym: ?vfunc_0@?$DynamicCaster@VLight@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::Light>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002864c0 pure3d::SimpleFrameController::vfunc_2 (63 B): matches/0x002864c0.cpp [wrapped: conflict: SimpleFrameController]
// sym: ?vfunc_2@SimpleFrameController@fn_002864c0@@UAEPAV12@E@Z
namespace fn_002864c0 {
extern "C" void _ReadWriteBarrier();
extern char simpleVftable;
extern char frameVftable;
class SimpleFrameController {
  public:
    virtual void a();
    virtual void b();
    virtual SimpleFrameController* vfunc_2(unsigned char);
    void cleanup_0027afd0();
    char pad[0x38];
    struct Obj {
        virtual void a();
        virtual void b();
    }* member;
};
extern void destroy_00263f30(SimpleFrameController*);
SimpleFrameController* SimpleFrameController::vfunc_2(unsigned char flag) {
    *(void**)this = &simpleVftable;
    _ReadWriteBarrier();
    if (member) {
        member->b();
        member = 0;
    }
    *(void**)this = &frameVftable;
    cleanup_0027afd0();
    if (flag & 1)
        destroy_00263f30(this);
    return this;
}
} // namespace fn_002864c0


// 0x00286520 FUN_00286520 (121 B): equivalent/0x00286520.cpp [wrapped: conflict: pure3d::DefaultFrameControllerHandler; pure3d::FrameControllerLoader]
// sym: ??0FrameControllerLoader@pure3d@fn_00286520@@QAE@XZ @12577e54f7a9 @w3572427d7646
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_00286520 {
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// FUN_00286520 @ 0x00286520

extern "C" void* __cdecl FUN_0008d690(unsigned int size);

namespace pure3d {

class Handler_286520 {
public:
    virtual void AddRef();
    virtual void Release();
    int f4;
};

class DefaultFrameControllerHandler : public Handler_286520 {
public:
    DefaultFrameControllerHandler() { f4 = 0; }
    virtual void AddRef();
    virtual void Release();
};

class FrameControllerLoader {
public:
    FrameControllerLoader();
    virtual void l0_00038290();
    int f4;
    int id;
    int fc;
    int f10;
    unsigned int handlerCount;
    Handler_286520* handlers[4];
};

FrameControllerLoader::FrameControllerLoader() {
    f4 = 0;
    id = 0x121201;
    fc = 0;
    f10 = 0;
    handlerCount = 0;
    handlers[0] = 0;
    handlers[1] = 0;
    handlers[2] = 0;
    handlers[3] = 0;
    void* mem = FUN_0008d690((int)sizeof(DefaultFrameControllerHandler));
    if (mem) {
        DefaultFrameControllerHandler* h = new (mem) DefaultFrameControllerHandler();
        unsigned int n = handlerCount;
        if (n < 4) {
            h->AddRef();
            if (handlers[n])
                handlers[n]->Release();
            handlers[n] = h;
            handlerCount++;
        }
    }
}

}
} // namespace fn_00286520


// 0x002865a0 pure3d::FrameControllerLoader::vfunc_2 (30 B): matches/0x002865a0.cpp
// sym: ??_GFrameControllerLoader@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::FrameControllerLoader::~FrameControllerLoader() {}


// 0x002865e0 pure3d::OldFrameControllerLoader::vfunc_2 (31 B): matches/0x002865e0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002865e0@@UAEPAV123@E@Z
namespace fn_002865e0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_2865e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2865e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002865e0

namespace fn_ff70be84 {

// 0x00286750 FUN_00286750 (42 B): matches/0x00286750.cpp
// sym: ?FUN_00286750@fn_ff70be84@@YAHPAVInventory@1@PAX@Z
hulk_intptr __cdecl FUN_00286750(Inventory* inv, void* p) {
    U64 v = getValue(p);
    DynamicCaster_286750 caster;
    return inv->load(&caster, v);
}


// 0x00286780 FUN_00286780 (42 B): matches/0x00286780.cpp
// sym: ?load@fn_ff70be84@@YAHPAUManager@1@PBD@Z
hulk_intptr load(Manager* manager, const char* name) {
    __int64 h = hash_0027b020(name);
    DynamicCaster_286780 caster;
    return manager->find(&caster, h);
}

} // namespace fn_ff70be84

// 0x002867b0 pure3d::DefaultFrameControllerHandler::vfunc_4 (2325 B): equivalent/0x002867b0.cpp [wrapped: macros]
// sym: ?FUN_002867b0@Handler@fn_002867b0@@QAEPAVFcBase@2@PBDIIPAVReader@2@PAVInv@2@@Z @399a2c49c1da @w6dbfa818a10c
namespace fn_002867b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3215 inputs, branch coverage 106/106)
// pure3d::DefaultFrameControllerHandler::vfunc_4 @ 0x002867b0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)



void *thunk_FUN_0008d690(unsigned int size);

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

namespace pure3d {
class Animation;
class CompositeDrawable;
class Geometry;
class ParticleSystem;
namespace scenegraph {
class Node {
public:
    virtual void n0();
};
class TransformNode : public Node {
public:
    virtual void t0();
};
class VisibilityNode : public Node {
public:
    virtual void v0();
};
}
}

struct Stream {
    int FUN_002647e0(void *buf, int count, int size, int flag);
};

class Reader {
public:
    char pad0[0x284];
    Stream *stream;
};

struct NameHolder {
    char pad[8];
    void FUN_0027b040(const char *name);
};

struct TaPair {
    char pad00[8];
    int f8;
    int fc;
};

class Cast2 {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void *c11();
    TaPair *FUN_00288a10(int z);
};

class Inv {
public:
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Cast2 *i3(void *caster, unsigned __int64 key);
};

class Res {
public:
    pure3d::scenegraph::Node *FUN_002961e0(int a, int b, int c, int d);
    char pad00[0x48];
};

class FcBase {
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
    virtual void v16(int mode);
    virtual void v17();
    virtual void v18(int v);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(void *anim, int a, int b);
    char pad04[4];
    NameHolder name;
};

class FcExp : public FcBase {
public:
    FcExp *FUN_002a9cb0();
    void FUN_002a9ea0(void *r);
};

class FcMac : public FcBase {
public:
    FcMac *FUN_00292eb0();
    void FUN_00293100(void *r);
};

class FcBqg : public FcBase {
public:
    FcBqg *FUN_002a9760();
    void FUN_002a98f0(void *r);
};

class FcTex : public FcBase {
public:
    FcTex *FUN_002a9410();
    void FUN_002a9540(void *r);
};

class FcShad : public FcBase {
public:
    FcShad *FUN_002a83e0();
    void FUN_002a8650(void *r);
};

class FcLite : public FcBase {
public:
    FcLite *FUN_002a87c0();
    void FUN_002a8aa0(void *r);
};

class FcPtrn : public FcBase {
public:
    FcPtrn *FUN_00287860();
    void FUN_00288080(void *r);
};

class FcStrn : public FcBase {
public:
    FcStrn *FUN_002a7730();
    void FUN_002a77c0(pure3d::scenegraph::TransformNode *r);
};

class FcPvis : public FcBase {
public:
    FcPvis *FUN_002a80c0();
    void FUN_002a8310(void *r);
};

class FcSvis : public FcBase {
public:
    FcSvis *FUN_002a7b90();
    void FUN_002a7cf0(pure3d::scenegraph::VisibilityNode *r);
};

class FcTrvp : public FcBase {
public:
    FcTrvp *FUN_002a5420();
    void FUN_002a6930(void *r);
};

class FcVrtx : public FcBase {
public:
    FcVrtx *FUN_002a6cb0();
    void FUN_002a6ed0(void *r);
};

class FcParticle : public FcBase {
public:
    FcParticle *FUN_002a73d0();
    void FUN_002a75a0(void *r);
};

void *__cdecl FUN_00286750(Inv *inv, char *name);
void *__cdecl FUN_000f23a0(Inv *inv, char *name);
void *__cdecl FUN_000f2340(Inv *inv, char *name);
void *__cdecl FUN_000c0db0(Inv *inv, char *name);
void *__cdecl FUN_000c0db0(Inv *inv, char *name);
void *__cdecl FUN_00286780(Inv *inv, char *name);
void *__cdecl FUN_000f23d0(Inv *inv, char *name);
void *__cdecl FUN_000c0d80(Inv *inv, char *name);
void *__cdecl FUN_000f23d0(Inv *inv, char *name);
void *__cdecl FUN_000c9ba0(Inv *inv, char *name);

extern "C" void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);


#define FC_INIT(T, SZ, CTOR)                                  \
    T *obj;                                                   \
    {                                                         \
        void *m_ = thunk_FUN_0008d690(SZ);                    \
        if (m_)                                               \
            obj = ((T *)m_)->CTOR();                          \
        else                                                  \
            obj = 0;                                          \
    }                                                         \
    obj->name.FUN_0027b040(arg1);                             \
    obj->v24(anim, 0, 0);                                     \
    obj->v16(mode);                                           \
    obj->v18(ebx);


class Handler {
public:
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    FcBase *FUN_002867b0(const char *arg1, unsigned int type, unsigned int ver, Reader *R, Inv *inv);
};

FcBase *Handler::FUN_002867b0(const char *arg1, unsigned int type, unsigned int ver, Reader *R, Inv *inv)
{
    struct Frame {
        union {
            unsigned int tag;
            int mode;
        } u;
        unsigned char pad4[3];
        unsigned char len;
        union {
            float ff;
            int ebx;
            int fl;
        } t;
        char buf1[0x100];
        char buf2[0x100];
    } f;
    unsigned int &tag = f.u.tag;
    int &mode = f.u.mode;
    unsigned char &len = f.len;
    char *buf1 = f.buf1;
    char *buf2 = f.buf2;
    float &ff = f.t.ff;
    int &fl = f.t.fl;
    int ebx;
    int &ebxs = f.t.ebx;
    R->stream->FUN_002647e0(&tag, 1, 4, 1);
    if (tag == 0x444c4f48)
        mode = 1;
    else if (tag == 0x445746)
        mode = 2;
    else if (tag == 0x44464b42)
        mode = 5;
    else if (tag == 0x4b424446)
        mode = 4;
    else if (tag == 0x4b434142)
        mode = 3;
    else
        mode = 0;
    if (ver < 1) {
        R->stream->FUN_002647e0(&ff, 1, 4, 1);
        ebx = (int)ff;
    } else {
        R->stream->FUN_002647e0(&ebxs, 1, 4, 1);
        ebx = ebxs;
    }
    R->stream->FUN_002647e0(&fl, 1, 4, 1);
    if (fl != 0)
        ebx = 0;
    R->stream->FUN_002647e0(&len, 1, 1, 1);
    unsigned int n1 = len;
    R->stream->FUN_002647e0(buf1, n1, 1, 1);
    buf1[n1] = 0;
    R->stream->FUN_002647e0(&len, 1, 1, 1);
    unsigned int n2 = len;
    R->stream->FUN_002647e0(buf2, n2, 1, 1);
    buf2[n2] = 0;
    Cast2 *anim = 0;
    if (type != 0x53595350 && type != 0x584645) {
        content::LoadInventory::DynamicCaster<pure3d::Animation> &c = *new ((void *)&f.t) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        unsigned __int64 key = FUN_0027b020(buf2);
        anim = inv->i3(&c, key);
    }

    if (type == 0x53595350 || type == 0x584645) {
        FcParticle *obj;
        void *m_ = thunk_FUN_0008d690(0x60);
        if (m_)
            obj = ((FcParticle *)m_)->FUN_002a73d0();
        else
            obj = 0;
        obj->name.FUN_0027b040(arg1);
        obj->v16(mode);
        obj->v18(ebx);
        content::LoadInventory::DynamicCaster<pure3d::ParticleSystem> &c = *new ((void *)&f.t) content::LoadInventory::DynamicCaster<pure3d::ParticleSystem>;
        unsigned __int64 key = FUN_0027b020(buf1);
        Cast2 *o = inv->i3(&c, key);
        if (!o)
            return obj;
        obj->FUN_002a75a0(o);
        return obj;
    }
    if (type == 0x505845) {
        FC_INIT(FcExp, 0x50, FUN_002a9cb0)
        void *r = FUN_00286750(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_002a9ea0(r);
        return obj;
    }
    if (type == 0x4d4143) {
        FC_INIT(FcMac, 0x118, FUN_00292eb0)
        void *r = FUN_000f23a0(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_00293100(r);
        return obj;
    }
    if (type == 0x475142) {
        FC_INIT(FcBqg, 0x48, FUN_002a9760)
        TaPair *r = (TaPair *)FUN_000f2340(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_002a98f0(**(void ***)((char *)r + 0x48));
        return obj;
    }
    if (type == 0x584554) {
        FC_INIT(FcTex, 0x48, FUN_002a9410)
        void *r = FUN_000c0db0(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_002a9540(r);
        return obj;
    }
    if (type == 0x44414853) {
        FC_INIT(FcShad, 0x48, FUN_002a83e0)
        void *r = FUN_000c0db0(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_002a8650(r);
        return obj;
    }
    if (type == 0x4554494c) {
        FC_INIT(FcLite, 0x118, FUN_002a87c0)
        void *r = FUN_00286780(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_002a8aa0(r);
        return obj;
    }
    if (type == 0x4e525450) {
        FC_INIT(FcPtrn, 0x150, FUN_00287860)
        content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> &c = *new ((void *)&f.t) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>;
        unsigned __int64 key = FUN_0027b020(buf1);
        Cast2 *o = inv->i3(&c, key);
        if (!o)
            return obj;
        obj->FUN_00288080(o->c11());
        return obj;
    }
    if (type == 0x53495653) {
        FC_INIT(FcSvis, 0x48, FUN_002a7b90)
        Res *r = (Res *)FUN_000f23d0(inv, buf1);
        if (!r)
            return obj;
        TaPair *ta = anim->FUN_00288a10(0);
        pure3d::scenegraph::Node *nd = r->FUN_002961e0(ta->f8, ta->fc, 4, 0);
        obj->FUN_002a7cf0(dynamic_cast<pure3d::scenegraph::VisibilityNode *>(nd));
        return obj;
    }
    if (type == 0x53495650) {
        FC_INIT(FcPvis, 0x60, FUN_002a80c0)
        void *r = FUN_000c0d80(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_002a8310(r);
        return obj;
    }
    if (type == 0x4e525453) {
        FC_INIT(FcStrn, 0x118, FUN_002a7730)
        Res *r = (Res *)FUN_000f23d0(inv, buf1);
        if (!r)
            return obj;
        TaPair *ta = anim->FUN_00288a10(0);
        pure3d::scenegraph::Node *nd = r->FUN_002961e0(ta->f8, ta->fc, 2, 0);
        obj->FUN_002a77c0(dynamic_cast<pure3d::scenegraph::TransformNode *>(nd));
        return obj;
    }
    if (type == 0x54525650) {
        FC_INIT(FcTrvp, 0x58, FUN_002a5420)
        content::LoadInventory::DynamicCaster<pure3d::Geometry> &c = *new ((void *)&f.t) content::LoadInventory::DynamicCaster<pure3d::Geometry>;
        unsigned __int64 key = FUN_0027b020(buf1);
        Cast2 *o = inv->i3(&c, key);
        if (!o)
            return obj;
        obj->FUN_002a6930(o);
        return obj;
    }
    if (type == 0x58545256) {
        FC_INIT(FcVrtx, 0x48, FUN_002a6cb0)
        void *r = FUN_000c9ba0(inv, buf1);
        if (!r)
            return obj;
        obj->FUN_002a6ed0(r);
        return obj;
    }
    return 0;
}
} // namespace fn_002867b0
#undef FC_INIT
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_ff70be84 {

// 0x00287860 FUN_00287860 (76 B): matches/0x00287860.cpp
// sym: ??0PoseAnimationController_287860@fn_ff70be84@@QAE@XZ
PoseAnimationController_287860::PoseAnimationController_287860() {
    *(int*)((char*)this + 0x110) = 0;
    *(int*)((char*)this + 0x118) = 0;
    *((char*)this + 0x131) = 0;
    *(int*)((char*)this + 0x14c) = 0;
    *(int*)((char*)this + 0x11c) = 0;
    *(int*)((char*)this + 0x134) = 0;
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_0042c81c;
    *(int*)((char*)this + 0x114) = 0x3f800000;
    *(int*)((char*)this + 0x148) = 0xffff;
}

} // namespace fn_ff70be84
