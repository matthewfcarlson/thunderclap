#include "gen/owners.h"
typedef unsigned int size_t;
extern "C" void* FUN_0008d690(unsigned int);
inline void* operator new(size_t n) throw() {
    return FUN_0008d690(n);
}
class Owner;
class Registry_302e0 {
  public:
    void FUN_000302e0(const char* a1, Owner* a2, void (*a3)());
};
class Closure2_302e0 {
    char pad[0x24];

  public:
    Closure2_302e0(const char*, Owner*, void (*)()) throw();
};
void Registry_302e0::FUN_000302e0(const char* a1, Owner* a2, void (*a3)()) {
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)(new Closure2_302e0(a1, a2, a3)));
}