// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000de140..0x000ded90 (kind game, layer game, confidence medium), dominant class ControllerPollerBase
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f551cf1f {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f551cf1f {} using namespace fn_f551cf1f;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f551cf1f {
class ControllerPollerBase {
  public:
    virtual void Release(int);
    ControllerPollerBase(void*);
    int a;
    void* p;
    u8 c[4];
    union { int d; void* mRef; };
    void Clear();
};
extern void* hulk_at_0040be54;
struct Other { virtual void slot0(); virtual void slot1(); };
struct Obj { virtual void slot0(); virtual void slot1(); virtual void slot2(); char pad[12]; Other* other; int fields[6]; int tail; int state; int extra; void FUN_000de190(); };
typedef float(__cdecl* RandomFn)();
class Item_de1f0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual const char *Name();
    virtual const char *Label();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual float Value(int axis);
};
class Device_de1f0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual bool IsReady();
    virtual void v4(); virtual void v5();
    virtual const char *Name();
    virtual unsigned int ItemCount();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual Item_de1f0 *GetItem(unsigned int index);
};
class DeviceManager_de1f0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual int Count();
    virtual Device_de1f0 *Get(int index);
};
extern "C" DeviceManager_de1f0 *FUN_002684b0();
struct Vec3_de800 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};


// 0x000de140 FUN_000de140 (35 B): matches/0x000de140.cpp
// sym: ??0ControllerPollerBase@fn_f551cf1f@@QAE@PAX@Z
ControllerPollerBase::ControllerPollerBase(void* x) {
    p = x;
    a = 0;
    (*(u8*)&DAT_004de7a8) = 0;
    d = 0;
    c[0] = 0;
}


// 0x000de170 FUN_000de170 (31 B): matches/0x000de170.cpp
// sym: ?Clear@ControllerPollerBase@fn_f551cf1f@@QAEXXZ
void ControllerPollerBase::Clear() {
    *(void**)this = &hulk_at_0040be54;
    _ReadWriteBarrier();
    if (mRef) {
        ((ControllerPollerBase*)mRef)->Release(1);
        mRef = 0;
    }
}


// 0x000de190 FUN_000de190 (60 B): equivalent/0x000de190.cpp
// sym: ?FUN_000de190@Obj@fn_f551cf1f@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000de190 @ 0x000de190
void Obj::FUN_000de190() { state = 14; if (other) other->slot1(); for (int i=0;i<6;i++) fields[i]=0; extra=0; tail=0; slot2(); }

} // namespace fn_f551cf1f

// 0x000de1d0 FUN_000de1d0 (29 B): matches/0x000de1d0.cpp
// sym: ?FUN_000de1d0@Obj_de1d0@owners@@QAEXXZ
// data: gRandom = DAT_004de948
void owners::Obj_de1d0::FUN_000de1d0() {
    first += (*(RandomFn*)&DAT_004de948)();
    second += (*(RandomFn*)&DAT_004de948)();
}

namespace fn_f551cf1f {

// 0x000de1f0 FUN_000de1f0 (751 B): equivalent/0x000de1f0.cpp
// sym: ?FUN_000de1f0@fn_f551cf1f@@YGX_N@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 57/58, incomplete)
// FUN_000de1f0 @ 0x000de1f0
void __stdcall FUN_000de1f0(bool analog)
{
    for (int i = 0; i < FUN_002684b0()->Count(); i++) {
        Device_de1f0 *dev = FUN_002684b0()->Get(i);
        if (dev == 0 || !dev->IsReady())
            continue;
        for (unsigned int j = 0; j < dev->ItemCount(); j++) {
            Item_de1f0 *item = dev->GetItem(j);
            if (item == 0)
                continue;
            if (!analog) {
                if (strcmp(item->Label(), "Button") != 0 && strcmp(item->Label(), "AnalogButton") != 0)
                    continue;
                if (strcmp(item->Name(), "Start") != 0 && strcmp(item->Name(), "Menu") != 0
                    && strcmp(item->Name(), "AnalogX") != 0 && strcmp(item->Name(), "A") != 0
                    && strcmp(item->Name(), "AnalogA") != 0)
                    continue;
                if (item->Value(0) > 0.2f) {
                    strcpy(DAT_004de7a8, dev->Name());
                    break;
                }
            } else {
                if (strcmp(item->Label(), "Button") != 0 && strcmp(item->Label(), "XAxis") != 0)
                    continue;
                if (strcmp(item->Name(), "AnalogDPadLeft") != 0 && strcmp(item->Name(), "AnalogDPadRight") != 0
                    && strcmp(item->Name(), "DPadLeft") != 0 && strcmp(item->Name(), "DPadRight") != 0
                    && strcmp(item->Name(), "LeftStickX") != 0 && strcmp(item->Name(), "RightStickX") != 0
                    && strcmp(item->Name(), "AnalogA") != 0)
                    continue;
                if (item->Value(0) > 0.2f || item->Value(0) < -0.2f) {
                    strcpy(DAT_004de768, dev->Name());
                    break;
                }
            }
        }
    }
}

} // namespace fn_f551cf1f

// 0x000de4e0 ControllerPollerBase::vfunc_0 (70 B): equivalent/0x000de4e0.cpp [wrapped: conflict: ControllerPollerBase]
// sym: ?vfunc_0@ControllerPollerBase@fn_000de4e0@@UAEXXZ
namespace fn_000de4e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// ControllerPollerBase::vfunc_0 @ 0x000de4e0
struct Device { virtual void vfunc_0(); virtual void vfunc_1(); }; struct ControllerPollerBase { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual Device* vfunc_5(int); char pad[12]; Device* device; int values[6]; int other; int state; int flag; }; void ControllerPollerBase::vfunc_0() { device = vfunc_5(0); state = 14; if (device) device->vfunc_1(); for (int i=0;i<6;++i) values[i]=0; flag=0; other=0; vfunc_2(); }
} // namespace fn_000de4e0

namespace fn_f551cf1f {

// 0x000de530 FUN_000de530 (95 B): matches/0x000de530.cpp
// sym: _FUN_000de530
extern "C" float __cdecl FUN_000de530(float x, float a, float b) {
    if (a > b) {
        if (x >= b && x <= a)
            return x;
        if (x > a)
            return a;
        return b;
    } else {
        if (x >= a && x <= b)
            return x;
        if (x > b)
            return b;
        return a;
    }
}

} // namespace fn_f551cf1f

// 0x000de590 ControllerPollerBase::vfunc_1 (595 B): equivalent/0x000de590.cpp [wrapped: conflict: ControllerPollerBase]
// sym: ?vfunc_1@ControllerPollerBase@fn_000de590@@UAEMIH@Z
namespace fn_000de590 {
// STATUS: equivalent (tools/equiv.py level 3: 20060 inputs, branch coverage 47/47)
// ControllerPollerBase::vfunc_1 @ 0x000de590

struct ButtonEntry {
    float value;
    int id;
};

struct AxisEntry {
    int id;
    float lo;
    float hi;
};

class Device_de590 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual float vfunc_4(float v);
    virtual void vfunc_5();
    virtual int vfunc_6();
    virtual float vfunc_7(int i);
    virtual void vfunc_8();
    virtual int vfunc_9();
    virtual float vfunc_10(int i);
};


extern "C++" __declspec(nothrow) float __cdecl FUN_000de530(float x, float lo, float hi);

class ControllerPollerBase {
public:
    virtual void vfunc_0();
    virtual hulk_freg vfunc_1(unsigned int cmd, int index);
    char pad04[0xc];
    Device_de590 *devices[4];
};

hulk_freg ControllerPollerBase::vfunc_1(unsigned int cmd, int index)
{
    Device_de590 *dev = devices[index];
    float best = 0.0f;

    switch (cmd) {
    case 8:
    case 10:
    case 11:
        for (int i = 0; i < (*(int*)&DAT_004de8c0); i++) {
            if (((ButtonEntry*)&DAT_004de800)[i].id == (int)cmd) {
                float v = devices[index]->vfunc_4(((ButtonEntry*)&DAT_004de800)[i].value);
                if (v > best)
                    best = v;
            }
        }
        if (best > DAT_004a0e68)
            return (best - DAT_004a0e68) / (1.0f - DAT_004a0e68);
        return 0.0f;

    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        for (int k = 0; k < 8; k++) {
            if (((AxisEntry*)&DAT_004a0e70)[k].id == (int)cmd) {
                for (int j = 0; j < dev->vfunc_6(); j++) {
                    float a = dev->vfunc_7(j);
                    float r = FUN_000de530(a, 0.0f, ((AxisEntry*)&DAT_004a0e70)[k].lo);
                    union { float f; unsigned int u; } ab;
                    ab.f = r;
                    ab.u = ab.u & 0x7fffffff;
                    if (ab.f > best)
                        best = ab.f;
                }
                for (int j = 0; j < dev->vfunc_9(); j++) {
                    float v = dev->vfunc_10(j);
                    float lo = 0.0f;
                    float hi = ((AxisEntry*)&DAT_004a0e70)[k].hi;
                    float r;
                    if (lo > hi) {
                        if (v >= hi && v <= lo)
                            r = v;
                        else if (v > lo)
                            r = lo;
                        else
                            r = hi;
                    } else {
                        if (v >= lo && v <= hi)
                            r = v;
                        else if (v > hi)
                            r = hi;
                        else
                            r = lo;
                    }
                    union { float f; unsigned int u; } ab;
                    ab.f = r;
                    ab.u = ab.u & 0x7fffffff;
                    if (ab.f > best)
                        best = ab.f;
                }
            }
        }
        if (best > DAT_004a0e68)
            return (best - DAT_004a0e68) / (1.0f - DAT_004a0e68);
        return 0.0f;

    default:
        return 0.0f;
    }
}
} // namespace fn_000de590

namespace fn_f551cf1f {

// 0x000de800 FUN_000de800 (406 B): equivalent/0x000de800.cpp
// sym: ?FUN_000de800@fn_f551cf1f@@YAMMM@Z
// STATUS: equivalent (tools/equiv.py level 3: 20059 inputs, branch coverage 17/20, incomplete)
// FUN_000de800 @ 0x000de800
hulk_freg FUN_000de800(float x, float z)
{
    if (fabs(x) <= 1e-5f && fabs(z) <= 1e-5f)
        return 0.0f;

    Vec3_de800 v;
    v.x = x;
    v.y = 0.0f;
    v.z = z;
    v.FUN_0022d110();

    hulk_freg a = v.z * 0.0f - v.y;
    hulk_freg b = v.x - v.z * 0.0f;
    hulk_freg c = v.y * 0.0f - v.x * 0.0f;
    hulk_freg m = sqrt(c * c + b * b + a * a);

    hulk_freg angle;
    if (fabs(m - 1.0f) <= 1e-5f)
        angle = 90.0f;
    else
        angle = FUN_000189c0(m) * 57.2957764f;

    if (x >= 0.0f) {
        if (z >= 0.0f)
            angle = angle + 270.0f;
        else if (z < 0.0f)
            angle = 90.0f - angle;
    } else if (x < 0.0f) {
        if (z < 0.0f)
            angle = angle + 90.0f;
        else if (z >= 0.0f)
            angle = 270.0f - angle;
    }
    if (angle == 360.0f)
        angle = 0.0f;
    return angle;
}

} // namespace fn_f551cf1f
