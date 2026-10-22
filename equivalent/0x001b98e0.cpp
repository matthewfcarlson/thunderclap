// STATUS: equivalent (tools/equiv.py level 3: 145 inputs, branch coverage 32/38, incomplete)
// FUN_001b98e0 @ 0x001b98e0
#include "decls/address.h"
#include "decls/data/game/global.h"
class Target_1b98e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int v8(float a0, int color2, float a1, float a2, int color1, float a3, float a4, float a5);
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
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual Target_1b98e0 *v89(int id);
};


static int clamp255(int v)
{
    if (v < 0)
        return 0;
    if (v > 255)
        return 255;
    return v;
}

class CRenderManager_1b98e0 {
public:
    char pad00[0x34];
    int r1;     // 0x34
    int g1;     // 0x38
    int b1;     // 0x3c
    int r2;     // 0x40
    int g2;     // 0x44
    int b2;     // 0x48
    float p0;   // 0x4c
    float p1;   // 0x50
    float p2;   // 0x54
    float p3;   // 0x58
    float p4;   // 0x5c
    float p5;   // 0x60
    int FUN_001b98e0(float a0, float a1, float a2, float a3, float a4, float a5);
};

int CRenderManager_1b98e0::FUN_001b98e0(float a0, float a1, float a2, float a3, float a4, float a5)
{
    p0 = a0;
    p1 = a1;
    p2 = a2;
    p3 = a3;
    p4 = a4;
    p5 = a5;
    Target_1b98e0 *t = DAT_0052c2a8->v89(0x103);
    if (t == 0)
        return 0;
    DAT_004e2254 = a0;
    DAT_004c3bf0 = r1;
    DAT_004c3bf4 = g1;
    DAT_004e2258 = a2;
    DAT_004c3bf8 = b1;
    DAT_004c3bfc = r2;
    DAT_004c3c00 = g2;
    DAT_004c3c04 = b2;
    DAT_004e225c = a3;
    DAT_004e2260 = a4;
    (*(float*)&DAT_004c3c08) = a5;
    int color1 = (0xff << 24) | (clamp255(r2) << 16) | (clamp255(g2) << 8) | clamp255(b2);
    int color2 = (0xff << 24) | (clamp255(r1) << 16) | (clamp255(g1) << 8) | clamp255(b1);
    return t->v8(a0, color2, a1, a2, color1, a3, a4, a5);
}
