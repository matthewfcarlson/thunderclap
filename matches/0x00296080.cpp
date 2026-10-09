class DrawableNode {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void vfunc_8(int, int);
    char p[12];
    unsigned char flags;
    char q[7];
    DrawableNode* child;
    void vfunc_8(int, int, int);
};
void DrawableNode::vfunc_8(int a, int b, int c) {
    if ((flags & 1) == 0 && child)
        child->vfunc_8(b, c);
}