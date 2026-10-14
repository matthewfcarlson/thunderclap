// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001f8f70 @ 0x001f8f70
struct Key {
    int lo, hi;
    Key() throw() {}
    Key(const Key& other) throw();
    void FUN_0027b0e0(const char* name);
    void FUN_0027af50();
};

struct Item_1f8f70 {
    char pad[1];
};

struct Factory_1f8f70 {
    Item_1f8f70* FUN_001fc8c0(int lo, int hi);
};

struct Game_1f8f70 {
    char pad[0x28];
    Factory_1f8f70* factory;       // 0x28
};
extern Game_1f8f70* DAT_004dd700;

class Registry_1f8f70 {
public:
    char pad0[0x10];
    Item_1f8f70* items[256];       // 0x10
    int count;              // 0x410
    int FUN_001f85f0(Key key);
    int FUN_001f8f70(const char* name);
};

// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
int Registry_1f8f70::FUN_001f8f70(const char* name)
{
    Key key;
    key.FUN_0027b0e0(name);
    int index = FUN_001f85f0(key);
    if (index == -1) {
        Item_1f8f70* item = DAT_004dd700->factory->FUN_001fc8c0(key.lo, key.hi);
        if (item != 0) {
            index = count;
            items[index] = item;
            count++;
        }
    }
    key.FUN_0027af50();
    return index;
}
