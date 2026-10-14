// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_000e4640 @ 0x000e4640
class FEObject {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual char vfunc_19();
};

class FEContainer {
public:
    virtual void v0();
    char pad04[0x48 - 4];
    FEObject *focus;
    FEObject *items[128];
    void FUN_000e4640();
};

void FEContainer::FUN_000e4640()
{
    for (int i = 0; i < 128; i++) {
        FEObject *obj = items[i];
        if (obj != 0 && focus == obj && !obj->vfunc_19())
            focus = 0;
    }
    if (focus != 0)
        return;
    for (int i = 0; i < 128; i++) {
        if (items[i] != 0 && items[i]->vfunc_19()) {
            focus = items[i];
            return;
        }
    }
}
