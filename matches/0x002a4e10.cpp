#include "compat/ptr.h"
extern "C" char DAT_0042d90c[];
class DrawableContainer_2a4e10 {
  public:
    void Base();
    void Second(unsigned int, unsigned int*);
};
class DrawableContainer {
  public:
    void* vftable;
    char pad[0x3c];
    unsigned int half;
    void* owner;
    void* Init(unsigned int arg);
};
void* DrawableContainer::Init(unsigned int arg) {
    ((DrawableContainer_2a4e10*)this)->Base();
    vftable = (void*)((hulk_intptr)DAT_0042d90c);
    half = 0x3f000000;
    ((DrawableContainer_2a4e10*)((char*)this + 0x48))->Second(arg, &arg);
    owner = this;
    return this;
}