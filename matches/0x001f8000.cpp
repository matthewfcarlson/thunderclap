#include "compat/ptr.h"
void* FUN_0008d690(hulk_uintptr) throw();
class Owner;
class Entry_1f8000 {
  public:
    static void* operator new(unsigned int n) throw() { return FUN_0008d690(n); }
    Entry_1f8000(const char*, Owner*, void (*)()) throw();
    char pad[0x24];
};
class Registry_1f8000 {
  public:
    void FUN_001d3b70(const char*, Entry_1f8000*);
    void FUN_001f8000(const char* a1, Owner* a2, void (*a3)());
};
void Registry_1f8000::FUN_001f8000(const char* a1, Owner* a2, void (*a3)()) {
    Entry_1f8000* e = new Entry_1f8000(a1, a2, a3);
    FUN_001d3b70(a1, e);
}