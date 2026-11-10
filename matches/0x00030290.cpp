#include "compat/ptr.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/owners.h"
void* operator new(hulk_uintptr) throw();
class Owner {};  // complete before the pointer-to-member: single-inheritance (one code pointer) representation
typedef void (Owner::*Fn_30290)(const char*, float);
class Registry_30290 {
  public:
    void FUN_00030290(const char* a1, Owner* a2, Fn_30290 a3);
};
class Closure2_30290 : public ScriptClosureView {
  public:
    Closure2_30290(const char*, Owner*, Fn_30290) throw();
};
void Registry_30290::FUN_00030290(const char* a1, Owner* a2, Fn_30290 a3) {
    HULK_SIZE32(Closure2_30290, 0x24);
    Closure2_30290* e = new Closure2_30290(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}