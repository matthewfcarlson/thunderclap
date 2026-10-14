// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0007ac30 @ 0x0007ac30
// equiv-map: ??0Name@@QAE@XZ = 0x0027af00
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50

__declspec(align(8)) struct Name {
    int lo, hi;
    Name() throw();
    ~Name() throw();
    bool FUN_0027af90(const Name *other) throw();
};

struct Resolver_7ac30 {
    void FUN_001dd930(int id, Name *out) throw();
};

struct Owner_7ac30 {
    char pad0[0xc];
    Resolver_7ac30 *resolver;         // 0xc
};

struct Item_7ac30 {
    char pad0[0x10];
    int id;                     // 0x10
};

class Scene_7ac30 {
public:
    char pad0[0x3800];
    Item_7ac30 *items[1];             // 0x3800
    char pad3804[0x3828 - 0x3804];
    int count;                  // 0x3828
    Owner_7ac30 *owner;               // 0x382c

    int FUN_0007ac30(const Name *key);
};

int Scene_7ac30::FUN_0007ac30(const Name *key)
{
    Name found;
    Resolver_7ac30 *resolver = owner->resolver;
    for (int i = 0; i < count; i++) {
        resolver->FUN_001dd930(items[i]->id, &found);
        if (found.FUN_0027af90(key))
            return i;
    }
    return -1;
}
