// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 8/8)
// FUN_00335c40 @ 0x00335c40
struct TypeInfo_335c40 {
    int tag;
};

struct Desc_335c40 {
    char pad0[8];
    int kind;
    TypeInfo_335c40 *type;
};

struct Types_335c40 {
    char pad0[0x44];
    int count;
    Desc_335c40 *FUN_00337090(int idx);
};

int __cdecl FUN_00337f20(int tag);

class Table_335c40 {
public:
    char pad0[4];
    Types_335c40 *types;
    char **rows;
    bool FUN_00335c40(int idx, int k, int *out0, int *out1);
};

bool Table_335c40::FUN_00335c40(int idx, int k, int *out0, int *out1)
{
    if (idx < 0 || idx >= types->count)
        return false;
    if (types->FUN_00337090(idx)->kind != 9)
        return false;
    char *row = rows[idx] + 4;
    if (types->FUN_00337090(idx)->type->tag != 5)
        return false;
    int off = FUN_00337f20(5) * k;
    *out0 = *(int *)(row + off);
    *out1 = *(int *)(row + off + 4);
    return true;
}
