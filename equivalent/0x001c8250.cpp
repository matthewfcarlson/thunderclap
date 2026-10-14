// STATUS: equivalent (tools/equiv.py level 3: 148 inputs, branch coverage 10/10)
// FUN_001c8250 @ 0x001c8250
extern float DAT_00421898;
extern float DAT_004218c0;
struct Item {
    char pad[0x90];
    float v90;
    float v94;
    void FUN_001c5130(float a, float b);
};
struct Target {
    char pad0[0x138];
    Item *items[0x400 / 4];
    unsigned int count;
    void FUN_001c8250();
};

void Target::FUN_001c8250()
{
    for (unsigned int i = 0; i < count; i++) {
        Item *it = items[i];
        if (it != 0) {
            if (it->v94 != DAT_00421898 || it->v90 != DAT_00421898)
                it->FUN_001c5130(DAT_00421898, DAT_004218c0);
        }
    }
}
