// STATUS: equivalent (tools/equiv.py level 3: 599 inputs, branch coverage 14/14)
// FUN_00024840 @ 0x00024840
union Hash {
    unsigned __int64 q;
    unsigned int w[2];
};
Hash FUN_0027b020(const char *s);

struct Target {
    char pad0[0x118];
    unsigned int hashLo;    // 0x118
    unsigned int hashHi;    // 0x11c
};

struct Actor {
    char pad0[0x1ca0];
    Target *target;         // 0x1ca0
};

struct Registry {
    Actor *FUN_00059c10(int id);
};

struct Manager {
    char pad0[0x44];
    Registry *registry;     // 0x44
};

class Group {
public:
    Manager *manager;       // 0x0
    char pad4[8];
    int count;              // 0xc
    int ids[1];             // 0x10
    char pad14[0x124 - 0x14];
    Actor *self;            // 0x124

    int FUN_00024840(const char *name);
};

// Number of members whose target has the hash of `name`.
int Group::FUN_00024840(const char *name)
{
    int matches = 0;
    Hash h;
    h.q = FUN_0027b020(name).q;
    for (int i = 0; i < count; i++) {
        Actor *a = manager->registry->FUN_00059c10(ids[i]);
        if (a != 0 && a != self) {
            Target *t = a->target;
            if (t != 0 && t->hashLo == h.w[0] && t->hashHi == h.w[1])
                matches++;
        }
    }
    return matches;
}
