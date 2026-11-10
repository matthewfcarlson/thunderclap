#include "compat/ptr.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/owners.h"
void* operator new(hulk_uintptr) throw();
class Owner {};  // complete before the pointer-to-member: single-inheritance (one code pointer) representation
typedef const char* (Owner::*Fn_31000)(const char*, const char*);
class Registry_31000 {
  public:
    void FUN_00031000(const char* a1, Owner* a2, Fn_31000 a3);
};
class Closure2_31000 : public ScriptClosureView {
  public:

    Closure2_31000(const char*, Owner*, Fn_31000) throw();
};
void Registry_31000::FUN_00031000(const char* a1, Owner* a2, Fn_31000 a3) {
    HULK_SIZE32(Closure2_31000, 0x24);
    Closure2_31000* e = new Closure2_31000(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}