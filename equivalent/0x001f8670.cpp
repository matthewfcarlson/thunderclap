// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 10/10)
// FUN_001f8670 @ 0x001f8670
// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
// equiv-map: ??1Key@@QAE@XZ = 0x0027af50

struct Key {
    int lo, hi;
    Key(const Key &other) throw();
    ~Key() throw();
};

struct Item {
    char pad[1];
};

class Registry {
public:
    char pad0[0x10];
    Item *items[256];       // 0x10
    int count;              // 0x410
    int firstActive;        // 0x414
    int activeCount;        // 0x418

    int FUN_001f85f0(Key key) throw();
    int FUN_001f8670(Key key);
};

// Removes the item named `key` by moving the last item into its slot; returns its old index or -1.
int Registry::FUN_001f8670(Key key)
{
    if (activeCount != 0 && firstActive >= 0) {
        int index = FUN_001f85f0(key);
        if (index != -1 && index >= firstActive) {
            items[index] = items[count - 1];
            count--;
            activeCount--;
            if (activeCount == 0)
                firstActive = -1;
            return index;
        }
    }
    return -1;
}
