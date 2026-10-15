namespace pure3d {
namespace scenegraph {
struct Mat {
    unsigned int v[16];
    void combine(Mat*, Mat*);
};
class Node {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual Mat* vfunc_17();
    char pad[12];
    union {
        unsigned int flags;
        unsigned char flagByte;
    };
    Node* other;
    char pad2[16];
    Mat local;
    Mat world;
};
class TransformNode : public Node {
  public:
    Mat* vfunc_17();
};
} // namespace scenegraph
} // namespace pure3d
pure3d::scenegraph::Mat* pure3d::scenegraph::TransformNode::vfunc_17() {
    if (flagByte & 4) {
        if (other) {
            Mat* m = other->vfunc_17();
            world.combine(&local, m);
            flags &= ~4;
        } else {
            unsigned int f = flags;
            world = local;
            flags = f & ~4;
        }
    }
    return &world;
}