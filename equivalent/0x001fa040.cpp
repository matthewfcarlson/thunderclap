// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_001fa040 @ 0x001fa040
struct Name_1fa040 {
    unsigned int lo, hi;
    void FUN_0027b040(const char* s);
};
struct Tree_1fa040 {
    void FUN_00230f50(void (__cdecl *cb)(void*, void*), void* user);
};
struct Pool_1fa040 {
    bool FUN_001d1900(int n);
};
Pool_1fa040* FUN_001d4c90();
void FUN_00267760(char* dst, int n, const char* fmt, ...);
void __cdecl FUN_001f9f80(void* node, void* user);

struct SlotA_1fa040 {
    int a0;
    int a4;
    int a8;
    int ac;
    int a10;
    int a14;
    int a18;
    int a1c;
    int a20;
    char a24;
    char pad25[3];
};
struct SlotB_1fa040 {
    int b0;
    char label[0x20];
    int pad24;
    Name_1fa040 name;
    unsigned char c30;
    unsigned char c31;
    char pad32[2];
    int pad34;
    int f38;
    int f3c;
    int f40;
    int f44;
    char f48;
    char f49;
    short f4a;
    int pad4c;
    int w50;
    Tree_1fa040* tree54;
};

class Table_1fa040 {
public:
    char pad0[8];
    Name_1fa040 name;
    char pad10[0x410 - 0x10];
    int f410;
    int f414;
    int f418;
    char title[0x20];
    int f43c;
    int f440;
    short f444;
    char pad446[2];
    int f448;
    int f44c;
    char f450;
    char pad451[3];
    int f454;
    int f458;
    int f45c;
    SlotA_1fa040 slotsA[16];
    int f6e0;
    char pad6e4[0x6f0 - 0x6e4];
    SlotB_1fa040 slotsB[16];
    void FUN_001fa040();
};

void Table_1fa040::FUN_001fa040()
{
    f410 = 0;
    f414 = -1;
    f418 = 0;
    name.FUN_0027b040("CONSTRUCTED, BUT NOT YET NAMED");
    FUN_00267760(title, 0x20, "%s", "CONSTRUCTED, BUT NOT YET NAMED");
    f43c = 0;
    f450 = 0;
    f454 = 1;
    f458 = 0;
    f45c = 0;
    f6e0 = 0;
    // words in the tail of the last slotB record: one is cleared here, the next is read as a Tree below
    slotsB[15].w50 = 0;
    for (int i = 0; i < 16; i++) {
        SlotA_1fa040& s = slotsA[i];
        s.a0 = 0;
        s.a4 = -1;
        s.a8 = -1;
        s.ac = 0;
        s.a10 = 0;
        s.a14 = 0;
        s.a18 = 0;
        s.a1c = 0;
        s.a24 = 0;
        Pool_1fa040* p = FUN_001d4c90();
        p->FUN_001d1900(s.a20);
        s.a20 = -1;
    }
    for (int j = 0; j < 16; j++) {
        SlotB_1fa040& s = slotsB[j];
        s.b0 = 0;
        FUN_00267760(s.label, 0x20, "CONSTRUCTED, BUT NOT YET NAMED");
        s.f38 = 0;
        s.f3c = 0;
        s.f40 = 0;
        s.f44 = 0;
        s.c30 = 0xff;
        s.name.FUN_0027b040("");
        s.c31 = 0xff;
        s.f48 = 0;
        s.f49 = 1;
        s.f4a = -1;
    }
    f440 = 0;
    f444 = 0;
    Tree_1fa040* tree = slotsB[15].tree54;
    tree->FUN_00230f50(FUN_001f9f80, tree);
    Pool_1fa040* pool = FUN_001d4c90();
    pool->FUN_001d1900(f448);
    int old = f44c;
    f448 = -1;
    pool->FUN_001d1900(old);
    f44c = -1;
}
