// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 22/22)
// pure3d::CompositeDrawable::vfunc_8 @ 0x00298cb0
struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be40(const struct V3 *translation);
};

struct V3 {
    float x, y, z;
    void FUN_0022d210(const Matrix *m);
};

class Part {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void SetVisible(int a, int b);
    char pad04[0x10 - 4];
    char flag;
    char FUN_00284ae0();
};

struct Transforms {
    char pad0[0x1c];
    Matrix *matrices;
    void FUN_00284820(int a);
};

class Drawable;

struct Anchor {
    char pad0[0x4c];
    V3 offset;
    void FUN_0029fd20(Drawable *d);
};

struct Owner {
    char pad0[0x18];
    Anchor *anchor;
    Anchor *FUN_0029b490();
};

class Element {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void Draw(Owner *owner, int arg);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int GetKind();
};

struct Entry {
    char kind;
    char pad1[3];
    int index;
    Element *element;
};

struct DrawList {
    char pad0[0x20];
    unsigned char count;
    char pad21[0x30 - 0x21];
    unsigned char *order;
    char pad34[0x3c - 0x34];
    Entry *entries;
};

class Device {
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
    virtual void SetState(int a);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void SetTransform(int a, Matrix *m);
};

struct DeviceRef { Device *device; };

struct Camera {
    char pad0[0x8c];
    struct Xf { char pad[0x30]; V3 pos; } xf;
    Xf *FUN_0028faa0();
};
struct CameraRef { Camera *camera; };

extern CameraRef *DAT_0052c2b0;
extern DeviceRef *DAT_0052c2ac;

class Drawable {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void Render(Owner *owner, int arg);
    char pad04[0x2c - 4];
    V3 offset;
    char pad38[0x40 - 0x38];
    Transforms *transforms;
    DrawList *list;
    char pad48[4];
    Part *partA;
    Part *partB;
};

void Drawable::Render(Owner *owner, int arg)
{
    if (partA != 0) {
        if (!partA->FUN_00284ae0()) {
            partA->SetVisible(0, 1);
            transforms->FUN_00284820(0);
        }
    }
    if (partB != 0) {
        if (!partB->FUN_00284ae0())
            partB->SetVisible(0, 1);
    }
    if (owner != 0) {
        if (owner->FUN_0029b490() != 0) {
            Matrix m;
            V3 v;
            m.FUN_0022b980();
            m.FUN_0022be40(&DAT_0052c2b0->camera->FUN_0028faa0()->pos);
            v = offset;
            v.FUN_0022d210(transforms->matrices);
            v.FUN_0022d210(&m);
            owner->FUN_0029b490()->offset = v;
            owner->FUN_0029b490()->FUN_0029fd20(this);
        }
    }
    unsigned int n = list->count;
    if (n != 0) {
        for (unsigned int i = 0; n != 0; n--, i++) {
            Entry *e = &list->entries[list->order[i]];
            if (e->kind == 1) {
                Element *el = e->element;
                if (el->GetKind() == 2 || el->GetKind() == 0x40) {
                    el->Draw(owner, arg);
                } else {
                    int idx = e->index;
                    DAT_0052c2ac->device->SetTransform(0, &transforms->matrices[idx]);
                    el->Draw(owner, arg);
                    DAT_0052c2ac->device->SetState(0);
                }
            }
        }
    }
}
