// pure3d::scenegraph::TransformNode::vfunc_8 @ 0x002968b0
// 0x002968b0: TransformNode::vfunc_8: draw the branch under this node's transform
#include "decls/data/engine/pure3d/prop.h"

struct Matrix {
    float m[16];
    void FUN_0022ca90(Matrix* a, Matrix* b);
};

struct Part_2968b0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void SetActive(int a, int b);
    char pad04[0xc];
    char ready;
    char FUN_00284ae0();
};

struct Device_2968b0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void PopMatrix(int a);
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void PushMatrix(int a, Matrix* m);
};

struct Context {
    Device_2968b0* device;
};

namespace pure3d {
namespace scenegraph {

class BranchNode {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void vfunc_8(int a, int b, int c);
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual Matrix* Transform();
    char pad04[0xc];
    unsigned char flags;
    char pad11[0x97];
    Part_2968b0* part;
};

class TransformNode : public BranchNode {
public:
    virtual void vfunc_8(int a, int b, int c);
};

void TransformNode::vfunc_8(int a, int b, int c)
{
    Matrix m;
    if (flags & 1)
        return;
    if (part != 0) {
        if (!part->FUN_00284ae0())
            part->SetActive(0, 1);
    }
    m.FUN_0022ca90(Transform(), (Matrix*)a);
    (*(Context**)&DAT_0052c2ac)->device->PushMatrix(0, &m);
    BranchNode::vfunc_8(a, b, c);
    (*(Context**)&DAT_0052c2ac)->device->PopMatrix(0);
}

}
}
