struct Block_309a40 {
    unsigned int x[16];
};
class Buf_309a40 {
  public:
    void run(void*, void*);
};
class PhysicsJoint {
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
    virtual void vfunc_10(void* arg);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    char pad0[4];
    int index;
    char pad1[12];
    void* link;
    char pad2[0x88];
};
struct Node {
    char pad[0x10];
    char* base;
};
struct Manager_309a40 {
    char pad[0x220];
    Node* node;
};

void PhysicsJoint::vfunc_10(void* arg) {
    char* p = (char*)this;
    *(Block_309a40*)(p + 0xa4) = *(Block_309a40*)arg;
    ((Buf_309a40*)(p + 0xa4))->run(p + 0x8c, p + 0x80);
    Manager_309a40* m = (Manager_309a40*)link;
    char* base = m->node->base;
    ((Buf_309a40*)(p + 0xa4))->run(base + index * 0x1c, p + 0x98);
}
