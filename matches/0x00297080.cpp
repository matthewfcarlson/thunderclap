class DrawableNode {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual int vfunc_4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
};
class Helper_297080 {
  public:
    int run(DrawableNode*);
};
extern void* __cdecl alloc(int);
int DrawableNode::vfunc_4() {
    void* p = alloc(0x20);
    if (p)
        return ((Helper_297080*)p)->run(this);
    return 0;
}