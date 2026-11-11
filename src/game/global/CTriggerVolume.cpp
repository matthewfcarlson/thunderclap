// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001fb3f0..0x001fc600 (kind game, layer game, confidence high), dominant class CTriggerVolume
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9414999 {
#define TREE_TU_END }
namespace fn_f9414999 {} using namespace fn_f9414999;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f9414999 {
class Obj_1fb950 {
  public:
    char pad[0xcd];
    unsigned char a;
    char pad2;
    unsigned char b;
    int c;
};
class Thing_1fb970 {
  public:
    char pad[0x10];
    int a;
    int b;
    int c;
    int d;
    unsigned char e;
    void Init();
};
class A_1fba00 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(unsigned*);
};
struct S_1fba00 {
    unsigned a, b, c, d, e, f, g;
};
struct Registry_1fba00 {
};
extern "C" Registry_1fba00* FUN_001c3d90();
struct Obj_1fba60 {
    char pad[0x20];
};
struct V3_1fbb80 { float x, y, z; };
class Bounds_1fbb80 {
public:
    char pad0[0xb0];
    V3_1fbb80 min;
    V3_1fbb80 max;
    float angle;
    unsigned char sideFlags;
    void FUN_001fbb80(V3_1fbb80 *a, V3_1fbb80 *b, float rawAngle);
};
struct V3_1fbd00 {
    float x, y, z;
};
struct Mat4_1fbd00 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be60(float x, float y, float z);
};
struct NameHolder_1fbd00 {
    char data[8];
};
struct Element_1fbd00 {
    char pad0[0xc];
    const char *name;
    void FUN_00336600(const char *attr, float *x, float *y, float *z);
};
int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);
class Marker_1fbd00 {
public:
    char pad0[8];
    NameHolder_1fbd00 nameHolder;
    char pad10[0x90 - 0x10];
    char label[0x20];
    char padB0[0xce - 0xb0];
    char flagCe;

    void FUN_001fbb80(V3_1fbd00 *origin, V3_1fbd00 *dir, float angle);
    void FUN_001fbd00(Element_1fbd00 *elem);
};
extern "C" void __cdecl Format(char*, unsigned int, const char*, void*);
class Inner_1fbfd0 {
  public:
};
class Obj_1fbfd0 {
  public:
    char pad[8];
    Inner_1fbfd0 inner;
    char pad2[0x10];
    void Run(void*);
};
extern void* Entity_1fc000_vftable[];
class Entity_1fc000 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CTriggerVolume_1fc000 : public Entity_1fc000 {
  public:
    CTriggerVolume_1fc000* vfunc_5(signed char flags);
};
struct Vec3_1fc150 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
void __cdecl FUN_00224d70(float angle, Vec3_1fc150 *v);
class CTriggerVolume_1fc150 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual bool vfunc_8(Vec3_1fc150 point);
    char pad04[0xb0 - 4];
    Vec3_1fc150 minimum;
    Vec3_1fc150 maximum;
    float angle;

    void FUN_001fbec0(Vec3_1fc150 *pivot);
    Vec3_1fc150 *FUN_001fc150(Vec3_1fc150 *out, const Vec3_1fc150 *a, const Vec3_1fc150 *b);
};
extern void* Entity_1fc390_vftable[];
class Entity_1fc390 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class CLocator_1fc390 : public Entity_1fc390 {
  public:
    CLocator_1fc390* vfunc_5(signed char flags);
};
class Obj_1fc480 {
  public:
    char pad[0x20c];
    int Get();
};


// 0x001fb3f0 CTriggerVolume::vfunc_5 (1 B): matches/0x001fb3f0.cpp
// sym: ?FUN_001fb3f0@fn_f9414999@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001fb3f0() {}


// 0x001fb400 CTriggerVolume::vfunc_6 (1 B): matches/0x001fb400.cpp
// sym: ?FUN_001fb400@fn_f9414999@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001fb400() {}

} // namespace fn_f9414999

// 0x001fb4f0 CTriggerVolume::vfunc_12 (170 B): equivalent/0x001fb4f0.cpp [wrapped: conflict: CTriggerVolume]
// sym: ?vfunc_12@CTriggerVolume@fn_001fb4f0@@UAEEPAUTriggerObject@2@@Z
namespace fn_001fb4f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// CTriggerVolume::vfunc_12 @ 0x001fb4f0
struct Vec3_1fb4f0 { float x,y,z; };
struct PositionSource_1fb4f0 { unsigned char FUN_00059a50(Vec3_1fb4f0* out); };
struct TriggerObject { char pad[8]; unsigned int field8; unsigned int fieldC; PositionSource_1fb4f0* source; };
struct CTriggerVolume {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 virtual void vfunc_6();
 virtual void vfunc_7();
 virtual unsigned char vfunc_8(Vec3_1fb4f0 position);
 virtual void vfunc_9();
 virtual unsigned char vfunc_10(unsigned int a, unsigned int b);
 virtual void vfunc_11();
 virtual unsigned char vfunc_12(TriggerObject* object);
 virtual void vfunc_13(TriggerObject* object);
 virtual void vfunc_14(TriggerObject* object);
 virtual void vfunc_15(TriggerObject* object);
 char padding[0xc9];
 unsigned char enabled;
};
unsigned char CTriggerVolume::vfunc_12(TriggerObject* object) {
 Vec3_1fb4f0 position;
 if (!object || !enabled || !object->source->FUN_00059a50(&position)) return 0;
 unsigned char inside = vfunc_8(position);
 unsigned char previous = vfunc_10(object->field8, object->fieldC);
 if (inside == 1) {
  if (previous == inside) vfunc_15(object);
  else vfunc_13(object);
 } else if (previous == 1) {
  vfunc_14(object);
 }
 return inside;
}
} // namespace fn_001fb4f0


// 0x001fb850 CTriggerVolume::vfunc_9 (140 B): equivalent/0x001fb850.cpp [wrapped: conflict: CTriggerVolume]
// sym: ?FUN_001fb850@CTriggerVolume@fn_001fb850@@QAEXHHD@Z
namespace fn_001fb850 {
// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 14/14)
// CTriggerVolume::vfunc_9 @ 0x001fb850
// CTriggerVolume: add (flag != 0) or remove (flag == 0) an (a, b) pair in the fixed 16-entry table.
// An existing pair is left alone when flag == 1.

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memmove(void*, const void*, unsigned int);
#endif


struct Pair_1fb850 {
    int a;
    int b;
};

class CTriggerVolume {
public:
    char pad0[0x10];
    Pair_1fb850 pairs[16];
    char pad90[0xd0 - 0x90];
    int count;

    void FUN_001fb850(int a, int b, char flag);
};

void CTriggerVolume::FUN_001fb850(int a, int b, char flag)
{
    int n = count;
    int i = 0;
    bool found = false;
    if (n > 0) {
        do {
            if (pairs[i].a == a && pairs[i].b == b) {
                found = true;
                break;
            }
            ++i;
        } while (i < count);
    }

    if (!found) {
        if (flag != 0 && n < 16) {
            pairs[n].a = a;
            pairs[n].b = b;
            ++count;
        }
        return;
    }
    if (flag == 1) {
        return;
    }
    count = n - 1;
    memmove(&pairs[i], &pairs[i + 1], (n - 1 - i) * sizeof(Pair_1fb850));
}
} // namespace fn_001fb850


// 0x001fb8e0 CTriggerVolume::vfunc_10 (69 B): equivalent/0x001fb8e0.cpp [wrapped: conflict: CTriggerVolume]
// sym: ?vfunc_10@CTriggerVolume@fn_001fb8e0@@QAE_NHH@Z
namespace fn_001fb8e0 {
// STATUS: equivalent (tools/equiv.py level 3: 2254 inputs, branch coverage 8/8)
// CTriggerVolume::vfunc_10 @ 0x001fb8e0
struct CTriggerVolume { char pad[0x10]; struct Pair { int first; int second; } pairs[24]; int count; bool vfunc_10(int first, int second); }; bool CTriggerVolume::vfunc_10(int first, int second) { for (int i = 0; i < count; ++i) { if (pairs[i].first == first && pairs[i].second == second) return true; } return false; }
} // namespace fn_001fb8e0


// 0x001fb930 CTriggerVolume::vfunc_11 (12 B): matches/0x001fb930.cpp
// sym: ?vfunc_11@CTriggerVolume@@UAEEXZ
unsigned char CTriggerVolume::vfunc_11() {
    return this->f_d0 == 0;
}


// 0x001fb940 FUN_001fb940 (13 B): matches/0x001fb940.cpp
// sym: ?FUN_001fb940@Obj_1fb940@owners@@QAEXXZ
void owners::Obj_1fb940::FUN_001fb940() {
    b = a;
}

namespace fn_f9414999 {

// 0x001fb950 FUN_001fb950 (23 B): matches/0x001fb950.cpp
// sym: ?target@fn_f9414999@@YIXPAVObj_1fb950@1@@Z
void __fastcall target(Obj_1fb950* p) {
    p->a = p->b;
    p->c = 0;
}


// 0x001fb970 FUN_001fb970 (18 B): matches/0x001fb970.cpp
// sym: ?Init@Thing_1fb970@fn_f9414999@@QAEXXZ
void Thing_1fb970::Init() {
    c = 0;
    b = 0;
    a = 0;
    d = 0;
    e = 0;
}

} // namespace fn_f9414999

// 0x001fb990 FUN_001fb990 (24 B): matches/0x001fb990.cpp
// sym: ?FUN_001fb990@Target_1fb990@owners@@QAEXPBH@Z
void owners::Target_1fb990::FUN_001fb990(const int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
}


// 0x001fb9b0 FUN_001fb9b0 (10 B): matches/0x001fb9b0.cpp
// sym: ?FUN_001fb9b0@C_1fb9b0@owners@@QAEXH@Z
void owners::C_1fb9b0::FUN_001fb9b0(int x) {
    value = x;
}

namespace fn_f9414999 {

// 0x001fb9c0 CLocator::vfunc_5 (1 B): matches/0x001fb9c0.cpp
// sym: ?FUN_001fb9c0@fn_f9414999@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001fb9c0() {}


// 0x001fb9d0 CLocator::vfunc_6 (1 B): matches/0x001fb9d0.cpp
// sym: ?FUN_001fb9d0@fn_f9414999@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001fb9d0() {}


// 0x001fba00 FUN_001fba00 (64 B): matches/0x001fba00.cpp
// sym: ?FUN_001fba00@fn_f9414999@@YIHPAVA_1fba00@1@@Z
int __fastcall FUN_001fba00(A_1fba00* p) {
    S_1fba00 x;
    p->f8(&x.a);
    x.d = x.a;
    x.e = x.b;
    x.f = x.c;
    x.g = 0x3f800000;
    return ((owners::Thing_1c4010 *)(FUN_001c3d90()))->FUN_001c4010((hulk_intptr)(&x.d));
}


// 0x001fba60 FUN_001fba60 (4 B): matches/0x001fba60.cpp
// sym: ?FUN_001fba60@fn_f9414999@@YIPAXPAUObj_1fba60@1@@Z
// Same code shape as 0x000897e0 (propagated; names are from that function)
void* __fastcall FUN_001fba60(Obj_1fba60* p) {
    return (char*)p + 0x20;
}

} // namespace fn_f9414999

// 0x001fba70 CLocator::vfunc_10 (75 B): equivalent/0x001fba70.cpp [wrapped: conflict: CLocator]
// sym: ?vfunc_10@CLocator@fn_001fba70@@QAEXPAUVec3@2@@Z
namespace fn_001fba70 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// CLocator::vfunc_10 @ 0x001fba70

struct Vec3 { float x,y,z; };  void __cdecl FUN_00224d70(void*, Vec3*); struct CLocator { char pad[0x1c]; void* field; void vfunc_10(Vec3* out); }; void CLocator::vfunc_10(Vec3* out) { Vec3 v; v.x=(*(float*)&DAT_004c85c8); v.y=(*(float*)&DAT_004c85cc); v.z=(*(float*)&DAT_004c85d0); FUN_00224d70(field,&v); *out=v; }
} // namespace fn_001fba70


// 0x001fbb30 FUN_001fbb30 (52 B): equivalent/0x001fbb30.cpp [wrapped: conflict: CTriggerVolume]
// sym: ??0CTriggerVolume@fn_001fbb30@@QAE@XZ
namespace fn_001fbb30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001fbb30 @ 0x001fbb30
struct FUN_0027b070 { virtual void baseVirtual(); char pad[0xc8]; FUN_0027b070(); }; struct CTriggerVolume : FUN_0027b070 { unsigned char stateCC, stateCD, stateCE, stateCF; unsigned int valueD0; CTriggerVolume(); }; CTriggerVolume::CTriggerVolume() { stateCC=0; valueD0=0; stateCE=0; stateCD=1; stateCF=1; }
} // namespace fn_001fbb30

namespace fn_f9414999 {

// 0x001fbb80 FUN_001fbb80 (336 B): equivalent/0x001fbb80.cpp
// sym: ?FUN_001fbb80@Bounds_1fbb80@fn_f9414999@@QAEXPAUV3_1fbb80@2@0M@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 9/10, incomplete)
// FUN_001fbb80 @ 0x001fbb80
void Bounds_1fbb80::FUN_001fbb80(V3_1fbb80 *a, V3_1fbb80 *b, float rawAngle)
{
    float r = FUN_0004af40(0.0f, 6.2831855f, rawAngle);
    float ar = r < 0.0f ? -r : r;
    float v;
    if (ar <= 1e-5f) {
        v = 0.0f;
    } else {
        float w = r - 6.2831855f;
        if (w < 0.0f)
            w = -w;
        if (w <= 1e-5f)
            v = 0.0f;
        else
            v = r;
    }

    V3_1fbb80 lo = *a;
    V3_1fbb80 hi = *b;
    sideFlags = 0xff;
    float minX, minY, minZ;
    if (a->x > b->x) {
        hi.x = a->x;
        minX = b->x;
        sideFlags &= 0xfe;
    } else {
        minX = lo.x;
    }
    if (a->y > b->y) {
        hi.y = a->y;
        minY = b->y;
        sideFlags &= 0xfd;
    } else {
        minY = lo.y;
    }
    float maxZ;
    if (a->z > b->z) {
        minZ = b->z;
        maxZ = a->z;
        sideFlags &= 0xfb;
    } else {
        minZ = lo.z;
        maxZ = hi.z;
    }
    min.x = minX;
    min.y = minY;
    min.z = minZ;
    max.x = hi.x;
    max.y = hi.y;
    max.z = maxZ;
    angle = v;
}


// 0x001fbd00 FUN_001fbd00 (440 B): matches/0x001fbd00.cpp
// sym: ?FUN_001fbd00@Marker_1fbd00@fn_f9414999@@QAEXPAUElement_1fbd00@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_001fbd00 @ 0x001fbd00
void Marker_1fbd00::FUN_001fbd00(Element_1fbd00 *elem)
{
    const char *name = elem->name;
    ((owners::Target_27b040 *)&nameHolder)->FUN_0027b040((hulk_uintptr)name);
    FUN_000964a0(label, 0x20, "%s", name);
    flagCe = 0;

    V3_1fbd00 up;
    V3_1fbd00 origin;
    float tx, ty, tz;
    float rx, ry, rz;
    float sx, sy, sz;
    up.x = 1.0f;
    up.y = 1.0f;
    up.z = -1.0f;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;

    elem->FUN_00336600("translate", &tx, &ty, &tz);
    elem->FUN_00336600("rotate", &rx, &ry, &rz);
    elem->FUN_00336600("scale", &sx, &sy, &sz);

    Mat4_1fbd00 identity;
    Mat4_1fbd00 scaleM;
    Mat4_1fbd00 moveM;
    Mat4_1fbd00 tmp;
    Mat4_1fbd00 full;
    identity.FUN_0022b980();
    scaleM.FUN_0022b980();
    scaleM.FUN_0022be60(sx, sy, sz);
    moveM.FUN_0022b980();
    V3_1fbd00 pos;
    pos.x = tx;
    pos.y = ty;
    pos.z = -tz;
    ((owners::Target_22be40 *)&moveM)->FUN_0022be40((const int *)(const V3_1fbd00 *)(&pos));
    ((owners::Matrix_22ca90 *)&tmp)->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Mat4_1fbd00 *)(&identity), (const owners::Matrix_22ca90 *)(const Mat4_1fbd00 *)(&scaleM));
    ((owners::Matrix_22ca90 *)&full)->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Mat4_1fbd00 *)(&tmp), (const owners::Matrix_22ca90 *)(const Mat4_1fbd00 *)(&moveM));
    tmp = full;
    ((owners::Mat_22c2b0 *)&tmp)->FUN_0022c2b0((float *)(V3_1fbd00 *)(&origin), (float *)(V3_1fbd00 *)(&origin));
    ((owners::Mat_22c2b0 *)&tmp)->FUN_0022c2b0((float *)(V3_1fbd00 *)(&up), (float *)(V3_1fbd00 *)(&up));
    FUN_001fbb80(&origin, &up, ry * -0.0174532924f);
}

} // namespace fn_f9414999

// 0x001fbec0 FUN_001fbec0 (91 B): equivalent/0x001fbec0.cpp [wrapped: conflict: Vec3]
// sym: ?FUN_001fbec0@CTriggerVolume_1fbec0@fn_001fbec0@@QAEXPAUVec3@2@@Z
namespace fn_001fbec0 {
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 6/6)
// FUN_001fbec0 @ 0x001fbec0
struct Vec3 { unsigned int x, y, z; };
struct CTriggerVolume_1fbec0 {
    char pad[0xb0];
    Vec3 primary;
    Vec3 fallback;
    char pad2[4];
    unsigned char flags;
    void FUN_001fbec0(Vec3 *result);
};
void CTriggerVolume_1fbec0::FUN_001fbec0(Vec3 *result) {
    unsigned int x = primary.x;
    unsigned int y = primary.y;
    unsigned int z = primary.z;
    unsigned char bits = flags;
    if (!(bits & 1)) x = fallback.x;
    if (!(bits & 2)) y = fallback.y;
    if (!(bits & 4)) z = fallback.z;
    result->x = x;
    result->y = y;
    result->z = z;
}
} // namespace fn_001fbec0


// 0x001fbf40 FUN_001fbf40 (35 B): matches/0x001fbf40.cpp [wrapped: conflict: CLocator]
// sym: ??0CLocator@fn_001fbf40@@QAE@XZ
namespace fn_001fbf40 {
extern "C" void _ReadWriteBarrier();
class Entity_1fbf40 {
  public:
    Entity_1fbf40();
    virtual void fn();
};
class CLocator : public Entity_1fbf40 {
  public:
    CLocator();
    char pad[12];
    int a, b, c, d;
    char flag;
};
CLocator::CLocator() {
    c = 0;
    _ReadWriteBarrier();
    b = 0;
    a = 0;
    d = 0;
    flag = 0;
}
} // namespace fn_001fbf40


// 0x001fbf70 CLocator::vfunc_8 (30 B): matches/0x001fbf70.cpp [wrapped: conflict: CLocator]
// sym: ?vfunc_8@CLocator@fn_001fbf70@@UAEPAUVec@2@PAU32@@Z
namespace fn_001fbf70 {
struct Vec {
    unsigned int x, y, z;
};
struct CLocator {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual Vec* vfunc_8(Vec* out);
    virtual void vfunc_9();
    virtual void vfunc_10();
    char padding[12];
    Vec pos;
};
Vec* CLocator::vfunc_8(Vec* out) {
    *out = pos;
    return out;
}
} // namespace fn_001fbf70


// 0x001fbf90 CLocator::vfunc_9 (4 B): matches/0x001fbf90.cpp
// sym: ?vfunc_9@CLocator@@UAEMXZ
// Same code shape as 0x00069070 (propagated; names are from that function)
hulk_freg CLocator::vfunc_9() {
    return this->f_1c;
}


// 0x001fbfa0 FUN_001fbfa0 (11 B): matches/0x001fbfa0.cpp [wrapped: conflict: CEffectStopTrack]
// sym: ?FUN_001fbfa0@fn_001fbfa0@@YIXPAVCEffectStopTrack@1@@Z
namespace fn_001fbfa0 {
// Same code shape as 0x00060920 (propagated; names are from that function)
extern int CEffectStopTrack_vftable;
class CEffectStopTrack {
  public:
};
void __fastcall FUN_0027afd0(CEffectStopTrack*);
void __fastcall FUN_001fbfa0(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&CEffectStopTrack_vftable;
    FUN_0027afd0(self);
}
} // namespace fn_001fbfa0

namespace fn_f9414999 {

// 0x001fbfd0 FUN_001fbfd0 (42 B): matches/0x001fbfd0.cpp
// sym: ?Run@Obj_1fbfd0@fn_f9414999@@QAEXPAX@Z
void Obj_1fbfd0::Run(void* arg) {
    Format((char*)this + 0x20, 0x20, "%s", arg);
    ((owners::Target_27b040 *)&inner)->FUN_0027b040((hulk_uintptr)arg);
}


// 0x001fc000 CTriggerVolume::vfunc_2 (36 B): matches/0x001fc000.cpp
// sym: ?vfunc_5@CTriggerVolume_1fc000@fn_f9414999@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CTriggerVolume_1fc000* CTriggerVolume_1fc000::vfunc_5(signed char flags) {
    *(void***)this = Entity_1fc000_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f9414999

// 0x001fc030 CTriggerVolume::vfunc_8 (276 B): equivalent/0x001fc030.cpp [wrapped: conflict: CTriggerVolume]
// sym: ?vfunc_8@CTriggerVolume@fn_001fc030@@QAE_NMMM@Z
namespace fn_001fc030 {
// STATUS: equivalent (tools/equiv.py level 3: 15681 inputs, branch coverage 14/14)
// CTriggerVolume::vfunc_8 @ 0x001fc030
// CTriggerVolume::vfunc_8 @ 0x001fc030
struct Vec_1fc030 { float x,y,z; };
void FUN_00224d70(float angle, Vec_1fc030* output);
struct CTriggerVolume {
 char pad[0xb0]; Vec_1fc030 minimum; Vec_1fc030 maximum; float angle;
 void FUN_001fbec0(Vec_1fc030* out);
 bool vfunc_8(float x,float y,float z);
};
bool CTriggerVolume::vfunc_8(float x,float y,float z) {
 Vec_1fc030 p; p.x=x; p.y=y; p.z=z;
 double px;
 if (angle != 0.0f) {
  Vec_1fc030* center = (Vec_1fc030*)&x;
  FUN_001fbec0(center);
  p.x -= x; p.y -= y; p.z -= z;
  FUN_00224d70(-angle, &p);
  px = (double)x + p.x;
  p.y = y + p.y;
  p.z = z + p.z;
 } else px=p.x;
 return px >= minimum.x && px <= maximum.x && p.y >= minimum.y && p.y <= maximum.y && p.z >= minimum.z && p.z <= maximum.z;
}
} // namespace fn_001fc030

namespace fn_f9414999 {

// 0x001fc150 FUN_001fc150 (531 B): equivalent/0x001fc150.cpp
// sym: ?FUN_001fc150@CTriggerVolume_1fc150@fn_f9414999@@QAEPAUVec3_1fc150@2@PAU32@PBU32@1@Z
// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 24/24)
// FUN_001fc150 @ 0x001fc150
Vec3_1fc150 *CTriggerVolume_1fc150::FUN_001fc150(Vec3_1fc150 *out, const Vec3_1fc150 *a, const Vec3_1fc150 *b)
{
    struct Frame {
        Vec3_1fc150 p;
        Vec3_1fc150 r;
        Vec3_1fc150 pivot;
    } fr;

    fr.r.x = 0.0f;
    fr.r.y = 0.0f;
    fr.r.z = 0.0f;
    if (!vfunc_8(*a) && vfunc_8(*b)) {
        fr.p = *a;
        if (angle != 0.0f) {
            FUN_001fbec0(&fr.pivot);
            fr.p.x = fr.p.x - fr.pivot.x;
            fr.p.y = fr.p.y - fr.pivot.y;
            fr.p.z = fr.p.z - fr.pivot.z;
            FUN_00224d70(-angle, &fr.p);
            fr.p.x = fr.pivot.x + fr.p.x;
            fr.p.y = fr.pivot.y + fr.p.y;
            fr.p.z = fr.pivot.z + fr.p.z;
        }
        if (fr.p.x < minimum.x)
            fr.r.x = -1.0f;
        else if (fr.p.x > maximum.x)
            fr.r.x = 1.0f;
        if (fr.p.y < minimum.y)
            fr.r.y = -1.0f;
        else if (fr.p.y > maximum.y)
            fr.r.y = 1.0f;
        if (fr.p.z < minimum.z)
            fr.r.z = -1.0f;
        else if (fr.p.z > maximum.z)
            fr.r.z = 1.0f;
        fr.r.FUN_0022d110();
        FUN_00224d70(angle, &fr.r);
    }
    out->x = fr.r.x;
    out->y = fr.r.y;
    out->z = fr.r.z;
    return out;
}


// 0x001fc390 FUN_001fc390 (36 B): matches/0x001fc390.cpp
// sym: ?vfunc_5@CLocator_1fc390@fn_f9414999@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CLocator_1fc390* CLocator_1fc390::vfunc_5(signed char flags) {
    *(void***)this = Entity_1fc390_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f9414999

// 0x001fc3c0 FUN_001fc3c0 (151 B): matches/0x001fc3c0.cpp [wrapped: conflict: FUN_000964a0]
// sym: ?FUN_001fc3c0@Transform_1fc3c0@fn_001fc3c0@@QAEXPAVXmlNode@2@@Z
namespace fn_001fc3c0 {
// FUN_001fc3c0 @ 0x001fc3c0
struct Name_1fc3c0 {
    int word;
};

class XmlNode {
public:
    char pad0[0xc];
    const char *name;       // 0xc
    unsigned char FUN_00336600(const char *key, float *a, float *b, float *c);
};

void __cdecl FUN_000964a0(char *dst, int size, const char *fmt, ...);

class Transform_1fc3c0 {
public:
    char pad0[8];
    Name_1fc3c0 name;              // 8
    char padc[4];
    float tx;               // 0x10
    float ty;               // 0x14
    float tz;               // 0x18
    float rotation;         // 0x1c
    char label[0x20];       // 0x20
    void FUN_001fc3c0(XmlNode *node);
};

void Transform_1fc3c0::FUN_001fc3c0(XmlNode *node)
{
    const char *nodeName = node->name;
    FUN_000964a0(label, 0x20, "%s", nodeName);
    ((owners::Target_27b040 *)&name)->FUN_0027b040((hulk_uintptr)nodeName);

    float x, y, z;
    if (node->FUN_00336600("translate", &x, &y, &z)) {
        tx = x;
        ty = y;
        tz = -z;
    }
    if (node->FUN_00336600("rotate", &x, &y, &z) == 1)
        rotation = y * -0.01745329238474369f;
}
} // namespace fn_001fc3c0

namespace fn_f9414999 {

// 0x001fc480 FUN_001fc480 (7 B): matches/0x001fc480.cpp
// sym: ?Get@Obj_1fc480@fn_f9414999@@QAEHXZ
int Obj_1fc480::Get() {
    return *(int*)((char*)this + 0x20c);
}

} // namespace fn_f9414999

// 0x001fc590 CLocator::vfunc_2 (98 B): equivalent/0x001fc590.cpp [wrapped: conflict: CLocator]
// sym: ?vfunc_2@CLocator@fn_001fc590@@UAEPAU12@E@Z
namespace fn_001fc590 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// CLocator::vfunc_2 @ 0x001fc590
struct CLocator { virtual void vfunc_0(); virtual void vfunc_1(); virtual CLocator* vfunc_2(unsigned char flags); void FUN_001fbfa0(); }; void __cdecl FUN_00263f30(void*); void __cdecl FUN_00263f40(void*); CLocator* CLocator::vfunc_2(unsigned char flags) { if (flags & 2) { int* base = (int*)((char*)this - 4); int count = *base; for (int i=count-1; i>=0; --i) ((CLocator*)((char*)this + i*64))->FUN_001fbfa0(); if(flags & 1) FUN_00263f40(base); return (CLocator*)base; } FUN_001fbfa0(); if(flags & 1) FUN_00263f30(this); return this; }
} // namespace fn_001fc590

