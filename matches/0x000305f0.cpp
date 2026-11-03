#include "gen/owners.h"
void* __cdecl operator new(unsigned int) throw();
class Owner;
class Registry_305f0 {
  public:
    void FUN_000305f0(const char* a1, Owner* a2, void (*a3)());
};
class Closure2_305f0 {
    char pad[0x24];

  public:
    Closure2_305f0(const char*, Owner*, void (*)()) throw();
};
void Registry_305f0::FUN_000305f0(const char* a1, Owner* a2, void (*a3)()) {
    Closure2_305f0* e = new Closure2_305f0(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}