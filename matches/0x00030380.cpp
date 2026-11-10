#include "compat/ptr.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/owners.h"
void* operator new(hulk_uintptr) throw();
class Owner {};  // complete before the pointer-to-member: single-inheritance (one code pointer) representation
typedef bool (Owner::*Fn_30380)(const char*);
class Registry_30380 {
  public:
    void FUN_00030380(const char* a1, Owner* a2, Fn_30380 a3);
};
class Closure1_30380 : public ScriptClosureView {
  public:

    Closure1_30380(const char*, Owner*, Fn_30380) throw();
};
void Registry_30380::FUN_00030380(const char* a1, Owner* a2, Fn_30380 a3) {
    HULK_SIZE32(Closure1_30380, 0x24);
    Closure1_30380* e = new Closure1_30380(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}