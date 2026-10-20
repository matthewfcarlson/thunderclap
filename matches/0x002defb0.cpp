#include "compat/ptr.h"
void* __cdecl alloc(hulk_uintptr);
class Buffer {
  public:
    Buffer(int);
    virtual void v();
};
class ShadowSkin : public Buffer {
  public:
    ShadowSkin();
    virtual void v();
    void set(int, void*);
};
class Block {
  public:
    void* get();
};
ShadowSkin::ShadowSkin() : Buffer(1) {
    Block* b = (Block*)alloc(0x80);
    set(0, b ? b->get() : 0);
}