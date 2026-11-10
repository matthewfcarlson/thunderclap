#include "compat/ptr.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/owners.h"
extern "C" void* FUN_0008d690(unsigned int);
class Owner {};  // complete before the pointer-to-member: single-inheritance (one code pointer) representation
typedef void (Owner::*Fn_30860)(const char*, const char*);
class Registry_30860 {
  public:
    void FUN_00030860(const char* a1, Owner* a2, Fn_30860 a3);
};
class Closure2_30860 {
  public:
    Closure2_30860(const char*, Owner*, Fn_30860);
};
inline void* operator new(hulk_uintptr, void* p) throw() {
    return p;
}
void Registry_30860::FUN_00030860(const char* a1, Owner* a2, Fn_30860 a3) {
    HULK_SIZE32(ScriptClosureView, 0x24);
    Closure2_30860* e = new (FUN_0008d690((int)sizeof(ScriptClosureView))) Closure2_30860(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}