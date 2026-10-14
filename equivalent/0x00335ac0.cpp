// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 12/12)
// FUN_00335ac0 @ 0x00335ac0
struct TypeInfo_335ac0 {
    int kind;
};

struct Value_335ac0 {
    char pad00[8];
    int type;                // 0x08
    TypeInfo_335ac0 *info;          // 0x0c
};

class Table_335ac0 {
public:
    char pad00[0x44];
    int count;               // 0x44
    Value_335ac0 *FUN_00337090(int index);
};

int __cdecl FUN_00337f20(int kind);

class Reader {
public:
    char pad00[4];
    Table_335ac0 *table;            // 0x04
    char **rows;             // 0x08
    bool FUN_00335ac0(int column, int row, unsigned int *outLength);
};

// Length of the string stored in a string-typed column (0 when null).
bool Reader::FUN_00335ac0(int column, int row, unsigned int *outLength) {
    if (column < 0 || column >= table->count)
        return false;
    if (table->FUN_00337090(column)->type != 9)
        return false;
    char *base = rows[column] + 4;
    if (table->FUN_00337090(column)->info->kind != 4)
        return false;
    const char *s = *(const char **)(base + FUN_00337f20(4) * row);
    if (s == 0) {
        *outLength = 0;
        return true;
    }
    const char *e = s;
    while (*e)
        e++;
    *outLength = e - s;
    return true;
}
