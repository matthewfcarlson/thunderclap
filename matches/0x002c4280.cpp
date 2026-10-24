#include "gen/pure3d.h"

#include "decls/address.h"
struct Desc_2c4280 {
    unsigned char flag;
    char pad[3];
    int a, b;
    float c, d, e, f, g, h, i, j, k, l, m, n, o;
    void FUN_0029c240(int, void*, void*, float, float, float, float, float, float);
};
struct Gfx {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37(int, Desc_2c4280*, int);
};
namespace pure3d {
} // namespace pure3d
void pure3d::SpotLight::vfunc_9(int arg) {
    if (this->f_10) {
        Desc_2c4280 desc;
        desc.flag = (*(unsigned char *)&this->f_11);
        desc.a = 0;
        desc.b = -1;
        desc.c = 0;
        desc.d = 0;
        desc.e = 0;
        desc.f = 0;
        desc.g = 0;
        desc.h = 1.0f;
        desc.i = 1.0f;
        desc.j = 0;
        desc.k = 0;
        desc.l = 0;
        desc.m = 0;
        desc.n = 0;
        desc.o = 10000000.0f;
        desc.FUN_0029c240(this->f_14, (*(char (*)[12])&this->f_18), (*(float (*)[3])&this->f_58), this->f_74, this->f_78, this->f_7c, this->f_64, this->f_68, this->f_6c);
        DAT_0052c2a8->v37(this->f_24, &desc, arg);
    }
}
