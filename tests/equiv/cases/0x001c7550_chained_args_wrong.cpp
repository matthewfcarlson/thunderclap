// STATUS: (regression case, wrong) a second arg-unshift pass (native10, reverted): `entry` moved from the virtual
// Lookup (which pops it) to FUN_0027af90 (ret 4: takes only the key); byte-identical code, must fail
// FUN_001c7550 @ 0x001c7550
struct Key_1c7550 {
    int lo, hi;
};

struct Pending_1c7550 {
    int lo, hi;
    int w8, wc;
};

class Result_1c7550 {
public:
    char FUN_0027af90(void *entry, const Key_1c7550 *key);
};

class Registry_1c7550 {
public:
    virtual void v0();
    virtual Result_1c7550 *Lookup();     // slot 1
    char pad04[8];
    int removed;             // 0x0c
    int last;                // 0x10
    void **entries;          // 0x14
    Pending_1c7550 pending[16];     // 0x18
    void FUN_001c7550(const Key_1c7550 *key);
};

// Cancels a pending request for the key, then drops the first entry that resolves it.
void Registry_1c7550::FUN_001c7550(const Key_1c7550 *key) {
    int lo = key->lo;
    int hi = key->hi;
    for (int i = 0; i < 16; i++) {
        if (pending[i].lo == lo && pending[i].hi == hi) {
            pending[i].lo = 0;
            pending[i].hi = 0;
            pending[i].w8 = 0;
            break;
        }
    }
    if (last < 0)
        return;
    int i = 0;
    do {
        void *entry = entries[i];
        if (entry != 0 && Lookup()->FUN_0027af90(entry, key)) {
            entries[i] = 0;
            removed++;
            return;
        }
        i++;
    } while (i <= last);
}
