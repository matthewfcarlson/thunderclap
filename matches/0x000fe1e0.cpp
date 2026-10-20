#include "compat/ptr.h"
extern int golemVtable;
extern int memoryVtable;
extern int refVtable_fe1e0;
class IRefCount {
  public:
    virtual void f0();
    virtual void Release();
};
class CGolem {
  public:
    hulk_intptr vf;
    char pad04[8];
    IRefCount* items[16];
    char pad4c[12];
    hulk_intptr memory;
    void destroy();
};
void CGolem::destroy() {
    int i;
    vf = (hulk_intptr)&golemVtable;
    for (i = 0; i < 16; ++i) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
    }
    memory = (hulk_intptr)&memoryVtable;
    vf = (hulk_intptr)&refVtable_fe1e0;
}