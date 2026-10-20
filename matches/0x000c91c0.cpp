#include "compat/ptr.h"
struct Manager {
    void Release(int);
};
struct Global {
    char pad[12];
    Manager* manager;
};
extern Global* g;
struct Entry {
    int value;
    char pad[44];
    int handle;
    char tail[4];
};
class Obj {
    char pad[0x2258];
    Entry entries[32];

  public:
    void Clear();
};
void Obj::Clear() {
    for (int i = 0; i < 32; i++) {
        Entry* e = &entries[i];
        if (i >= 0 && i < 32 && e->value && (hulk_uintptr)this + 0x2258 + i * 56 != 0) {
            g->manager->Release(e->handle);
            e->handle = -1;
            e->value = 0;
        }
    }
}