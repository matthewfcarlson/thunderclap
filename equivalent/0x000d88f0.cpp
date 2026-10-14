// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000d88f0 @ 0x000d88f0
struct Query {
    int FUN_000890a0(int key, int index);
};

struct Table {
    void *FUN_00089a50();
};

struct Source {
    Table *FUN_000b5000();
};

struct Row {
    char flag;
    char pad[0x3b];
};

unsigned int __cdecl FUN_0008c580();

class Panel {
public:
    char pad0[0x150];
    Source *source;     // 0x150
    char pad154[0x258 - 0x154];
    Row rows[1];        // 0x258
    void FUN_000d88f0(int key, char *foundNone, char *foundOther);
};

void Panel::FUN_000d88f0(int key, char *foundNone, char *foundOther)
{
    *foundNone = 0;
    *foundOther = 0;
    // the bound is a constant; the original still fetches the table before asking for it
    unsigned int i = 0;
    source->FUN_000b5000()->FUN_00089a50();
    unsigned int count = FUN_0008c580();
    for (; i < count; i++) {
        int r = ((Query *)source->FUN_000b5000())->FUN_000890a0(key, i);
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
