// STATUS: equivalent (tools/equiv.py level 3: 3031 inputs, branch coverage 12/12)
// FUN_00335e60 @ 0x00335e60
struct TypeInfo {
    int kind;
};

struct Value {
    char pad00[8];
    int type;                // 0x08
    TypeInfo *info;          // 0x0c
};

class Table {
public:
    char pad00[0x44];
    int count;               // 0x44
    Value *FUN_00337090(int index);
};

int __cdecl FUN_00337f20(int kind);

class Reader {
public:
    char pad00[4];
    Table *table;            // 0x04
    char **rows;             // 0x08
    bool FUN_00335e60(int column, int row, unsigned int *outLength);
};

// Length of the string stored in a string-typed column (0 when null).
bool Reader::FUN_00335e60(int column, int row, unsigned int *outLength) {
    if (column < 0 || column >= table->count)
        return false;
    if (table->FUN_00337090(column)->type != 9)
        return false;
    char *base = rows[column] + 4;
    if (table->FUN_00337090(column)->info->kind != 10)
        return false;
    const char *s = *(const char **)(base + FUN_00337f20(10) * row);
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
