// STATUS: equivalent (tools/equiv.py level 3: 20021 inputs, branch coverage 12/12)
// FUN_001aa150 @ 0x001aa150
// FUN_001aa150 @ 0x001aa150
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/owners.h"
struct Placement_1aa150;
namespace core {
struct IRefCount_1aa150 {
    virtual void r0();
    virtual void r1();
    virtual void r2();
};
}

namespace pure3d {
namespace scenegraph {
class Scenegraph_1aa150 : public core::IRefCount_1aa150 {
public:
    virtual void s3();
};
class Node_1aa150 : public core::IRefCount_1aa150 {
public:
    virtual void n3();
};
class TransformNode_1aa150 : public Node_1aa150 {
public:
    virtual void t4();
    Placement_1aa150 *FUN_001a4990();
};
}
}

using namespace pure3d::scenegraph;

struct Vec3_1aa150 {
    float x, y, z;
};

struct Transform_1aa150 {
    char data[0x40];
    void FUN_0022b980();
};

struct Placement_1aa150 {
};

// Anything the controller can track; slot 9 is called on it.
class Entity : public core::IRefCount_1aa150 {
public:
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void e6();
    virtual void e7();
    virtual void e8();
    virtual void e9();
    class Sequence *FUN_002961d0();
};

class Sequence {
public:
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
    virtual void q7();
    virtual void q8();
    virtual void q9();
    virtual void q10();
    virtual int q11();
    virtual Node_1aa150 *q12(int a);
};

struct Cursor_1aa150 {
    unsigned int a;
    int b;
    void *c;
    void FUN_002314a0(unsigned int v);
    Entity *FUN_00231640();
};

struct Inner_1aa150 {
    char pad0[0xc];
    unsigned int f0c;
};

struct Registry_1aa150 {
};

struct Owner_1aa150 {
    char pad0[0x2c];
    float f2c;
    char pad30[0x54 - 0x30];
    int f54;
};

struct Finish_1aa150 {
    void FUN_001b92c0(Entity *e);
};

struct Handle_1aa150 {
};

struct World {
    char pad0[0x54];
    Handle_1aa150 *handle;
};


class Controller_1aa150 {
public:
    char pad0[0x1c];
    Owner_1aa150 *owner;
    char pad20[0x20c - 0x20];
    Registry_1aa150 *registry;
    Entity *entity;
    unsigned char noOwner;

    void FUN_001a54a0(Vec3_1aa150 *out1, float *out2);
    void FUN_001aa150();
};


void Controller_1aa150::FUN_001aa150()
{
    struct Frame {
        hulk_freg f;
        float extra;
        Cursor_1aa150 it;
        Vec3_1aa150 out1;
        Transform_1aa150 xf;
    } fr;

    int idx;
    if (noOwner)
        idx = 0;
    else
        idx = owner->f54;
    Inner_1aa150 *inner = ((Inner_1aa150 *)((owners::C_203d60 *)registry)->FUN_00203d60(idx));
    fr.it.FUN_002314a0(inner->f0c);
    fr.it.c = inner;
    Entity *e = fr.it.FUN_00231640();
    core::IRefCount_1aa150 *r = e;
    if (dynamic_cast<Scenegraph_1aa150 *>(r) != 0)
        entity = e;
    else
        entity = ((Entity *)((owners::Owner_1a6e10 *)&(fr.it))->FUN_001a6e10());
    if (entity != 0) {
        entity->e9();
        Sequence *seq = entity->FUN_002961d0();
        if (seq != 0 && seq->q11() != 0) {
            Node_1aa150 *n = seq->q12(0);
            TransformNode_1aa150 *tn = dynamic_cast<TransformNode_1aa150 *>(n);
            if (tn != 0) {
                FUN_001a54a0(&fr.out1, &fr.extra);
                fr.f = owner->f2c;
                fr.xf.FUN_0022b980();
                ((owners::Target_22be40 *)&(fr.xf))->FUN_0022be40((const int *)(const Vec3_1aa150 *)(&fr.out1));
                ((owners::Mat_22ba70 *)&(fr.xf))->FUN_0022ba70(fr.f + fr.extra);
                const Transform_1aa150 * arg1_ = &fr.xf;
                ((owners::Obj_98380 *)(tn->FUN_001a4990()))->FUN_00098380((hulk_uintptr)(const Transform_1aa150 *)arg1_);
            }
        }
    }
    Entity * arg2_ = entity;
    ((Finish_1aa150 *)((owners::Obj_86290 *)(DAT_004dd700->handle))->FUN_00086290())->FUN_001b92c0(arg2_);
}
