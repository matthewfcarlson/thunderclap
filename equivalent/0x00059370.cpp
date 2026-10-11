// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/24)
// FUN_00059370 @ 0x00059370
class RefCounted {
public:
    virtual void addRef();
    virtual void release();
};

struct Slots {
    int f00;  // 0x0
    int f04;  // 0x4
    int f08;  // 0x8
    int f0c;  // 0xc
    int f10;  // 0x10
    char b14;  // 0x14
    char skip15[0x3];
    int f18;  // 0x18
    int f1c;  // 0x1c
    int f20;  // 0x20
    char b24;  // 0x24
    char skip25[0x3];
    int f28;  // 0x28
    int f2c;  // 0x2c
    int f30;  // 0x30
    char b34;  // 0x34
    char skip35[0x3];
    int f38;  // 0x38
    int f3c;  // 0x3c
    int f40;  // 0x40
    char b44;  // 0x44
    char skip45[0x3];
    int f48;  // 0x48
    RefCounted * r4c;  // 0x4c
    RefCounted * r50;  // 0x50
    int f54;  // 0x54
    int f58;  // 0x58
    int f5c;  // 0x5c
    RefCounted * r60;  // 0x60
    int f64;  // 0x64
    int f68;  // 0x68
    RefCounted * r6c;  // 0x6c
    RefCounted * r70;  // 0x70
    int f74;  // 0x74
    int f78;  // 0x78
    int f7c;  // 0x7c
    int f80;  // 0x80
    RefCounted * r84;  // 0x84
    int f88;  // 0x88
    int f8c;  // 0x8c
    char b90;  // 0x90
    char b91;  // 0x91
    char tail[2];
    Slots *FUN_00059370(const Slots *other);
};
Slots *Slots::FUN_00059370(const Slots *other)
{
    f48 = other->f48;
    {
        RefCounted *p = other->r4c;
        if (p)
            p->addRef();
        if (r4c)
            r4c->release();
        r4c = p;
    }
    {
        RefCounted *p = other->r50;
        if (p)
            p->addRef();
        if (r50)
            r50->release();
        r50 = p;
    }
    {
        RefCounted *p = other->r6c;
        if (p)
            p->addRef();
        if (r6c)
            r6c->release();
        r6c = p;
    }
    {
        RefCounted *p = other->r70;
        if (p)
            p->addRef();
        if (r70)
            r70->release();
        r70 = p;
    }
    {
        RefCounted *p = other->r84;
        if (p)
            p->addRef();
        if (r84)
            r84->release();
        r84 = p;
    }
    {
        RefCounted *p = other->r60;
        if (p)
            p->addRef();
        if (r60)
            r60->release();
        r60 = p;
    }
    f74 = other->f74;
    f08 = other->f08;
    f0c = other->f0c;
    f10 = other->f10;
    f18 = other->f18;
    f1c = other->f1c;
    f20 = other->f20;
    f38 = other->f38;
    f3c = other->f3c;
    f40 = other->f40;
    f00 = other->f00;
    f04 = other->f04;
    f54 = other->f54;
    b24 = other->b24;
    f58 = other->f58;
    f5c = other->f5c;
    f28 = other->f28;
    f2c = other->f2c;
    f30 = other->f30;
    f64 = other->f64;
    f68 = other->f68;
    f78 = other->f78;
    f7c = other->f7c;
    f80 = other->f80;
    f88 = other->f88;
    f8c = other->f8c;
    b14 = other->b14;
    b34 = other->b34;
    b90 = other->b90;
    b44 = other->b44;
    b91 = other->b91;
    return this;
}
