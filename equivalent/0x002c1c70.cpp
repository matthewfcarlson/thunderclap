// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_002c1c70 @ 0x002c1c70
struct CreateParams {
    int a1;
    int a2;
    int zero;
    int a3;
    int a4;
    int a5;
    int a6;
    int a7;
    char flag0;
    char flag1;
};

class Resource {
public:
    virtual void vfn0();
};

class Factory {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual Resource *vfn9(CreateParams *p);
};

extern Factory *DAT_0052c2a0;

class Holder {
public:
    bool FUN_002c1c70(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
    char pad0[0x10];
    Resource *res;
};

bool Holder::FUN_002c1c70(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    CreateParams p;
    p.a1 = a1;
    p.a2 = a2;
    p.zero = 0;
    p.a3 = a3;
    p.a4 = a4;
    p.a5 = a5;
    p.a6 = a6;
    p.a7 = a7;
    p.flag0 = 0;
    p.flag1 = 0;
    res = DAT_0052c2a0->vfn9(&p);
    if (!res)
        return false;
    res->vfn0();
    return true;
}
