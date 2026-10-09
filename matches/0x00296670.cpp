class BranchNode {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void vfunc_9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    char pad[0x10 - 4];
    unsigned int flags;
    char pad2[4];
    unsigned int count;
    void** children;
};
void BranchNode::vfunc_9() {
    flags &= 0xfffffffe;
    for (unsigned int i = 0; i < count; ++i) {
        struct Child {
            virtual void a();
            virtual void b();
            virtual void c();
            virtual void d();
            virtual void e();
            virtual void f();
            virtual void g();
            virtual void h();
            virtual void i();
            virtual void call();
        };
        ((Child*)children[i])->call();
    }
}
