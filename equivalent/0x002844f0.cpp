// STATUS: equivalent (tools/equiv.py level 3: 2533 inputs, branch coverage 8/8)
// FUN_002844f0 @ 0x002844f0
struct Row16_2844f0 {
    int a, b, c, d;
    void FUN_0022b370(const Row16_2844f0 *src);
};

void __cdecl FUN_0022b080(Row16_2844f0 *out, Row16_2844f0 *a, Row16_2844f0 *b);

struct Skeleton {
    char pad0[0x28];
    unsigned short *parents;    // 0x28
};

class Pose {
public:
    char pad0[8];
    Skeleton *skeleton;         // 0x08
    unsigned int count;         // 0x0c
    Row16_2844f0 *local;               // 0x10
    char pad14[4];
    Row16_2844f0 *world;               // 0x18
    void FUN_002844f0(const Row16_2844f0 *root);
};

void Pose::FUN_002844f0(const Row16_2844f0 *root)
{
    if (world == 0)
        return;
    if (root != 0) {
        Row16_2844f0 rootCopy;
        rootCopy.FUN_0022b370(root);
        FUN_0022b080(world, local, &rootCopy);
    } else {
        world[0] = local[0];
    }
    Row16_2844f0 *src = local + 1;
    Row16_2844f0 *dst = world + 1;
    for (unsigned int i = 1; i < count; i++) {
        FUN_0022b080(dst, src, world + skeleton->parents[i]);
        dst++;
        src++;
    }
}
