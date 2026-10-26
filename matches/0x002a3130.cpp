#include "decls/data/engine/pure3d.h"

#include "compat/ptr.h"
struct Inner_2a3130 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
};
struct Shader_2a3130 {
    virtual void init();
    char pad[12];
    Inner_2a3130* inner;
    Shader_2a3130* build();
};
extern void* alloc(hulk_uintptr);
void FUN_002a3130() {
    if ((*(Shader_2a3130**)&DAT_00554bb4) == 0) {
        Shader_2a3130* p = (Shader_2a3130*)alloc(0x20);
        if (p)
            (*(Shader_2a3130**)&DAT_00554bb4) = p->build();
        else
            (*(Shader_2a3130**)&DAT_00554bb4) = 0;
        (*(Shader_2a3130**)&DAT_00554bb4)->init();
        (*(Shader_2a3130**)&DAT_00554bb4)->inner->f6(0x444d4853, 0);
        (*(Shader_2a3130**)&DAT_00554bb4)->inner->f6(0x54535441, 0);
        (*(Shader_2a3130**)&DAT_00554bb4)->inner->f6(0x444d4c42, 1);
    }
}