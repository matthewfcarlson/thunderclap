// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000dc590 @ 0x000dc590
class FEBase_dc590 {
public:
    FEBase_dc590(int arg) throw();
    virtual void v0();
    char pad04[0x44 - 4];
    int link;
    char pad48[0x118 - 0x48];
};

class FEControl : public FEBase_dc590 {
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

class FETextInput : public FEControl {
public:
    FETextInput(int arg) throw();
    virtual void t0();
    int cursor[8];      // 0x150
    unsigned int color; // 0x170
    int f174;
    int f178;
    char f17c;
};

// equiv-map: ??0FEControl@@QAE@H@Z = 0x000e9240
FETextInput::FETextInput(int arg) throw() : FEControl(arg)
{
    for (int i = 0; i < 8; i++)
        cursor[i] = 0;
    color = 0x50ffffff;
    f174 = -1;
    f178 = 1;
    f17c = 1;
}
