// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000436f0 @ 0x000436f0
#include "compat/ptr.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
void* operator new(hulk_uintptr) throw();
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int);
class Unused;
namespace math { class Vector { public: float x, y, z; }; }
typedef float Float; typedef bool Bool; typedef int Int; typedef void Void;
typedef const char* String; typedef char* CharPtr; typedef math::Vector Vector;
// The free functions bound as Function<N> (0x00086fa0's Invoke calls them __cdecl); their types are the game's
// Function7<void, int, float x6> (helper 0x0003eea0) and Function3<void, const char*, const char*, float> (0x0003efb0).
void __cdecl FUN_00044c60(int, float, float, float, float, float, float);
void __cdecl FUN_00044cb0(const char*, const char*, float);
void __cdecl FUN_000452e0(const char*, const char*, float);
class Registry { public:
    void FUN_001d3b70(const char*, void*);
};
class Entry { public:
    void* FUN_0003eea0(const char*, void (__cdecl*)(int, float, float, float, float, float, float));
    void* FUN_0003efb0(const char*, void (__cdecl*)(const char*, const char*, float));
};
Registry* FUN_001d4c90();
#define EF(n, c, b) { HULK_SIZE32(ScriptStaticFunctionView, 0x20); Entry* e = (Entry*)FUN_0008d690((unsigned int)sizeof(ScriptStaticFunctionView)); void* x = 0; if (e) x = e->FUN_##c(n, FUN_##b); r->FUN_001d3b70(n, x); }
extern "C" void FUN_000436f0() {
    Registry* r = FUN_001d4c90();
    if (r) {
EF("char_DefineForceReactionProfile", 0003eea0, 00044c60)
EF("char_SetNPCDefault", 0003efb0, 00044cb0)
EF("char_SetNPCParameter", 0003efb0, 000452e0)
    }
}
