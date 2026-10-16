// STATUS: equivalent (tools/equiv.py level 3: 589 inputs, branch coverage 117/118, incomplete)
// FUN_000464c0 @ 0x000464c0
#include "decls/address.h"
inline void* operator new(unsigned int, void* p) { return p; }
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" long __cdecl atol(const char*);
extern "C" int __cdecl _atexit(void (__cdecl*)());
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern int __cdecl FUN_00267760(char* buf, int size, const char* fmt, ...);
extern void __cdecl FUN_00363bc0();

extern unsigned int DAT_004d9968;
extern unsigned int DAT_004dc358;
extern const char* DAT_0048f6a4[];
extern const char* DAT_0048f6b4[];
extern const char* DAT_0048f6d0[];
extern float DAT_003f5eb8[];

struct Vec3_464c0 { float x, y, z; };
struct Key_464c0 {
    unsigned int first, second;
    void FUN_0027af00();
    void FUN_0027af10(Key_464c0 src);
    void FUN_0027af50();
    void FUN_0027b040(const char* s);
};
extern Key_464c0 DAT_004dc350;

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void* p) = 0;
};
template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void* p);
};
}
}
namespace pure3d { class DrawableHierarchy; class ShadowSkin; }
class CSPHulkProp;

class Obj_464c0 {
public:
    virtual void v0();
    virtual void v1();
};
class Factory_464c0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Obj_464c0* f3(content::LoadInventory::DynamicCasterBase* caster, unsigned int lo, unsigned int hi);
};
struct Holder44_464c0 { Factory_464c0* FUN_00203d70(); };
struct Holder28_464c0 { Holder44_464c0* FUN_000862a0(); };
struct World { char pad0[0x54]; Holder28_464c0* holder; };

struct Finder_464c0 { int FUN_0027b200(unsigned int lo, unsigned int hi); };
struct Skel_464c0 { char pad0[8]; Finder_464c0* finder; };
class Node {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual Skel_464c0* v11();
};

class Reader {
public:
    char FUN_0027aa20(const char* name, float* out);
    void FUN_0027a9d0(const char* name, int* out);
    void FUN_0027aac0(const char* name, const char** out);
    void FUN_0027ab00(const char* name, Vec3_464c0* out);
};
class Scope_464c0 {
public:
    char FUN_001d2ba0(const char* name, int a, int b);
    char FUN_001d2d40(const char* name, float* out);
    void FUN_001d19d0(int n);
};
Scope_464c0* FUN_001d4c90();

struct Sub12 { char b[12]; void FUN_00233f20(const char* s); };
struct Attach_464c0 {
    Obj_464c0* r;
    char pad4[4];
    unsigned int jlo;
    unsigned int jhi;
    Vec3_464c0 off;
    Vec3_464c0 ori;
};

// The original's locals, at their stack offsets (relative to its esp after the prologue, minus 0x14): the
// checker fills the words behind every out-parameter, so what sits next to what matters.
struct Frame_464c0 {
    int* jidp;                                              // 0x10
    union { const char* s14; char* namep; } x14;            // 0x14  Size / CameraSize, joint name cursor
    union { Vec3_464c0* offp; char pad[4]; } u18;                 // 0x18
    union { const char* js; const char* ps; char caster[4]; } u1c;
    union { Factory_464c0* inv; float m; } u20;
    union { const char* js2; const char** nm; } u24;        // 0x24
    float def;                                              // 0x28
    const char* s1;                                         // 0x2c
    const char* sal;                                        // 0x30
    union { Key_464c0 tmp; char caster[4]; Finder_464c0* finder; } u34; // 0x34
    const char* t5;                                         // 0x3c
    int u4, u5;                                             // 0x40 0x44
    const char* s2;                                         // 0x48
    int u7;                                                 // 0x4c
    const char* t1;                                         // 0x50
    int u8;                                                 // 0x54
    const char* t3;                                         // 0x58
    int u9;                                                 // 0x5c
    const char* s3;                                         // 0x60
    int u10, u1, u11, u3, u12;                              // 0x64 .. 0x74
    const char* t0;                                         // 0x78
    int u13;                                                // 0x7c
    const char* t4;                                         // 0x80
    int u14, u2;                                            // 0x84 0x88
    const char* s5;                                         // 0x8c
    const char* t2;                                         // 0x90
    int boss;                                               // 0x94
    const char* s4;                                         // 0x98
    char pad9c[8];
    char buf[0x80];                                         // 0xa4
    char nbuf[0x20];                                        // 0x124
    unsigned int cookie;                                    // 0x144
};

class CharDef {
public:
    bool FUN_000464c0(int unused, Reader* props);
    void FUN_00045da0(Obj_464c0* o);
    void FUN_00045f30(Obj_464c0* o);
    void FUN_00044820(Key_464c0* k, float f);
    int f000;
    char pad004[0x4];
    Node* p8;
    char pad00c[0x4];
    char b010;
    char pad011[0x3];
    int f014;
    int f018;
    float f01c;
    char pad020[0xc];
    float f02c;
    float f030;
    float f034;
    Vec3_464c0 f038;
    char jname[3][0x20];
    int jid[3];
    Vec3_464c0 joff[3];
    float jrad[3];
    Sub12 sub[6];
    float f128;
    float f12c;
    float f130;
    float f134;
    float f138;
    float f13c;
    float f140;
    float f144;
    float f148;
    float f14c;
    float f150;
    float f154;
    float f158;
    float f15c;
    float f160;
    float f164;
    float f168;
    int f16c;
    float f170;
    float f174;
    float f178;
    float f17c;
    float f180;
    float f184;
    float f188;
    float f18c;
    int f190;
    Vec3_464c0 f194;
    float f1a0;
    int f1a4;
    float f1a8;
    float f1ac;
    int f1b0;
    char pad1b4[0x4];
    Attach_464c0 attach[8];
    char b2f8;
    char pad2f9[0x3];
    float f2fc;
    Vec3_464c0 f300;
    float f30c;
    float f310;
    float f314;
    float f318;
    float f31c;
    float f320;
    float f324;
    float f328;
    float f32c;
    float f330;
    float f334;
    float f338;
    float f33c;
    float f340;
    float f344;
    float f348;
    float f34c;
    float f350;
    float f354;
    float f358;
    float f35c;
    float f360;
    float f364;
    float f368;
    float f36c;
    float f370;
    float f374;
    float f378;
    char b37c;
    char b37d;
    char b37e;
    char b37f;
    int f380;
    char b384;
    char pad385[0x3];
    float f388;
    char b38c;
    char b38d;
    char b38e;
    char b38f;
    char b390;
    char pad391[0x3];
    float f394;
    float f398;
    float f39c;
    float f3a0;
    float f3a4;
    float f3a8;
    float f3ac;
    char name3b0[0x40];
    char name3f0[0x40];
    char name430[5];
    char pad435[0x3];
    float f438;
    float f43c;
    float f440;
    float f444;
    float f448;
    int f44c;
    float f450;
    char b454;
    char pad455[0x3];
    float f458;
    float f45c;
    float f460;
    float f464;
    float f468;
    char pad46c[0x4];
    float f470;
    char b474;
    char b475;
    char pad476[0x2];
    float f478;
    float f47c;
};

bool CharDef::FUN_000464c0(int unused, Reader* props) {
    Frame_464c0 fr;
    fr.cookie = DAT_004d9968;
    fr.u20.inv = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    fr.s1 = 0;
    props->FUN_0027aac0("VariationName", &fr.s1);
    name3b0[0] = 0;
    if (fr.s1)
        FUN_00267760(name3b0, 0x40, "%s", fr.s1);
    fr.s2 = 0;
    props->FUN_0027aac0("BaseName", &fr.s2);
    name3f0[0] = 0;
    if (fr.s2)
        FUN_00267760(name3f0, 0x40, "%s", fr.s2);
    if (strcmp(name3f0, "") == 0) {
        name3f0[0] = 0;
        if (fr.s1)
            FUN_00267760(name3f0, 0x40, "%s", fr.s1);
    }
    fr.s3 = 0;
    props->FUN_0027aac0("VariationName4CC", &fr.s3);
    if (fr.s3)
        FUN_00267760(name430, 5, "%s", fr.s3);
    fr.s4 = 0;
    props->FUN_0027aac0("Model", &fr.s4);
    {
        unsigned __int64 id = FUN_0027b020(fr.s4);
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>* caster =
            new (fr.u1c.caster) content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>;
        FUN_00045da0(fr.u20.inv->f3(caster, (unsigned int)id, (unsigned int)(id >> 32)));
    }
    fr.s5 = 0;
    props->FUN_0027aac0("ShadowModel", &fr.s5);
    {
        unsigned __int64 id = FUN_0027b020(fr.s5);
        content::LoadInventory::DynamicCaster<pure3d::ShadowSkin>* caster =
            new (fr.u1c.caster) content::LoadInventory::DynamicCaster<pure3d::ShadowSkin>;
        FUN_00045f30(fr.u20.inv->f3(caster, (unsigned int)id, (unsigned int)(id >> 32)));
    }
    fr.x14.s14 = 0;
    props->FUN_0027aac0("Size", &fr.x14.s14);
    if (fr.x14.s14) {
        for (int i = 0; i < 6; i++) {
            if (strcmp(fr.x14.s14, DAT_0048f6b4[i]) == 0) {
                f014 = i;
                f018 = i;
                f01c = DAT_003f5eb8[i];
                break;
            }
        }
    }
    props->FUN_0027aa20("CharacterMass", &this->f01c);
    fr.x14.s14 = 0;
    props->FUN_0027aac0("CameraSize", &fr.x14.s14);
    if (fr.x14.s14) {
        for (int i = 0; i < 6; i++) {
            if (strcmp(fr.x14.s14, DAT_0048f6b4[i]) == 0) {
                f018 = i;
                break;
            }
        }
    }
    fr.boss = 0;
    props->FUN_0027a9d0("Boss", &fr.boss);
    b010 = (fr.boss != 0);
    f030 = 0.0f;
    props->FUN_0027aa20("CollWorldHeight", &f030);
    this->f034 = 0.0f; props->FUN_0027aa20("CollWorldRadius", &this->f034);
    this->f038.x = 0.0f; this->f038.y = 0.0f; this->f038.z = 0.0f; props->FUN_0027ab00("CollWorldOffset", &this->f038);
    props->FUN_0027aa20("CharacterRootHeight", &this->f02c);
    fr.jidp = jid;
    fr.x14.namep = jname[0];
    fr.u18.offp = joff;
    fr.u24.nm = DAT_0048f6d0;
    do {
        const char* sub = *fr.u24.nm;
        FUN_00267760(fr.buf, 0x80, "CollActor%sJoint", sub);
        fr.u1c.js = 0;
        props->FUN_0027aac0(fr.buf, &fr.u1c.js);
        if (fr.u1c.js)
            FUN_00267760(fr.x14.namep, 0x20, "%s", fr.u1c.js);
        if (p8 && (fr.u34.finder = p8->v11()->finder) != 0) {
            unsigned __int64 h = FUN_002672f0(fr.x14.namep, 0, 0);
            *fr.jidp = fr.u34.finder->FUN_0027b200((unsigned int)h, (unsigned int)(h >> 32));
            if (*fr.jidp < 0)
                *fr.jidp = atol(fr.x14.namep);
        } else {
            *fr.jidp = -1;
        }
        FUN_00267760(fr.buf, 0x80, "CollActor%sOffset", sub);
        props->FUN_0027ab00(fr.buf, fr.u18.offp);
        FUN_00267760(fr.buf, 0x80, "CollActor%sRadius", sub);
        props->FUN_0027aa20(fr.buf, (float*)(fr.jidp + 12));
        fr.jidp++;
        fr.x14.namep += 0x20;
        fr.u18.offp++;
        fr.u24.nm++;
    } while (fr.u24.nm < DAT_0048f6d0 + 3);
    fr.t0 = 0;
    props->FUN_0027aac0("FightRoot", &fr.t0);
    sub[0].FUN_00233f20(fr.t0);
    fr.t1 = 0;
    props->FUN_0027aac0("FightOpen", &fr.t1);
    sub[1].FUN_00233f20(fr.t1);
    fr.t2 = 0;
    props->FUN_0027aac0("FightHit", &fr.t2);
    sub[2].FUN_00233f20(fr.t2);
    fr.t3 = 0;
    props->FUN_0027aac0("FightWater", &fr.t3);
    sub[3].FUN_00233f20(fr.t3);
    fr.t4 = 0;
    props->FUN_0027aac0("FightExplosion", &fr.t4);
    sub[4].FUN_00233f20(fr.t4);
    fr.t5 = 0;
    props->FUN_0027aac0("AiScript", &fr.t5);
    sub[5].FUN_00233f20(fr.t5);
    f128 = 0.0f;
    props->FUN_0027aa20("MaxHealth", &f128);
    this->f130 = 0.0f; props->FUN_0027aa20("MaxRegen", &this->f130);
    this->f134 = 0.0f; props->FUN_0027aa20("EnterAdrenalineBoost", &this->f134);
    this->f138 = 0.0f; props->FUN_0027aa20("HealthUpgrade1", &this->f138);
    this->f13c = 0.0f; props->FUN_0027aa20("HealthUpgrade2", &this->f13c);
    this->f140 = 0.0f; props->FUN_0027aa20("HealthUpgrade3", &this->f140);
    this->f144 = 0.0f; props->FUN_0027aa20("CriticalMass", &this->f144);
    this->f148 = 0.0f; props->FUN_0027aa20("CriticalMassUpgrade1", &this->f148);
    this->f14c = 0.0f; props->FUN_0027aa20("CriticalMassUpgrade2", &this->f14c);
    this->f12c = 1.0f; props->FUN_0027aa20("StartingHealth", &this->f12c);
    this->f150 = 0.0f; props->FUN_0027aa20("HealthRegen", &this->f150);
    this->f154 = 0.0f; props->FUN_0027aa20("HealthRegenDelay", &this->f154);
    this->f158 = 0.0f; props->FUN_0027aa20("HealthRegenDelay_DmgBuffer", &this->f158);
    this->f15c = 30.0f; props->FUN_0027aa20("HealthRegenDelay_DmgBufferTick", &this->f15c);
    this->f160 = 0.0f; props->FUN_0027aa20("IncreaseOnEnterRage", &this->f160);
    this->f164 = 0.0f; props->FUN_0027aa20("DecreaseOnExitRage", &this->f164);
    this->f170 = 1.0f; props->FUN_0027aa20("RageMultiplierDamageDealt", &this->f170);
    this->f174 = 1.0f; props->FUN_0027aa20("RageMultiplierDamageReceived", &this->f174);
    this->f178 = 0.0f; props->FUN_0027aa20("RageFactorDamageDealt", &this->f178);
    this->f17c = 0.0f; props->FUN_0027aa20("RageFactorDamageReceived", &this->f17c);
    this->f180 = 0.0f; props->FUN_0027aa20("RageDecreaseRegular", &this->f180);
    this->f184 = 0.0f; props->FUN_0027aa20("RageDecreaseRage", &this->f184);
    this->f188 = 1.0f; props->FUN_0027aa20("DmgRcvMultiplierOnEnterRage", &this->f188);
    this->f18c = 0.0f; props->FUN_0027aa20("DmgRcvDurationOnEnterRage", &this->f18c);
    this->f190 = 0; props->FUN_0027a9d0("TargetPriority", &this->f190);
    this->f194.x = 0.0f; this->f194.y = 0.0f; this->f194.z = 0.0f; props->FUN_0027ab00("TargetOffset", &this->f194);
    this->f1a0 = 0.0f; props->FUN_0027aa20("TargetLOSYOffset", &this->f1a0);
    this->f1a4 = 0; props->FUN_0027a9d0("InterruptPriority", &this->f1a4);
    this->f380 = 1; props->FUN_0027a9d0("MaxNodeSize", &this->f380);
    this->f168 = 0.0f; props->FUN_0027aa20("Armor", &this->f168);
    this->f16c = 1; props->FUN_0027a9d0("GrappleReaction", &this->f16c);
    this->f1a8 = 0.0f; props->FUN_0027aa20("InterruptAccumulatorMax", &this->f1a8);
    this->f1ac = 0.0f; props->FUN_0027aa20("InterruptAccumulatorRate", &this->f1ac);
    fr.sal = 0;
    props->FUN_0027aac0("Alignment", &fr.sal);
    if (fr.sal) {
        for (int i = 0; i < 4; i++) {
            if (strcmp(fr.sal, DAT_0048f6a4[i]) == 0) {
                f1b0 = i;
                break;
            }
        }
    }
    if (!(DAT_004dc358 & 1)) {
        DAT_004dc358 |= 1;
        DAT_004dc350.FUN_0027af00();
        _atexit(FUN_00363bc0);
    }
    for (int i = 1; i <= 14; i++) {
        fr.def = -1.0f;
        FUN_00267760(fr.nbuf, 0x20, "Attack%d", i);
        DAT_004dc350.FUN_0027b040(fr.nbuf);
        props->FUN_0027aa20(fr.nbuf, &fr.def);
        fr.u34.tmp.FUN_0027af10(DAT_004dc350);
        FUN_00044820(&fr.u34.tmp, fr.def);
        fr.u34.tmp.FUN_0027af50();
    }
    for (int i = 0; i < 8; i++) {
        Attach_464c0* ap = &attach[i];
        FUN_00267760(fr.buf, 0x80, "AttachProp%d", i);
        fr.u1c.ps = 0;
        props->FUN_0027aac0(fr.buf, &fr.u1c.ps);
        if (fr.u1c.ps) {
            unsigned __int64 h = FUN_002672f0(fr.u1c.ps, 0, 0);
            if (h != 0) {
                content::LoadInventory::DynamicCaster<CSPHulkProp>* caster =
                    new (fr.u34.caster) content::LoadInventory::DynamicCaster<CSPHulkProp>;
                Obj_464c0* r = fr.u20.inv->f3(caster, (unsigned int)h, (unsigned int)(h >> 32));
                if (r) {
                    r->v0();
                    if (ap->r)
                        ap->r->v1();
                    ap->r = r;
                    FUN_00267760(fr.buf, 0x80, "AttachProp%dJoint", i);
                    fr.u24.js2 = 0;
                    props->FUN_0027aac0(fr.buf, &fr.u24.js2);
                    if (fr.u24.js2) {
                        unsigned __int64 jh = FUN_002672f0(fr.u24.js2, 0, 0);
                        ap->jlo = (unsigned int)jh;
                        ap->jhi = (unsigned int)(jh >> 32);
                    }
                    FUN_00267760(fr.buf, 0x80, "AttachProp%dOffset", i);
                    props->FUN_0027ab00(fr.buf, &ap->off);
                    FUN_00267760(fr.buf, 0x80, "AttachProp%dOrientation", i);
                    props->FUN_0027ab00(fr.buf, &ap->ori);
                    ap->ori.x = ap->ori.x * 0.017453292f;
                    ap->ori.y = ap->ori.y * 0.017453292f;
                    ap->ori.z = ap->ori.z * 0.017453292f;
                }
            }
        }
    }
    this->b2f8 = props->FUN_0027aa20("CSMRadius", &this->f2fc);
    this->f300.x = 0.0f; this->f300.y = 0.0f; this->f300.z = 0.0f; props->FUN_0027ab00("CSMOffset", &this->f300);
    this->f30c = 1.0f; props->FUN_0027aa20("GlobalMultiplierDamageDealt", &this->f30c);
    this->f310 = 1.0f; props->FUN_0027aa20("GlobalMultiplierDamageReceived", &this->f310);
    this->f314 = 1.0f; props->FUN_0027aa20("MultDamageReceived_Easy", &this->f314);
    this->f318 = 1.0f; props->FUN_0027aa20("MultDamageReceived_Normal", &this->f318);
    this->f31c = 1.0f; props->FUN_0027aa20("MultDamageReceived_Hard", &this->f31c);
    this->f320 = 0.5f; props->FUN_0027aa20("GrappleStruggleChance", &this->f320);
    this->f324 = 5.0f; props->FUN_0027aa20("GrappleMinFrequency", &this->f324);
    this->f328 = 5.0f; props->FUN_0027aa20("GrappleMaxFrequency", &this->f328);
    this->f32c = 0.0f; props->FUN_0027aa20("DesiredMinEngage", &this->f32c);
    this->f330 = 0.0f; props->FUN_0027aa20("DesiredMaxEngage", &this->f330);
    this->f334 = 0.0f; props->FUN_0027aa20("AbsoluteMinEngage", &this->f334);
    this->f338 = 0.0f; props->FUN_0027aa20("AbsoluteMaxEngage", &this->f338);
    this->f33c = 0.0f; props->FUN_0027aa20("MaxAttack", &this->f33c);
    this->f340 = 0.0f; props->FUN_0027aa20("HearingRadius", &this->f340);
    this->f344 = 0.0f; props->FUN_0027aa20("Noisiness", &this->f344);
    this->f348 = 0.0f; props->FUN_0027aa20("SightRadius", &this->f348);
    this->f34c = 0.0f; props->FUN_0027aa20("SightFOV", &this->f34c);
    this->f350 = 0.0f; props->FUN_0027aa20("CautionThreshold", &this->f350);
    this->f354 = 0.0f; props->FUN_0027aa20("PanicThreshold", &this->f354);
    this->f358 = 0.0f; props->FUN_0027aa20("RageThreshold", &this->f358);
    this->f35c = 0.0f; props->FUN_0027aa20("DodgingSkill", &this->f35c);
    this->f360 = 0.0f; props->FUN_0027aa20("MinAttackPeriod", &this->f360);
    this->f364 = 0.0f; props->FUN_0027aa20("MinTauntPeriod", &this->f364);
    this->f368 = 0.0f; props->FUN_0027aa20("MinAttackPause", &this->f368);
    this->f36c = 0.0f; props->FUN_0027aa20("MaxAttackPause", &this->f36c);
    this->f370 = 1.0f; props->FUN_0027aa20("TargetPerceptionLag", &this->f370);
    this->f374 = 4.0f; props->FUN_0027aa20("ChasePersistenceTime", &this->f374);
    this->f378 = 8.0f; props->FUN_0027aa20("SuspiciousTime", &this->f378);
    fr.u1 = 0;
    props->FUN_0027a9d0("NoGolem", &fr.u1);
    b37c = (fr.u1 != 0);
    fr.u2 = 0;
    props->FUN_0027a9d0("FightingNPCMode", &fr.u2);
    b37d = (fr.u2 != 0);
    fr.u3 = 0;
    props->FUN_0027a9d0("SuckInProp", &fr.u3);
    b37e = (fr.u3 != 0);
    fr.u4 = 0;
    props->FUN_0027a9d0("GroupManaged", &fr.u4);
    b37f = (fr.u4 != 0);
    fr.u5 = 0;
    props->FUN_0027a9d0("IgnoreFriendlyFire", &fr.u5);
    b384 = (fr.u5 != 0);
    f388 = 1.0f;
    props->FUN_0027aa20("SpeedSleepwalking", &f388);
    fr.u7 = 0;
    props->FUN_0027a9d0("RangedAgent", &fr.u7);
    b38c = (fr.u7 != 0);
    fr.u8 = 0;
    props->FUN_0027a9d0("Hand2HandAgent", &fr.u8);
    b38d = (fr.u8 != 0);
    fr.u9 = 0;
    props->FUN_0027a9d0("ChaseAgent", &fr.u9);
    b38e = (fr.u9 != 0);
    fr.u10 = 0;
    props->FUN_0027a9d0("PathGraphAgent", &fr.u10);
    b38f = (fr.u10 != 0);
    fr.u11 = 0;
    props->FUN_0027a9d0("OccupationAgent", &fr.u11);
    b390 = (fr.u11 != 0);
    this->f394 = 0.0f; props->FUN_0027aa20("WeaponDesiredMinEngage", &this->f394);
    this->f398 = 0.0f; props->FUN_0027aa20("WeaponDesiredMaxEngage", &this->f398);
    this->f39c = 0.0f; props->FUN_0027aa20("WeaponRangeMin", &this->f39c);
    this->f3a0 = 0.0f; props->FUN_0027aa20("WeaponRangeMax", &this->f3a0);
    this->f3a4 = 0.0f; props->FUN_0027aa20("WeaponBurstRounds", &this->f3a4);
    this->f3a8 = 0.0f; props->FUN_0027aa20("WeaponTimeBetweenBursts", &this->f3a8);
    this->f3ac = 0.0f; props->FUN_0027aa20("WeaponRateOfFire", &this->f3ac);
    this->f438 = 0.400000006f; props->FUN_0027aa20("AvoidTolerance", &this->f438);
    this->f43c = 12.0f; props->FUN_0027aa20("AvoidRadius", &this->f43c);
    this->f440 = 0.0f; props->FUN_0027aa20("AvoidSpeed", &this->f440);
    this->f450 = 0.0f; props->FUN_0027aa20("SemaphoreTimeout", &this->f450);
    fr.u12 = 0;
    props->FUN_0027a9d0("AlwaysPriority", &fr.u12);
    b454 = (fr.u12 != 0);
    f444 = 0.0f;
    props->FUN_0027aa20("ShotFailsMin", &f444);
    this->f448 = 0.0f; props->FUN_0027aa20("ShotFailsMax", &this->f448);
    this->f44c = 0; props->FUN_0027a9d0("ShotFailsCount", &this->f44c);
    this->f458 = 1.0f; props->FUN_0027aa20("DamageMultiplier", &this->f458);
    this->f45c = 1.0f; props->FUN_0027aa20("HitReactionDamageMultiplier", &this->f45c);
    this->f460 = -1.0f; props->FUN_0027aa20("PatrolPathBreakOffHealth", &this->f460);
    this->f464 = -1.0f; props->FUN_0027aa20("PatrolPathBreakOffDistance", &this->f464);
    this->f468 = -1.0f; props->FUN_0027aa20("PatrolPathBreakOffReset", &this->f468);
    this->f470 = 20.0f; props->FUN_0027aa20("DefendResetRate", &this->f470);
    fr.u13 = 0;
    props->FUN_0027a9d0("UsesRandomWaitSystem", &fr.u13);
    b474 = (fr.u13 != 0);
    fr.u14 = 0;
    props->FUN_0027a9d0("SPCVsSPCCollision", &fr.u14);
    b475 = (fr.u14 != 0);
    this->f478 = 65.0f; props->FUN_0027aa20("PivotThresholdHalf", &this->f478);
    this->f47c = 165.0f; props->FUN_0027aa20("PivotThresholdFull", &this->f47c);
    Scope_464c0* sc = FUN_001d4c90();
    if (sc->FUN_001d2ba0("constants", 1, 0)) {
        if (sc->FUN_001d2ba0("actors", 0, 0)) {
            float* pf = &f128;
            if (sc->FUN_001d2ba0(name3f0, 0, 0)) {
                fr.u20.m = 1.0f;
                if (sc->FUN_001d2d40("MaxHealthMultiplier", &fr.u20.m))
                    *pf = fr.u20.m * *pf;
                sc->FUN_001d19d0(1);
            }
            if (sc->FUN_001d2ba0(DAT_0048f6a4[f1b0], 0, 1)) {
                fr.u20.m = 1.0f;
                if (sc->FUN_001d2d40("MaxHealthMultiplier", &fr.u20.m))
                    *pf = fr.u20.m * *pf;
                sc->FUN_001d19d0(1);
            }
            sc->FUN_001d19d0(1);
        }
        sc->FUN_001d19d0(1);
    }
    __security_check_cookie(fr.cookie);
    return true;
}
