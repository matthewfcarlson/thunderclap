// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000e9240 @ 0x000e9240
class FEObject_e9240 {
public:
    FEObject_e9240(int arg) throw();
    virtual void v0();
    char pad04[0x44 - 4];
    int link;
    char pad48[0x118 - 0x48];
};

class FEControl : public FEObject_e9240 {
public:
    FEControl(int arg) throw();
    virtual void c0();
    int slots[10];
    bool flag0;
    bool flag1;
    bool flag2;
    bool flag3;
    char flag4;
    char pad145[3];
    int link0;
    int link1;
};

// equiv-map: ??0FEBase@@QAE@H@Z = 0x000e2860
FEControl::FEControl(int arg) throw() : FEObject_e9240(arg)
{
    for (int i = 0; i < 10; i++)
        slots[i] = 0;
    flag0 = true;
    flag1 = true;
    flag2 = true;
    flag3 = true;
    link0 = link;
    link1 = link;
    flag4 = 0;
}
