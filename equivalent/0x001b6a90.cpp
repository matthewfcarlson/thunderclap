// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 15/18, incomplete)
// FUN_001b6a90 @ 0x001b6a90
class Item {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(int arg);
    int pad4;
    int link;
    float timer;
};

class ItemTable {
public:
    void FUN_001b6a90(int unused, int arg);
    Item *items[32];
};

void ItemTable::FUN_001b6a90(int unused, int arg)
{
    for (unsigned int i = 0; i < 32; i++) {
        Item *item = items[i];
        if (item == 0)
            continue;
        item->vf4(arg);
        if (item->timer <= 0.0f) {
            int link = item->link;
            if (link >= 0 && link < 32 && items[link] != 0) {
                items[link]->vf1();
                items[link] = 0;
            }
        }
    }
}
