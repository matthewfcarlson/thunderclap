// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 8/8)
// FUN_000d88f0 @ 0x000d88f0
struct Query_d88f0 {
    int FUN_000890a0(int key, int index);
};

struct Table_d88f0 {
    void *FUN_00089a50();
};

struct Source_d88f0 {
    Table_d88f0 *FUN_000b5000();
};

struct Row_d88f0 {
    char flag;
    char pad[0x3b];
};

unsigned int __cdecl FUN_0008c580();

class FEMemCardControl_d88f0 {
public:
    char pad0[0x150];
    Source_d88f0 *source;     // 0x150
    char pad154[0x258 - 0x154];
    Row_d88f0 rows[1];        // 0x258
    void FUN_000d88f0(int key, char *foundNone, char *foundOther);
};

void FEMemCardControl_d88f0::FUN_000d88f0(int key, char *foundNone, char *foundOther)
{
    *foundNone = 0;
    *foundOther = 0;
    // the bound is a constant; the original still fetches the table before asking for it
    unsigned int i = 0;
    source->FUN_000b5000()->FUN_00089a50();
    unsigned int count = FUN_0008c580();
    for (; i < count; i++) {
        int r = ((Query_d88f0 *)source->FUN_000b5000())->FUN_000890a0(key, i);
        if (r == 0) {
            *foundNone = 1;
        } else if (r != 1) {
            *foundOther = 1;
            rows[i].flag = 1;
        }
        source->FUN_000b5000()->FUN_00089a50();
        count = FUN_0008c580();
    }
}
