extern "C" char DAT_003f7d48[];
extern "C" char DAT_003f7d70[];
extern "C" char DAT_0042773c[];
extern "C" void* __cdecl Alloc(unsigned int);
extern int gGuard;
extern int gTable;
extern int gSix;
struct ParamEnumConstList {
    int pad[5];
    int field14;
    int field18;
    void Init(const char*);
};
struct ParamIntConstRange {
    int pad[4];
    int field10;
    void Init(const char*);
};
extern void __cdecl Register(void*, void**, int);
void FUN_00053d80() {
    if (gGuard) {
        ++gGuard;
        return;
    }
    void* slots[2];
    ParamEnumConstList* a = (ParamEnumConstList*)Alloc(0x20);
    if (a) {
        int k = gSix;
        a->Init("compare");
        a->field14 = k;
        a->pad[0] = ((int)DAT_003f7d48);
        a->pad[4] = ((int)DAT_0042773c);
        a->field18 = 0x47f80;
        slots[0] = a;
    } else
        slots[0] = 0;
    ParamIntConstRange* b = (ParamIntConstRange*)Alloc(0x18);
    if (b) {
        b->Init("state");
        b->pad[0] = ((int)DAT_003f7d70);
        b->field10 = 0x47f90;
        slots[1] = b;
    } else
        slots[1] = 0;
    Register(&gTable, slots, 2);
    ++gGuard;
}