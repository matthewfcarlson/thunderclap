// STATUS: equivalent (tools/equiv.py level 3: 485 inputs, branch coverage 66/66)
// FUN_00200c10 @ 0x00200c10
#include "compat/ptr.h"
typedef unsigned int size_t;
void* operator new(size_t) throw();
inline void* operator new(size_t, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr);
char FUN_001d04d0(const void*) throw();
class CTriggerVolumeManager;
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
    void FUN_002006f0(const char*, CTriggerVolumeManager*, void (*)());
    void FUN_002007b0(const char*, CTriggerVolumeManager*, void (*)());
    void FUN_00200950(const char*, CTriggerVolumeManager*, void (*)());
    void FUN_00200a00(const char*, CTriggerVolumeManager*, void (*)());
    void FUN_00200ab0(const char*, CTriggerVolumeManager*, void (*)());
    void FUN_00200b10(const char*, CTriggerVolumeManager*, void (*)());
};
class Entry { public:
    void* FUN_001ffb00(const char*, CTriggerVolumeManager*, void (*)());
    void* FUN_001ffbc0(const char*, CTriggerVolumeManager*, void (*)());
    void* FUN_001ffe70(const char*, CTriggerVolumeManager*, void (*)());
    void* FUN_001fffa0(const char*, CTriggerVolumeManager*, void (*)());
    void* FUN_00200050(const char*, CTriggerVolumeManager*, void (*)());
    void* FUN_00200190(const char*, CTriggerVolumeManager*, void (*)());
};
Registry* FUN_001d4c90();
#define FN(b) extern void FUN_##b();
#define G1(n, b, R, A1) { FN(b) r->FUN_001d3b70(n, new Closure1<CTriggerVolumeManager, R, A1>(n, this, FUN_##b, &t##R, &t##A1)); }
#define E(n, c, b) { FN(b) Entry* e = (Entry*)FUN_0008d690(0x24); void* x = 0; if (e) x = e->FUN_##c(n, this, FUN_##b); r->FUN_001d3b70(n, x); }
#define O(n, c, b) { FN(b) r->FUN_##c(n, this, FUN_##b); }

class CTriggerVolumeManager {
public:
    void Register(int a);
    int i0;
    int i4;
};

void CTriggerVolumeManager::Register(int a) {
    i4 = a;
    Registry* r = FUN_001d4c90();
    if (r) {
G1("tvm_GetLocatorPosition", 001fd7d0, Vector, String)
G1("tvm_GetLocatorOrientation", 001fd830, Float, String)
E("tvm_SetLocatorPosition", 001ffb00, 001fd870)
E("tvm_SetLocatorOrientation", 001ffbc0, 001fd8b0)
G1("tvm_DoesLocatorExist", 001fd7a0, Bool, String)
O("tvm_GetLocatorCount", 002006f0, 001fc480)
G1("tvm_GetLocatorName", 001fc9a0, String, Int)
G1("tvm_DoesTriggerVolumeExist", 001fc9d0, Bool, String)
G1("tvm_GetTriggerVolumeMinPosition", 001fc9f0, Vector, String)
G1("tvm_GetTriggerVolumeMaxPosition", 001fca40, Vector, String)
G1("tvm_GetTriggerVolumeOrientation", 001fca90, Float, String)
E("tvm_SetTriggerVolumeOrientation", 001ffbc0, 001fcab0)
O("tvm_SetTriggerVolume", 002007b0, 001fcb30)
G1("tvm_IsTriggerVolumeEnabled", 001fcb70, Bool, String)
G1("tvm_IsNPCAvoidTriggerVolume", 001fcb90, Bool, String)
E("tvm_SetNPCAvoidTriggerVolume", 001ffe70, 001fcbc0)
G1("tvm_DisableTriggerVolume", 001fcc40, Void, String)
G1("tvm_EnableTriggerVolume", 001fcc60, Void, String)
G1("tvm_IsTriggerVolumeEmpty", 001fcbe0, Bool, String)
E("tvm_IsActorInTriggerVolume", 001fffa0, 001fcc00)
G1("tvm_IsLocatorInCameraView", 001fd8f0, Bool, String)
E("tvm_KillPropsInTriggerVolume", 001ffe70, 001fcc80)
E("tvm_DamageAllActorsInTriggerVolume", 00200050, 001fcdb0)
O("tvm_IsVectorInTriggerVolume", 00200950, 001fce50)
G1("tvm_CreateEncounterGenerator", 001fd9a0, Bool, String)
E("tvm_AddCharacterToEncounterGenerator", 001fffa0, 001fdc90)
G1("tvm_DeleteEncounterGenerator", 001fdfc0, Bool, String)
E("tvm_SetEncounterGeneratorEnabled", 00200190, 001fdeb0)
G1("tvm_IsEncounterGeneratorEnabled", 001fdf10, Bool, String)
O("tvm_SetEncounterCharacterEnabled", 00200a00, 001fdf50)
G1("tvm_GetEncounterGeneratorCharacterTypeCount", 001fdf90, Int, String)
O("tvm_DamagePropsInTriggerVolume", 00200ab0, 001fd920)
G1("tvm_GetNumPropsInTriggerVolume", 001fd980, Int, String)
G1("tvm_GetPropInTriggerVolume", 001fccb0, String, Int)
O("tvm_GetStreamedLocatorName", 00200b10, 001ff950)
G1("tvm_GetNearestLocator", 001fe280, String, String)
G1("tvm_SetSpawnDistanceOffCamera", 001fd4c0, Void, Float)
G1("tvm_SetSpawnDistanceOnCamera", 001fd4d0, Void, Float)
    }
}
