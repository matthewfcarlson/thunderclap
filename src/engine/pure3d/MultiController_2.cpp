// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002b1870..0x002b2110 (kind game, layer engine, confidence high), dominant class pure3d::MultiController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f5757c83 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f5757c83 {} using namespace fn_f5757c83;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace pure3d {
struct FrameController_2b1a80 {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual float vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(float,float); virtual void vfunc_15(); virtual void vfunc_16(int); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual float vfunc_20();
};
}
namespace fn_f5757c83 {
class Node_2b1b90 {
  public:
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
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void update(int);
};
struct Controller_2b1c40 {
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
    virtual int v19();
};
class Child_2b1eb0 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual float GetValue();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void SetPair(float a, float b);
    virtual void v15();
    virtual void SetParam(int p);
};
class Mixer {
public:
    char pad0[0x28];
    float scaleA;           // 0x28
    float scaleB;           // 0x2c
    char pad30[0xc];
    int param;              // 0x3c
    char pad40[4];
    unsigned int count;     // 0x44
    Child_2b1eb0 **children;       // 0x48
    Child_2b1eb0 **capacityEnd;    // 0x4c
    void FUN_002b1eb0(Child_2b1eb0 *child);
};

} // namespace fn_f5757c83

// 0x002b1870 pure3d::MultiController::vfunc_3 (3 B): matches/0x002b1870.cpp
// sym: ?vfunc_3@MultiController@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::MultiController::vfunc_3() {
    return true;
}


// 0x002b1880 pure3d::MultiController::vfunc_5 (3 B): matches/0x002b1880.cpp
// sym: ?vfunc_5@MultiController@pure3d@@UAEXPAX@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::MultiController::vfunc_5(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    (void)a;
}


// 0x002b1890 pure3d::MultiController::vfunc_6 (29 B): matches/0x002b1890.cpp
// sym: ?vfunc_6@MultiController@pure3d@@UAEXMD@Z
void pure3d::MultiController::vfunc_6(float x, char update) {
    this->f_18 = x * this->f_20 + this->f_18;
    if (update == 1)
        vfunc_7();
}


// 0x002b18b0 pure3d::MultiController::vfunc_8 (10 B): matches/0x002b18b0.cpp
// sym: ?vfunc_8@MultiController@pure3d@@UAEXH@Z
// Same code shape as 0x00083d50 (propagated; names are from that function)
void pure3d::MultiController::vfunc_8(int x) {
    (*(int *)&this->f_20) = x;
}


// 0x002b18c0 pure3d::MultiController::vfunc_9 (4 B): matches/0x002b18c0.cpp
// sym: ?vfunc_9@MultiController@pure3d@@UAEMXZ
// Same code shape as 0x00069080 (propagated; names are from that function)
hulk_freg pure3d::MultiController::vfunc_9() {
    return this->f_20;
}


// 0x002b18d0 pure3d::MultiController::vfunc_10 (4 B): matches/0x002b18d0.cpp
// sym: ?vfunc_10@MultiController@pure3d@@UAEMXZ
// Same code shape as 0x00069070 (propagated; names are from that function)
hulk_freg pure3d::MultiController::vfunc_10() {
    return this->f_1c;
}


// 0x002b18e0 pure3d::MultiController::vfunc_11 (4 B): matches/0x002b18e0.cpp
// sym: ?vfunc_11@MultiController@pure3d@@UAEMXZ
// Same code shape as 0x000690c0 (propagated; names are from that function)
hulk_freg pure3d::MultiController::vfunc_11() {
    return this->f_30;
}


// 0x002b18f0 pure3d::MultiController::vfunc_13 (4 B): matches/0x002b18f0.cpp
// sym: ?vfunc_13@MultiController@pure3d@@UAEMXZ
// Same code shape as 0x00069090 (propagated; names are from that function)
hulk_freg pure3d::MultiController::vfunc_13() {
    return this->f_24;
}


// 0x002b1900 pure3d::MultiController::vfunc_15 (27 B): matches/0x002b1900.cpp
// sym: ?vfunc_15@MultiController@pure3d@@UAEXPAX0@Z
void pure3d::MultiController::vfunc_15(void* __p0, void* __p1) { float * a = (float *)__p0; float * b = (float *)__p1;

    *a = this->f_28 * this->f_1c;
    *b = this->f_2c * this->f_1c;
}


// 0x002b1920 pure3d::MultiController::vfunc_17 (4 B): matches/0x002b1920.cpp
// sym: ?vfunc_17@MultiController@pure3d@@UAEIXZ
// Same code shape as 0x00086340 (propagated; names are from that function)
unsigned int pure3d::MultiController::vfunc_17() {
    return (*(unsigned int *)&this->f_3c);
}


// 0x002b1930 pure3d::MultiController::vfunc_18 (59 B): matches/0x002b1930.cpp
// sym: ?vfunc_18@MultiController@pure3d@@UAEXH@Z
 // namespace pure3d
void pure3d::MultiController::vfunc_18(int value) {
    if (this->f_38 != value) {
        this->f_38 = value;
        this->f_34 = vfunc_20();
        int r;
        if (this->f_3c == 3 || this->f_3c == 5)
            r = 0;
        else
            r = 1;
        this->f_40 = (char)r;
    }
}


// 0x002b1970 pure3d::MultiController::vfunc_21 (4 B): matches/0x002b1970.cpp
// sym: ?vfunc_21@MultiController@pure3d@@UAEMXZ
// Same code shape as 0x000690d0 (propagated; names are from that function)
hulk_freg pure3d::MultiController::vfunc_21() {
    return this->f_34;
}


// 0x002b1990 pure3d::MultiController::vfunc_12 (228 B): equivalent/0x002b1990.cpp [wrapped: conflict: pure3d::MultiController]
// sym: ?vfunc_12@MultiController@pure3d@fn_002b1990@@UAEHM@Z
namespace fn_002b1990 {
// STATUS: equivalent (tools/equiv.py level 3: 148 inputs, branch coverage 16/16)
// pure3d::MultiController::vfunc_12 @ 0x002b1990
namespace pure3d {
struct MultiController {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual float vfunc_10(); virtual void vfunc_11(); virtual int vfunc_12(float frame); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(int mode); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual float vfunc_20();
 char pad04[0x18]; float rate; char pad20[4]; float current; float start; float end; char pad30[4]; float result; char pad38[4]; int mode; unsigned char active; char pad41[3]; unsigned count; MultiController **children;
};
int MultiController::vfunc_12(float frame) {
 double upper = (double)end * rate;
 float lower = start * rate;
 double selected;
 if (frame >= lower && frame <= upper) selected = frame;
 else if (frame > upper) selected = upper;
 else selected = lower;
 current = (float)selected;
 frame = selected > 0.0f ? (float)(selected / rate) : 0.0f;
 for (unsigned i=0; i<count; ++i) {
 float scale = children[i]->vfunc_10();
 children[i]->vfunc_16(mode);
 children[i]->vfunc_12(scale * frame);
 }
 result = vfunc_20();
 int enabled = mode != 3 && mode != 5;
 active = (unsigned char)enabled;
 return enabled;
}
}
} // namespace fn_002b1990


// 0x002b1a80 pure3d::MultiController::vfunc_14 (271 B): equivalent/0x002b1a80.cpp
// sym: ?vfunc_14@MultiController@pure3d@@UAEXMM@Z
// STATUS: equivalent (tools/equiv.py level 3: 147 inputs, branch coverage 17/18, incomplete)
// pure3d::MultiController::vfunc_14 @ 0x002b1a80
void pure3d::MultiController::vfunc_14(float first, float last) {
 double scale = 1.0 / this->f_1c;
 float start = (float)(first * scale);
 double finish = last * scale;
 if (start == this->f_28 && finish == this->f_2c) return;
 this->f_2c = (float)finish;
 this->f_28 = start;
 if (!(this->f_24 >= first && this->f_24 <= last)) {
 this->f_24 = this->f_24 > last ? last : first;
 }
 for (unsigned i=0;i<(*(unsigned int *)&this->f_44);++i) {
 float length=(*(FrameController_2b1a80 ** *)&this->f_48)[i]->vfunc_10();
 (*(FrameController_2b1a80 ** *)&this->f_48)[i]->vfunc_16(this->f_3c);
 (*(FrameController_2b1a80 ** *)&this->f_48)[i]->vfunc_14(length*this->f_28,length*this->f_2c);
 }
 this->f_34=vfunc_20();
 (*(unsigned char *)&this->f_40) = this->f_3c != 3 && this->f_3c != 5;
}


// 0x002b1b90 pure3d::MultiController::vfunc_16 (99 B): matches/0x002b1b90.cpp
// sym: ?vfunc_16@MultiController@pure3d@@UAEXH@Z
void pure3d::MultiController::vfunc_16(int p) {
    if (this->f_3c != p) {
        this->f_3c = p;
        for (unsigned int i = 0; i < (unsigned int)this->f_44; i++)
            (*(Node_2b1b90 ** *)&this->f_48)[i]->update(p);
        this->f_34 = vfunc_20();
        int r;
        if (this->f_3c != 3 && this->f_3c != 5)
            r = 1;
        else
            r = 0;
        (*(unsigned char *)&this->f_40) = (unsigned char)r;
    }
}


// 0x002b1c00 pure3d::MultiController::vfunc_19 (61 B): matches/0x002b1c00.cpp
// sym: ?vfunc_19@MultiController@pure3d@@UAEHXZ
int pure3d::MultiController::vfunc_19() {
    if (!this->f_3c) {
        for (unsigned int i = 0; i < (unsigned int)this->f_44; ++i)
            if (!(*(pure3d::MultiController ** *)&this->f_48)[i]->vfunc_19())
                return 0;
        return 1;
    }
    return this->f_38;
}


// 0x002b1c40 pure3d::MultiController::vfunc_20 (300 B): equivalent/0x002b1c40.cpp
// sym: ?vfunc_20@MultiController@pure3d@@UAEMXZ
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 30/30)
// pure3d::MultiController::vfunc_20 @ 0x002b1c40
hulk_freg pure3d::MultiController::vfunc_20() {
    float a = this->f_28 * this->f_1c;
    double endp = this->f_2c * this->f_1c; // unrounded for dur, a rounded frame copy (end) for the later uses
    volatile float end = endp;
    float dur = endp - a;

    switch (this->f_3c) {
    case 0: {
        for (unsigned i = 0; i < (*(unsigned int *)&this->f_44); i++) {
            if (!(*(Controller_2b1c40 ** *)&this->f_48)[i]->v19())
                return 3.4028235e+38f;
        }
        return dur;
    }
    case 2:
        if ((*(unsigned int *)&this->f_38) == 0)
            return 3.4028235e+38f;
        return (float)(*(unsigned int *)&this->f_38) * dur - (this->f_24 - a);
    case 3:
        if ((*(unsigned int *)&this->f_38) == 0)
            return 3.4028235e+38f;
        return (float)(*(unsigned int *)&this->f_38) * dur - (end - this->f_24);
    case 4:
        if ((*(unsigned int *)&this->f_38) == 0)
            return 3.4028235e+38f;
        {
            double v = (float)(*(unsigned int *)&this->f_38) * dur;
            return (v + v) - (this->f_24 - a);
        }
    case 5:
        if ((*(unsigned int *)&this->f_38) == 0)
            return 3.4028235e+38f;
        {
            double v = (float)(*(unsigned int *)&this->f_38) * dur;
            return (v + v) - (end - this->f_24);
        }
    default:
        return 0.0f;
    }
}


// 0x002b1d90 pure3d::MultiController::vfunc_22 (82 B): matches/0x002b1d90.cpp [wrapped: conflict: pure3d::MultiController]
// sym: ?f22@MultiController@pure3d@fn_002b1d90@@UAE_NXZ
namespace fn_002b1d90 {
// data: zero_2b1d90 = DAT_003f32e0

namespace pure3d {
class MultiController {
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
    virtual bool f22();
    virtual void f23();
    char pad[0x30];
    float value;
    char gap1[4];
    int flag;
    char gap2[4];
    unsigned count;
    MultiController** items;
};
} // namespace pure3d
bool pure3d::MultiController::f22() {
    if (flag == 0) {
        unsigned i = 0;
        if (count > 0) {
            do {
                if (!items[i]->f22())
                    return false;
                ++i;
            } while (i < count);
        }
        return true;
    }
    return value == DAT_003f32e0;
}
} // namespace fn_002b1d90


// 0x002b1df0 pure3d::MultiController::vfunc_23 (171 B): equivalent/0x002b1df0.cpp
// sym: ?vfunc_23@MultiController@pure3d@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 144 inputs, branch coverage 6/6)
// pure3d::MultiController::vfunc_23 @ 0x002b1df0
void pure3d::MultiController::vfunc_23() {
 this->f_18=0.0f; this->f_1c=30.0f; this->f_20=1.0f; this->f_24=0.0f; this->f_28=0.0f;
 double end=(this->f_30-1.0)*0.033333333333333333f;
 if(end<0.0) end=0.0;
 this->f_2c=(float)end;
 this->f_34=3.402823466e38f; this->f_38=0; this->f_3c=0;
 for(unsigned i=0;i<(*(unsigned int *)&this->f_44);++i) {
 (*(pure3d::MultiController ** *)&this->f_48)[i]->vfunc_23();
 double length=(*(pure3d::MultiController ** *)&this->f_48)[i]->vfunc_10();
 (*(pure3d::MultiController ** *)&this->f_48)[i]->vfunc_14((float)(length*this->f_28),(float)(length*this->f_2c));
 (*(pure3d::MultiController ** *)&this->f_48)[i]->vfunc_16(0);
 }
}

namespace fn_f5757c83 {

// 0x002b1eb0 FUN_002b1eb0 (150 B): equivalent/0x002b1eb0.cpp
// sym: ?FUN_002b1eb0@Mixer@fn_f5757c83@@QAEXPAVChild_2b1eb0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 12/12)
// FUN_002b1eb0 @ 0x002b1eb0
void Mixer::FUN_002b1eb0(Child_2b1eb0 *child)
{
    unsigned int n = count;
    for (unsigned int i = 0; i < count; i++) {
        if (children[i] == child)
            return;
    }
    if (n >= (unsigned int)(capacityEnd - children))
        return;

    Child_2b1eb0 **slot = &children[n];
    if (child)
        child->AddRef();
    if (*slot)
        (*slot)->Release();
    *slot = child;

    float v = children[count]->GetValue();
    children[count]->SetPair(v * scaleA, v * scaleB);
    children[count]->SetParam(param);
    count++;
}

} // namespace fn_f5757c83

// 0x002b2040 pure3d::MultiController::vfunc_7 (147 B): equivalent/0x002b2040.cpp [wrapped: conflict: pure3d::MultiController]
// sym: ?vfunc_7@MultiController@pure3d@fn_002b2040@@UAEXXZ
namespace fn_002b2040 {
// STATUS: equivalent (tools/equiv.py level 3: 18370 inputs, branch coverage 6/6)
// pure3d::MultiController::vfunc_7 @ 0x002b2040
struct Controller_2b2040 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void Advance(float dt, int flag);       // slot 6
};

struct Blend_2b2040 {
    float weight;
    float a;
    int mode;
};

float __cdecl FUN_002899e0(Blend_2b2040 *blend, void *target, float c, float d, float e, float f, bool g);

namespace pure3d {
class MultiController {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual int IsFrozen(int time);                 // slot 19

    char pad4[0x14];
    float dt;               // 0x18
    float speed;            // 0x1c
    char pad20[4];
    float phase;            // 0x24
    float rateA;            // 0x28
    float rateB;            // 0x2c
    char pad30[4];
    Blend_2b2040 blend;            // 0x34
    char pad40[0x44 - 0x40];
    unsigned int childCount;    // 0x44
    Controller_2b2040 **children;      // 0x48
};

void MultiController::vfunc_7()
{
    bool active = IsFrozen(blend.mode) == 0;
    phase = FUN_002899e0(&blend, (char *)this + 0x40, phase,
                         (speed * dt) * 0.001f, rateA * speed, rateB * speed, active);
    if (blend.weight > 0.0f) {
        for (unsigned int i = 0; i < childCount; i++)
            children[i]->Advance(dt, 1);
    }
    dt = 0;
}
}
} // namespace fn_002b2040

