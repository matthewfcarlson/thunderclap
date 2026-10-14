// STATUS: equivalent (tools/equiv.py level 3: 159 inputs, branch coverage 8/8)
// FUN_00284460 @ 0x00284460
struct Mat_284460 {
    float m[16];
    void FUN_0022ca90(const Mat_284460 *a, const Mat_284460 *b);
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
    Mat_284460 *local;
    char pad18[4];
    Mat_284460 *world;
    char pad20[3];
    char dirty;
    void Update(const Mat_284460 *root);
};

void Pose::Update(const Mat_284460 *root)
{
    if (root != 0) {
        world->FUN_0022ca90(local, root);
    } else {
        if (!dirty)
            return;
        *world = *local;
    }
    Mat_284460 *out = world + 1;
    Mat_284460 *in = local + 1;
    for (unsigned int i = 1; i < count; i++) {
        out->FUN_0022ca90(in, world + skeleton->parent[i]);
        out++;
        in++;
    }
    dirty = 0;
}
