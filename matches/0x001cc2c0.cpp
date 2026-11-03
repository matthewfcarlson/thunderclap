#include "gen/owners.h"
extern "C" void* FUN_0008d690(unsigned int);
inline void* operator new(unsigned int, void* p) throw() {
    return p;
}
class Owner;
class Registry_1cc2c0 {
  public:
    void FUN_001cc2c0(const char* a1, Owner* a2, void (*a3)());
};
class Closure1_1cc2c0 {
  public:
    Closure1_1cc2c0(const char*, Owner*, void (*)());
};
void Registry_1cc2c0::FUN_001cc2c0(const char* a1, Owner* a2, void (*a3)()) {
    Closure1_1cc2c0* e = new (FUN_0008d690(0x24)) Closure1_1cc2c0(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}