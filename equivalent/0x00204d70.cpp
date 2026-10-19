// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 4/4)
// FUN_00204d70 @ 0x00204d70
// cl-flags: /GS
#include "decls/data/game/global.h"

extern "C" int __cdecl sprintf(char *, const char *, ...);
struct Frame_204d70 { char buf[32];  };
struct Rec_204d70 { char pad[0x38]; int v38; };
struct Target_204d70 {
    char pad0[0x24];
    char name[1];
    Rec_204d70 *FUN_00204540(char *key);
    int FUN_00204d70(int index);
};
int Target_204d70::FUN_00204d70(int index)
{
    Frame_204d70 f;
    char *buf = f.buf;
    sprintf(buf, "%s_r%03d", name, index);
    if ((*(char*)&DAT_004c91d8) != 0) {
        Rec_204d70 *r = FUN_00204540(buf);
        if (r != 0) {
            int v = r->v38;
            return v;
        }
    }
    return 0;
}
