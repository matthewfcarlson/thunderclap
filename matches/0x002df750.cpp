class Obj {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void* s4();
    virtual void s5(void*);
    virtual void s6();
};
class Global {
  public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void g19();
    virtual void g20();
    virtual void g21();
    virtual void g22();
    virtual void g23();
    virtual void g24();
    virtual void g25();
    virtual void g26();
    virtual void g27();
    virtual void g28();
    virtual void g29();
    virtual void g30();
    virtual void g31();
    virtual void g32(void*, Obj*);
};
class Sub {
  public:
    void call(void*, int, int);
};
struct Res {
    char pad[0x10];
    void* val;
};
extern Global* gGlobal;
class Prim {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vfunc_6();
    char pad0[0x3c];
    Res* res;
    char pad1[0x14];
    Obj* obj;
    int m5c;
    int m60;
    int m64;
    Sub* sub;
};
void Prim::vfunc_6() {
    void* r = obj->s4();
    sub->call(r, m60, m64);
    obj->s5(r);
    obj->s6();
    void* v = res ? res->val : 0;
    gGlobal->g32(v, obj);
}
