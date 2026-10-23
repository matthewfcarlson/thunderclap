// CHypnoticCamera::vfunc_36 @ 0x000a9f00
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
class Input_a9f00 {
public:
    char FUN_00092940(int button);
};

class Pad_a9f00 {
public:
    Input_a9f00 *FUN_00086340();
};

struct World {
    char pad0[0x54];
    Pad_a9f00 *pad;
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
    virtual void v24(int a);
    virtual int v25();
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
    virtual void v58();
    virtual void v59();
    virtual void v60(int a);
    virtual int v61();
    virtual void v62(int a);
    virtual char v63();
};

class Cam_a9f00 {
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
    virtual void v13(int a);
    virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};

class Clock_a9f00 {
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
    virtual float v16();
};

class Target_a9f00 {
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

class Renderer_a9f00 {
public:
    Cam_a9f00 *cam;
    void FUN_00293da0(float a, float b, float c);
    void FUN_00293d40(int a, int b, float c);
};


class CHypnoticCamera {
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    char pad04[0x478 - 4];
    Target_a9f00 *target;
    char active;
};

void CHypnoticCamera::vfunc_36()
{
    Input_a9f00 *input = DAT_004dd700->pad->FUN_00086340();
    if (input->FUN_00092940(0xe))
        return;
    if (input->FUN_00092940(0xd))
        return;
    if (!active)
        return;
    if (!target)
        return;
    union {
        char b;
        int w;
    } saved;
    int prev = DAT_0052c2a8->v25();
    DAT_0052c2a8->v24(1);
    saved.b = DAT_0052c2a8->v63();
    DAT_0052c2a8->v62(0);
    int mode = DAT_0052c2a8->v61();
    DAT_0052c2a8->v60(1);
    (*(Renderer_a9f00**)&DAT_0052c2ac)->cam->v15(0);
    (*(Renderer_a9f00**)&DAT_0052c2ac)->cam->v13(0);
#if defined(__clang__)
    // MSVC evaluates the arguments (the clock call) before loading the renderer; clang loads the object first
    float aspect = 1.0f / (*(Clock_a9f00**)&DAT_0052c2a4)->v16();
    (*(Renderer_a9f00**)&DAT_0052c2ac)->FUN_00293da0(1.0f, aspect, 1.0f);
#else
    (*(Renderer_a9f00**)&DAT_0052c2ac)->FUN_00293da0(1.0f, 1.0f / (*(Clock_a9f00**)&DAT_0052c2a4)->v16(), 1.0f);
#endif
    (*(Renderer_a9f00**)&DAT_0052c2ac)->FUN_00293d40(0, 0, 1.0f);
    target->v8(0, 0);
    (*(Renderer_a9f00**)&DAT_0052c2ac)->cam->v16(0);
    DAT_0052c2a8->v60(mode);
    DAT_0052c2a8->v62(saved.w);
    DAT_0052c2a8->v24(prev);
}
