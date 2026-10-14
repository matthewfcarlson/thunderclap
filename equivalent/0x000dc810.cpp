// STATUS: equivalent (tools/equiv.py level 3: 41 inputs, branch coverage 24/24)
// FUN_000dc810 @ 0x000dc810
struct Vec3_dc810 {
    float x, y, z;
};

void FUN_0008d340(void *p);
void *FUN_0008d6d0(unsigned int size);

class ParticleBuffers {
public:
    char pad000[0x150];
    int count;                // 0x150
    int used;                 // 0x154
    char *flags;              // 0x158
    Vec3_dc810 *positions;          // 0x15c
    Vec3_dc810 *velocities;         // 0x160
    void **links0;            // 0x164
    void **links1;            // 0x168
    int *ids;                 // 0x16c

    void FUN_000dc810(int newCount);
};

void ParticleBuffers::FUN_000dc810(int newCount)
{
    for (int i = 0; i < count; i++) {
        if (links0[i]) {
            FUN_0008d340(links0[i]);
            links0[i] = 0;
        }
        if (links1[i]) {
            FUN_0008d340(links1[i]);
            links1[i] = 0;
        }
    }
    if (links0) {
        FUN_0008d340(links0);
        links0 = 0;
    }
    if (links1) {
        FUN_0008d340(links1);
        links1 = 0;
    }

    count = newCount;
    used = 0;
    if (flags) {
        FUN_0008d340(flags);
        flags = 0;
    }
    if (positions) {
        FUN_0008d340(positions);
        positions = 0;
    }
    if (velocities) {
        FUN_0008d340(velocities);
        velocities = 0;
    }
    if (ids) {
        FUN_0008d340(ids);
        ids = 0;
    }

    flags = (char *)FUN_0008d6d0(count + 1);
    flags[0] = 0;
    positions = (Vec3_dc810 *)FUN_0008d6d0(count * 12);
    velocities = (Vec3_dc810 *)FUN_0008d6d0(count * 12);
    links0 = (void **)FUN_0008d6d0(count * 4);
    links1 = (void **)FUN_0008d6d0(count * 4);
    ids = (int *)FUN_0008d6d0(count * 4);

    for (int i = 0; i < count; i++) {
        ids[i] = -1;
        links0[i] = 0;
        links1[i] = 0;
    }
}
