// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::ChargeAction::vfunc_4 @ 0x00171950
struct Buf28 {
    char d[28];
    void FUN_001c9a60(int a, int b, int c);
};
struct Sink { void FUN_001cbc20(Buf28 *b); };
struct Probe { bool FUN_001ccff0(); };
struct Mgr { char pad[0x2c]; Probe *probe; Sink *sink; };
extern Mgr *DAT_004dd700;

struct Ctx2 { char pad[0x10]; int *p10; char pad2[0x1e58 - 0x14]; int v1e58; };
struct Ctx1 { Ctx2 *FUN_00059a30(); };
struct Owner { Ctx1 *FUN_000592a0(); };
struct Inner { char pad[0x14]; int v14; };

class ChargeAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x1c - 4];
    Inner *inner;
    Owner *owner;
};

void ChargeAction::vfunc_4()
{
    Buf28 buf;
    if (DAT_004dd700->probe != 0 && DAT_004dd700->probe->FUN_001ccff0()) {
        Sink *sink = DAT_004dd700->sink;
        if (sink != 0) {
            Ctx2 *c = owner->FUN_000592a0()->FUN_00059a30();
            if (c != 0) {
                buf.FUN_001c9a60(*c->p10, inner->v14, c->v1e58);
                sink->FUN_001cbc20(&buf);
            }
        }
    }
}
