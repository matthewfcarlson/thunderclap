#include "compat/ptr.h"
extern int vtLoader;
extern int vtRef_2aaf10;
class Ref_2aaf10 {
  public:
    virtual void V0();
    virtual void Release();
};
class Loader_2aaf10 {
  public:
    unsigned char pad[0x14];
    unsigned int count;
    Ref_2aaf10* items[8];
    void Destroy();
};
void Loader_2aaf10::Destroy() {
    unsigned int i = 0;
    *(hulk_intptr*)this = (hulk_intptr)&vtLoader;
    while (i < count) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
        ++i;
    }
    if (items[8]) {
        items[8]->Release();
        items[8] = 0;
    }
    *(hulk_intptr*)this = (hulk_intptr)&vtRef_2aaf10;
}