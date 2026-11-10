#include "compat/ptr.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/owners.h"
void* operator new(hulk_uintptr) throw();
class Owner {};  // complete before the pointer-to-member: single-inheritance (one code pointer) representation
typedef void (Owner::*Fn_311b0)(bool);
class Closure1_311b0 : public ScriptClosureView {
  public:

    Closure1_311b0(const char*, Owner*, Fn_311b0) throw();
};
class Registry_311b0 {
  public:
    void FUN_000311b0(const char* a1, Owner* a2, Fn_311b0 a3);
};
void Registry_311b0::FUN_000311b0(const char* a1, Owner* a2, Fn_311b0 a3) {
    HULK_SIZE32(Closure1_311b0, 0x24);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)(new Closure1_311b0(a1, a2, a3)));
}