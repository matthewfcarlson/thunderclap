#include "compat/ptr.h"
extern "C" char DAT_0042d23c[];
class Base_295f30 {
  public:
    Base_295f30();
    char pad[16];
};
class LeafNode : public Base_295f30 {
  public:
    int x;
    int y;
    LeafNode();
};
LeafNode::LeafNode() : Base_295f30() {
    x = 6;
    y = 0;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042d23c);
}
