// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00327860 @ 0x00327860
struct SkinSource_327860 {
    void *FUN_00321da0(const char *name, int index, unsigned int flags, int one);
};

struct Skin_327860 {
    char pad0[0x10];
    int field_10;
    int index;
    unsigned int flags;
    char pad1[0x1c];
    SkinSource_327860 *source;
    void *result;
    void FUN_003270c0(int a);
    void FUN_00327130(int a);
    void FUN_00327860(int index, unsigned int flags, int unused, int a4, int a5, const char *name);
};

extern int DAT_004d3ea8[];
extern char DAT_005555b4;

void Skin_327860::FUN_00327860(int idx, unsigned int fl, int unused, int a4, int a5, const char *name)
{
    field_10 = DAT_004d3ea8[idx];
    index = idx;
    flags = fl;
    const char *s = &DAT_005555b4;
    if ((char)fl < 0) {
        s = (fl & 0x100) ? "skin" : "skin_onebone";
    }
    if (name != 0) {
        s = name;
    }
    result = source->FUN_00321da0(s, idx, fl, 1);
    FUN_003270c0(a4);
    FUN_00327130(a5);
}
