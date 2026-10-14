// FUN_002d0a50: optionally update, then dispatch to one of four renderers
// depending on the attached object (+0x58), the mode flag and member +0x14
struct Attached {
    char pad00[8];
    unsigned int flags;
};

struct Ctrl {
    char pad00[0x14];
    int f14;
    char pad18[0x50 - 0x18];
    int f50;
    char pad54[4];
    Attached *f58;

    void FUN_002c8a80(int b, int c);
    void FUN_002c92f0(int b, int c);
    void FUN_002d0a50(void *a, int b, int c);
};

// equiv-conv: FUN_002cec10 ecx edx esi
void __cdecl FUN_002cec10(Ctrl *self, char flag, void *a);
// equiv-conv: FUN_002cd130 eax edx esi
void __cdecl FUN_002cd130(Ctrl *self, char flag, void *a);
// equiv-conv: FUN_002c7e40 eax ecx esi
void __cdecl FUN_002c7e40(Ctrl *self, char flag, void *a);
// equiv-conv: FUN_002c8130 eax ecx esi
void __cdecl FUN_002c8130(Ctrl *self, char flag, void *a);

void Ctrl::FUN_002d0a50(void *a, int b, int c)
{
    char flag;
    bool special;
    if (c != 0 && f50 != 0) {
        if (f58 != 0)
            FUN_002c8a80(b, c);
        else
            FUN_002c92f0(b, c);
        flag = 1;
        special = f58 != 0 && (f58->flags & 0xffffffcf) != 0;
    } else {
        flag = 0;
        special = f58 != 0;
    }

    if (special) {
        if (f14 == 0)
            FUN_002cec10(this, flag, a);
        else
            FUN_002cd130(this, flag, a);
    } else {
        if (f14 == 0)
            FUN_002c8130(this, flag, a);
        else
            FUN_002c7e40(this, flag, a);
    }
}
