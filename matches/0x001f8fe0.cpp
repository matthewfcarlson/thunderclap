struct Key {
    int lo, hi;
    Key() throw() {}
    Key(const Key& other) throw();
};

struct Item {
    char pad[8];
    Key key;                // 0x08
};

class Registry {
public:
    char pad0[0x10];
    Item* items[256];       // 0x10
    int count;              // 0x410
    int pad414;
    int total;              // 0x418
    int FUN_001f85f0(Key key);
    int FUN_001f8fe0(Item* item);
};

// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
int Registry::FUN_001f8fe0(Item* item)
{
    if (item == 0)
        return -1;
    int index = FUN_001f85f0(item->key);
    if (index == -1) {
        index = count;
        items[index] = item;
        count++;
        total++;
    }
    return index;
}
