// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 36/36)
// FUN_002ba220 @ 0x002ba220
#include "decls/address.h"
struct Vec3_2ba220 {
    float x, y, z;
    void FUN_0022d240(Vec3_2ba220 *v, void *matrix);
};

struct Matrix {
    float m[16];
};

struct Mesh_2ba220 {
    char pad00[8];
    Vec3_2ba220 *verts;
    char pad0c[4];
    unsigned int *colors;
    void FUN_0008ef00();
};

struct Handle;

class Layer_2ba220 {
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

class Obj_2ba220 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int a);
    virtual int v4(int a);
};

class ObjQuery {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
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
    virtual Mesh_2ba220* v30(Handle* h, int a, int b, int count, int c);
    virtual void v31(Mesh_2ba220* m);
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
    virtual void v56(int a, int b, int c, int d);
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62(int f);
    virtual unsigned char v63();
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
    virtual Obj_2ba220* v89(int id);
};

class Xform_2ba220 {
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
    virtual void v23(Vec3_2ba220 *in, Vec3_2ba220 *out);
};

struct Scene_2ba220 {
    char pad00[0x18];
    Xform_2ba220 *xf;
    void FUN_002940d0(const Vec3_2ba220 *in, Vec3_2ba220 *out);
    void FUN_00294670(Vec3_2ba220 v, Vec3_2ba220 *p);
};

struct Display_2ba220 {
    Layer_2ba220 *layer;
};

struct Camera {
    char pad00[8];
    Scene_2ba220 *scene;
    Matrix *FUN_0028faa0();
};

extern Display_2ba220 *DAT_0052c2ac;
extern Camera *DAT_0052c2b4;

extern "C" int __cdecl FUN_0034483c();

class BillboardQuadGroup {
public:
    char pad00[0x70];
    Vec3_2ba220 pos70;
    float FUN_002ba220();
};

float BillboardQuadGroup::FUN_002ba220()
{
    struct Frame {
        float x0;
        float y0;
        float y1;
        float x1;
        union {
            unsigned char flag;
            int word;
        } prev;
        Vec3_2ba220 out;
        Vec3_2ba220 p1;
        Vec3_2ba220 p3;
        Vec3_2ba220 p2;
    } fr;

    Obj_2ba220 *o = DAT_0052c2a8->v89(0x500002);
    if (o == 0)
        return 1.0f;
    int mult = 1;
    ObjQuery *q = (ObjQuery *)DAT_0052c2a8->v89(0x500001);
    if (q != 0) {
        switch (q->v4()) {
        case 0x1021: case 0x1121: case 0x2012: case 0x2021:
            mult = 2;
            break;
        case 0x1022: case 0x1222: case 0x2022: case 0x2222:
            mult = 4;
            break;
        case 0x1233: case 0x2233:
            mult = 9;
            break;
        }
    }
    DAT_0052c2a8->v56(0, 0, 0, 1);
    fr.prev.flag = DAT_0052c2a8->v63();
    DAT_0052c2a8->v62(0);
    Scene_2ba220 *scene = DAT_0052c2b4->scene;
    Vec3_2ba220 tmp;
    tmp.FUN_0022d240(&pos70, DAT_0052c2b4->FUN_0028faa0());
    scene->FUN_002940d0(&tmp, &fr.out);
    float r = fr.out.z * 0.01f;
    fr.x0 = fr.out.x - r;
    fr.x1 = fr.out.x + r;
    fr.y0 = fr.out.y - r;
    fr.y1 = fr.out.y + r;
    DAT_0052c2ac->layer->v21(0);
    o->v2();
    Mesh_2ba220 *m = DAT_0052c2a8->v30(0, 1, 0x2020, 4, 0);
    *m->colors = 0xff000000;
    m->verts->x = fr.x0;
    m->verts->y = fr.y0;
    m->verts->z = fr.out.z;
    m->FUN_0008ef00();
    *m->colors = 0xff000000;
    m->verts->x = fr.x0;
    m->verts->y = fr.y1;
    m->verts->z = fr.out.z;
    m->FUN_0008ef00();
    *m->colors = 0xff000000;
    m->verts->x = fr.x1;
    m->verts->y = fr.y0;
    m->verts->z = fr.out.z;
    m->FUN_0008ef00();
    *m->colors = 0xff000000;
    m->verts->x = fr.x1;
    m->verts->y = fr.y1;
    m->verts->z = fr.out.z;
    m->FUN_0008ef00();
    o->v3(0);
    DAT_0052c2a8->v31(m);
    DAT_0052c2ac->layer->v16(0);
    DAT_0052c2a8->v62(fr.prev.word);
    DAT_0052c2a8->v56(1, 1, 1, 1);
    Xform_2ba220 *xf = scene->xf;
    fr.p1.x = fr.x0;
    fr.p1.y = fr.y0;
    fr.p1.z = fr.out.z;
    xf->v23(&fr.p1, &fr.p1);
    scene->FUN_00294670(fr.p1, &fr.p1);
    fr.p2.x = fr.x0;
    fr.p2.y = fr.y1;
    fr.p2.z = fr.out.z;
    xf->v23(&fr.p2, &fr.p2);
    scene->FUN_00294670(fr.p2, &fr.p2);
    fr.p3.x = fr.x1;
    fr.p3.y = fr.y0;
    fr.p3.z = fr.out.z;
    xf->v23(&fr.p3, &fr.p3);
    scene->FUN_00294670(fr.p3, &fr.p3);
    int area = (int)((fr.p3.x - fr.p1.x) * (fr.p1.y - fr.p2.y) * 0.8f) * mult;
    double ratio = (double)o->v4(0) / (double)area;
    if (ratio >= 0.0 && ratio <= 1.0)
        return ratio;
    if (ratio > 1.0)
        return 1.0f;
    return 0.0f;
}
