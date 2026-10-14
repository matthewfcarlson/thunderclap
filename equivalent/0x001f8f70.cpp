// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001f8f70 @ 0x001f8f70
struct Key {
    int lo, hi;
    Key() throw() {}
    Key(const Key& other) throw();
    void FUN_0027b0e0(const char* name);
    void FUN_0027af50();
};

struct Item {
    char pad[1];
};

struct Factory {
    Item* FUN_001fc8c0(int lo, int hi);
};

struct Game {
    char pad[0x28];
    Factory* factory;       // 0x28
};
extern Game* DAT_004dd700;

class Registry {
public:
    char pad0[0x10];
    Item* items[256];       // 0x10
    int count;              // 0x410
    int FUN_001f85f0(Key key);
    int FUN_001f8f70(const char* name);
};

// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
int Registry::FUN_001f8f70(const char* name)
{
    Key key;
    key.FUN_0027b0e0(name);
    int index = FUN_001f85f0(key);
    if (index == -1) {
        Item* item = DAT_004dd700->factory->FUN_001fc8c0(key.lo, key.hi);
        if (item != 0) {
            index = count;
            items[index] = item;
            count++;
        }
    }
    key.FUN_0027af50();
    return index;
}
