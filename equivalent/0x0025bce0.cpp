// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0025bce0 @ 0x0025bce0
#include "gen/owners.h"
struct Reader {
    bool FUN_00246f00(char *buf, int size, int a, int b);
};

struct Printer_25bce0 {
};

struct Holder_25bce0 {
    Reader *reader;
};

bool __cdecl FUN_0025abd0(Holder_25bce0 *h, int *len);

bool __cdecl FUN_0025bce0(Holder_25bce0 *h, Printer_25bce0 *out)
{
    struct Frame {
        int len;
        char buf[0x400];
    } f;
    bool ok = FUN_0025abd0(h, &f.len);
    if (ok) {
        ok = h->reader->FUN_00246f00(f.buf, f.len + 1, 0, 1);
        if (!ok) {
            ((owners::String_23fe50 *)out)->FUN_0023fe50("");
            return false;
        }
        ((owners::String_23fe50 *)out)->FUN_0023fe50(f.buf);
    }
    return ok;
}
