// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 24/24)
// FUN_00045da0 @ 0x00045da0
struct Key_45da0 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af10(unsigned a, unsigned b);
    void FUN_0027af50();
};

struct Bone_45da0 {
    char pad0[0x34];
    float offset;            // 0x34
    char pad38[8];
};

struct Skeleton {
    char pad0[0x1c];
    Bone_45da0 *bones;             // 0x1c
    int FUN_0027b200(unsigned __int64 id);
};

struct ModelHolder {
    char pad0[8];
    Skeleton *skeleton;      // 0x08
};

class Owner_45da0 {
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
    virtual ModelHolder *v11();
    char pad4[4];
    unsigned keyLo;          // 0x08
    unsigned keyHi;          // 0x0c
};

struct Registry_45da0 {
    int FUN_001c5b00(Key_45da0 *k);
};
struct Manager_45da0 {
    char pad0[0xc];
    Registry_45da0 *registry;      // 0x0c
    void FUN_001c4190(Key_45da0 *k);
};
Manager_45da0 *__cdecl FUN_001c3d90();
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);

struct Tracker_45da0 {
    char pad0[8];
    Owner_45da0 *owner;            // 0x08
    Owner_45da0 *pending;          // 0x0c
    char pad10[0x10];
    int rootIdx;             // 0x20
    int balanceIdx;          // 0x24
    int headIdx;             // 0x28
    float rootOffset;        // 0x2c

    char FUN_00045da0(Owner_45da0 *newOwner);
};

char Tracker_45da0::FUN_00045da0(Owner_45da0 *newOwner)
{
    if (newOwner == owner)
        return 1;

    bool sameSkeleton = false;
    if (newOwner) {
        Skeleton *a = newOwner->v11()->skeleton;
        Skeleton *b = 0;
        if (owner)
            b = owner->v11()->skeleton;
        sameSkeleton = (a == b);
    }
    if (!sameSkeleton && pending) {
        pending->v1();
        pending = 0;
    }

    if (newOwner)
        newOwner->v0();
    if (owner)
        owner->v1();
    owner = newOwner;
    rootIdx = 0;
    balanceIdx = 0;
    headIdx = 0xffff;
    rootOffset = 0;
    if (owner == 0)
        return 1;

    Skeleton *skel = newOwner->v11()->skeleton;
    if (skel) {
        rootIdx = skel->FUN_0027b200(FUN_002672f0("Character_Root", 0, 0));
        if (rootIdx != 0xffff) {
            float v = skel->bones[rootIdx].offset;
            rootOffset = v;
            rootOffset = v - skel->bones[0].offset;
        } else {
            rootIdx = 0;
        }
        balanceIdx = skel->FUN_0027b200(FUN_002672f0("Balance_Root", 0, 0));
        if (balanceIdx == 0xffff)
            balanceIdx = rootIdx;
        headIdx = skel->FUN_0027b200(FUN_002672f0("Head", 0, 0));
    }

    {
        Key_45da0 k;
        k.FUN_0027af10(owner->keyLo, owner->keyHi);
        bool found = FUN_001c3d90()->registry->FUN_001c5b00(&k) == 0;
        k.FUN_0027af50();
        if (!found)
            return 1;
    }
    {
        Key_45da0 k;
        k.FUN_0027af10(owner->keyLo, owner->keyHi);
        FUN_001c3d90()->FUN_001c4190(&k);
        k.FUN_0027af50();
    }
    return 1;
}
