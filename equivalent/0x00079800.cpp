// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00079800 @ 0x00079800
// equiv-map: ??0Name@@QAE@XZ = 0x0027af00
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50

__declspec(align(8)) struct Name {
    int lo, hi;
    Name() throw();
    ~Name() throw();
    bool FUN_0027af90(const Name *other) throw();
};

struct Resolver {
    void FUN_001dd930(int id, Name *out) throw();
};

struct Owner {
    char pad0[0xc];
    Resolver *resolver;         // 0xc
};

struct Item {
    char pad0[0x34];
    int id;                     // 0x34
};

class Scene {
public:
    char pad0[0x374c];
    Item *items[1];             // 0x374c
    char pad3750[0x379c - 0x3750];
    int count;                  // 0x379c
    char pad37a0[0x382c - 0x37a0];
    Owner *owner;               // 0x382c

    int FUN_00079800(const Name *key);
};

int Scene::FUN_00079800(const Name *key)
{
    Name found;
    for (int i = 0; i < count; i++) {
        owner->resolver->FUN_001dd930(items[i]->id, &found);
        if (found.FUN_0027af90(key))
            return i;
    }
    return -1;
}
