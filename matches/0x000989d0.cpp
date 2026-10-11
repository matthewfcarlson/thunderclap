class Obj {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31(void*);
    virtual void V32();
};
struct Triple {
    int x, y, z;
    void Set(Triple* s) {
        x = s->x;
        y = s->y;
        z = s->z;
    }
};
class Owner {
  public:
    char pad[0x170];
    Obj* a;
    Obj* b;
    char flag;
    char pad2[3];
    int zero;
    char pad3[0x28];
    Triple t1a8;
    void helper(Obj*, void*);
    Triple* get(Obj*, Obj*);
    char F(void*, Obj*, char, Obj*);
};
char Owner::F(void* p2, Obj* p3, char p4, Obj* p5) {
    p3->V0();
    a = p3;
    flag = p4;
    if (!p4) {
        helper(p3, (char*)this + 0x180);
        p3->V31(p2);
    }
    p5->V0();
    b = p5;
    Triple* q = get(a, p5);
    t1a8 = *q;
    zero = 0;
    return 1;
}