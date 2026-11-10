#include "compat/ptr.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/owners.h"
void* FUN_0008d690(unsigned int) throw();
namespace math { class Vector_1f8000 { public: float x, y, z; }; }
class Owner {};  // complete before the pointer-to-member: single-inheritance (one code pointer) representation
typedef bool (Owner::*Fn_1f8000)(int, math::Vector_1f8000);
class Closure2_1f8000 : public ScriptClosureView {
  public:
    static void* operator new(hulk_uintptr n) throw() { return FUN_0008d690((unsigned int)n); }
    Closure2_1f8000(const char*, Owner*, Fn_1f8000) throw();
};
class Registry_1f8000 {
  public:
    void FUN_001f8000(const char* a1, Owner* a2, Fn_1f8000 a3);
};
void Registry_1f8000::FUN_001f8000(const char* a1, Owner* a2, Fn_1f8000 a3) {
    HULK_SIZE32(Closure2_1f8000, 0x24);
    Closure2_1f8000* e = new Closure2_1f8000(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)(Closure2_1f8000 *)e);
}