// FEThingsBase::vfunc_6 @ 0x000e8310
// Releases every object held in the three widget tables.
class FEWidget_e8310 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void Release();
};

class FEThingsBase {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad04[8];
    FEWidget_e8310 *first[0x40];
    FEWidget_e8310 *second[0x40];
    FEWidget_e8310 *big[0x100];
};

void FEThingsBase::vfunc_6()
{
    for (int i = 0; i < 0x100; i++) {
        if (big[i])
            big[i]->Release();
    }
    for (int i = 0; i < 0x40; i++) {
        if (first[i])
            first[i]->Release();
    }
    for (int i = 0; i < 0x40; i++) {
        if (second[i])
            second[i]->Release();
    }
}
