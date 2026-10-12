// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 21/24, incomplete)
// FUN_001f8b40 @ 0x001f8b40
struct V3 {
    float x, y, z;
};

struct Sub {
    int FUN_00204200(float x, float y, float z);
    char FUN_00204440(int idx);
    char FUN_00204470(int idx);
};

struct Tracker {
    Sub *FUN_000862a0();
};

struct Mgr {
    const char *FUN_001ff950(V3 pos, int a, int b, float lo, float hi);
    int FUN_001fc8c0(unsigned __int64 id);
};

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void getPos(V3 *out);   // 0x20
};

struct Global {
    char pad0[0x28];
    Mgr *mgr;                       // 0x28
    char pad2c[0x54 - 0x2c];
    Tracker *tracker;               // 0x54
};
extern Global *DAT_004dd700;

unsigned __int64 __cdecl FUN_0027b020(const char *s);

int __stdcall FUN_001f8b40(int a1, Obj *obj, float x, float y, float z)
{
    struct Frame {
        V3 p;
        V3 q;
    } f;

    Mgr *mgr = DAT_004dd700->mgr;
    if (mgr == 0)
        return 0;

    if (a1 == 1) {
        obj->getPos(&f.q);
        obj->getPos(&f.p);
        int idx = DAT_004dd700->tracker->FUN_000862a0()->FUN_00204200(f.p.x, f.p.y, f.p.z);
        if (idx == -1) {
            f.p.x = x; f.p.y = y; f.p.z = z;
        } else {
            char b1 = DAT_004dd700->tracker->FUN_000862a0()->FUN_00204440(idx);
            char b2 = DAT_004dd700->tracker->FUN_000862a0()->FUN_00204470(idx);
            if (!b1 && !b2) {
                f.p.x = x; f.p.y = y; f.p.z = z;
            }
        }
        const char *name = mgr->FUN_001ff950(f.p, 1, 2, -3.4028235e38f, 30.0f);
        if (name == 0)
            return (int)obj;
        return mgr->FUN_001fc8c0(FUN_0027b020(name));
    }

    if (a1 > 1 && a1 <= 5) {
        obj->getPos(&f.p);
        int idx = DAT_004dd700->tracker->FUN_000862a0()->FUN_00204200(f.p.x, f.p.y, f.p.z);
        if (idx == -1) {
            f.p.x = x; f.p.y = y; f.p.z = z;
        } else {
            char b1 = DAT_004dd700->tracker->FUN_000862a0()->FUN_00204440(idx);
            char b2 = DAT_004dd700->tracker->FUN_000862a0()->FUN_00204470(idx);
            if (!b1 && !b2) {
                f.p.x = x; f.p.y = y; f.p.z = z;
            }
        }
        const char *name = mgr->FUN_001ff950(f.p, a1, 0, -3.4028235e38f, 3.4028235e38f);
        if (name != 0)
            return mgr->FUN_001fc8c0(FUN_0027b020(name));
    }
    return (int)obj;
}
