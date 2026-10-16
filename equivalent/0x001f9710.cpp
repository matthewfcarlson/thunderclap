// STATUS: equivalent (tools/equiv.py level 3: 2899 inputs, branch coverage 8/8)
// FUN_001f9710 @ 0x001f9710
#include "decls/address.h"
struct Key {
    int lo, hi;
    Key() throw() {}
    Key(const Key &other) throw();
    Key *FUN_0027b0e0(const char *name);
    void FUN_0027af70(const Key *other);
    void FUN_0027af50();
};

struct NameEntry {
    Key key;
    char flagA;
    char flagB;
    char unused[6];

    NameEntry() throw() {}
    NameEntry(const NameEntry &o) throw() : key(o.key)
    {
        flagA = o.flagA;
        flagB = o.flagB;
    }
};

struct Item_1f9710 {
    int key;
    char pad04[0x24];
};

struct Sub_1f9710 {
    char pad[0x50];
};

class Table {
public:
    char pad00[0x41c];
    Sub_1f9710 sub;
    Item_1f9710 items[15];
    char pad6c4[0x1c];
    int count;

    void FUN_001f96b0(NameEntry entry, int id) throw();
};

class Factory_1f9710 {
public:
    char FUN_001fcff0(Sub_1f9710 *sub);
};

struct World {
    char pad[0x28];
    Factory_1f9710 *factory;
};

extern int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);

class Slot_1f9710 {
public:
    char pad00[8];
    Table *table;
    char name[0x20];
    int pad2c;
    NameEntry entry;
    int arg3;
    int arg4;
    int f48;
    int f4c;

    void FUN_001f9710(Table *owner, const char *label, int a, int b);
};

// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
void Slot_1f9710::FUN_001f9710(Table *owner, const char *label, int a, int b)
{
    table = owner;
    FUN_00267760(name, 0x20, "%s", label);
    arg3 = a;
    arg4 = b;
    f48 = 0;
    f4c = 0;
    entry.flagA = DAT_004dd700->factory->FUN_001fcff0(&owner->sub);
    Key tmp;
    entry.key.FUN_0027af70(tmp.FUN_0027b0e0(label));
    tmp.FUN_0027af50();
    for (int i = 0; i < table->count; i++) {
        Item_1f9710 *item = &table->items[i];
        if (item->key == -1 || item->key == -2)
            continue;
        entry.flagB = (char)i;
        table->FUN_001f96b0(entry, (short)item->key);
    }
    entry.flagB = (char)0xff;
}
