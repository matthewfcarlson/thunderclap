#include "compat/ptr.h"
void* FUN_0008d690(hulk_uintptr);
inline void* operator new(unsigned int, void* p) throw() {
    return p;
}
class Owner;
class Registry_1cf500 {
  public:
    void FUN_001d3b70(const char*, void*);
    void FUN_001cf500(const char* a1, Owner* a2, void (*a3)());
};
class Entry_1cf500 {
  public:
    Entry_1cf500(const char*, Owner*, void (*)());
};
void Registry_1cf500::FUN_001cf500(const char* a1, Owner* a2, void (*a3)()) {
    Entry_1cf500* e = new (FUN_0008d690(0x24)) Entry_1cf500(a1, a2, a3);
    FUN_001d3b70(a1, e);
}