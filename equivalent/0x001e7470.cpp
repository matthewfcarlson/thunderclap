// STATUS: equivalent (tools/equiv.py level 3: 934 inputs, branch coverage 102/102)
// FUN_001e7470 @ 0x001e7470
#include "compat/ptr.h"
typedef unsigned int size_t;
void* operator new(size_t) throw();
inline void* operator new(size_t, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr);
char FUN_001d04d0(const void*) throw();
class CSPManager;
namespace math { class Vector { public: float x, y, z; }; }
typedef float Float; typedef bool Bool; typedef int Int; typedef void Void;
typedef const char* String; typedef char* CharPtr; typedef math::Vector Vector;
extern char DAT_0048e0e4, DAT_0048e0f0, DAT_0048e100, DAT_0048e10c, DAT_0048e128, DAT_0048e134;
#define tBool DAT_0048e0e4
#define tString DAT_0048e0f0
#define tVoid DAT_0048e100
#define tVector DAT_0048e10c
#define tFloat DAT_0048e128
#define tInt DAT_0048e134
class Base { public: virtual void v(); char p[12]; char a[8]; char result; char z[3]; Base(const char*, int) throw(); };
template<class C, class R, class A1> class Method1 : public Base { public: void (*f)(); Method1(const char* n, void (*x)(), const void* r, const void* a1) : Base(n, 1) { f = x; result = FUN_001d04d0(r); a[0] = FUN_001d04d0(a1); } virtual void v(); };
template<class C, class R, class A1> class Closure1 : public Method1<C, R, A1> { public: C* owner; Closure1(const char* n, C* o, void (*f)(), const void* r, const void* a1) : Method1<C, R, A1>(n, f, r, a1) { owner = o; } virtual void v(); };
class Registry { public:
    void FUN_001d3b70(const char*, void*);
    void FUN_001e12b0(const char*, void (*)());
    void FUN_001e35a0(const char*, CSPManager*, void (*)());
    void FUN_001e3790(const char*, CSPManager*, void (*)());
    void FUN_001e3930(const char*, CSPManager*, void (*)());
    void FUN_001e3990(const char*, CSPManager*, void (*)());
    void FUN_001e39f0(const char*, CSPManager*, void (*)());
    void FUN_001e3a50(const char*, CSPManager*, void (*)());
    void FUN_001e3ba0(const char*, CSPManager*, void (*)());
    void FUN_001e3c50(const char*, CSPManager*, void (*)());
    void FUN_001e3cb0(const char*, CSPManager*, void (*)());
    void FUN_001e3d10(const char*, CSPManager*, void (*)());
    void FUN_001e3dc0(const char*, CSPManager*, void (*)());
    void FUN_001e3e20(const char*, CSPManager*, void (*)());
    void FUN_001e3ee0(const char*, CSPManager*, void (*)());
    void FUN_001e3f40(const char*, CSPManager*, void (*)());
    void FUN_001e3ff0(const char*, CSPManager*, void (*)());
    void FUN_001e40f0(const char*, CSPManager*, void (*)());
};
class Entry { public:
    void* FUN_001df560(const char*, void (*)());
    void* FUN_001e1430(const char*, CSPManager*, void (*)());
    void* FUN_001e14e0(const char*, CSPManager*, void (*)());
    void* FUN_001e1620(const char*, CSPManager*, void (*)());
    void* FUN_001e16c0(const char*, CSPManager*, void (*)());
    void* FUN_001e17d0(const char*, CSPManager*, void (*)());
    void* FUN_001e1880(const char*, CSPManager*, void (*)());
    void* FUN_001e1930(const char*, CSPManager*, void (*)());
    void* FUN_001e1d40(const char*, CSPManager*, void (*)());
    void* FUN_001e2150(const char*, CSPManager*, void (*)());
    void* FUN_001e24c0(const char*, CSPManager*, void (*)());
    void* FUN_001e26a0(const char*, CSPManager*, void (*)());
};
Registry* FUN_001d4c90();
#define FN(b) extern void FUN_##b();
#define G1(n, b, R, A1) { FN(b) r->FUN_001d3b70(n, new Closure1<CSPManager, R, A1>(n, this, FUN_##b, &t##R, &t##A1)); }
#define E(n, c, b) { FN(b) Entry* e = (Entry*)FUN_0008d690(0x24); void* x = 0; if (e) x = e->FUN_##c(n, this, FUN_##b); r->FUN_001d3b70(n, x); }
#define EF(n, c, b) { FN(b) Entry* e = (Entry*)FUN_0008d690(0x20); void* x = 0; if (e) x = e->FUN_##c(n, FUN_##b); r->FUN_001d3b70(n, x); }
#define O(n, c, b) { FN(b) r->FUN_##c(n, this, FUN_##b); }
#define OF(n, c, b) { FN(b) r->FUN_##c(n, FUN_##b); }

class Link { public: char b[8]; void FUN_0027af00(); void FUN_0027b040(int); };
class Sub6 { public: char b[6]; void FUN_001db780(const void*); };
struct Slot { Link a; Link b; char pad[0x18]; };
struct Entry40 {
    Link a;
    Link b;
    Sub6 c;
    unsigned short w16;
    int d18;
    int d1c;
    unsigned short w20;
    unsigned short w22;
    unsigned short w24;
    unsigned char b26;
    unsigned char b27;
};
struct Rec14 { int a; int b; int c; float d; unsigned short w; unsigned short x; };
struct Rec18 { Link l; int a; int b; int c; int pad[1]; };
struct Vec4 { float x, y, z, w; };

class CSPManager {
public:
    CSPManager();
    virtual void v0();
    char pad_04[4];
    int arr8[0x180];
    Entry40 e[0x800];
    Rec14 r14[0x800];
    int i1e608, i1e60c, i1e610, i1e614, i1e618, i1e61c;
    int arr1e620[0x80];
    int i1e820, i1e824, i1e828, i1e82c, i1e830;
    char c1e834;
    char pad1e835[3];
    int i1e838;
    char pad1e83c[4];
    Link links[0x80];
    char pad1ec40[0x10];
    int i1ec50, i1ec54, i1ec58;
    char pad1ec5c[4];
    int arr1ec60[0x40];
    Rec18 r18[0x10];
    float f1eee0;
    int i1eee4;
};

CSPManager::CSPManager() {
    int i;
    for (i = 0; i < 0x800; i++) {
        e[i].a.FUN_0027af00();
        e[i].b.FUN_0027af00();
    }
    i1e608 = 0; i1e60c = 0; i1e610 = 0; i1e614 = 0; i1e61c = 0;
    i1e820 = 0; i1e824 = 0; i1e828 = 0; i1e82c = 0; i1e830 = 0;
    c1e834 = 0;
    i1e838 = 0;
    for (i = 0; i < 0x80; i++)
        links[i].FUN_0027af00();
    i1ec50 = 0; i1ec54 = 0; i1ec58 = 0;
    for (i = 0; i < 0x10; i++)
        r18[i].l.FUN_0027af00();
    f1eee0 = 1.0f;
    i1eee4 = 0x2d;
    Registry* r = FUN_001d4c90();
    if (r) {
G1("spm_SetMaxVU1RenderableCount", 001dde30, Void, Int)
O("spm_AddVU1Renderable", 001e35a0, 001dde50)
E("spm_SetSmartPropMustBeActive", 001e1430, 001dc100)
E("spm_SetSmartPropStateDescription", 001e14e0, 001df160)
G1("spm_GetSmartPropStateDescription", 001df130, Int, String)
G1("spm_SetMaxInstancedProps", 001dde20, Void, Int)
E("spm_SendSmartPropEvent", 001e1620, 001e30f0)
E("spm_ShowSmartProp", 001e16c0, 001defe0)
O("spm_AttachSmartProp", 001e3790, 001df010)
E("spm_SetSmartPropState", 001e17d0, 001df100)
G1("spm_GetSmartPropState", 001dc350, Int, String)
E("spm_SetSmartPropStateByName", 001e1880, 001e3230)
E("spm_SetSmartPropHitPoints", 001e1930, 001dc9a0)
G1("spm_GetSmartPropHitPoints", 001dc940, Int, String)
G1("spm_GetSmartPropERSIncrease", 001dca00, Int, String)
G1("spm_SetEnemyDamageFactor", 001dde00, Void, Float)
O("spm_SetSmartPropPatrolPath", 001e3930, 001df400)
O("spm_SpawnCollectable", 001e3990, 001e4fc0)
O("spm_SpawnCollectableName", 001e39f0, 001e5070)
O("spm_SpawnCollectableNameOffQueue", 001e39f0, 001e5110)
O("spm_SetMustRespawn", 001e3a50, 001dca40)
E("spm_AddCollectable", 001e17d0, 001df2e0)
E("spm_SetIsCollected", 001e1430, 001dccf0)
EF("spm_PhysicsProperty", 001df560, 001dca50)
G1("spm_GetSmartPropPosition", 001df190, Vector, String)
E("spm_SetSmartPropPosition", 001e1d40, 001df1e0)
G1("spm_GetSmartPropOrientation", 001dc4a0, Float, String)
E("spm_SetSmartPropOrientation", 001e1d40, 001dc550)
G1("spm_GetSmartPropVelocity", 001dc660, Vector, String)
E("spm_SetSmartPropVelocity", 001e1d40, 001dc720)
G1("spm_GetSmartPropLastLaunchPosition", 001dc810, Vector, String)
G1("spm_GetSmartPropCurrentFrame", 001dc8d0, Float, String)
G1("spm_GetSmartPropWeaponizableType", 001e32b0, Int, String)
G1("spm_GetSmartPropWeaponType", 001e3360, Int, String)
OF("spm_SetMajorHealthBonus", 001e12b0, 001dba30)
OF("spm_SetMinorHealthBonus", 001e12b0, 001dba40)
OF("spm_SetMajorRageBonus", 001e12b0, 001dba50)
OF("spm_SetMinorRageBonus", 001e12b0, 001dba60)
O("spm_SetRumbleEvent", 001e3ba0, 001df320)
E("spm_SetIndestructable", 001e16c0, 001df330)
G1("spm_GetIndestructable", 001df350, Bool, String)
O("spm_SpawnSmartPropOffQueue", 001e3c50, 001e54b0)
O("spm_SpawnSmartProp", 001e3c50, 001e57e0)
O("spm_SpawnSmartPropV", 001e3cb0, 001e5860)
O("spm_SpawnSmartPropDirV", 001e3d10, 001e5540)
G1("spm_RemovePropInstance", 001e7440, Bool, String)
E("spm_IsSmartPropInAreaV", 001e2150, 001dcdf0)
O("spm_IsSmartPropInArea", 001e3dc0, 001dcf00)
O("spm_GetNumActiveProps", 001e3e20, 001dcf50)
G1("spm_GetSmartPropCollisionEnabled", 001df370, Bool, String)
E("spm_SetSmartPropCollisionEnabled", 001e1430, 001df3a0)
G1("spm_SetDoYCheck", 001dba80, Void, Bool)
G1("spm_SetYCheck", 001dba90, Void, Float)
OF("spm_SetCollectableFadeTime", 001e12b0, 001dba70)
O("spm_SetDestructionEffectName", 001e3ee0, 001dd030)
O("spm_SetRestingSensitivity", 001e3f40, 001dd090)
E("spm_AddMassClass", 001e24c0, 001dd110)
O("spm_AddPhysicsRestingParam", 001e3ff0, 001dd1e0)
E("spm_SetSmartPropCharacterAlignment", 001e1620, 001ddc20)
G1("spm_GetSmartPropCharacterAlignment", 001ddcc0, String, String)
E("spm_SetSmartPropCharacterAlignmentDamageFactor", 001e26a0, 001ddd50)
G1("spm_GetSmartPropCharacterAlignmentDamageFactor", 001ddda0, Float, String)
E("spm_SetSmartPropSuckable", 001e16c0, 001ddb80)
E("spm_SetSmartPropChuckable", 001e16c0, 001ddb30)
E("spm_SetSmartPropMustSimulateTime", 001e26a0, 001ddbd0)
O("spm_SpewCollectables", 001e40f0, 001e4e50)
        for (i = 0; i < 4; i++)
            for (int j = 0; j < 0x20; j++)
                links[i * 0x20 + j].FUN_0027b040(0);
        for (i = 0; i < 0x40; i++)
            arr1ec60[i] = 0;
        for (i = 0; i < 0x10; i++) {
            r18[i].l.FUN_0027b040(0);
            r18[i].a = 0;
            r18[i].b = 0;
            r18[i].c = 0xff;
        }
        i1e618 = 0;
        for (i = 0; i < 0x80; i++)
            arr1e620[i] = 0;
        for (i = 0; i < 0x180; i++)
            arr8[i] = 0;
        Vec4 q;
        q.x = 0; q.y = 0; q.z = 0; q.w = 1.0f;
        for (i = 0; i < 0x800; i++) {
            e[i].a.FUN_0027b040(0);
            e[i].b.FUN_0027b040(0);
            e[i].d1c = 0;
            e[i].c.FUN_001db780(&q);
            e[i].d18 = 0;
            e[i].w20 = 0;
            e[i].w16 = 0;
            e[i].b26 = 0;
            e[i].w24 = 0;
            e[i].b27 = 1;
            e[i].w22 = 0xffff;
            r14[i].a = 0;
            r14[i].b = 0;
            r14[i].c = 0;
            r14[i].d = 3.4028235e38f;
            r14[i].w = 0;
            r14[i].x = 0xffff;
        }
    }
}
