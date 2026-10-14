// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FEScreenBase::vfunc_1 @ 0x000e5620
class FEWidget {
public:
    virtual void v0();
    virtual void Event(int a, int b);
};

class FEOverlay {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool Event(int a, int b);
};

class FEScreenBase {
public:
    virtual void vfunc_0();
    virtual bool vfunc_1(int a, int b);
    char pad04[0x48 - 0x4];
    FEOverlay *overlay;
    char pad4c[0xa78 - 0x4c];
    void *blocker;
    char pad7c[0xab8 - 0xa7c];
    unsigned char active;
    char padb9[3];
    FEWidget *kids[32];
    int kidCount;
};

bool FEScreenBase::vfunc_1(int a, int b)
{
    if (!active || blocker != 0)
        return false;
    for (int i = 0; i < kidCount; i++)
        kids[i]->Event(a, b);
    if (overlay == 0)
        return false;
    return overlay->Event(a, b);
}
