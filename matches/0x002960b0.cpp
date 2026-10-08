class Child { public: virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void vfunc_9(); };
class DrawableNode {
public:
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void vfunc_9();
    virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14();
    virtual void a15(); virtual void a16(); virtual void a17();
    char pad10[12]; unsigned int field10; char pad18[4]; Child* child;
};
void DrawableNode::vfunc_9() { field10 &= 1; if (child) child->vfunc_9(); }