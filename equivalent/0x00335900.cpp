// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 8/8)
// FUN_00335900 @ 0x00335900
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
    bool FUN_00335900(int idx, int index2, char *out);
};
bool Target::FUN_00335900(int idx, int index2, char *out)
{
    if (idx < 0 || idx >= table->count || table->FUN_00337090(idx)->kind != 9)
        return false;
    char *base = rows[idx] + 4;
    if (table->FUN_00337090(idx)->type->kind != 0)
        return false;
    int off = FUN_00337f20(0) * index2;
    *out = *(char *)(base + off);
    return true;
}
