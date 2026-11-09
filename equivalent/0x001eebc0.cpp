// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 4/4)
// FUN_001eebc0 @ 0x001eebc0
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int);
class CSoundSimManager;
namespace math { class Vector { public: float x, y, z; }; }
typedef float Float; typedef bool Bool; typedef int Int; typedef void Void;
typedef const char* String; typedef char* CharPtr; typedef math::Vector Vector;
// Function (include/decls/data/script.h): the vftable, then Function's fields; Method<N> adds the member-function
// pointer, Closure<N> the object.
class Base : public ScriptFunctionFields { public: virtual void v(); Base(const char*, int) throw(); };
template<class C, class R, class A1, class A2, class A3, class A4> class Method4 : public Base { public: ScriptMemberFn f; Method4(const char* n, ScriptMemberFn x, const void* r, const void* a1, const void* a2, const void* a3, const void* a4) : Base(n, 4) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); argTypes[2] = FUN_001d04d0(a3); argTypes[3] = FUN_001d04d0(a4); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4 : public Method4<C, R, A1, A2, A3, A4> { public: C* owner; Closure4(const char* n, C* o, ScriptMemberFn f, const void* r, const void* a1, const void* a2, const void* a3, const void* a4) : Method4<C, R, A1, A2, A3, A4>(n, f, r, a1, a2, a3, a4) { owner = o; } virtual void v(); };
// The Method4 part is built by 0x001ede10 (below); this specialization only adds the object.
template<> class Closure4<CSoundSimManager, void, const char*, const char*, const char*, const char*> : public ScriptFunctionFields { public: virtual void v(); ScriptMemberFn fn; CSoundSimManager* owner; Closure4(CSoundSimManager* o) { owner = o; } };
class Registry { public:
    void FUN_001d3b70(const char*, void*);
};
class Entry { public:
    void* FUN_001ee4c0(const char*, CSoundSimManager*, ScriptMemberFn);
};
class Raw_001ede10 { public: void FUN_001ede10(const char*, ScriptMemberFn); };
Registry* FUN_001d4c90();
#define MF(b) reinterpret_cast<ScriptMemberFn>(&CSoundSimManager::FUN_##b)
#define M4(n, c, b, R, A1, A2, A3, A4) { typedef Closure4<CSoundSimManager, R, A1, A2, A3, A4> Closure_t; HULK_SIZE32(Closure_t, 0x24); void* m = FUN_0008d690((unsigned int)sizeof(Closure_t)); void* x = 0; if (m) { ((Raw_##c*)m)->FUN_##c(n, MF(b)); x = new (m) Closure_t(this); } r->FUN_001d3b70(n, x); }
#define E(n, c, b) { HULK_SIZE32(ScriptClosureView, 0x24); Entry* e = (Entry*)FUN_0008d690((unsigned int)sizeof(ScriptClosureView)); void* x = 0; if (e) x = e->FUN_##c(n, this, MF(b)); r->FUN_001d3b70(n, x); }

class CSoundSimManager {
public:
    // The member functions bound to Lua below.
    void FUN_001ecda0();
    void FUN_001ebd00();
    void Register();
    int i0;
};

void CSoundSimManager::Register() {
    Registry* r = FUN_001d4c90();
M4("snd_PlayFightDialogue", 001ede10, 001ecda0, Void, String, String, String, String)
E("snd_HUDEvent", 001ee4c0, 001ebd00)
}
