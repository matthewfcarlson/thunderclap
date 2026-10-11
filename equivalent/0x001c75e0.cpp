// STATUS: equivalent (tools/equiv.py level 3: 32 inputs, branch coverage 22/22)
// FUN_001c75e0 @ 0x001c75e0
struct Key {
    unsigned int lo;
    unsigned int hi;
};

struct Slot {
    unsigned int keyLo;
    unsigned int keyHi;
    void *value;
    unsigned int stamp;
};

struct Resolved {
    char FUN_0027af90();
};

class Cache {
public:
    virtual void v0();
    virtual Resolved *v1(void *source, Key *key);
    char pad04[0xc];
    int sourceCount;
    void **sources;
    Slot slots[16];
    unsigned int clock;

    void *FUN_001c75e0(Key *key);
};

void *Cache::FUN_001c75e0(Key *key)
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
        if (v1(src, key)->FUN_0027af90())
            break;
    }
    if (i > sourceCount)
        return 0;

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
