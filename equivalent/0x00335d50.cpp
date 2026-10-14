// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 8/8)
// FUN_00335d50 @ 0x00335d50
struct TypeInfo {
    int tag;
};

struct Desc {
    char pad0[8];
    int kind;
    TypeInfo *type;
};

struct Types {
    char pad0[0x44];
    int count;
    Desc *FUN_00337090(int idx);
};

int __cdecl FUN_00337f20(int tag);

class Table {
public:
    char pad0[4];
    Types *types;
    char **rows;
    bool FUN_00335d50(int idx, int k, int *out0, int *out1);
};

bool Table::FUN_00335d50(int idx, int k, int *out0, int *out1)
{
    if (idx < 0 || idx >= types->count)
        return false;
    if (types->FUN_00337090(idx)->kind != 9)
        return false;
    char *row = rows[idx] + 4;
    if (types->FUN_00337090(idx)->type->tag != 7)
        return false;
    int off = FUN_00337f20(7) * k;
    *out0 = *(int *)(row + off);
    *out1 = *(int *)(row + off + 4);
    return true;
}
