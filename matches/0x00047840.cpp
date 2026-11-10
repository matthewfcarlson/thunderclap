#include "compat/ptr.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/owners.h"
void* operator new(hulk_uintptr) throw();
class Owner {};  // complete before the pointer-to-member: single-inheritance (one code pointer) representation
typedef void (Owner::*Fn_47840)(const char*);
class Closure1_47840 : public ScriptClosureView {
  public:

    Closure1_47840(const char*, Owner*, Fn_47840) throw();
};
class Registry_47840 {
  public:
    void FUN_00047840(const char* a1, Owner* a2, Fn_47840 a3);
};
void Registry_47840::FUN_00047840(const char* a1, Owner* a2, Fn_47840 a3) {
    HULK_SIZE32(Closure1_47840, 0x24);
    Closure1_47840* e = new Closure1_47840(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)(Closure1_47840 *)e);
}