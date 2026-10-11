// STATUS: equivalent (tools/equiv.py level 3: 26 inputs, branch coverage 36/36)
// FEThingsBase::vfunc_4 @ 0x000efaf0
struct Owned {
    virtual ~Owned();
};
struct Released {
    virtual void vfn0();
    virtual void vfn1();
};
class FEThingsBase {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    char pad0[0x8];
    Owned *objsA[0x40];       // 0xc
    Owned *objsB[0x40];       // 0x10c
    Owned *objsC[0x100];      // 0x20c
    Owned *objsD[0x400];      // 0x60c
    char pad1[0x170c - 0x160c];
    char flag170c;
    char pad2[0x175c - 0x170d];
    int f175c;
    int f1760;
    char pad3[4];
    int f1768;
    int f176c;
    int tab1770[16];
    int f17b0;
    int tab17b4[16];
    int f17f4;
    char pad4[0x1830 - 0x17f8];
    int f1830;
    char pad5[0x1854 - 0x1834];
    Released *resA[2];        // 0x1854
    char pad6[0x1a5c - 0x185c];
    Released *resB[2];        // 0x1a5c
    char pad7[0x1c64 - 0x1a64];
    Released *resC[2];        // 0x1c64
    Released *resD[2];        // 0x1c6c
    char pad8[0x2080 - 0x1c74];
    int slots2080[0x20];
    int f2100;
    char flag2104;
};

void FEThingsBase::vfunc_4()
{
    int i;
    f175c = 0;
    f1768 = 0;
    f1760 = 0;
    for (i = 0; i < 16; i++) tab1770[i] = 0;
    f17b0 = -1;
    for (i = 0; i < 16; i++) tab17b4[i] = 0;
    f17f4 = -1;
    f176c = 0;
    f1830 = 0;
    for (i = 0; i < 0x20 && slots2080[i] != 0; i++) slots2080[i] = 0;
    flag170c = 0;
    for (i = 0; i < 0x40; i++) {
        if (objsA[i]) { delete objsA[i]; objsA[i] = 0; }
    }
    for (i = 0; i < 0x40; i++) {
        if (objsB[i]) { delete objsB[i]; objsB[i] = 0; }
    }
    for (i = 0; i < 0x100; i++) {
        if (objsC[i]) { delete objsC[i]; objsC[i] = 0; }
    }
    for (i = 0; i < 0x400; i++) {
        if (objsD[i]) { delete objsD[i]; objsD[i] = 0; }
    }
    for (i = 0; i < 2; i++) {
        if (resA[i]) { resA[i]->vfn1(); resA[i] = 0; }
    }
    for (i = 0; i < 2; i++) {
        if (resB[i]) { resB[i]->vfn1(); resB[i] = 0; }
    }
    for (i = 0; i < 2; i++) {
        if (resC[i]) { resC[i]->vfn1(); resC[i] = 0; }
    }
    for (i = 0; i < 2; i++) {
        if (resD[i]) { resD[i]->vfn1(); resD[i] = 0; }
    }
    f2100 = 0;
    flag2104 = 0;
}
