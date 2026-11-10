#include "compat/ptr.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/owners.h"
void* operator new(hulk_uintptr) throw();
class Owner {};  // complete before the pointer-to-member: single-inheritance (one code pointer) representation
typedef void (Owner::*Fn_31050)(float);
class Registry_31050 {
  public:
    void FUN_00031050(const char* a1, Owner* a2, Fn_31050 a3);
};
class Closure1_31050 : public ScriptClosureView {
  public:
    Closure1_31050(const char*, Owner*, Fn_31050) throw();
};
void Registry_31050::FUN_00031050(const char* a1, Owner* a2, Fn_31050 a3) {
    HULK_SIZE32(Closure1_31050, 0x24);
    Closure1_31050* e = new Closure1_31050(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}