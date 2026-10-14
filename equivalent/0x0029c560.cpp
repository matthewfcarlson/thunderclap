// STATUS: equivalent (tools/equiv.py level 3: 487 inputs, branch coverage 12/12)
// FUN_0029c560 @ 0x0029c560
struct Rec { char flag; char pad[0x3f]; };
struct Device {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34();
    virtual void SetActive(int id);
    virtual int *GetActive(int *out);
    virtual void Configure(int i, Rec *rec, int enable);
    virtual void Release(int i, int mode);
    virtual bool IsValid(int i);
};
extern Device *DAT_0052c2a8;

class Bank {
public:
    char pad0[0x10];
    int numSlots;
    int numRecs;
    char pad18[0x24 - 0x18];
    Rec *recs;
    char pad28[0x34 - 0x28];
    int active;
    void FUN_0029c560();
};

void Bank::FUN_0029c560()
{
    int i;
    for (i = 0; i < numRecs; i++) {
        recs[i].flag = 1;
        DAT_0052c2a8->Configure(i, &recs[i], 1);
    }
    for (; i < numSlots; i++) {
        if (!DAT_0052c2a8->IsValid(i))
            break;
        DAT_0052c2a8->Release(i, 0);
    }
    int tmp;
    if (*DAT_0052c2a8->GetActive(&tmp) != active)
        DAT_0052c2a8->SetActive(active);
}
