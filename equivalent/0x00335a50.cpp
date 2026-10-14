// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 8/8)
// FUN_00335a50 @ 0x00335a50
struct TypeInfo { int kind; };
struct Entry { char pad0[8]; int kind; TypeInfo *type; };
struct Table {
    char pad0[0x44];
    int count;
    Entry *FUN_00337090(int idx);
};
int __cdecl FUN_00337f20(int n);
struct Target {
    char pad0[4];
    Table *table;
    char **rows;
    bool FUN_00335a50(int idx, int index2, int *out);
};
bool Target::FUN_00335a50(int idx, int index2, int *out)
{
    if (idx < 0 || idx >= table->count || table->FUN_00337090(idx)->kind != 9)
        return false;
    char *base = rows[idx] + 4;
    if (table->FUN_00337090(idx)->type->kind != 3)
        return false;
    int off = FUN_00337f20(3) * index2;
    *out = *(int *)(base + off);
    return true;
}
