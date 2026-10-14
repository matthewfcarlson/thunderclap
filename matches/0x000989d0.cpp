class Obj_989d0 {
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
struct Triple_989d0 {
    int x, y, z;
    void Set(Triple_989d0* s) {
        x = s->x;
        y = s->y;
        z = s->z;
    }
};
class Owner_989d0 {
  public:
    char pad[0x170];
    Obj_989d0* a;
    Obj_989d0* b;
    char flag;
    char pad2[3];
    int zero;
    char pad3[0x28];
    Triple_989d0 t1a8;
    void helper(Obj_989d0*, void*);
    Triple_989d0* get(Obj_989d0*, Obj_989d0*);
    char F(void*, Obj_989d0*, char, Obj_989d0*);
};
char Owner_989d0::F(void* p2, Obj_989d0* p3, char p4, Obj_989d0* p5) {
    p3->V0();
    a = p3;
    flag = p4;
    if (!p4) {
        helper(p3, (char*)this + 0x180);
        p3->V31(p2);
    }
    p5->V0();
    b = p5;
    Triple_989d0* q = get(a, p5);
    t1a8 = *q;
    zero = 0;
    return 1;
}