// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 42/44, incomplete)
// FUN_001c8060 @ 0x001c8060
struct Key {
    unsigned lo;
    unsigned hi;
    void FUN_0027af10(unsigned lo, unsigned hi);
    void FUN_0027af50();
};

struct Entry {
    unsigned lo;
    unsigned hi;
    char active;
    char pad9[3];
    bool FUN_001c6660(int query);
};

struct Index {
    Entry *FUN_001c75e0(Key *k);
};

class Registry {
public:
    char pad0[0x18];
    Index index;
    char pad19[0xf];
    int count;
    Entry **table;

    Entry *FUN_001c8060(int query, Key *out);
};

Entry *Registry::FUN_001c8060(int query, Key *out)
{
    Entry *e = 0;
    bool found = false;
    if (out != 0 && (out->lo | out->hi) != 0) {
        Key k;
        k.lo = 0;
        k.FUN_0027af10(out->lo, out->hi);
        e = index.FUN_001c75e0(&k);
        found = (e != 0);
        k.FUN_0027af50();
    }
    if (found && e->FUN_001c6660(query))
        return e;

    for (int pass = 0; pass < 2; pass++) {
        int i = 0;
        for (;;) {
            Entry **t = table;
            if (t[i] == 0) {
                int n = count;
                while (i <= n) {
                    Entry *next = t[i + 1];
                    i++;
                    if (next != 0)
                        break;
                }
            }
            if (i > count)
                break;
            e = t[i];
            i++;
            if (e == 0)
                break;
            if ((e->active != 0) != (pass == 0))
                continue;
            if (!e->FUN_001c6660(query))
                continue;
            if (out != 0) {
                out->lo = e->lo;
                out->hi = e->hi;
            }
            return e;
        }
    }
    if (out != 0) {
        out->lo = 0;
        out->hi = 0;
    }
    return 0;
}
