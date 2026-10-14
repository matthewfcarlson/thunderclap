// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001dd110 @ 0x001dd110
struct Slot_1dd110 {
    unsigned int keyLo;
    unsigned int keyHi;
    float value;
    int pad;
};

extern "C" unsigned __int64 __cdecl FUN_0027b020(const char* name);

class SlotTable_1dd110 {
public:
    char pad0[0x1ec60];
    Slot_1dd110 slots[16];
    bool FUN_001dd110(const char* name, float value);
};

bool SlotTable_1dd110::FUN_001dd110(const char* name, float value) {
    unsigned __int64 key = FUN_0027b020(name);
    unsigned int lo = (unsigned int)key;
    unsigned int hi = (unsigned int)(key >> 32);
    for (int i = 0; i < 16; i++) {
        Slot_1dd110* s = &slots[i];
        if (s->keyLo == lo && s->keyHi == hi) {
            s->value = value;
            return true;
        }
        if ((s->keyLo | s->keyHi) == 0) {
            s->keyLo = lo;
            s->keyHi = hi;
            s->value = value;
            return true;
        }
    }
    return false;
}
