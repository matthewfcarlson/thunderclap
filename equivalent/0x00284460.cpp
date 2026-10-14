// STATUS: equivalent (tools/equiv.py level 3: 159 inputs, branch coverage 8/8)
// FUN_00284460 @ 0x00284460
struct Mat {
    float m[16];
    void FUN_0022ca90(const Mat *a, const Mat *b);
};

struct Skeleton {
    char pad00[0x28];
    unsigned short *parent;
};

class Pose {
public:
    char pad00[8];
    Skeleton *skeleton;
    unsigned int count;
    char pad10[4];
    Mat *local;
    char pad18[4];
    Mat *world;
    char pad20[3];
    char dirty;
    void Update(const Mat *root);
};

void Pose::Update(const Mat *root)
{
    if (root != 0) {
        world->FUN_0022ca90(local, root);
    } else {
        if (!dirty)
            return;
        *world = *local;
    }
    Mat *out = world + 1;
    Mat *in = local + 1;
    for (unsigned int i = 1; i < count; i++) {
        out->FUN_0022ca90(in, world + skeleton->parent[i]);
        out++;
        in++;
    }
    dirty = 0;
}
