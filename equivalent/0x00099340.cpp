// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00099340 @ 0x00099340
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void *thunk_FUN_0008d690(unsigned int size);

class Range_99340 {
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
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    char pad[0x2d0 - 4];
    Range_99340 *FUN_000ac7d0();
    void FUN_000a90f0(int which, int v);
    void FUN_000a9130(int which, int v);
    void FUN_000a9110(int which, float v);
};

class Panel_99340 {
public:
    char pad0[0xc4];
    Range_99340 *range;
    void FUN_00099340();
};

void Panel_99340::FUN_00099340()
{
    if (range == 0) {
        Range_99340 *r = (Range_99340 *)thunk_FUN_0008d690(0x2d0);
        if (r != 0)
            r = r->FUN_000ac7d0();
        range = r;
        r->v0();
        range->v28();
    }
    range->FUN_000a90f0(0, 0);
    range->FUN_000a9130(0, 0);
    range->FUN_000a9110(0, 1.0f);
    range->FUN_000a90f0(1, 0);
    range->FUN_000a9130(1, 0);
    range->FUN_000a9110(1, 1.0f);
}
