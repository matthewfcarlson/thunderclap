// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 53/54, incomplete)
// FUN_0003b7d0 @ 0x0003b7d0
extern char DAT_0048e090[];
extern char DAT_0048e0ac[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct V3 {
    float x, y, z;
    bool FUN_0022d2b0(const V3 *other, float eps);
};

class RefObj {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Handle;

class Link {
public:
    void FUN_00231ad0(void *h, int v, int flag);
};

struct Handle {
    RefObj *obj;
    bool FUN_00231ee0();
};

struct Anim {
    void FUN_002322f0(int a, float dt);
    void FUN_00231f20(int a);
    void FUN_002324b0(int a);
    void FUN_00232240();
    bool FUN_00231ee0();
};

class Finder {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Link *Make(int v, int flag);
    Link *FUN_00233320(int lo, int hi);
};

class Listener {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void Update(int a, float dt);
};

class Host {
public:
    char pad0[0xec];
    Finder *finder;
    char padf0[0x11c - 0xf0];
    Finder *activeFinder;
};

struct Prop {
    char pad[0xfc];
    int state;
};

struct PropSlot {
    Prop *prop;
    char pad[0x4c];
};

struct Pool {
    void FUN_00060170();
};

class Actor {
public:
    char pad0[0xb4];
    Anim anim;  // 0xb4
    char padb5[0x27];
    Handle current;  // 0xdc
    char pade0[0x24];
    int key;  // 0x104
    RefObj *previous;  // 0x108
    RefObj *previous2;  // 0x10c
    char pad110[0x8];
    bool dead;  // 0x118
    bool frozen;  // 0x119
    char pad11a[0x2];
    Host *host;  // 0x11c
    char pad120[0x1f4];
    float timeScale;  // 0x314
    char pad318[0x20];
    int lock;  // 0x338
    char pad33c[0x6c];
    PropSlot slots[8];  // 0x3a8
    char pad628[0x1540];
    V3 dir;  // 0x1b68
    char pad1b74[0x12c];
    Listener *listener;  // 0x1ca0
    char pad1ca4[0x2b4];
    Pool pool;  // 0x1f58
    char pad1f59[0x11b];
    V3 savedDir;  // 0x2074
    char pad2080[0x18];
    int idLo;  // 0x2098
    int idHi;  // 0x209c
    bool hasId;  // 0x20a0
    char pad20a1[0x7];
    int phase;  // 0x20a8
    char pad20ac[0x1f0];
    bool flagA;  // 0x229c
    bool flagB;  // 0x229d
    char pad229e[0x2];
    int z0;  // 0x22a0
    int z1;  // 0x22a4
    int z2;  // 0x22a8
    int poolCount;  // 0x22ac
    void FUN_0003acf0(int slot, int a, int b, int c, int d, int e);
    void FUN_0003b7d0(int a, float dt);
};

void Actor::FUN_0003b7d0(int a, float dt)
{
    V3 zero;
    if (dead)
        return;
    if (frozen)
        return;
    dt = dt * timeScale;
    flagA = false;
    flagB = false;
    z2 = 0;
    z1 = 0;
    z0 = 0;
    if (host == 0)
        return;
    if (listener != 0)
        listener->Update(a, dt);
    if (phase < 0) {
        Finder *f = host->activeFinder;
        if (f != 0 && !anim.FUN_00231ee0()) {
            Link *l = f->Make(key, 0);
            if (l != 0)
                l->FUN_00231ad0(&anim, key, 0);
        }
        anim.FUN_002322f0(1, dt);
        anim.FUN_00231f20(0);
        anim.FUN_002324b0(1);
    } else {
        anim.FUN_00232240();
    }
    for (int i = 0; i < 8; i++) {
        if (slots[i].prop != 0) {
            int st = slots[i].prop->state;
            if (st == 2 || st == 3)
                FUN_0003acf0(i, 0, -1, 0, 0, 0);
        }
    }
    zero.z = 0;
    zero.y = 0;
    zero.x = 0;
    if (!dir.FUN_0022d2b0(&zero, 1e-5f))
        savedDir = dir;
    if (poolCount > 0)
        pool.FUN_00060170();
    RefObj *cur = current.obj;
    if (cur != 0)
        cur->AddRef();
    if (previous != 0)
        previous->Release();
    previous = cur;
    Finder *f2 = host->finder;
    if (f2 != 0 && !current.FUN_00231ee0() && lock == 0) {
        Link *l = 0;
        if (hasId && (idLo | idHi) != 0) {
            Link *r = f2->FUN_00233320(idLo, idHi);
            if (r != 0)
                l = (Link *)FUN_00344e74(r, 0, DAT_0048e090, DAT_0048e0ac, 0);
        }
        if (l == 0)
            l = f2->Make(key, 0);
        if (l != 0)
            l->FUN_00231ad0(&current, key, 0);
    }
    RefObj *p = previous;
    if (current.obj != p) {
        if (p != 0)
            p->AddRef();
        if (previous2 != 0)
            previous2->Release();
        previous2 = p;
    }
}
