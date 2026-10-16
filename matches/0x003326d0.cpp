#include "gen/pure3d.h"

struct Dev_3326d0 {
    char p0[0x20];
    int tc;
    char p1[0xc0];
    int s;
    char p2[0x14];
    int t;
};
extern unsigned int g_dirty;
extern int g_a_3326d0;
extern int g_b_3326d0;
void __stdcall SetTC(int a, int b);
class Sub_3326d0 {
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
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void Set(int x);
};

void pure3d::d3dBuildingShader::vfunc_13() {
    if ((*(Dev_3326d0 * *)&this->f_14)->s != 1) {
        (*(Dev_3326d0 * *)&this->f_14)->s = 1;
        g_dirty |= 0x800;
        g_a_3326d0 = 1;
    }
    if ((*(Dev_3326d0 * *)&this->f_14)->tc != 2) {
        (*(Dev_3326d0 * *)&this->f_14)->tc = 2;
        SetTC(2, 2);
    }
    if ((*(Dev_3326d0 * *)&this->f_14)->t != 0) {
        (*(Dev_3326d0 * *)&this->f_14)->t = 0;
        g_dirty |= 0x400;
        g_b_3326d0 = 0;
    }
    (*(Sub_3326d0 * *)&this->f_10)->Set(3);
}
