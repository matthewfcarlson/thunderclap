// STATUS: equivalent (tools/equiv.py level 3: 2964 inputs, branch coverage 22/22)
// FUN_001c75e0 @ 0x001c75e0
struct Key_1c75e0 {
    unsigned int lo;
    unsigned int hi;
};

struct Slot_1c75e0 {
    unsigned int keyLo;
    unsigned int keyHi;
    void *value;
    unsigned int stamp;
};

struct Resolved {
    char FUN_0027af90(Key_1c75e0 *key);
};

class Cache_1c75e0 {
public:
    virtual void v0();
    virtual Resolved *v1(void *source);
    char pad04[0xc];
    int sourceCount;
    void **sources;
    Slot_1c75e0 slots[16];
    unsigned int clock;

    void *FUN_001c75e0(Key_1c75e0 *key);
};

void *Cache_1c75e0::FUN_001c75e0(Key_1c75e0 *key)
{
    int i;

    for (i = 0; i < 16; i++) {
        if (slots[i].keyLo == key->lo && slots[i].keyHi == key->hi) {
            slots[i].stamp = clock;
            clock++;
            return slots[i].value;
        }
    }

    for (i = 0; i <= sourceCount; i++) {
        void *src = sources[i];
        if (src == 0)
            continue;
        if (!v1(src)->FUN_0027af90(key))
            continue;

        void *found = sources[i];
        if (found == 0)
            return 0;

        int victim = 0;
        unsigned int oldest = 0xffffffff;
        for (int j = 0; j < 16; j++) {
            if (slots[j].value == 0) {
                victim = j;
                break;
            }
            if (slots[j].stamp < oldest) {
                oldest = slots[j].stamp;
                victim = j;
            }
        }

        slots[victim].stamp = clock;
        clock++;
        slots[victim].value = found;
        slots[victim].keyLo = key->lo;
        slots[victim].keyHi = key->hi;
        return found;
    }
    return 0;
}
