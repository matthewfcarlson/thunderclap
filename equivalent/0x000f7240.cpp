// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 12/12)
// FUN_000f7240 @ 0x000f7240
// Finds a key in the table, preferring the platform-hashed variant ("_XBOX") over the plain key.
unsigned __int64 __cdecl FUN_002672f0(const char *name, unsigned int lo, unsigned int hi);

struct KeyEntry {
    unsigned int lo, hi;
};

class KeyTable {
public:
    char pad00[0x18];
    KeyEntry *entries;
    char pad1c[4];
    int count;
    int FUN_000f7240(unsigned int lo, unsigned int hi);
};

int KeyTable::FUN_000f7240(unsigned int lo, unsigned int hi)
{
    union {
        unsigned __int64 q;
        unsigned int w[2];
    } platform;
    int found = -1;
    platform.q = FUN_002672f0("_XBOX", lo, hi);
    int n = count;
    for (int i = 0; i < n; i++) {
        unsigned int elo = entries[i].lo;
        unsigned int ehi = entries[i].hi;
        if (platform.w[0] == elo && platform.w[1] == ehi)
            return i;
        if (lo == elo && hi == ehi)
            found = i;
    }
    return found;
}
