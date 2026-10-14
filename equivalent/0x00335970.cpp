// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 8/8)
// FUN_00335970 @ 0x00335970
struct TypeInfo_335970 { int kind; };
struct Entry_335970 { char pad0[8]; int kind; TypeInfo_335970 *type; };
struct Table_335970 {
    char pad0[0x44];
    int count;
    Entry_335970 *FUN_00337090(int idx);
};
int __cdecl FUN_00337f20(int n);
struct Target_335970 {
    char pad0[4];
    Table_335970 *table;
    char **rows;
    bool FUN_00335970(int idx, int index2, int *out);
};
bool Target_335970::FUN_00335970(int idx, int index2, int *out)
{
    if (idx < 0 || idx >= table->count || table->FUN_00337090(idx)->kind != 9)
        return false;
    char *base = rows[idx] + 4;
    if (table->FUN_00337090(idx)->type->kind != 1)
        return false;
    int off = FUN_00337f20(1) * index2;
    *out = *(int *)(base + off);
    return true;
}
