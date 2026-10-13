// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 102/102)
// FUN_000b2810 @ 0x000b2810
extern char DAT_0049caae;
extern "C" char *__cdecl FUN_00267830(char *dst, const char *src, int n);

struct Arr {
    int cap;
    char *data;
    void FUN_000b1020(int n);
};

class Pad {
public:
    char pad0[0xc - 0x0];
    char b0c;
    char padd[0x58 - 0xd];
    Arr a58;
    Arr a60;
    Arr a68;
    Arr a70;
    Arr a78;
    Arr a80;
    Arr a88;
    Arr a90;
    Arr a98;
    Arr aa0;
    Arr aa8;
    Arr ab0;
    Arr ab8;
    Arr ac0;
    Arr ac8;
    Arr ad0;
    Arr ad8;
    Arr ae0;
    Arr ae8;
    Arr af0;
    Arr af8;
    Arr a100;
    Arr a108;
    char pad110[0x1c8 - 0x110];
    Arr a1c8;
    Arr a1d0;
    Arr a1d8;
    Arr a1e0;
    Arr a1e8;
    Arr a1f0;
    Arr a1f8;
    Arr a200;
    Arr a208;
    Arr a210;
    Arr a218;
    Arr a220;
    Arr a228;
    Arr a230;
    Arr a238;
    Arr a240;
    Arr a248;
    Arr a250;
    Arr a258;
    Arr a260;
    Arr a268;
    Arr a270;
    Arr a278;
    Arr a280;
    Arr a288;
    char pad290[0x490 - 0x290];
    float f490;
    float f494;
    float f498;
    float f49c;
    float f4a0;
    float f4a4;
    void FUN_000b1db0();
    void FUN_000b2810();
};

void Pad::FUN_000b2810()
{
    b0c = 1;
    f490 = 0.2f;
    f494 = 0.8f;
    f498 = 0.35f;
    f49c = 0.8f;
    f4a0 = 0.8f;
    f4a4 = 1.0f;
    if (!(a58.cap > 0))
        a58.FUN_000b1020(1);
    FUN_00267830(a58.data, "A", 0x20);
    if (!(a60.cap > 0))
        a60.FUN_000b1020(1);
    FUN_00267830(a60.data, "B", 0x20);
    if (!(a68.cap > 0))
        a68.FUN_000b1020(1);
    FUN_00267830(a68.data, "X", 0x20);
    if (!(a70.cap > 0))
        a70.FUN_000b1020(1);
    FUN_00267830(a70.data, "Y", 0x20);
    if (!(a78.cap > 0))
        a78.FUN_000b1020(1);
    FUN_00267830(a78.data, "Start", 0x20);
    if (!(a80.cap > 0))
        a80.FUN_000b1020(1);
    FUN_00267830(a80.data, "Back", 0x20);
    if (!(a88.cap > 0))
        a88.FUN_000b1020(1);
    FUN_00267830(a88.data, "Back", 0x20);
    if (!(a90.cap > 0))
        a90.FUN_000b1020(1);
    FUN_00267830(a90.data, "LeftTrigger", 0x20);
    if (!(a98.cap > 0))
        a98.FUN_000b1020(1);
    FUN_00267830(a98.data, "RightTrigger", 0x20);
    if (!(aa0.cap > 0))
        aa0.FUN_000b1020(1);
    FUN_00267830(aa0.data, "Black", 0x20);
    if (!(aa8.cap > 0))
        aa8.FUN_000b1020(1);
    FUN_00267830(aa8.data, "White", 0x20);
    if (!(ab0.cap > 0))
        ab0.FUN_000b1020(1);
    FUN_00267830(ab0.data, "LeftStickX", 0x20);
    if (!(ab8.cap > 0))
        ab8.FUN_000b1020(1);
    FUN_00267830(ab8.data, "DPadRight", 0x20);
    if (!(ac0.cap > 0))
        ac0.FUN_000b1020(1);
    FUN_00267830(ac0.data, "DPadLeft", 0x20);
    if (!(ac8.cap > 0))
        ac8.FUN_000b1020(1);
    FUN_00267830(ac8.data, "LeftStickY", 0x20);
    if (!(ad0.cap > 0))
        ad0.FUN_000b1020(1);
    FUN_00267830(ad0.data, "DPadUp", 0x20);
    if (!(ad8.cap > 0))
        ad8.FUN_000b1020(1);
    FUN_00267830(ad8.data, "DPadDown", 0x20);
    if (!(ae0.cap > 0))
        ae0.FUN_000b1020(1);
    FUN_00267830(ae0.data, "RightStickX", 0x20);
    if (!(ae8.cap > 0))
        ae8.FUN_000b1020(1);
    FUN_00267830(ae8.data, "", 0x20);
    if (!(af0.cap > 0))
        af0.FUN_000b1020(1);
    FUN_00267830(af0.data, "", 0x20);
    if (!(af8.cap > 0))
        af8.FUN_000b1020(1);
    FUN_00267830(af8.data, "RightStickY", 0x20);
    if (!(a100.cap > 0))
        a100.FUN_000b1020(1);
    FUN_00267830(a100.data, "", 0x20);
    if (!(a108.cap > 0))
        a108.FUN_000b1020(1);
    FUN_00267830(a108.data, "", 0x20);
    if (!(a1c8.cap > 0))
        a1c8.FUN_000b1020(1);
    FUN_00267830(a1c8.data, "X", 0x20);
    if (!(a1d0.cap > 0))
        a1d0.FUN_000b1020(1);
    FUN_00267830(a1d0.data, "Y", 0x20);
    if (!(a1d8.cap > 0))
        a1d8.FUN_000b1020(1);
    FUN_00267830(a1d8.data, "B", 0x20);
    if (!(a1e0.cap > 0))
        a1e0.FUN_000b1020(1);
    FUN_00267830(a1e0.data, "A", 0x20);
    a1e8.FUN_000b1020(2);
    if (!(a1e8.cap > 0))
        a1e8.FUN_000b1020(1);
    FUN_00267830(a1e8.data, "Black", 0x20);
    if (!(a1e8.cap > 0))
        a1e8.FUN_000b1020(1);
    FUN_00267830(a1e8.data + 0x20, "White", 0x20);
    if (!(a1f0.cap > 0))
        a1f0.FUN_000b1020(1);
    FUN_00267830(a1f0.data, "RightTrigger", 0x20);
    if (!(a1f8.cap > 0))
        a1f8.FUN_000b1020(1);
    FUN_00267830(a1f8.data, "LeftTrigger", 0x20);
    if (!(a200.cap > 0))
        a200.FUN_000b1020(1);
    FUN_00267830(a200.data, "Start", 0x20);
    if (!(a208.cap > 0))
        a208.FUN_000b1020(1);
    FUN_00267830(a208.data, "Back", 0x20);
    if (!(a210.cap > 0))
        a210.FUN_000b1020(1);
    FUN_00267830(a210.data, "LeftThumb", 0x20);
    if (!(a218.cap > 0))
        a218.FUN_000b1020(1);
    FUN_00267830(a218.data, "RightThumb", 0x20);
    if (!(a220.cap > 0))
        a220.FUN_000b1020(1);
    FUN_00267830(a220.data, "LeftJoystick", 0x20);
    if (!(a228.cap > 0))
        a228.FUN_000b1020(1);
    FUN_00267830(a228.data, "RightJoystick", 0x20);
    if (!(a230.cap > 0))
        a230.FUN_000b1020(1);
    FUN_00267830(a230.data, "LeftStickX", 0x20);
    if (!DAT_0049caae) {
        if (!(a238.cap > 0))
            a238.FUN_000b1020(1);
        FUN_00267830(a238.data, "DPadRight", 0x20);
        if (!(a240.cap > 0))
            a240.FUN_000b1020(1);
        FUN_00267830(a240.data, "DPadLeft", 0x20);
    }
    if (!(a248.cap > 0))
        a248.FUN_000b1020(1);
    FUN_00267830(a248.data, "LeftStickY", 0x20);
    if (!DAT_0049caae) {
        if (!(a250.cap > 0))
            a250.FUN_000b1020(1);
        FUN_00267830(a250.data, "DPadUp", 0x20);
        if (!(a258.cap > 0))
            a258.FUN_000b1020(1);
        FUN_00267830(a258.data, "DPadDown", 0x20);
    }
    if (!(a260.cap > 0))
        a260.FUN_000b1020(1);
    FUN_00267830(a260.data, "RightStickX", 0x20);
    if (!(a268.cap > 0))
        a268.FUN_000b1020(1);
    FUN_00267830(a268.data, "", 0x20);
    if (!(a270.cap > 0))
        a270.FUN_000b1020(1);
    FUN_00267830(a270.data, "", 0x20);
    if (!(a278.cap > 0))
        a278.FUN_000b1020(1);
    FUN_00267830(a278.data, "RightStickY", 0x20);
    if (!(a280.cap > 0))
        a280.FUN_000b1020(1);
    FUN_00267830(a280.data, "", 0x20);
    if (!(a288.cap > 0))
        a288.FUN_000b1020(1);
    FUN_00267830(a288.data, "", 0x20);
    FUN_000b1db0();
}
