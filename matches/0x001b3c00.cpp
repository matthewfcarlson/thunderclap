#include "gen/owners.h"
extern "C" void* FUN_0008d690(unsigned int);
inline void* operator new(unsigned int, void* p) throw() {
    return p;
}
class Owner;
class Registry_1b3c00 {
  public:
    void FUN_001b3c00(const char*, Owner*);
};
class Function5_1b3c00 {
  public:
    Function5_1b3c00(const char*, Owner*);
    char pad[0x20];
};
void Registry_1b3c00::FUN_001b3c00(const char* a1, Owner* a2) {
    Function5_1b3c00* e = new (FUN_0008d690(0x20)) Function5_1b3c00(a1, a2);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)e);
}