// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 12/12)
// FUN_00065ee0 @ 0x00065ee0
struct Pair { int a; int b; };

struct PairList {
    char pad0[0x390];
    int count;
    int pad394;
    Pair entries[64];
    void FUN_00065ee0(const Pair* key);
};

// Removes every entry equal to key.
void PairList::FUN_00065ee0(const Pair* key) {
    for (int i = 0; i < count; i++) {
        if (key->a == entries[i].a && key->b == entries[i].b) {
            for (int j = i + 1; j < count; j++)
                entries[j - 1] = entries[j];
            count--;
        }
    }
}
