#include "compat/ptr.h"
extern "C" char DAT_0042d90c[];
class Calls {
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
    ((Calls*)this)->Base();
    vftable = (void*)((hulk_intptr)DAT_0042d90c);
    half = 0x3f000000;
    ((Calls*)((char*)this + 0x48))->Second(arg, &arg);
    owner = this;
    return this;
}