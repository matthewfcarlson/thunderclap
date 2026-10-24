// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 10/10)
// pure3d::CompositeDrawable::vfunc_12 @ 0x002992c0
#include "gen/pure3d.h"

struct Mat_2992c0 { float m[16]; };

struct Box_2992c0 {
    float min[3];
    float max[3];
    void FUN_00298530(const Mat_2992c0 *m, const Box_2992c0 *src);
    void FUN_000a87f0(const float *p);
    float *FUN_000a8890(float *tmp);
};

class Drawable_2992c0 {
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
    virtual int vfunc_15();
    char pad04[0x14 - 4];
    Box_2992c0 bounds;
};

struct Entry_2992c0 {
    char type;
    char pad1[3];
    int matrixIndex;
    Drawable_2992c0 *drawable;
};

struct Layout_2992c0 {
    char pad0[0x20];
    unsigned char count;
    char pad21[0x30 - 0x21];
    unsigned char *order;
    char pad34[0x3c - 0x34];
    Entry_2992c0 *entries;
};

struct Skeleton_2992c0 {
    char pad0[0x1c];
    Mat_2992c0 *matrices;
    void FUN_00284820(int n);
};

void pure3d::CompositeDrawable::vfunc_12() {
    (*(Skeleton_2992c0 * *)&this->f_40)->FUN_00284820(0);

    (*(Box_2992c0 *)&this->f_14).min[0] = 1e12f;
    (*(Box_2992c0 *)&this->f_14).min[1] = 1e12f;
    (*(Box_2992c0 *)&this->f_14).min[2] = 1e12f;
    (*(Box_2992c0 *)&this->f_14).max[0] = -1e12f;
    (*(Box_2992c0 *)&this->f_14).max[1] = -1e12f;
    (*(Box_2992c0 *)&this->f_14).max[2] = -1e12f;
    (*(float (*)[4])&this->f_2c)[0] = 0.0f;
    (*(float (*)[4])&this->f_2c)[1] = 0.0f;
    (*(float (*)[4])&this->f_2c)[2] = 0.0f;
    (*(float (*)[4])&this->f_2c)[3] = 0.0f;

    Box_2992c0 box;
    unsigned char n = (*(Layout_2992c0 * *)&this->f_44)->count;
    for (int i = 0; i < n; i++) {
        Entry_2992c0 *e = &(*(Layout_2992c0 * *)&this->f_44)->entries[(*(Layout_2992c0 * *)&this->f_44)->order[i]];
        if (e->type == 1) {
            Drawable_2992c0 *d = e->drawable;
            d->vfunc_12();
            box = d->bounds;
            if (d->vfunc_15() != 2 && d->vfunc_15() != 0x40)
                box.FUN_00298530(&(*(Skeleton_2992c0 * *)&this->f_40)->matrices[e->matrixIndex], &box);
            (*(Box_2992c0 *)&this->f_14).FUN_000a87f0(box.min);
            (*(Box_2992c0 *)&this->f_14).FUN_000a87f0(box.max);
        }
    }

    float *s = (*(Box_2992c0 *)&this->f_14).FUN_000a8890(box.min);
    (*(float (*)[4])&this->f_2c)[0] = s[0];
    (*(float (*)[4])&this->f_2c)[1] = s[1];
    (*(float (*)[4])&this->f_2c)[2] = s[2];
    (*(float (*)[4])&this->f_2c)[3] = s[3];
}
