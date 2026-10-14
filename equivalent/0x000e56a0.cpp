// STATUS: equivalent (tools/equiv.py level 3: 655 inputs, branch coverage 8/8)
// FEScreenBase::vfunc_2 @ 0x000e56a0
class FEChild_e56a0 {
public:
    virtual void v0();
    virtual void v1();
    virtual char vfunc_2(int a, int b);
};

class FEFocus {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual char vfunc_6(int a, int b);
};

class FEScreenBase {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual char vfunc_2(int a, int b);
    char pad04[0x48 - 4];
    FEFocus *focus;
    char pad4c[0xab8 - 0x4c];
    char active;
    FEChild_e56a0 *children[32];
    int numChildren;
};

char FEScreenBase::vfunc_2(int a, int b)
{
    if (!active)
        return 0;
    for (int i = 0; i < numChildren; i++)
        children[i]->vfunc_2(a, b);
    if (focus == 0)
        return 0;
    return focus->vfunc_6(a, b);
}
