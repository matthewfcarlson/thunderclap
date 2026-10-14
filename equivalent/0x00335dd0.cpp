// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 8/8)
// FUN_00335dd0 @ 0x00335dd0
struct TypeDesc_335dd0 {
    int kind;
};

struct Entry_335dd0 {
    char pad0[8];
    int type;               // 0x8
    TypeDesc_335dd0 *desc;         // 0xc
};

struct Registry_335dd0 {
    char pad0[0x44];
    int count;              // 0x44
    Entry_335dd0 *FUN_00337090(int index);
};

extern "C" int __cdecl FUN_00337f20(int type);

struct Table_335dd0 {
    char pad0[4];
    Registry_335dd0 *registry;     // 4
    char **columns;         // 8
    bool FUN_00335dd0(int index, int row, int *out0, int *out1, int *out2);
};

bool Table_335dd0::FUN_00335dd0(int index, int row, int *out0, int *out1, int *out2)
{
    if (index < 0 || index >= registry->count)
        return false;
    if (registry->FUN_00337090(index)->type != 9)
        return false;

    int *base = (int *)(columns[index] + 4);
    if (registry->FUN_00337090(index)->desc->kind != 8)
        return false;

    int *rec = (int *)((char *)base + FUN_00337f20(8) * row);
    *out0 = rec[0];
    *out1 = rec[1];
    *out2 = rec[2];
    return true;
}
