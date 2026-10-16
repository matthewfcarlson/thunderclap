// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 10/10)
// FUN_002beb20 @ 0x002beb20
#include "decls/address.h"
extern "C" double sqrt(double);
void *FUN_00263ea0(unsigned int size);

class Attr_2beb20 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(unsigned int tag, int value);
};

class Res_2beb20 {
public:
    virtual void v0();
    char pad04[0xc];
    Attr_2beb20 *attr;
    char pad14[0xc];
    Res_2beb20 *FUN_0028edb0();
};

struct Desc_2beb20 {
    char pad0[0x10];
    int width;
    int height;
    char pad18[0x10];
    unsigned char flag;
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
    virtual int v84();
};
extern char DAT_004d0894;
extern int DAT_004d0898;

namespace pure3d {

class __declspec(novtable) SpriteBase_2beb20 {
public:
    virtual void v0();
    char pad04[0x48];
    void FUN_002a5060();
    SpriteBase_2beb20() { FUN_002a5060(); }
};

class Sprite : public SpriteBase_2beb20 {
public:
    Res_2beb20 *res;
    int pad50;
    int height;
    int width;
    int slot;
    int arg4;
    int arg5;
    int off68;
    int off6c;
    float inv70;
    float inv74;
    int z78;
    int z7c;
    int z80;
    float w84;
    float h88;
    int z8c;
    float halfW;
    float halfH;
    int z98;
    float diag;
    char flagA0;
    virtual void v1();
    virtual void v2();
    void FUN_002be720(Desc_2beb20 *d, int a);
    void FUN_002bdd00(int a);
    Sprite(Desc_2beb20 *d, Res_2beb20 *r, int s, int a4, int a5, int a6);
};

Sprite::Sprite(Desc_2beb20 *d, Res_2beb20 *r, int s, int a4, int a5, int a6)
{
    flagA0 = DAT_004d0894;
    if (DAT_004d0894 != 0) {
        slot = 0;
    } else {
        if (s >= 0)
            slot = s;
        else
            slot = slot;
    }
    int two = slot * 2;
    int base = DAT_0052c2a8->v84();
    off68 = base - two;
    off6c = DAT_004d0898 - two;
    arg4 = a4;
    arg5 = a5;
    z8c = 0;
    z80 = 0;
    z7c = 0;
    z78 = 0;
    float inv = 1.0f / (float)a4;
    inv70 = inv;
    inv74 = inv;
    w84 = d->width * inv;
    h88 = d->height * inv;
    halfH = h88 * 0.5f;
    z98 = 0;
    halfW = w84 * 0.5f;
    diag = (float)sqrt((double)w84 * w84 + (double)h88 * h88);
    if (r != 0) {
        res = r;
    } else {
        Res_2beb20 *m = (Res_2beb20 *)FUN_00263ea0(0x20);
        if (m)
            res = m->FUN_0028edb0();
        else
            res = 0;
    }
    res->v0();
    if (r == 0) {
        res->attr->v6(0x54494c, 0);
        res->attr->v6(0x444d4c42, d->flag);
        res->attr->v6(0x444d5655, 1);
    }
    height = d->height;
    width = d->width;
    FUN_002be720(d, a6);
    FUN_002bdd00(-1);
}
}
