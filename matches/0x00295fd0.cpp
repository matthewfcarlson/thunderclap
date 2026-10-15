extern "C" void _ReadWriteBarrier();
extern char vt[];
class DrawableNode {
  public:
    virtual void Dummy();
    char pad[0x10 - 4];
    int m10;
    int m14;
    int m18;
    DrawableNode();
};
class Node : public DrawableNode {
  public:
    Node();
};
Node::Node() : DrawableNode() {
    m14 = 0;
    m18 = 0;
    m10 = 6;
    *(int*)this = (int)vt;
    _ReadWriteBarrier();
}
