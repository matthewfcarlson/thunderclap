// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 12/12)
// pure3d::BlendFrameController::vfunc_16 @ 0x002851b0
struct Entry {
    char pad0[0x14];
    float value;        // 0x14
    char pad18[4];
    int mode;           // 0x1c
    char flag;          // 0x20
    char pad21[0x2c - 0x21];
};

class BlendFrameController {
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
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void vfunc_16(int mode);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual float GetEnd();             // slot 20
    char pad04[0x20 - 4];
    int mode;               // 0x20
    int f24;                // 0x24
    unsigned int count;     // 0x28
    char pad2c[4];
    Entry entries[1];       // 0x30
};

void BlendFrameController::vfunc_16(int newMode)
{
    if (mode == newMode)
        return;
    mode = newMode;
    if (count == 0)
        return;
    Entry* e = &entries[count - 1];
    e->mode = newMode;
    e->value = GetEnd();
    if (e->mode == 0) {
        if (e->value == 3.4028235e38f)
            f24 = 0;
    }
    e->flag = (e->mode != 3 && e->mode != 5);
}
