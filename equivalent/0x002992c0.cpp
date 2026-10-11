// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 10/10)
// pure3d::CompositeDrawable::vfunc_12 @ 0x002992c0
struct Mat { float m[16]; };

struct Box {
    float min[3];
    float max[3];
    void FUN_00298530(const Mat *m, const Box *src);
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
    Box bounds;
};

struct Entry {
    char type;
    char pad1[3];
    int matrixIndex;
    Drawable *drawable;
};

struct Layout {
    char pad0[0x20];
    unsigned char count;
    char pad21[0x30 - 0x21];
    unsigned char *order;
    char pad34[0x3c - 0x34];
    Entry *entries;
};

struct Skeleton {
    char pad0[0x1c];
    Mat *matrices;
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
    Box bounds;
    float sphere[4];
    char pad3c[0x40 - 0x3c];
    Skeleton *skeleton;
    Layout *layout;
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

    Box box;
    unsigned char n = layout->count;
    for (int i = 0; i < n; i++) {
        Entry *e = &layout->entries[layout->order[i]];
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
