// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::ChargeAction::vfunc_4 @ 0x00171950
#include "gen/hulkfight.h"
#include "decls/address.h"

struct Buf28 {
    char d[28];
    void FUN_001c9a60(int a, int b, int c);
};
struct Sink_171950 { void FUN_001cbc20(Buf28 *b); };
struct Probe_171950 { bool FUN_001ccff0(); };
struct World { char pad[0x2c]; Probe_171950 *probe; Sink_171950 *sink; };

struct Ctx2_171950 { char pad[0x10]; int *p10; char pad2[0x1e58 - 0x14]; int v1e58; };
struct Ctx1_171950 { Ctx2_171950 *FUN_00059a30(); };
struct Owner_171950 { Ctx1_171950 *FUN_000592a0(); };
struct Inner_171950 { char pad[0x14]; int v14; };

void hulkfight::motion::ChargeAction::vfunc_4() {
    Buf28 buf;
    if (DAT_004dd700->probe != 0 && DAT_004dd700->probe->FUN_001ccff0()) {
        Sink_171950 *sink = DAT_004dd700->sink;
        if (sink != 0) {
            Ctx2_171950 *c = (*(Owner_171950 * *)&this->f_20)->FUN_000592a0()->FUN_00059a30();
            if (c != 0) {
                buf.FUN_001c9a60(*c->p10, (*(Inner_171950 * *)&this->f_1c)->v14, c->v1e58);
                sink->FUN_001cbc20(&buf);
            }
        }
    }
}
