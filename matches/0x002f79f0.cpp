struct Ref {
    virtual void f0();
    virtual void f1();
};
struct Embedded {
    char x[1];
    void init();
};
extern int vt;
class Obj {
  public:
    virtual void v();
    Ref* a;
    char gap[0x94 - 8];
    Embedded e94;
    char gap2[0xb0 - 0x95];
    Embedded eb0;
    char gap3[0xcc - 0xb1];
    Embedded ecc;
    char gap4[0xfc - 0xcd];
    Ref* b;
    void cleanup();
};
void Obj::cleanup() {
    *(int*)this = (int)&vt;
    if (a)
        a->f1();
    if (b)
        b->f1();
    ecc.init();
    eb0.init();
    e94.init();
}