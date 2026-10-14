// STATUS: equivalent (tools/equiv.py level 3: 138 inputs, branch coverage 10/10)
// FUN_00287db0 @ 0x00287db0
struct Elem {
    char pad[0x2c];
    float FUN_00284f70();
};

struct Inner {
    char pad[0x10];
    unsigned int count;
};

struct Mid {
    char pad[8];
    Inner *inner;
};

struct Anim {
    char pad00[0x28];
    unsigned int numElems;
    Elem elems[1];
    char pad58[0x110 - 0x2c - 0x2c];
    Mid *mid;
    char pad114[0x131 - 0x114];
    char enabled;
    char pad132[2];
    float *tracks[1];
    void FUN_00287db0();
};

void Anim::FUN_00287db0()
{
    if (!enabled)
        return;
    for (unsigned int i = 0; i < numElems; i++) {
        float v = elems[i].FUN_00284f70();
        for (unsigned int j = 0; j < mid->inner->count; j++)
            tracks[i][j] = v;
    }
}
