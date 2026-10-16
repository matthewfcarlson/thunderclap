// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_002a3250 @ 0x002a3250
#include "decls/address.h"
struct VBuf_2a3250 {
    char pad00[8];
    float *pos;              // 0x08
    char pad0c[4];
    int *tag;                // 0x10
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
    virtual void v24(int a);
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual VBuf_2a3250 *v30(int a, int b, int c, int d, int e);
    virtual void v31(VBuf_2a3250 *b);
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
    virtual void v54(int a);
    virtual void v55();
    virtual void v56(int a, int b, int c, int d);
    virtual void v57();
    virtual void v58(int a);
    virtual void v59();
    virtual void v60(int a);
    virtual void v61();
    virtual void v62(int a);
    virtual void v63();
    virtual void v64(int a);
    virtual void v65();
    virtual void v66(int a);
    virtual void v67();
    virtual void v68(int a);
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74(int a, int b, int c);
};

class Obj3_2a3250 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual int v7();
};

class Obj2_2a3250 {
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
    virtual void v16(int a);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int a);
};

struct Holder_2a3250 {
    Obj2_2a3250 *obj;
    void FUN_00293da0(float a, float b, float c);
};

class Probe_2a3250 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual float v8();
};

struct ProbeHolder {
    char pad00[0x18];
    Probe_2a3250 *probe;            // 0x18
};

struct ProbeOwner {
    char pad00[8];
    ProbeHolder *holder;     // 0x08
};

struct Target_2a3250 {
    char pad00[0x10];
    int handle;              // 0x10
};

extern Obj3_2a3250 *DAT_0052c2a4;
extern Holder_2a3250 *DAT_0052c2ac;
extern ProbeOwner *DAT_0052c2b4;

class Quad_2a3250 {
public:
    Target_2a3250 *target;          // 0x00
    int tag;                 // 0x04
    int mode;                // 0x08
    void FUN_002a3250();
};

void Quad_2a3250::FUN_002a3250()
{
    Gfx *dev = DAT_0052c2a8;
    dev->v54(mode);
    dev->v56(1, 1, 1, 1);
    dev->v58(0);
    dev->v64(1);
    dev->v74(1, 1, 1);
    dev->v66(2);
    dev->v68(0);
    DAT_0052c2ac->obj->v21(0);
    int w = DAT_0052c2a4->v6();
    int h = DAT_0052c2a4->v7();
    DAT_0052c2ac->FUN_00293da0((float)h, (float)w, 1.0f);
    dev->v24(2);
    VBuf_2a3250 *vb = dev->v30(target->handle, 1, 0x2020, 4, 0);
    float f = DAT_0052c2b4->holder->probe->v8() + 0.001f;
    *vb->tag = tag;
    vb->pos[0] = 0.0f;
    vb->pos[1] = 0.0f;
    vb->pos[2] = f;
    vb->FUN_0008ef00();
    *vb->tag = tag;
    vb->pos[0] = 1.0f;
    vb->pos[1] = 0.0f;
    vb->pos[2] = f;
    vb->FUN_0008ef00();
    *vb->tag = tag;
    vb->pos[0] = 0.0f;
    vb->pos[1] = 1.0f;
    vb->pos[2] = f;
    vb->FUN_0008ef00();
    *vb->tag = tag;
    vb->pos[0] = 1.0f;
    vb->pos[1] = 1.0f;
    vb->pos[2] = f;
    vb->FUN_0008ef00();
    dev->v31(vb);
    DAT_0052c2ac->obj->v16(0);
    dev->v24(0);
    dev->v58(1);
    dev->v62(1);
    dev->v60(3);
    dev->v64(0);
}
