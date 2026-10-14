// STATUS: equivalent (tools/equiv.py level 3: 2891 inputs, branch coverage 20/20)
// FUN_001d1360 @ 0x001d1360
int __cdecl FUN_00096600(const char *a, const char *b);

struct Item {
    virtual ~Item() throw();
    char pad[4];
    const char *name;          // 0x8
};

struct Key {
    char pad[8];
    const char *name;          // 0x8
};

class ItemList {
public:
    Item *items[0x400];
    int count;                 // 0x1000
    bool FUN_001d1360(Key *key);
};

bool ItemList::FUN_001d1360(Key *key)
{
    const char *want = key->name;
    if (want == 0 || *want == 0)
        return false;
    for (int i = 0; i < count; i++) {
        const char *name = items[i]->name;
        if (name != 0 && *name != 0 && FUN_00096600(name, want) == 0) {
            if (items[i] != 0) {
                delete items[i];
                items[i] = 0;
            }
            for (int j = i + 1; j < count; j++)
                items[j - 1] = items[j];
            items[count - 1] = 0;
            count--;
            return true;
        }
    }
    return false;
}
