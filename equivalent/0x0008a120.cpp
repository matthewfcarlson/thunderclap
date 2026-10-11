// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 29/38, incomplete)
// FUN_0008a120 @ 0x0008a120
extern "C" int memcmp(const void *a, const void *b, unsigned n);

struct NameEntry {
    unsigned __int64 key;
    char name[16];
};

extern const char *DAT_003ffde0[35];
extern const char DAT_003f335c[16];

unsigned __int64 __cdecl FUN_0027b020(const char *s);

class LevelRegistry {
public:
    char pad0[0x158];
    NameEntry entries[100];
    int FUN_00089400(const char *s);
    void FUN_00089f00(const char *key, const char *value);
    void FUN_0008a120();
};

void LevelRegistry::FUN_0008a120()
{
    const char *seen = 0;
    int i;
    int k;
    for (i = 34; i >= 0; i--) {
        const char *s = DAT_003ffde0[i];
        unsigned __int64 h = FUN_0027b020(s);
        const char *name = DAT_003f335c;
        for (k = 0; k < 100; k++) {
            if (entries[k].key == 0)
                break;
            if (entries[k].key == h) {
                name = entries[k].name;
                break;
            }
        }
        if (seen == 0) {
            if (memcmp(name, "complete", 9) == 0)
                seen = s;
        } else {
            if (memcmp(name, "complete", 9) != 0)
                FUN_00089f00(s, "complete");
        }
    }

    unsigned __int64 h = FUN_0027b020("c06m03");
    const char *name = DAT_003f335c;
    for (k = 0; k < 100; k++) {
        if (entries[k].key == 0)
            break;
        if (entries[k].key == h) {
            name = entries[k].name;
            break;
        }
    }
    if (name[0] == 0) {
        int idx = FUN_00089400("c06m02");
        const char *n2 = DAT_003f335c;
        if (idx != -1)
            n2 = entries[idx].name;
        if (n2[0] != 0)
            FUN_00089f00("c06m03", "locked");
    }
}
