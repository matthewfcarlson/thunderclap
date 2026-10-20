// STATUS: equivalent (tools/equiv.py level 3: 479 inputs, branch coverage 74/74)
// FUN_0007f950 @ 0x0007f950
#include "compat/ptr.h"
typedef unsigned int size_t;
void* operator new(size_t) throw();
inline void* operator new(size_t, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr);
char FUN_001d04d0(const void*) throw();
class CAmbientsManager;
namespace math { class Vector { public: float x, y, z; }; }
typedef float Float; typedef bool Bool; typedef int Int; typedef void Void;
typedef const char* String; typedef char* CharPtr; typedef math::Vector Vector;
typedef const math::Vector ConstMathVector;
typedef unsigned int UnsignedInt;
extern char DAT_0048e0e4, DAT_0048e0f0, DAT_0048e100, DAT_0048e10c, DAT_0048e128, DAT_0048e134, DAT_0049b95c;
#define tBool DAT_0048e0e4
#define tString DAT_0048e0f0
#define tVoid DAT_0048e100
#define tVector DAT_0048e10c
#define tConstMathVector DAT_0048e10c
#define tFloat DAT_0048e128
#define tInt DAT_0048e134
#define tUnsignedInt DAT_0049b95c
class Base { public: virtual void v(); char p[12]; char a[8]; char result; char z[3]; Base(const char*, int) throw(); };
template<class C, class R> class Method0 : public Base { public: void (*f)(); Method0(const char* n, void (*x)(), const void* r) : Base(n, 0) { f = x; result = FUN_001d04d0(r); } virtual void v(); };
template<class C, class R> class Closure0 : public Method0<C, R> { public: C* owner; Closure0(const char* n, C* o, void (*f)(), const void* r) : Method0<C, R>(n, f, r) { owner = o; } virtual void v(); };
template<class C, class R, class A1> class Method1 : public Base { public: void (*f)(); Method1(const char* n, void (*x)(), const void* r, const void* a1) : Base(n, 1) { f = x; result = FUN_001d04d0(r); a[0] = FUN_001d04d0(a1); } virtual void v(); };
template<class C, class R, class A1> class Closure1 : public Method1<C, R, A1> { public: C* owner; Closure1(const char* n, C* o, void (*f)(), const void* r, const void* a1) : Method1<C, R, A1>(n, f, r, a1) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2> class Method2 : public Base { public: void (*f)(); Method2(const char* n, void (*x)(), const void* r, const void* a1, const void* a2) : Base(n, 2) { f = x; result = FUN_001d04d0(r); a[0] = FUN_001d04d0(a1); a[1] = FUN_001d04d0(a2); } virtual void v(); };
template<class C, class R, class A1, class A2> class Closure2 : public Method2<C, R, A1, A2> { public: C* owner; Closure2(const char* n, C* o, void (*f)(), const void* r, const void* a1, const void* a2) : Method2<C, R, A1, A2>(n, f, r, a1, a2) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3> class Method3 : public Base { public: void (*f)(); Method3(const char* n, void (*x)(), const void* r, const void* a1, const void* a2, const void* a3) : Base(n, 3) { f = x; result = FUN_001d04d0(r); a[0] = FUN_001d04d0(a1); a[1] = FUN_001d04d0(a2); a[2] = FUN_001d04d0(a3); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3> class Closure3 : public Method3<C, R, A1, A2, A3> { public: C* owner; Closure3(const char* n, C* o, void (*f)(), const void* r, const void* a1, const void* a2, const void* a3) : Method3<C, R, A1, A2, A3>(n, f, r, a1, a2, a3) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4> class Method4 : public Base { public: void (*f)(); Method4(const char* n, void (*x)(), const void* r, const void* a1, const void* a2, const void* a3, const void* a4) : Base(n, 4) { f = x; result = FUN_001d04d0(r); a[0] = FUN_001d04d0(a1); a[1] = FUN_001d04d0(a2); a[2] = FUN_001d04d0(a3); a[3] = FUN_001d04d0(a4); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4 : public Method4<C, R, A1, A2, A3, A4> { public: C* owner; Closure4(const char* n, C* o, void (*f)(), const void* r, const void* a1, const void* a2, const void* a3, const void* a4) : Method4<C, R, A1, A2, A3, A4>(n, f, r, a1, a2, a3, a4) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Method5 : public Base { public: void (*f)(); Method5(const char* n, void (*x)(), const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5) : Base(n, 5) { f = x; result = FUN_001d04d0(r); a[0] = FUN_001d04d0(a1); a[1] = FUN_001d04d0(a2); a[2] = FUN_001d04d0(a3); a[3] = FUN_001d04d0(a4); a[4] = FUN_001d04d0(a5); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Closure5 : public Method5<C, R, A1, A2, A3, A4, A5> { public: C* owner; Closure5(const char* n, C* o, void (*f)(), const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5) : Method5<C, R, A1, A2, A3, A4, A5>(n, f, r, a1, a2, a3, a4, a5) { owner = o; } virtual void v(); };
class Registry { public:
    void FUN_001d3b70(const char*, void*);
};
class Entry { public:
};
Registry* FUN_001d4c90();
#define FN(b) extern void FUN_##b();
#define G0(n, b, R) { FN(b) r->FUN_001d3b70(n, new Closure0<CAmbientsManager, R>(n, this, FUN_##b, &t##R)); }
#define G1(n, b, R, A1) { FN(b) r->FUN_001d3b70(n, new Closure1<CAmbientsManager, R, A1>(n, this, FUN_##b, &t##R, &t##A1)); }
#define G2(n, b, R, A1, A2) { FN(b) r->FUN_001d3b70(n, new Closure2<CAmbientsManager, R, A1, A2>(n, this, FUN_##b, &t##R, &t##A1, &t##A2)); }
#define G3(n, b, R, A1, A2, A3) { FN(b) r->FUN_001d3b70(n, new Closure3<CAmbientsManager, R, A1, A2, A3>(n, this, FUN_##b, &t##R, &t##A1, &t##A2, &t##A3)); }
#define G4(n, b, R, A1, A2, A3, A4) { FN(b) r->FUN_001d3b70(n, new Closure4<CAmbientsManager, R, A1, A2, A3, A4>(n, this, FUN_##b, &t##R, &t##A1, &t##A2, &t##A3, &t##A4)); }
#define G5(n, b, R, A1, A2, A3, A4, A5) { FN(b) r->FUN_001d3b70(n, new Closure5<CAmbientsManager, R, A1, A2, A3, A4, A5>(n, this, FUN_##b, &t##R, &t##A1, &t##A2, &t##A3, &t##A4, &t##A5)); }

class Link16 { public: char b[16]; void FUN_0027af00(); };
class Link8 { public: char b[8]; void FUN_0027af00(); };
struct Slot8 { char pad0[2]; char b2; char b3; char pad4[4]; };

class CAmbientsManager {
public:
    CAmbientsManager();
    virtual void v0();
    char pad04[4];
    Slot8 slots[0x320];
    char pad1908[0x18];
    char tab[0x1b88];
    Link16 links1[10];
    int i3548;
    int z354c[20];
    int i359c;
    Link8 links2[0x14];
    int i3640;
    float f3644;
    float f3648;
    char c364c;
    char pad364d[3];
    Link16 links3[10];
    char pad36f0[0x50];
    int i3740;
    int i3744;
    int i3748;
    int z374c[20];
    int i379c;
    int i37a0;
    float f37a4;
    float f37a8;
    int z37ac[20];
    int i37fc;
    int z3800[10];
    int i3828, i382c, i3830;
};

CAmbientsManager::CAmbientsManager() {
    int i, k;
    for (i = 0; i < 10; i++)
        links1[i].FUN_0027af00();
    i3548 = 0;
    i359c = 0;
    for (i = 0; i < 0x14; i++)
        links2[i].FUN_0027af00();
    i3640 = 0;
    f3644 = 1.0f;
    f3648 = 1.5f;
    c364c = 0;
    for (i = 0; i < 10; i++)
        links3[i].FUN_0027af00();
    i3740 = 0;
    i3744 = 1;
    i3748 = 0;
    i379c = 0;
    i37a0 = 0;
    f37a4 = 5.0f;
    f37a8 = 10.0f;
    i37fc = 0;
    i3828 = 0;
    i382c = 0;
    i3830 = 0;
    for (i = 0; i < 0x320; i++) {
        slots[i].b3 = 0;
        slots[i].b2 = 0;
    }
    {
        char* p = tab + 0x28;
        for (k = 0; k < 7; k++) {
            *(int*)(p - 0x28) = 0;
            for (i = 0; i < 14; i++) {
                *p = 0;
                p += 0x48;
            }
        }
    }
    {
        char* p = tab + 0x3495 - 0x1920;
        for (i = 0; i < 7; i++) {
            p[-1] = 0;
            *p = 0;
            p += 2;
        }
    }
    for (i = 0; i < 20; i++) z354c[i] = 0;
    for (i = 0; i < 10; i++) z3800[i] = 0;
    for (i = 0; i < 20; i++) z374c[i] = 0;
    for (i = 0; i < 20; i++) z37ac[i] = 0;
    for (i = 0; i < 10; i++) {
        int j;
        for (j = 0; j < 4; j++) *(int*)(links1[i].b + j * 4) = 0;
    }
    Registry* r = FUN_001d4c90();
    if (r) {
G5("amb_CreateCivilian", 0007f450, Void, String, Int, Bool, Vector, Vector)
G2("amb_SetCivilianPersistent", 0007d640, Void, String, Bool)
G0("amb_ClearCivilianModels", 00079290, Void)
G3("amb_AddCivilianModel", 000792a0, Void, String, Int, Bool)
G0("amb_ClearPatrolPaths", 00079310, Void)
G1("amb_AddPatrolPath", 00079320, Void, String)
G1("amb_SetMaxActiveCivilianCount", 00079370, Void, Int)
G1("amb_SetAllowedCharacterCount", 00079390, Void, Int)
G1("amb_SetMinDistanceBetweenCivilians", 000793a0, Void, Float)
G2("amb_SetCivilianSpawnRadii", 000793c0, Void, Float, Float)
G2("amb_SetCivilianPanicRadii", 00079400, Void, Float, Float)
G0("amb_RemoveAllCivilians", 0007b480, Void)
G1("amb_SetCiviliansIgnoreHulk", 00078d00, Void, Bool)
G1("amb_AddCattleRoom", 0007ab60, Void, Int)
G2("amb_SetCowSpawnStrata", 0007aba0, Void, Float, Float)
G1("amb_SetMaxActiveCattleCount", 0007abc0, Void, Int)
G4("amb_CreateCow", 0007de00, Void, String, Int, ConstMathVector, ConstMathVector)
G1("amb_SetMaxActiveVehicleCount", 00079420, Void, Int)
G1("amb_SetMaxTotalVehicleCount", 00079440, Void, Int)
G0("amb_ClearVehicleTypes", 000788e0, Void)
G3("amb_AddVehicleType", 000794a0, Void, String, UnsignedInt, Float)
G1("amb_SetVehiclePerceptionRadius", 00079550, Void, Float)
G1("amb_SetVehiclePanicRadius", 000795a0, Void, Float)
G1("amb_SetVehiclePanicAcceleration", 000795f0, Void, Float)
G2("amb_SetVehicleSpeed", 0007d680, Void, String, Float)
G1("amb_SetAllVehicleSpeeds", 00079660, Void, Float)
G2("amb_SetVehicleSpeedRange", 00079640, Void, Float, Float)
G2("amb_VaryVehicleSpeed", 0007d6c0, Void, String, Float)
G1("amb_VaryAllVehicleSpeeds", 000796a0, Void, Float)
    }
}
