// STATUS: equivalent (tools/equiv.py level 3: 3031 inputs, branch coverage 12/12)
// FUN_00335ef0 @ 0x00335ef0
struct Column {
    char pad0[8];
    int type;
    int *kind;
};

struct Schema {
    Column *FUN_00337090(int index);

    char pad0[0x44];
    int count;
};

int __cdecl FUN_00337f20(int kind);

class Table {
public:
    bool FUN_00335ef0(int index, int column, char *out);

    char pad0[4];
    Schema *schema;
    char **rows;
};

// Copies the string stored in a string-typed cell of a row into `out`.
bool Table::FUN_00335ef0(int index, int column, char *out) {
    if (index < 0 || index >= schema->count) {
        return false;
    }
    if (schema->FUN_00337090(index)->type != 9) {
        return false;
    }
    char *row = rows[index] + 4;
    if (*schema->FUN_00337090(index)->kind != 0xa) {
        return false;
    }
    char *src = *(char **)(row + FUN_00337f20(0xa) * column);
    if (src == 0) {
        return false;
    }
    char c;
    do {
        c = *src++;
        *out++ = c;
    } while (c);
    return true;
}
