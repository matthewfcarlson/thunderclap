#include "gen/pure3d.h"

struct RTTI {
    char data[1];
};
extern RTTI DAT_004d3c0c, DAT_004d3bec;
extern void* __cdecl FUN_00344e74(void*, int, RTTI*, RTTI*, int);
struct Special_3218c0 {
    void FUN_003285d0(int);
};
struct Shader_3218c0 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9(unsigned, void*);
    virtual void s10();
    virtual int s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual bool s22();
    virtual void s23();
    virtual void s24();
    void FUN_00327d00();
    void FUN_00327d20(int);
};
struct Output_3218c0 {
    void FUN_003272f0();
};
namespace pure3d {
struct d3dContext_nv_3218c0 {
    void FUN_00321310();
};
} // namespace pure3d
void pure3d::d3dContext::vfunc_32(int __p0, int __p1) { Shader_3218c0 * shader = (Shader_3218c0 *)__p0; Output_3218c0 * output = (Output_3218c0 *)__p1;

    Special_3218c0* special = (Special_3218c0*)FUN_00344e74(shader, 0, &DAT_004d3bec, &DAT_004d3c0c, 0);
    if (special) {
        special->FUN_003285d0(0);
        return;
    }
    if (!shader)
        shader = (*(Shader_3218c0 * *)&this->f_160);
    if ((*(bool *)&this->f_414))
        ((d3dContext_nv_3218c0*)this)->FUN_00321310();
    unsigned values[3];
    vfunc_47(0, values);
    shader->s9(0x5654494c, values);
    if (shader->s22())
        shader->s24();
    int i = 0;
    if (shader->s11() > 0) {
        do {
            shader->FUN_00327d00();
            shader->FUN_00327d20(i);
            output->FUN_003272f0();
            ++i;
        } while (i < shader->s11());
    }
}
