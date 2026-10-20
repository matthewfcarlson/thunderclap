#include "compat/ptr.h"
class A_2fe420 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual int Get(int);
    char pad[0x34];
    int count;
};
class B_2fe420 {
  public:
    char pad[0x24];
    int state;
    void Apply(int, unsigned char);
};
class C_2fe420 {
  public:
    char pad70[0x70];
    B_2fe420* b;
    A_2fe420* a;
    void Run(int);
};
void C_2fe420::Run(int x) {
    if (a) {
        int* result = (int*)a->Get(x);
        if (b && b->state == 2) {
            int n = a->count;
            for (hulk_intptr i = 0; i < n; ++i)
                b->Apply(i, *(unsigned char*)(result[2] + i));
        }
    }
}