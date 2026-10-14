typedef unsigned int uint;
class Child_2965e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual bool f7();
};
class BranchNode {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual bool vfunc_7();
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
    virtual void a18();
    virtual void a19();
    char pad[0x0c];
    unsigned char flags;
    char pad14[7];
    uint count;
    Child_2965e0** children;
};
bool BranchNode::vfunc_7() {
    if ((flags & 1) == 0) {
        uint i = 0;
        if (count > 0) {
            do {
                if (!children[i]->f7())
                    return false;
                ++i;
            } while (i < count);
        }
    }
    return true;
}
