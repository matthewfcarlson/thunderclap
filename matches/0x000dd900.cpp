#include "gen/global.h"

class IDollyControllerState_dd900 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual float vfunc_10(int arg);
    virtual void vfunc_11();
    char pad[8];
};

extern const int g_table[][2];

float ControllerState::vfunc_10(int arg) {
    float* a = (*(float * *)&this->f_0c);
    const int* p = g_table[arg];
    return a[p[0]] - a[p[1]];
}
