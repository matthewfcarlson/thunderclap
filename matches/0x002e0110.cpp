class Obj {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5(int, void*);
    virtual void f6(void*, void*);
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
};
struct Vec {
    int* begin;
    int* end;
    unsigned size() const { return end - begin; }
};
struct Arr {
    int pad[2];
    Vec v;
};
struct Base {
    char pad[8];
    void* data;
};
class Manager {
  public:
    Obj* get();
};
extern Manager* gMgr;
class Prim : public Obj {
  public:
    char pad[0x3c];
    void* p40;
    char p44[0x14];
    void* p58;
    void* p5c;
    Base* p60;
    Arr* p64;
    void f6();
};
void Prim::f6() {
    Obj* s = gMgr->get();
    s->f2();
    Vec* vv = &p64->v;
    unsigned n = vv->size();
    s->f4(n);
    for (int i = 0; i < (unsigned)n; ++i) {
        int idx = p64->v.begin[i];
        s->f5(i, (char*)p60->data + (idx << 6));
    }
    void* x = p40 ? *((void**)p40 + 4) : 0;
    s->f6(x, p58);
    s->f3();
}