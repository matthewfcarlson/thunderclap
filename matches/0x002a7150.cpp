#include "compat/ptr.h"
extern float __cdecl FUN_002899e0(float*, float*, float, float, int, int, bool, int);
class Item_2a7150 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void Update(float, float);
};
struct Vec_2a7150 {
    Item_2a7150** begin;
    Item_2a7150** end;
    hulk_uintptr size() const { return end - begin; }
    Item_2a7150* at(unsigned i) const { return begin[i]; }
};
class PC_2a7150 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void vfunc_7();
    char pad08[0x1c];
    int m20;
    int m24;
    float m28;
    int m2c;
    int m30;
    float m34;
    float m38;
    char pad3c[0x0c];
    float m48;
    float m4c;
    Vec_2a7150 v;
};
void PC_2a7150::vfunc_7() {
    float delta = m48 * m4c * 0.001f;
    m34 = FUN_002899e0(&m28, &m38, m34, delta, m2c, m30, m24 == 0, m20);
    unsigned i = 0;
    if (v.size() > 0) {
        do {
            v.at(i)->Update(m34, delta);
            i++;
        } while (i < v.size());
    }
    m4c = 0.0f;
}
