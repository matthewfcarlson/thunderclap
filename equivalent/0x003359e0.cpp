// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 8/8)
// FUN_003359e0 @ 0x003359e0
struct TypeInfo_3359e0 { int kind; };
struct Entry_3359e0 { char pad0[8]; int kind; TypeInfo_3359e0 *type; };
struct Table_3359e0 {
    char pad0[0x44];
    int count;
    Entry_3359e0 *FUN_00337090(int idx);
};
int __cdecl FUN_00337f20(int n);
struct Target_3359e0 {
    char pad0[4];
    Table_3359e0 *table;
    char **rows;
    bool FUN_003359e0(int idx, int index2, int *out);
};
bool Target_3359e0::FUN_003359e0(int idx, int index2, int *out)
{
    if (idx < 0 || idx >= table->count || table->FUN_00337090(idx)->kind != 9)
        return false;
    char *base = rows[idx] + 4;
    if (table->FUN_00337090(idx)->type->kind != 2)
        return false;
    int off = FUN_00337f20(2) * index2;
    *out = *(int *)(base + off);
    return true;
}
