#include "compat/ptr.h"
extern "C" char DAT_0042d9dc[];
typedef unsigned int u32_2a6c00;
extern void* __cdecl alloc(unsigned int);
class ProceduralVertexAnimController {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void* vfunc_4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    void init(ProceduralVertexAnimController*);
    void copyfield(u32_2a6c00);
    char pad[0x3c];
    u32_2a6c00 field40, field44, field48, field4c, field50;
};
void* ProceduralVertexAnimController::vfunc_4() {
    ProceduralVertexAnimController* p = (ProceduralVertexAnimController*)alloc(0x58);
    if (p) {
        p->init(this);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0042d9dc);
        p->field40 = 0;
        p->field48 = 0;
        p->field4c = 0;
        if (field40)
            p->copyfield(field40);
        p->field50 = field50;
        return p;
    }
    return 0;
}