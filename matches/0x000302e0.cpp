#include "compat/ptr.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/owners.h"
extern "C" void* FUN_0008d690(unsigned int);
inline void* operator new(hulk_uintptr n) throw() {
    return FUN_0008d690((unsigned int)n);
}
class Owner {};  // complete before the pointer-to-member: single-inheritance (one code pointer) representation
typedef void (Owner::*Fn_302e0)(const char*, int);
class Registry_302e0 {
  public:
    void FUN_000302e0(const char* a1, Owner* a2, Fn_302e0 a3);
};
class Closure2_302e0 : public ScriptClosureView {
  public:

    Closure2_302e0(const char*, Owner*, Fn_302e0) throw();
};
void Registry_302e0::FUN_000302e0(const char* a1, Owner* a2, Fn_302e0 a3) {
    HULK_SIZE32(Closure2_302e0, 0x24);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)(new Closure2_302e0(a1, a2, a3)));
}