// STATUS: equivalent (tools/equiv.py level 3: 204 inputs, branch coverage 8/8)
// FUN_001d7150 @ 0x001d7150
struct Id {
    unsigned int lo;
    unsigned int hi;
};
extern Id DAT_004e2560[];

struct Counter {
    int FUN_001d5710();
};

struct Item {
    char pad00[8];
    unsigned int lo;
    unsigned int hi;
};

struct ItemList {
    char pad00[0x1c];
    Item **items;
};

class Manager {
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
    ItemList *list;
    char pad9c[0xec - 0x9c];
    Counter *counter;
    bool SelectById(int id);
};

bool Manager::SelectById(int id)
{
    int count = counter->FUN_001d5710();
    if (count <= 0)
        return false;
    unsigned int lo = DAT_004e2560[id].lo;
    unsigned int hi = DAT_004e2560[id].hi;
    Item **p = list->items;
    for (int i = 0; i < count; i++) {
        if (p[i]->lo == lo && p[i]->hi == hi) {
            Select(i, 1);
            return true;
        }
    }
    return false;
}
