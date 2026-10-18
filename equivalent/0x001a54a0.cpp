// STATUS: equivalent (tools/equiv.py level 3: 20026 inputs, branch coverage 12/12)
// FUN_001a54a0 @ 0x001a54a0
struct Vec3_1a54a0 {
    float x, y, z;
};

struct ModeA {
    int FUN_001def30(int id);
    Vec3_1a54a0 *FUN_001df190(Vec3_1a54a0 *tmp, int id);
    float FUN_001dc4a0(int id);
};

struct Item_1a54a0 {
    unsigned char FUN_000352b0(Vec3_1a54a0 *out);
    float FUN_000354c0();
};

struct ModeB_1a54a0 {
    int FUN_00024280(unsigned __int64 key);
    Item_1a54a0 *FUN_000259f0(int id);
};

struct ModeC {
    Vec3_1a54a0 *FUN_001fd7d0(Vec3_1a54a0 *tmp, int id);
    float FUN_001fd830(int id);
};

struct Globals_1a54a0 {
    char pad0[0xc];
    ModeA *modeA;
    char pad10[0x20 - 0x10];
    ModeB_1a54a0 *modeB;
    char pad24[0x28 - 0x24];
    ModeC *modeC;
};

struct Source_1a54a0 {
    char pad0[0x24];
    int id;
    int mode;
};

extern Globals_1a54a0 *DAT_004dd700;
extern "C" unsigned __int64 FUN_002672f0(int id, int a, int b);

struct Component_1a54a0 {
    char pad0[0x1c];
    Source_1a54a0 *source;
    void FUN_001a54a0(Vec3_1a54a0 *outVec, float *outScalar);
};

void Component_1a54a0::FUN_001a54a0(Vec3_1a54a0 *outVec, float *outScalar)
{
    Vec3_1a54a0 tmp;

    outVec->x = 0;
    outVec->y = 0;
    outVec->z = 0;
    *outScalar = 0;

    int mode = source->mode;
    int id = source->id;

    if (mode == 0) {
        *outVec = *DAT_004dd700->modeC->FUN_001fd7d0(&tmp, id);
        *outScalar = DAT_004dd700->modeC->FUN_001fd830(id) * 0.0174532924f;
    } else if (mode == 1) {
        ModeB_1a54a0 *b = DAT_004dd700->modeB;
        unsigned __int64 key = FUN_002672f0(id, 0, 0);
        if (b->FUN_00024280(key) == 0)
            return;
        DAT_004dd700->modeB->FUN_000259f0(id)->FUN_000352b0(outVec);
        *outScalar = DAT_004dd700->modeB->FUN_000259f0(id)->FUN_000354c0();
    } else if (mode == 2) {
        if (DAT_004dd700->modeA->FUN_001def30(id) == 0)
            return;
        *outVec = *DAT_004dd700->modeA->FUN_001df190(&tmp, id);
        *outScalar = DAT_004dd700->modeA->FUN_001dc4a0(id);
    }
}
