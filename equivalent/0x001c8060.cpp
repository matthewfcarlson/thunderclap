// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 42/44, incomplete)
// FUN_001c8060 @ 0x001c8060
struct Key_1c8060 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af10(unsigned lo, unsigned hi);
    void FUN_0027af50();
};

struct Entry_1c8060 {
    unsigned lo;
    unsigned hi;
    char active;
    char pad9[3];
    bool FUN_001c6660(int query);
};

struct Index_1c8060 {
    Entry_1c8060 *FUN_001c75e0(Key_1c8060 *k);
};

class Registry_1c8060 {
public:
    char pad0[0x18];
    Index_1c8060 index;
    char pad19[0xf];
    int count;
    Entry_1c8060 **table;

    Entry_1c8060 *FUN_001c8060(int query, Key_1c8060 *out);
};

Entry_1c8060 *Registry_1c8060::FUN_001c8060(int query, Key_1c8060 *out)
{
    Entry_1c8060 *e = 0;
    bool found = false;
    if (out != 0 && (out->lo | out->hi) != 0) {
        Key_1c8060 k;
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
            Entry_1c8060 **t = table;
            if (t[i] == 0) {
                int n = count;
                while (i <= n) {
                    Entry_1c8060 *next = t[i + 1];
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
