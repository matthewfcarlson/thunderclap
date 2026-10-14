// STATUS: equivalent (tools/equiv.py level 3: 61 inputs, branch coverage 6/6)
// FUN_002842f0 @ 0x002842f0
struct Block64 {
    int w[16];
};

struct Row16 {
    int a, b, c, d;
};

struct Clone {
    char pad0[0x10];
    Row16 *rows;            // 0x10
    Block64 *blocksA;       // 0x14
    Row16 *extraRows;       // 0x18
    Block64 *blocksB;       // 0x1c
};

struct Maker {
    Clone *FUN_0027b240();
};

struct Source {
    char pad0[8];
    Maker *maker;           // 0x08
    unsigned int count;     // 0x0c
    Row16 *rows;            // 0x10
    Block64 *blocksA;       // 0x14
    Row16 *extraRows;       // 0x18
    Block64 *blocksB;       // 0x1c
};

class Frames : public Source {
public:
    void FUN_002842f0();
};

void Frames::FUN_002842f0()
{
    Clone *dst = maker->FUN_0027b240();
    for (unsigned int i = 0; i < count; i++) {
        dst->blocksA[i] = blocksA[i];
        dst->blocksB[i] = blocksB[i];
        dst->rows[i] = rows[i];
        if (extraRows != 0)
            dst->extraRows[i] = extraRows[i];
    }
}
