#include "compat/ptr.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/owners.h"
void* __cdecl operator new(hulk_uintptr) throw();
class Owner {};  // complete before the pointer-to-member: single-inheritance (one code pointer) representation
typedef void (Owner::*Fn_305f0)(const char*, bool);
class Registry_305f0 {
  public:
    void FUN_000305f0(const char* a1, Owner* a2, Fn_305f0 a3);
};
class Closure2_305f0 : public ScriptClosureView {
  public:

    Closure2_305f0(const char*, Owner*, Fn_305f0) throw();
};
void Registry_305f0::FUN_000305f0(const char* a1, Owner* a2, Fn_305f0 a3) {
    HULK_SIZE32(Closure2_305f0, 0x24);
    Closure2_305f0* e = new Closure2_305f0(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}