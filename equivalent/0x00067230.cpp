// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 24/24)
// FUN_00067230 @ 0x00067230
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Transform {
    void FUN_00059a50(Vec3 *out);
};

struct Target {
    char pad0[0x10];
    Transform *transform;
    char pad1[0x1b0c - 0x14];
    float score;
    char pad2[0x1ba4 - 0x1b10];
    char locked;
    int FUN_00035910();
};

struct TargetTable {
    char pad0[0x124];
    Target *player;
    Target *FUN_00024280(int a, int b);
};

struct World {
    char pad0[0x20];
    TargetTable *targets;
};

extern World *DAT_004dd700;

struct Key {
    int a, b;
};

struct TreeNode {
    char pad0[0x18];
    int keyA;
    int keyB;
};

struct Entry {
    float dist;
    int unused;
    int keyA;
    int keyB;
};

struct Tree {
    int link[6];
    void FUN_00230f50(void (__cdecl *cb)(void *, void *), void *user);
    void FUN_00066a90(int *out, Entry *entry);
    TreeNode *FUN_00230ea0();
    TreeNode *FUN_00230800(TreeNode *node);
};

void __cdecl FUN_00066930(void *node, void *user);

class Tracker {
public:
    bool FUN_00067230(Target *self);

    char pad0[0x154];
    Vec3 origin;
    char pad2[0x170 - 0x160];
    Key keys[40];
    int count;
    char pad4[0x2c4 - 0x2b4];
    int bonus;
    char pad5[0x2d0 - 0x2c8];
    int limit;
    char pad6[0x310 - 0x2d4];
    Tree tree;
};

bool Tracker::FUN_00067230(Target *self)
{
    struct Frame {
        int outPair[2];
        Vec3 d;
        Vec3 pos;
        Vec3 player;
        Entry entry;
    } f;
    int n = 0;
    int nearCount = 0;
    int i;

    f.pos.x = 0.0f; f.pos.y = 0.0f; f.pos.z = 0.0f;
    f.player.x = 0.0f; f.player.y = 0.0f; f.player.z = 0.0f;
    tree.FUN_00230f50(FUN_00066930, &tree);
    DAT_004dd700->targets->player->transform->FUN_00059a50(&f.player);
    for (i = 0; i < count; i++) {
        Target *t = DAT_004dd700->targets->FUN_00024280(keys[i].a, keys[i].b);
        t->transform->FUN_00059a50(&f.pos);
        if (!(t->score < 0.0f)) {
            f.d.x = f.pos.x - origin.x;
            f.d.y = f.pos.y - origin.y;
            f.d.z = f.pos.z - origin.z;
            if (t->FUN_00035910() == 6 || self == t)
                nearCount++;
            f.d.y = 0.0f;
            f.entry.dist = f.d.FUN_0022d110();
            f.entry.keyA = keys[i].a;
            f.entry.keyB = keys[i].b;
            tree.FUN_00066a90(f.outPair, &f.entry);
        } else {
            for (int j = i + 1; j < count; j++)
                keys[j - 1] = keys[j];
            count--;
            i--;
        }
    }
    if (tree.link[5] < limit)
        return false;
    TreeNode *node = tree.FUN_00230ea0();
    if (node == 0)
        return false;
    do {
        Target *t = DAT_004dd700->targets->FUN_00024280(node->keyA, node->keyB);
        if (t != 0) {
            if (n < bonus + nearCount) {
                n++;
                t->locked = 1;
            } else {
                t->locked = 0;
            }
        }
        node = tree.FUN_00230800(node);
    } while (node != 0);
    return true;
}
