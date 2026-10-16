// STATUS: equivalent (tools/equiv.py level 3: 204 inputs, branch coverage 8/8)
// FUN_001d7150 @ 0x001d7150
#include "decls/data/game/global.h"

struct Id_1d7150 {
    unsigned int lo;
    unsigned int hi;
};

struct Counter_1d7150 {
    int FUN_001d5710();
};

struct Item_1d7150 {
    char pad00[8];
    unsigned int lo;
    unsigned int hi;
};

struct ItemList_1d7150 {
    char pad00[0x1c];
    Item_1d7150 **items;
};

class Manager_1d7150 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void Select(int index, int flag);
    char pad04[0x94];
    ItemList_1d7150 *list;
    char pad9c[0xec - 0x9c];
    Counter_1d7150 *counter;
    bool SelectById(int id);
};

bool Manager_1d7150::SelectById(int id)
{
    int count = counter->FUN_001d5710();
    if (count <= 0)
        return false;
    unsigned int lo = ((Id_1d7150*)&DAT_004e2560)[id].lo;
    unsigned int hi = ((Id_1d7150*)&DAT_004e2560)[id].hi;
    Item_1d7150 **p = list->items;
    for (int i = 0; i < count; i++) {
        if (p[i]->lo == lo && p[i]->hi == hi) {
            Select(i, 1);
            return true;
        }
    }
    return false;
}
