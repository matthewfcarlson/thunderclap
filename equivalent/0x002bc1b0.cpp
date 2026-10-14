// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 20/20)
// pure3d::BillboardQuadGroup::vfunc_6 @ 0x002bc1b0
struct Matrix {
    float m[16];
};

struct Handle_2bc1b0 {
    char pad00[0x10];
    void *target;
};

struct Lock;

class Engine_2bc1b0 {
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
    virtual Lock *v30(Handle_2bc1b0 *h, int a, int b, int count, int c);
    virtual void v31(Lock *l);
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
    virtual void v60(int mode);
    virtual int v61();
    virtual void v62(int flag);
    virtual unsigned char v63();
};

class Renderer_2bc1b0 {
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

class MatrixSource_2bc1b0 {
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
    virtual Matrix *v13();
    virtual Matrix *v14();
};

struct Display_2bc1b0 {
    Renderer_2bc1b0 *renderer;
};

struct SceneNode {
    char pad00[0x18];
    MatrixSource_2bc1b0 *source;
};

struct Camera {
    char pad00[8];
    SceneNode *node;
    Matrix *FUN_0028faa0();
};

extern Engine_2bc1b0 *DAT_0052c2a8;
extern Display_2bc1b0 *DAT_0052c2ac;
extern Camera *DAT_0052c2b4;

struct Quad_2bc1b0 {
    void FUN_002bbb40(Lock *lock, Matrix *view, Matrix *proj, Matrix *world, float scale, int arg);
};

struct Owner_2bc1b0 {
    char pad00[0x10];
    void *target;
};

namespace pure3d {

class BillboardQuadGroup {
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
    virtual float vfunc_11(Matrix *a, Matrix *b);

    char pad04[0x80 - 4];
    int arg80;
    Owner_2bc1b0 *owner;               // 0x84
    char disabled;              // 0x88
    unsigned char keep;         // 0x89
    char useScale;              // 0x8a
    char pad8b;
    Quad_2bc1b0 **begin;               // 0x8c
    Quad_2bc1b0 **end;                 // 0x90

    float FUN_002ba220();
};

}

void pure3d::BillboardQuadGroup::vfunc_6()
{
    struct Frame {
        float scale;
        union {
            unsigned char flag;
            int word;
        } prev;
        int mode;
        Matrix m1;
        Matrix m2;
        Matrix m3;
    } fr;

    if ((unsigned int)(end - begin) == 0)
        return;

    fr.scale = 1.0f;
    if (useScale == 1)
        fr.scale = FUN_002ba220();

    unsigned char prev = DAT_0052c2a8->v63();
    fr.prev.flag = prev;
    if (prev != keep)
        DAT_0052c2a8->v62(keep);
    fr.mode = DAT_0052c2a8->v61();
    if (disabled == 0 && fr.mode != 1)
        DAT_0052c2a8->v60(1);

    fr.m1 = *DAT_0052c2b4->FUN_0028faa0();
    fr.m2 = *DAT_0052c2b4->node->source->v14();
    fr.m3 = *DAT_0052c2b4->node->source->v13();
    fr.scale = vfunc_11(&fr.m1, &fr.m2) * fr.scale;
    DAT_0052c2ac->renderer->v21(0);

    Handle_2bc1b0 *h = (Handle_2bc1b0 *)owner->target;
    Lock *lock = DAT_0052c2a8->v30(h, 0, 0x2021, (int)(end - begin) * 6, 0);
    for (unsigned int i = 0; i < (unsigned int)(end - begin); i++)
        begin[i]->FUN_002bbb40(lock, &fr.m1, &fr.m2, &fr.m3, fr.scale, arg80);
    DAT_0052c2a8->v31(lock);
    DAT_0052c2ac->renderer->v16(0);
    if (disabled == 0 && fr.mode != 1)
        DAT_0052c2a8->v60(fr.mode);
    if (fr.prev.flag != keep)
        DAT_0052c2a8->v62(fr.prev.word);
}
