// FEBackground::vfunc_5 @ 0x000d7950
#include "gen/global.h"

#include "decls/data/engine/pure3d/prop.h"

struct Vec3_d7950 {
    float x, y, z;
};
class Renderer_d7950 {
public:
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
    virtual void v15(int a);
    virtual void v16(int a);
};
class Overlay_d7950 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int a, int b);
};
struct Display_d7950 {
    Renderer_d7950* renderer;
    void FUN_00293d00(Vec3_d7950* v);
    void FUN_00293bf0(float angle);
};
struct FEBackground_nv_d7950 {
    Vec3_d7950* FUN_000e2800(Vec3_d7950* out);
};

void FEBackground::vfunc_5() {
    if ((*(Overlay_d7950 * *)&this->f_150) == 0)
        return;
    Vec3_d7950 pos;
    (*(Display_d7950**)&DAT_0052c2ac)->renderer->v15(0);
    (*(Display_d7950**)&DAT_0052c2ac)->FUN_00293d00(((FEBackground_nv_d7950*)this)->FUN_000e2800(&pos));
    (*(Display_d7950**)&DAT_0052c2ac)->FUN_00293bf0(-1.5707964f);
    (*(Overlay_d7950 * *)&this->f_150)->v8(0, 0);
    (*(Display_d7950**)&DAT_0052c2ac)->renderer->v16(0);
}
