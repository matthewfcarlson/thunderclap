// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 13/14, incomplete)
// FUN_001c6660 @ 0x001c6660
struct Sub_1c6660 { char data[0xa4]; bool FUN_001c27d0(int a); };
struct Elem_1c6660 { char flag; char pad[3]; Sub_1c6660 sub; };
struct Guard_1c6660 { char data[4]; bool FUN_001acb90(int a); };

class Pool_1c6660 {
public:
    char pad0[0x14];
    Elem_1c6660 *begin;
    Elem_1c6660 *end;
    char pad1c[0x2c - 0x1c];
    Guard_1c6660 guard;
    bool FUN_001c6660(int a);
};

bool Pool_1c6660::FUN_001c6660(int a)
{
    unsigned n = end - begin;
    if (n == 0)
        return true;
    if (!guard.FUN_001acb90(a))
        return false;
    for (unsigned i = 0; i < n; i++) {
        Elem_1c6660 *e = &begin[i];
        if (e->flag) {
            if (e->sub.FUN_001c27d0(a))
                return false;
        } else if (e->sub.FUN_001c27d0(a)) {
            return true;
        }
    }
    return false;
}
