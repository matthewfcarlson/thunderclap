#include "gen/owners.h"
void* operator new(unsigned int) throw();
class Owner;
class Registry_31050 {
  public:
    void FUN_00031050(const char* a1, Owner* a2, void (*a3)());
};
class Closure1_31050 {
  public:
    char pad[0x24];
    Closure1_31050(const char*, Owner*, void (*)()) throw();
};
void Registry_31050::FUN_00031050(const char* a1, Owner* a2, void (*a3)()) {
    Closure1_31050* e = new Closure1_31050(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}