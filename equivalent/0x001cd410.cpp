// STATUS: equivalent (tools/equiv.py level 3: 12697 inputs, branch coverage 24/24)
// FUN_001cd410 @ 0x001cd410
// cl-flags: /GS
extern "C" int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);

struct Node { void FUN_001dcac0(); };
struct Part28 { void FUN_001fc7c0(); };
struct Part20 { void FUN_0002b3d0(); };
struct Part3cInner { void FUN_000ce850(); };
struct Part3c { char pad[8]; Part3cInner *inner; };
struct Part38 { void FUN_001f6cb0(); };
struct Part14 { void FUN_001b69c0(); };
struct Part48 { void FUN_001faf70(char *buf); };
struct Part30_1cd410 { void FUN_001cc230(); };
struct Part44 { void FUN_00059db0(); };
struct Target_1cd410 {
    char pad[0x32];
    char flag32;
    void FUN_001b9160(int v);
};
struct Part54_1cd410 { Target_1cd410 *FUN_00086290(); };
struct Session_1cd410;
struct Holder_1cd410 { void FUN_0009bc60(Session_1cd410 *s); };
struct Session_1cd410 {
    char pad0[8];
    Holder_1cd410 *holder;
    Node *p0c;
    char pad10[4];
    Part14 *p14;
    char pad18[8];
    Part20 *p20;
    char pad24[4];
    Part28 *p28;
    char pad2c[4];
    Part30_1cd410 *p30;
    char pad34[4];
    Part38 *p38;
    Part3c *p3c;
    char pad40[4];
    Part44 *p44;
    Part48 *p48;
    char pad4c[8];
    Part54_1cd410 *p54;
};
struct Names_1cd410 { const char *FUN_0008a2d0(); };
struct Singleton_1cd410 { void FUN_001d40b0(); };
extern Singleton_1cd410 *FUN_001d4c90();

struct Controller_1cd410 {
    char pad0[4];
    Session_1cd410 *session;
    Names_1cd410 *names;
    char pad0c[0x14a9 - 0xc];
    char busy;
    void FUN_001cd220(int a);
    void FUN_001cd410();
};

struct Frame_1cd410 {
    char buf[0x100];
};

void Controller_1cd410::FUN_001cd410() {
    Frame_1cd410 f;
    char *buf = f.buf;
    busy = 1;
    if (session != 0) {
        if (session->p0c != 0)
            session->p0c->FUN_001dcac0();
        if (session->p28 != 0)
            session->p28->FUN_001fc7c0();
        if (session->p20 != 0)
            session->p20->FUN_0002b3d0();
        if (session->p3c->inner != 0)
            session->p3c->inner->FUN_000ce850();
        if (session->p38 != 0)
            session->p38->FUN_001f6cb0();
        if (session->p14 != 0)
            session->p14->FUN_001b69c0();
        FUN_00267760(buf, 0xff, "art/missions/%s/%s.dh", names->FUN_0008a2d0(), names->FUN_0008a2d0());
        session->p48->FUN_001faf70(buf);
        session->p30->FUN_001cc230();
        session->p44->FUN_00059db0();
    }
    if (session->p54 != 0 && session->p54->FUN_00086290() != 0) {
        session->p54->FUN_00086290()->FUN_001b9160(0);
        session->p54->FUN_00086290()->flag32 = 0;
    }
    Singleton_1cd410 *s = FUN_001d4c90();
    if (s != 0) {
        FUN_001cd220(0);
        s->FUN_001d40b0();
    }
    if (session != 0 && session->holder != 0)
        session->holder->FUN_0009bc60(session);
    busy = 0;
}
