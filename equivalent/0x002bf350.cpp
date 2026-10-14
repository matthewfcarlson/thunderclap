// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 18/18)
// FUN_002bf350 @ 0x002bf350
class KeyTable_2bf350 {
public:
    char pad00[0x30];
    int count;               // 0x30
    char *entries;           // 0x34, 12-byte records with the key at +0x0a
    int FUN_002bf350(unsigned short key);
};

// Binary search of the entry with the given key; -1 when absent.
int KeyTable_2bf350::FUN_002bf350(unsigned short key) {
    char *base = entries;
    int hi = count - 1;
    int lo = 0;
    int mid = hi / 2;
#define KEY(i) (*(unsigned short *)(base + (i) * 12 + 0xa))
    if (KEY(0) == key)
        return 0;
    if (KEY(hi) == key)
        return hi;
    if (hi > 1) {
        do {
            if (!(KEY(lo) < key))
                break;
            if (!(KEY(hi) > key))
                break;
            unsigned short m = KEY(mid);
            if (m == key)
                return mid;
            if (m < key)
                lo = mid;
            else
                hi = mid;
            mid = lo + (hi - lo) / 2;
        } while (hi - lo > 1);
    }
    if (KEY(mid) == key)
        return mid;
    return -1;
#undef KEY
}
