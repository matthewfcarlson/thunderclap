// FUN_00287db0 @ 0x00287db0
struct Elem_287db0 {
    char pad[0x2c];
    float FUN_00284f70();
};

struct Inner_287db0 {
    char pad[0x10];
    unsigned int count;
};

struct Mid_287db0 {
    char pad[8];
    Inner_287db0 *inner;
};

struct PoseAnimationController_287db0 {
    char pad00[0x28];
    unsigned int numElems;
    Elem_287db0 elems[1];
    char pad58[0x110 - 0x2c - 0x2c];
    Mid_287db0 *mid;
    char pad114[0x131 - 0x114];
    char enabled;
    char pad132[2];
    float *tracks[1];
    void FUN_00287db0();
};

void PoseAnimationController_287db0::FUN_00287db0()
{
    if (!enabled)
        return;
    for (unsigned int i = 0; i < numElems; i++) {
        float v = elems[i].FUN_00284f70();
        for (unsigned int j = 0; j < mid->inner->count; j++)
            tracks[i][j] = v;
    }
}
