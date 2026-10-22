// STATUS: equivalent (tools/equiv.py level 3: 19840 inputs, branch coverage 2/2)
// FUN_000d50f0 @ 0x000d50f0
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
struct V3_d50f0 {
    float x, y, z;
};

struct VertexBuf_d50f0 {
    char pad0[8];
    V3_d50f0 *vertex;
    char pad0c[4];
    unsigned *color;
    void FUN_0008ef00();
};

class Gfx {
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
    virtual VertexBuf_d50f0 *beginQuad(int obj, int one, int flags, int four, int zero);
    virtual void endQuad(VertexBuf_d50f0 *buf);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void setState(int on);
};

class Provider_d50f0 {
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

struct ProviderRef_d50f0 {
    Provider_d50f0 *provider;
    void FUN_00293d00(void *state);
};

struct Overlay {
    char pad0[0x10];
    int f10;
};


class FadeQuad {
public:
    char pad0[0x7c0];
    Overlay *overlay;
    char pad7c4[8];
    float amount;
    void FUN_000d50f0();
};

void FadeQuad::FUN_000d50f0()
{
    float a = amount;
    if (a < 0.0f)
        a = -a;
    if (a <= 1e-05f)
        return;

    DAT_0052c2a8->setState(0);
    (*(ProviderRef_d50f0**)&DAT_0052c2ac)->provider->v15(0);
    (*(ProviderRef_d50f0**)&DAT_0052c2ac)->FUN_00293d00(((char*)&DAT_004ddfc0));

    VertexBuf_d50f0 *buf = DAT_0052c2a8->beginQuad(overlay->f10, 1, 0x2020, 4, 0);

    float x0 = 16.6f * -0.5f;
    float y0 = DAT_004a06d0 * -0.5f;
    float x1 = amount * 0.5f;
    float y1 = DAT_004a06d0 * 0.5f;

    V3_d50f0 *v = buf->vertex;
    v->y = y0;
    v->x = x0;
    v->z = 0.0f;
    unsigned *color = buf->color;
    *color = 0x7f000000;
    buf->FUN_0008ef00();

    v = buf->vertex;
    v->x = x0;
    v->y = y1;
    v->z = 0.0f;
    color = buf->color;
    *color = 0x7f000000;
    buf->FUN_0008ef00();

    v = buf->vertex;
    v->x = x1;
    v->y = y0;
    v->z = 0.0f;
    color = buf->color;
    *color = 0x7f000000;
    buf->FUN_0008ef00();

    v = buf->vertex;
    v->x = x1;
    v->y = y1;
    v->z = 0.0f;
    color = buf->color;
    *color = 0x7f000000;
    buf->FUN_0008ef00();

    DAT_0052c2a8->endQuad(buf);
    (*(ProviderRef_d50f0**)&DAT_0052c2ac)->provider->v16(0);
    DAT_0052c2a8->setState(1);
}
