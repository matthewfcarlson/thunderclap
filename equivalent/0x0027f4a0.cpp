// STATUS: equivalent (tools/equiv.py level 3: 1557 inputs, branch coverage 6/6)
// FUN_0027f4a0 @ 0x0027f4a0
struct Device_27f4a0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void SetTexture(int handle, int value);                         // slot 32
    virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61();
    virtual void SetFlag(char on);                                          // slot 62
    virtual char GetFlag();                                                 // slot 63
};

struct Resource_27f4a0 {
    char pad0[0x10];
    int handle;             // 0x10
};

struct Slot_27f4a0 {
    Resource_27f4a0 *resource;     // 0x0
    char pad4[0xc];
    int value;              // 0x10
    char pad14[8];
};

extern Device_27f4a0 *DAT_0052c2a8;

class Ring_27f4a0 {
public:
    char pad0[0x10];
    unsigned int cursor;    // 0x10
    int count;              // 0x14
    char pad18[0x28 - 0x18];
    Slot_27f4a0 slots[100];        // 0x28

    void FUN_0027f4a0();
};

void Ring_27f4a0::FUN_0027f4a0()
{
    union {
        unsigned int word;
        char flag;
    } saved;
    saved.flag = DAT_0052c2a8->GetFlag();
    DAT_0052c2a8->SetFlag(0);
    for (int i = 0; i < 85; i++) {
        Slot_27f4a0 *s = &slots[(cursor + i + 15) % 100];
        if (s->resource != 0 && s->value != 0)
            DAT_0052c2a8->SetTexture(s->resource->handle, s->value);
    }
    count = 15;
    DAT_0052c2a8->SetFlag((char)saved.word);
}
