// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_001b3c50 @ 0x001b3c50
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
extern "C" void* __cdecl FUN_001d4c90();
extern "C" const char DAT_0048e100[];
extern "C" const char DAT_0048e10c[];
extern "C" const char DAT_0048e134[];
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }

namespace math {
class Vector;
}

template <class T> struct TypeName;
template <> struct TypeName<void> { static const char* get() { return DAT_0048e100; } };
template <> struct TypeName<int> { static const char* get() { return DAT_0048e134; } };
template <> struct TypeName<math::Vector> { static const char* get() { return DAT_0048e10c; } };

// Function's fields (include/decls/data/script.h) after the vftable.
class __declspec(novtable) Function : public ScriptFunctionFields {
  public:
    virtual void f0();
    virtual void f1();
    void FUN_001d0480(const char*, int);
    Function(const char* n, int k) { FUN_001d0480(n, k); }
};

template <class R, class A, class B>
class Function2 : public Function {
  public:
    typedef R (__cdecl *Fn)(A, B);
    Function2(const char* name, Fn f) : Function(name, 2) {
        fn = f;
        retType = FUN_001d04d0(TypeName<R>::get());
        argTypes[0] = FUN_001d04d0(TypeName<A>::get());
        argTypes[1] = FUN_001d04d0(TypeName<B>::get());
    }
    Fn fn;
};

struct Registry_1b3c50 { void FUN_001d3b70(const char*, void*); };

// Function4 / Function5 (matches/0x001b3810.cpp, 0x001b38b0.cpp): Function's fields, then the bound free function
// (its type is the game's Function<N> instantiation; 0x00086fa0's Invoke calls it __cdecl).
struct Function4_1b3c50 { void* vftable; ScriptFunctionFields f; void (__cdecl* fn)(int, const char*, const char*, float); Function4_1b3c50* FUN_001b3810(const char*, void (__cdecl*)(int, const char*, const char*, float)); };
struct Function5_1b3c50 { void* vftable; ScriptFunctionFields f; void (__cdecl* fn)(int, int, float, float, float); Function5_1b3c50* FUN_001b38b0(const char*, void (__cdecl*)(int, int, float, float, float)); };

void __cdecl FUN_001b3360(int, const char*, const char*, float);
void __cdecl FUN_001b33d0(int, int, float, float, float);
void __cdecl FUN_001b3320(int, math::Vector);

/* 180-byte records starting at 0x4e1830; this view starts at each record's +0x40 byte. */
struct ProfileTail {
    char active;
    char pad01[0x3f];
    float v[13];
};
extern char DAT_004e1870[];
extern char DAT_004e2194[];

extern "C" void FUN_001b3c50()
{
    ProfileTail* e = (ProfileTail*)DAT_004e1870;
    do {
        e->v[12] = 20.0f;
        e->v[0] = 4.0f;
        e->v[4] = 8000.0f;
        e->v[8] = 10.0f;
        e->v[1] = 10.0f;
        e->v[5] = 5000.0f;
        e->v[9] = 50.0f;
        e->v[2] = 15.0f;
        e->v[6] = 2000.0f;
        e->v[10] = 2.0f;
        e->v[3] = 20.0f;
        e->v[7] = 0.0f;
        e->v[11] = 0.0f;
        ((char*)e)[-0x40] = 0; /* record +0x00: enabled */
        e->active = 0;
        e = (ProfileTail*)((char*)e + 0xb4);
    } while ((char*)e < DAT_004e2194);

    Registry_1b3c50* reg = (Registry_1b3c50*)FUN_001d4c90();
    if (reg) {
        typedef Function2<void, int, math::Vector> FunctionIV;
        HULK_SIZE32(FunctionIV, 0x20);
        void* mem = FUN_0008d690((int)sizeof(FunctionIV));
        Function2<void, int, math::Vector>* trigger = 0;
        if (mem)
            trigger = new (mem) Function2<void, int, math::Vector>("exp_Trigger", FUN_001b3320);
        reg->FUN_001d3b70("exp_Trigger", trigger);

        HULK_SIZE32(Function4_1b3c50, 0x20);
        Function4_1b3c50* profile = (Function4_1b3c50*)FUN_0008d690((int)sizeof(Function4_1b3c50));
        if (profile)
            profile = profile->FUN_001b3810("exp_DefineProfile", FUN_001b3360);
        reg->FUN_001d3b70("exp_DefineProfile", profile);

        HULK_SIZE32(Function5_1b3c50, 0x20);
        Function5_1b3c50* damage = (Function5_1b3c50*)FUN_0008d690((int)sizeof(Function5_1b3c50));
        if (damage) {
            damage = damage->FUN_001b38b0("exp_DefineProfileDamage", FUN_001b33d0);
            reg->FUN_001d3b70("exp_DefineProfileDamage", damage);
        } else {
            reg->FUN_001d3b70("exp_DefineProfileDamage", 0);
        }
    }
}
