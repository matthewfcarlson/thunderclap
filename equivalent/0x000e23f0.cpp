// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 8/8)
// FUN_000e23f0 @ 0x000e23f0
struct Cell {
    float out;
    float in;
    unsigned char on;
    char pad[3];
    int spare;
};

class Spreader {
public:
    char pad0[0x30];
    float limit;
    char pad34[0x44 - 0x34];
    Cell cells[1];
    char pad_cells[0x240 - 0x44 - sizeof(Cell)];
    int count;
    char pad244[0x24c - 0x244];
    int skip;
    int last;
    void FUN_000e23f0();
};

void Spreader::FUN_000e23f0()
{
    float acc = 0.0f;
    for (int i = 0; i < count; i++) {
        if (i < skip) {
            cells[i].on = 0;
            *(int *)&cells[i].out = 0;
        } else {
            acc = cells[i].in * 1.05f + acc;
            if (acc > limit) {
                cells[i].on = 0;
                *(int *)&cells[i].out = 0;
            } else {
                cells[i].on = 1;
                cells[i].out = acc - cells[i].in * 0.5f;
                last = i;
            }
        }
    }
}
