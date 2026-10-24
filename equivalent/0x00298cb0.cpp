// STATUS: equivalent (tools/equiv.py level 3: 19980 inputs, branch coverage 22/22)
// pure3d::CompositeDrawable::vfunc_8 @ 0x00298cb0
#include "gen/pure3d.h"

#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"

struct Matrix_298cb0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be40(const struct V3_298cb0 *translation);
};

struct V3_298cb0 {
    float x, y, z;
    void FUN_0022d210(const Matrix_298cb0 *m);
};

class Part_298cb0 {
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
    Matrix_298cb0 *matrices;
    void FUN_00284820(int a);
};

struct Anchor_298cb0 {
    char pad0[0x4c];
    V3_298cb0 offset;
    void FUN_0029fd20(pure3d::CompositeDrawable *d);
};

struct Owner_298cb0 {
    char pad0[0x18];
    Anchor_298cb0 *anchor;
    Anchor_298cb0 *FUN_0029b490();
};

class Element_298cb0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void Draw(Owner_298cb0 *owner, int arg);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int GetKind();
};

struct Entry_298cb0 {
    char kind;
    char pad1[3];
    int index;
    Element_298cb0 *element;
};

struct DrawList {
    char pad0[0x20];
    unsigned char count;
    char pad21[0x30 - 0x21];
    unsigned char *order;
    char pad34[0x3c - 0x34];
    Entry_298cb0 *entries;
};

class Device_298cb0 {
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
    virtual void SetTransform(int a, Matrix_298cb0 *m);
};

struct DeviceRef { Device_298cb0 *device; };

struct Camera_298cb0 {
    char pad0[0x8c];
    struct Xf { char pad[0x30]; V3_298cb0 pos; } xf;
    Xf *FUN_0028faa0();
};
struct CameraRef { Camera_298cb0 *camera; };

void pure3d::CompositeDrawable::vfunc_8(int __p0, int arg) { Owner_298cb0 * owner = (Owner_298cb0 *)__p0;

    if ((*(Part_298cb0 * *)&this->f_4c) != 0) {
        if (!(*(Part_298cb0 * *)&this->f_4c)->FUN_00284ae0()) {
            (*(Part_298cb0 * *)&this->f_4c)->SetVisible(0, 1);
            (*(Transforms * *)&this->f_40)->FUN_00284820(0);
        }
    }
    if ((*(Part_298cb0 * *)&this->f_50) != 0) {
        if (!(*(Part_298cb0 * *)&this->f_50)->FUN_00284ae0())
            (*(Part_298cb0 * *)&this->f_50)->SetVisible(0, 1);
    }
    if (owner != 0) {
        if (owner->FUN_0029b490() != 0) {
            Matrix_298cb0 m;
            V3_298cb0 v;
            m.FUN_0022b980();
            m.FUN_0022be40(&(*(CameraRef**)&DAT_0052c2b0)->camera->FUN_0028faa0()->pos);
            v = (*(V3_298cb0 *)&this->f_2c);
            v.FUN_0022d210((*(Transforms * *)&this->f_40)->matrices);
            v.FUN_0022d210(&m);
            owner->FUN_0029b490()->offset = v;
            owner->FUN_0029b490()->FUN_0029fd20(this);
        }
    }
    unsigned int n = (*(DrawList * *)&this->f_44)->count;
    if (n != 0) {
        for (unsigned int i = 0; n != 0; n--, i++) {
            Entry_298cb0 *e = &(*(DrawList * *)&this->f_44)->entries[(*(DrawList * *)&this->f_44)->order[i]];
            if (e->kind == 1) {
                Element_298cb0 *el = e->element;
                if (el->GetKind() == 2 || el->GetKind() == 0x40) {
                    el->Draw(owner, arg);
                } else {
                    int idx = e->index;
                    (*(DeviceRef**)&DAT_0052c2ac)->device->SetTransform(0, &(*(Transforms * *)&this->f_40)->matrices[idx]);
                    el->Draw(owner, arg);
                    (*(DeviceRef**)&DAT_0052c2ac)->device->SetState(0);
                }
            }
        }
    }
}
