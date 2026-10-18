class FEChild {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void Notify(int arg);
};

class FEAnimChild {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void Notify(int arg);
};

class FEContainer {
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
    virtual void vfunc_11();
    virtual void vfunc_12(int arg);
    char pad4[0x4c - 4];
    FEChild* children[0x100];
    FEAnimChild* anims[0x80];
};

void FEContainer::vfunc_12(int arg)
{
    // both tables are packed: a null entry ends the list
    for (int i = 0; i < 0x80; i++) {
        if (!children[i])
            break;
        children[i]->Notify(arg);
    }
    for (int i = 0; i < 0x80; i++) {
        if (!anims[i])
            break;
        anims[i]->Notify(arg);
    }
}
