// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 19/20, incomplete)
// CGrappleSizeCondition::vfunc_7 @ 0x00049de0
struct Shape {
    char pad0[0x14];
    int size;
};

struct Body {
    char pad0[0x11c];
    Shape *shape;
};

struct Fighter {
    char pad0[0x330];
    Body *b330;
    Body *b334;
    Body *b338;
};

struct Anchor {
    Fighter *FUN_00059a30();
};

struct FightHandle {
    Anchor *FUN_000592a0();
};

class CGrappleSizeCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(FightHandle *h);
    char pad04[0xc - 4];
    int mode;
    int size;
};

bool CGrappleSizeCondition::vfunc_7(FightHandle *h)
{
    if (h == 0)
        return false;
    Fighter *f = h->FUN_000592a0()->FUN_00059a30();
    Body *body = f->b334;
    if (body == 0)
        body = f->b330;
    if (body == 0)
        body = f->b338;
    if (body == 0)
        return false;
    Shape *shape = body->shape;
    if (shape == 0)
        return false;
    if (mode == 0)
        return shape->size == size;
    if (mode == 1)
        return shape->size != size;
    return false;
}
