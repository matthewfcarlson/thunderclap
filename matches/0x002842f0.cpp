// FUN_002842f0 @ 0x002842f0
struct Block64 {
    int w[16];
};

struct Row16_2842f0 {
    int a, b, c, d;
};

struct Clone {
    char pad0[0x10];
    Row16_2842f0 *rows;            // 0x10
    Block64 *blocksA;       // 0x14
    Row16_2842f0 *extraRows;       // 0x18
    Block64 *blocksB;       // 0x1c
};

struct Maker_2842f0 {
    Clone *FUN_0027b240();
};

struct Source_2842f0 {
    char pad0[8];
    Maker_2842f0 *maker;           // 0x08
    unsigned int count;     // 0x0c
    Row16_2842f0 *rows;            // 0x10
    Block64 *blocksA;       // 0x14
    Row16_2842f0 *extraRows;       // 0x18
    Block64 *blocksB;       // 0x1c
};

class Frames_2842f0 : public Source_2842f0 {
public:
    Clone * FUN_002842f0();
};

Clone * Frames_2842f0::FUN_002842f0()
{
    Clone *dst = maker->FUN_0027b240();
    for (unsigned int i = 0; i < count; i++) {
        dst->blocksA[i] = blocksA[i];
        dst->blocksB[i] = blocksB[i];
        dst->rows[i] = rows[i];
        if (extraRows != 0)
            dst->extraRows[i] = extraRows[i];
    }
    return dst;
}
