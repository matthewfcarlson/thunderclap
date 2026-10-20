#include "compat/ptr.h"
class Obj_2e0110 {
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
struct Vec_2e0110 {
    int* begin;
    int* end;
    hulk_uintptr size() const { return end - begin; }
};
struct Arr_2e0110 {
    int pad[2];
    Vec_2e0110 v;
};
struct Base_2e0110 {
    char pad[8];
    void* data;
};
class Manager_2e0110 {
  public:
    Obj_2e0110* get();
};
extern Manager_2e0110* gMgr_2e0110;
class Prim_2e0110 : public Obj_2e0110 {
  public:
    char pad[0x3c];
    void* p40;
    char p44[0x14];
    void* p58;
    void* p5c;
    Base_2e0110* p60;
    Arr_2e0110* p64;
    void f6();
};
void Prim_2e0110::f6() {
    Obj_2e0110* s = gMgr_2e0110->get();
    s->f2();
    Vec_2e0110* vv = &p64->v;
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