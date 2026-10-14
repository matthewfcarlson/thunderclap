// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// pure3d::VertexAnimPrimGroup::vfunc_10 @ 0x002e0b10
struct Ref_2e0b10 {
    virtual void addRef();
    virtual void release();
};

struct Block6 {
    int v[6];
};

struct Block4_2e0b10 {
    int v[4];
};

struct Holder_2e0b10 {
    char pad00[0x58];
    Ref_2e0b10 *ref;
};

class Prim_2e0b10 {
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
    char pad04[0x14 - 4];
    Block6 b14;
    Block4_2e0b10 b2c;
    char pad3c[0x5c - 0x3c];
    Holder_2e0b10 *holder;
};

class VertexAnimPrimGroup {
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
    char pad04[0x14 - 4];
    Block6 b14;
    Block4_2e0b10 b2c;
    char pad3c[0x58 - 0x3c];
    Prim_2e0b10 *prim;
    Ref_2e0b10 *ref;
};

void VertexAnimPrimGroup::vfunc_10()
{
    Holder_2e0b10 *holder = prim->holder;
    Ref_2e0b10 *old = holder->ref;
    if (old)
        old->addRef();
    Ref_2e0b10 *mine = ref;
    if (mine)
        mine->addRef();
    if (holder->ref)
        holder->ref->release();
    holder->ref = mine;

    Block6 save14 = prim->b14;
    Block4_2e0b10 save2c = prim->b2c;
    prim->vfunc_10();
    b14 = prim->b14;
    b2c = prim->b2c;
    prim->b14 = save14;
    prim->b2c = save2c;

    if (old)
        old->addRef();
    if (holder->ref)
        holder->ref->release();
    holder->ref = old;
    if (old)
        old->release();
}
