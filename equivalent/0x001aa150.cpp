// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_001aa150 @ 0x001aa150
// FUN_001aa150 @ 0x001aa150
struct Placement;
namespace core {
struct IRefCount {
    virtual void r0();
    virtual void r1();
    virtual void r2();
};
}

namespace pure3d {
namespace scenegraph {
class Scenegraph : public core::IRefCount {
public:
    virtual void s3();
};
class Node : public core::IRefCount {
public:
    virtual void n3();
};
class TransformNode : public Node {
public:
    virtual void t4();
    Placement *FUN_001a4990();
};
}
}

using namespace pure3d::scenegraph;

struct Vec3 {
    float x, y, z;
};

struct Transform {
    char data[0x40];
    void FUN_0022b980();
    void FUN_0022be40(const Vec3 *pos);
    void FUN_0022ba70(float v);
};

struct Placement {
    void FUN_00098380(const Transform *xf);
};

// Anything the controller can track; slot 9 is called on it.
class Entity : public core::IRefCount {
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
    virtual Node *q12(int a);
};

struct Cursor {
    unsigned int a;
    int b;
    void *c;
    void FUN_002314a0(unsigned int v);
    Entity *FUN_00231640();
    Entity *FUN_001a6e10();
};

struct Inner {
    char pad0[0xc];
    unsigned int f0c;
};

struct Registry {
    Inner *FUN_00203d60(int index);
};

struct Owner {
    char pad0[0x2c];
    float f2c;
    char pad30[0x54 - 0x30];
    int f54;
};

struct Finish {
    void FUN_001b92c0(Entity *e);
};

struct Handle {
    Finish *FUN_00086290();
};

struct Manager {
    char pad0[0x54];
    Handle *handle;
};

extern Manager *DAT_004dd700;

class Controller {
public:
    char pad0[0x1c];
    Owner *owner;
    char pad20[0x20c - 0x20];
    Registry *registry;
    Entity *entity;
    unsigned char noOwner;

    void FUN_001a54a0(Vec3 *out1, float *out2);
    void FUN_001aa150();
};


void Controller::FUN_001aa150()
{
    struct Frame {
        float f;
        float extra;
        Cursor it;
        Vec3 out1;
        Transform xf;
    } fr;

    int idx;
    if (noOwner)
        idx = 0;
    else
        idx = owner->f54;
    Inner *inner = registry->FUN_00203d60(idx);
    fr.it.FUN_002314a0(inner->f0c);
    fr.it.c = inner;
    Entity *e = fr.it.FUN_00231640();
    core::IRefCount *r = e;
    if (dynamic_cast<Scenegraph *>(r) != 0)
        entity = e;
    else
        entity = fr.it.FUN_001a6e10();
    if (entity != 0) {
        entity->e9();
        Sequence *seq = entity->FUN_002961d0();
        if (seq != 0 && seq->q11() != 0) {
            Node *n = seq->q12(0);
            TransformNode *tn = dynamic_cast<TransformNode *>(n);
            if (tn != 0) {
                FUN_001a54a0(&fr.out1, &fr.extra);
                fr.f = owner->f2c;
                fr.xf.FUN_0022b980();
                fr.xf.FUN_0022be40(&fr.out1);
                fr.xf.FUN_0022ba70(fr.f + fr.extra);
                tn->FUN_001a4990()->FUN_00098380(&fr.xf);
            }
        }
    }
    DAT_004dd700->handle->FUN_00086290()->FUN_001b92c0(entity);
}
