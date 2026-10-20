// STATUS: equivalent (tools/equiv.py level 3: 236 inputs, branch coverage 44/44)
// physics::PhysicsObjectLoader::vfunc_5 @ 0x002f70a0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
#include "compat/ptr.h"
#include "gen/physics.h"
#include "decls/address.h"
#include "decls/data/game/global.h"

struct Vec3_2f70a0 {
    float x, y, z;
};

struct Key_2f70a0 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027b040(const char *name);
};

struct SymMatrix_2f70a0 {
    int vptr;
    float m[6];
    void FUN_002fca90();
    void FUN_002fcaa0();
    void FUN_002fd0a0();
};

struct Stream_2f70a0 {
    char pad[0xc];
    char FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Reader_2f70a0 {
    char pad000[0x284];
    Stream_2f70a0 *stream;                  // 0x284
    char FUN_002669f0();
    void FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
};

class Part_2f70a0 {
public:
    virtual ~Part_2f70a0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(unsigned int a, unsigned int b);
    char pad04[2];
    short f6;
    char pad08[0xe4 - 8];
    unsigned int fe4;
    void FUN_00309940(SymMatrix_2f70a0 *sm);
};

struct Props;

struct SimObject {
    char pad00[8];
    Key_2f70a0 key8;
    char pad10[0x30 - 0x10];
    Key_2f70a0 key30;
    void FUN_002fe6b0(void *world);
};

struct Composite_2f70a0 : SimObject {
    Composite_2f70a0 *FUN_00309520(Props *props, Part_2f70a0 **parts, int count);
};

struct Articulated : SimObject {
    Articulated *FUN_002f6220(Props *props, Vec3_2f70a0 *center, SymMatrix_2f70a0 *sm, unsigned int c);
};


void __cdecl FUN_002f5fe0(Reader_2f70a0 *r, SymMatrix_2f70a0 *sm);
Part_2f70a0 *__cdecl FUN_0030d4f0(unsigned int a, Vec3_2f70a0 *v, unsigned int b, unsigned int c);
Props *__cdecl FUN_002f2750(unsigned __int64 key);
int __cdecl FUN_00266da0(int sel);
void *__cdecl FUN_0008d6d0(hulk_uintptr size);
void __cdecl thunk_FUN_00267090(void *p);
void *thunk_FUN_0008d690(unsigned int size);
int __cdecl FUN_00267760(char *buf, int n, const char *fmt, ...);

void physics::PhysicsObjectLoader::vfunc_5(void* __p0, void* __p1, void* __p2, int unused) { void ** outObj = (void **)__p0; Key_2f70a0 * outKey = (Key_2f70a0 *)__p1; Reader_2f70a0 * r = (Reader_2f70a0 *)__p2;

    struct Frame {
        char pad00[3];
        unsigned char len;           // 0x03
        int b;                       // 0x04   number of articulated parts
        unsigned int d;              // 0x08
        unsigned int c;              // 0x0c
        unsigned int v1;             // 0x10
        unsigned int v0;             // 0x14
        unsigned int v2;             // 0x18
        int a;                       // 0x1c   kind
        unsigned int v3;             // 0x20
        unsigned int v5;             // 0x24
        Vec3_2f70a0 zero;                   // 0x28
        SymMatrix_2f70a0 sm;                // 0x34
        Vec3_2f70a0 center;                 // 0x50
        char name1[0x100];           // 0x5c
        char name2[0x100];           // 0x15c
        char msg[0x12c];             // 0x25c
    } f;

    r->stream->FUN_002647e0(&f.len, 1, 1, 1);
    unsigned int n = f.len;
    r->stream->FUN_002647e0(f.name1, n, 1, 1);
    f.name1[n] = 0;
    r->stream->FUN_002647e0(&f.a, 1, 4, 1);
    r->stream->FUN_002647e0(&f.len, 1, 1, 1);
    n = f.len;
    r->stream->FUN_002647e0(f.name2, n, 1, 1);
    f.name2[n] = 0;
    r->stream->FUN_002647e0(&f.b, 1, 4, 1);
    r->stream->FUN_002647e0(&f.c, 1, 4, 1);
    r->stream->FUN_002647e0(&f.d, 1, 4, 1);

    Part_2f70a0 **parts = 0;
    int count = 0;
    if (f.b > 0) {
        int prev = FUN_00266da0(1);
        parts = (Part_2f70a0 **)FUN_0008d6d0(f.b * 4);
        FUN_00266da0(prev);
    }
    f.sm.FUN_002fca90();

    while (r->FUN_002669f0()) {
        r->FUN_00266a30();
        int id = r->FUN_00266c30();
        if (id == 0x7011001) {
            FUN_002f5fe0(r, &f.sm);
        } else if (id == 0x7011002) {
            r->stream->FUN_002647e0(&f.center, 3, 4, 1);
        } else if (id == 0x7011020) {
            r->stream->FUN_002647e0(&f.v0, 1, 4, 1);
            r->stream->FUN_002647e0(&f.v1, 1, 4, 1);
            r->stream->FUN_002647e0(&f.v2, 1, 4, 1);
            r->stream->FUN_002647e0(&f.v3, 1, 4, 1);
            r->stream->FUN_002647e0(&f.d, 1, 4, 1);
            r->stream->FUN_002647e0(&f.v5, 1, 4, 1);
            f.zero.x = 0.0f;
            f.zero.y = 0.0f;
            f.zero.z = 0.0f;
            f.sm.FUN_002fd0a0();
            while (r->FUN_002669f0()) {
                r->FUN_00266a30();
                int sub = r->FUN_00266c30();
                if (sub == 0x7011001)
                    FUN_002f5fe0(r, &f.sm);
                else if (sub == 0x7011002)
                    r->stream->FUN_002647e0(&f.zero, 3, 4, 1);
                r->FUN_00266be0();
            }
            int prev = FUN_00266da0(1);
            Part_2f70a0 *p = FUN_0030d4f0(f.v5, &f.zero, f.v1, f.v0);
            parts[count] = p;
            if (p->f6 > 0)
                p->fe4 = f.v2;
            parts[count]->v9(f.d, f.v3);
            parts[count]->FUN_00309940(&f.sm);
            FUN_00266da0(prev);
            count++;
        }
        r->FUN_00266be0();
    }

    Props *props = FUN_002f2750(FUN_0027b020(f.name2));
    if (props == 0)
        props = FUN_002f2750(FUN_0027b020(count == 0 ? "defaultPhysicsProperties" : "defaultArtPhysicsProperties"));

    SimObject *res = 0;
    if (f.a == 2) {
        void *mem = thunk_FUN_0008d690(0x200);
        Composite_2f70a0 *c = 0;
        if (mem != 0)
            c = ((Composite_2f70a0 *)mem)->FUN_00309520(props, parts, count);
        res = c;
        for (int i = 0; i < f.b; i++) {
            if (parts[i] != 0)
                delete parts[i];
        }
        thunk_FUN_00267090(parts);
    } else if (f.b == 0) {
        void *mem = thunk_FUN_0008d690(0x1f8);
        if (mem != 0)
            res = ((Articulated *)mem)->FUN_002f6220(props, &f.center, &f.sm, f.c);
    } else if (count > 0) {
        FUN_00267760(f.msg, 0x12c, "Found an ArticulatedPhysicsObject named %s.", f.name1);
    }

    unsigned int lo = 0;
    unsigned int hi = 0;
    if (res != 0) {
        res->key8.FUN_0027b040(f.name1);
        res->key30.FUN_0027b040(f.name2);
        res->FUN_002fe6b0((*(void**)&DAT_00554c10));
        lo = res->key8.lo;
        hi = res->key8.hi;
    }
    *outObj = res;
    outKey->lo = lo;
    outKey->hi = hi;
    f.sm.FUN_002fcaa0();
}
