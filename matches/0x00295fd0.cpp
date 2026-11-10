#include "compat/ptr.h"
extern "C" void _ReadWriteBarrier();
extern char vt[];
class LeafNode_295fd0 {
  public:
    virtual void Dummy();
    char pad[0x10 - 4];
    int m10;
    int m14;
    int m18;
    LeafNode_295fd0();
};
class DrawableNode_295fd0 : public LeafNode_295fd0 {
  public:
    DrawableNode_295fd0();
};
DrawableNode_295fd0::DrawableNode_295fd0() : LeafNode_295fd0() {
    m14 = 0;
    m18 = 0;
    m10 = 6;
    *(hulk_intptr*)this = (hulk_intptr)vt;
    _ReadWriteBarrier();
}
