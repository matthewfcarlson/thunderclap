// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00066c20 @ 0x00066c20
struct Globals {
    char pad0[0x2c];
    int field_2c;
    char pad30[0x58 - 0x30];
    int field_58;
};

struct Pair {
    int a;
    int b;
};

struct Key {
    int a;
    int b;
    int c;
};

struct Table {
    void FUN_00066b60(Pair *out, Key *key);
};

extern Globals *DAT_004dd700;
extern int DAT_004dcec8;
extern int DAT_004dcecc;
extern int DAT_004dced0;
extern int DAT_004dced4;
extern int DAT_004dced8;
extern int DAT_004dcedc;
extern int DAT_004dcee8;
extern int DAT_004dceec;
extern int DAT_004dcef0;
extern int DAT_004dcef4;
extern int DAT_004dcef8;
extern int DAT_004dcefc;

struct Owner {
    int field_00;
    int field_04;
    char pad08[0x2f4 - 8];
    Table table;
    void FUN_00066c20(int unused);
};

void Owner::FUN_00066c20(int unused)
{
    Pair out;
    Key key;

    field_00 = DAT_004dd700->field_2c;
    field_04 = DAT_004dd700->field_58;

    key.a = DAT_004dced0; key.b = DAT_004dced4; key.c = 0;
    table.FUN_00066b60(&out, &key);
    key.a = DAT_004dcef8; key.b = DAT_004dcefc; key.c = 0;
    table.FUN_00066b60(&out, &key);
    key.a = DAT_004dced8; key.b = DAT_004dcedc; key.c = 0;
    table.FUN_00066b60(&out, &key);
    key.a = DAT_004dcec8; key.b = DAT_004dcecc; key.c = 0;
    table.FUN_00066b60(&out, &key);
    key.a = DAT_004dcef0; key.b = DAT_004dcef4; key.c = 0;
    table.FUN_00066b60(&out, &key);
    key.a = DAT_004dcee8; key.b = DAT_004dceec; key.c = 0;
    table.FUN_00066b60(&out, &key);
}
