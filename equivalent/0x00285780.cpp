// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00285780 @ 0x00285780
// 0x00285780: SimpleFrameController copy constructor
extern char DAT_0042c5bc[];
extern char DAT_0042c624[];
extern char DAT_0042c694[];

struct Ref_285780 {
    virtual void AddRef();
    virtual void Release();
};

class SimpleFrameController_285780 {
public:
    int vptr;
    char pad04[0xc];
    char field_10;
    char pad11[7];
    int field_18;
    char pad1c[4];
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
    int field_30;
    int field_34;
    char field_38;
    char pad39[3];
    Ref_285780* ref;
    void FUN_0027b0b0(const SimpleFrameController_285780* src);
    SimpleFrameController_285780* FUN_00285780(const SimpleFrameController_285780* src);
};

SimpleFrameController_285780* SimpleFrameController_285780::FUN_00285780(const SimpleFrameController_285780* src)
{
    FUN_0027b0b0(src);
    vptr = (int)DAT_0042c5bc;
    vptr = (int)DAT_0042c624;
    field_10 = src->field_10;
    field_18 = src->field_18;
    vptr = (int)DAT_0042c694;
    field_20 = src->field_20;
    field_24 = src->field_24;
    field_28 = src->field_28;
    field_2c = src->field_2c;
    field_30 = src->field_30;
    field_34 = src->field_34;
    field_38 = src->field_38;
    ref = 0;
    Ref_285780* r = src->ref;
    if (r != 0)
        r->AddRef();
    if (ref != 0)
        ref->Release();
    ref = r;
    return this;
}
