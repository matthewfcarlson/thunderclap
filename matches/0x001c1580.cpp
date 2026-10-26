#include "compat/ptr.h"
#include "gen/Render.h"

const float gZero_1c1580 = 0.0f;
const float gOne_1c1580 = 1.0f;
class Shader_1c1580 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
    virtual void f7(int, int);
};
class Arg_1c1580 {
  public:
    char pad[16];
    Shader_1c1580* shader;
};
class Manager_1c1580 {
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
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35(int);
};
extern Manager_1c1580* gManager_1c1580;

hulk_intptr Render::Canvas::HulkShaderCallback::vfunc_4(void* __p0) { Arg_1c1580 * p = (Arg_1c1580 *)__p0;

    hulk_intptr result = (hulk_intptr)p;
    if (this->f_08 > 0.0f && p)
        p->shader->f7(0x45444146, 0);
    if (this->f_10 > 0.0f)
        gManager_1c1580->f35(this->f_18);
    if (this->f_0c < 1.0f && p)
        p->shader->f6(0x4153524c, 0);
    return result;
}
