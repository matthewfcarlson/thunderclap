// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 13/14, incomplete)
// FUN_001c6660 @ 0x001c6660
struct Sub { char data[0xa4]; bool FUN_001c27d0(int a); };
struct Elem { char flag; char pad[3]; Sub sub; };
struct Guard { char data[4]; bool FUN_001acb90(int a); };

class Pool {
public:
    char pad0[0x14];
    Elem *begin;
    Elem *end;
    char pad1c[0x2c - 0x1c];
    Guard guard;
    bool FUN_001c6660(int a);
};

bool Pool::FUN_001c6660(int a)
{
    unsigned n = end - begin;
    if (n == 0)
        return true;
    if (!guard.FUN_001acb90(a))
        return false;
    for (unsigned i = 0; i < n; i++) {
        Elem *e = &begin[i];
        if (e->flag) {
            if (e->sub.FUN_001c27d0(a))
                return false;
        } else if (e->sub.FUN_001c27d0(a)) {
            return true;
        }
    }
    return false;
}
