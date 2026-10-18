// FUN_00065ee0 @ 0x00065ee0
struct Pair_65ee0 { int a; int b; };

struct PairList {
    char pad0[0x390];
    int count;
    int pad394;
    Pair_65ee0 entries[64];
    void FUN_00065ee0(const Pair_65ee0* key);
};

// Removes every entry equal to key.
void PairList::FUN_00065ee0(const Pair_65ee0* key) {
    for (int i = 0; i < count; i++) {
        if (key->a == entries[i].a && key->b == entries[i].b) {
            for (int j = i + 1; j < count; j++)
                entries[j - 1] = entries[j];
            count--;
        }
    }
}
