// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 10/10)
// pure3d::CompositeDrawable::vfunc_12 @ 0x002992c0
struct Mat_2992c0 { float m[16]; };

struct Box_2992c0 {
    float min[3];
    float max[3];
    void FUN_00298530(const Mat_2992c0 *m, const Box_2992c0 *src);
    void FUN_000a87f0(const float *p);
    float *FUN_000a8890(float *tmp);
};

class Drawable {
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
    Drawable *drawable;
};

struct Layout_2992c0 {
    char pad0[0x20];
    unsigned char count;
    char pad21[0x30 - 0x21];
    unsigned char *order;
    char pad34[0x3c - 0x34];
    Entry_2992c0 *entries;
};

struct Skeleton {
    char pad0[0x1c];
    Mat_2992c0 *matrices;
    void FUN_00284820(int n);
};

class CompositeDrawable {
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

    char pad04[0x14 - 4];
    Box_2992c0 bounds;
    float sphere[4];
    char pad3c[0x40 - 0x3c];
    Skeleton *skeleton;
    Layout_2992c0 *layout;
};

void CompositeDrawable::vfunc_12()
{
    skeleton->FUN_00284820(0);

    bounds.min[0] = 1e12f;
    bounds.min[1] = 1e12f;
    bounds.min[2] = 1e12f;
    bounds.max[0] = -1e12f;
    bounds.max[1] = -1e12f;
    bounds.max[2] = -1e12f;
    sphere[0] = 0.0f;
    sphere[1] = 0.0f;
    sphere[2] = 0.0f;
    sphere[3] = 0.0f;

    Box_2992c0 box;
    unsigned char n = layout->count;
    for (int i = 0; i < n; i++) {
        Entry_2992c0 *e = &layout->entries[layout->order[i]];
        if (e->type == 1) {
            Drawable *d = e->drawable;
            d->vfunc_12();
            box = d->bounds;
            if (d->vfunc_15() != 2 && d->vfunc_15() != 0x40)
                box.FUN_00298530(&skeleton->matrices[e->matrixIndex], &box);
            bounds.FUN_000a87f0(box.min);
            bounds.FUN_000a87f0(box.max);
        }
    }

    float *s = bounds.FUN_000a8890(box.min);
    sphere[0] = s[0];
    sphere[1] = s[1];
    sphere[2] = s[2];
    sphere[3] = s[3];
}
