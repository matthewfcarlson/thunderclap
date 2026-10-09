class Obj {
  public:
    virtual void F0();
    virtual void Release();
};

class Mgr {
  public:
    void Reset();
    void A(int);
    void B(int);
    void C();
    char pad0[0xb];
    char flags[0x320 * 8];
    char pad1[0x3548 - 0xb - 0x320 * 8];
    int v3548;
    char pad2[0x359c - 0x354c];
    int v359c;
    char pad3[0x3640 - 0x35a0];
    int v3640;
    char pad4[0x3740 - 0x3644];
    int v3740;
    char pad5[0x379c - 0x3744];
    int v379c;
    char pad6[0x37ac - 0x37a0];
    Obj* objs[20];
    int v37fc;
    char pad8[0x3828 - 0x3800];
    int v3828;
};

void Mgr::Reset() {
    for (int i = 0; i < 20; i++) {
        if (objs[i]) {
            objs[i]->Release();
            objs[i] = 0;
        }
    }
    v3548 = 0;
    while (v359c > 0)
        A(0);
    v3640 = 0;
    v3740 = 0;
    while (v379c > 0)
        B(0);
    for (int i = 0; i < 0x320; i++)
        flags[i * 8] = 0;
    C();
    v3828 = 0;
    v37fc = 0;
}
