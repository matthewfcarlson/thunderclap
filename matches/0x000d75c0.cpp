// FUN_000d75c0 @ 0x000d75c0
#include "decls/data/game/global.h"

typedef unsigned int size_t;
void *operator new(size_t) throw();
char FUN_001d04d0(const void *) throw();

class Base_d75c0 {
public:
    virtual void v();
    char p[12];
    char arg;
    char q[7];
    char result;
    char z[3];
    Base_d75c0(const char *, int) throw();
};

template <class C, class R, class A>
class Method1 : public Base_d75c0 {
public:
    void (*f)();
    Method1(const char *n, void (*x)(), const void *r, const void *a) : Base_d75c0(n, 1)
    {
        f = x;
        result = FUN_001d04d0(r);
        arg = FUN_001d04d0(a);
    }
    virtual void v();
};

template <class C, class R, class A>
class Closure1 : public Method1<C, R, A> {
public:
    C *owner;
    Closure1(const char *n, C *o, void (*f)(), const void *r, const void *a) : Method1<C, R, A>(n, f, r, a)
    {
        owner = o;
    }
    virtual void v();
};

class CSimOverlayManager;

struct Registry_d75c0 {
    void FUN_001d3b70(const char *name, void *obj);
    void FUN_000d7550(const char *name, CSimOverlayManager *mgr, void (*fn)());
};
Registry_d75c0 *FUN_001d4c90();

struct MessageOverlay_d75c0 {
    char pad[0x810];
    MessageOverlay_d75c0 *FUN_000d6640();
};

struct HUDOverlay_d75c0 {
    char pad[0x510];
    HUDOverlay_d75c0 *FUN_000d1720();
};

void FUN_000d6fb0();
void FUN_000d6f80();
void FUN_000d6f90();
void FUN_000d7250();
void FUN_000d72b0();
void FUN_000d7030();
void FUN_000d6f50();

class CSimOverlayManager {
public:
    CSimOverlayManager();
    virtual void v0();
    MessageOverlay_d75c0 *panel;
    HUDOverlay_d75c0 *overlays;
    int f0c;
};

CSimOverlayManager::CSimOverlayManager()
{
    MessageOverlay_d75c0 *p = new MessageOverlay_d75c0;
    panel = p ? p->FUN_000d6640() : 0;
    HUDOverlay_d75c0 *o = new HUDOverlay_d75c0;
    overlays = o ? o->FUN_000d1720() : 0;
    f0c = 0;
    Registry_d75c0 *r = FUN_001d4c90();
    if (r) {
        r->FUN_001d3b70("hud_ShowOverlays", new Closure1<CSimOverlayManager, void, bool>("hud_ShowOverlays", this, FUN_000d6fb0, ((char*)&DAT_0048e100), &DAT_0048e0e4));
        r->FUN_001d3b70("hud_ShowHUD", new Closure1<CSimOverlayManager, void, bool>("hud_ShowHUD", this, FUN_000d6f80, ((char*)&DAT_0048e100), &DAT_0048e0e4));
        r->FUN_001d3b70("hud_ShowMessages", new Closure1<CSimOverlayManager, void, bool>("hud_ShowMessages", this, FUN_000d6f90, ((char*)&DAT_0048e100), &DAT_0048e0e4));
        r->FUN_001d3b70("hud_Show", new Closure1<CSimOverlayManager, void, int>("hud_Show", this, FUN_000d7250, ((char*)&DAT_0048e100), ((char*)&DAT_0048e134)));
        r->FUN_001d3b70("hud_Hide", new Closure1<CSimOverlayManager, void, int>("hud_Hide", this, FUN_000d72b0, ((char*)&DAT_0048e100), ((char*)&DAT_0048e134)));
        r->FUN_001d3b70("hud_SetVisibility", new Closure1<CSimOverlayManager, void, int>("hud_SetVisibility", this, FUN_000d7030, ((char*)&DAT_0048e100), ((char*)&DAT_0048e134)));
        r->FUN_000d7550("hud_GetVisibility", this, FUN_000d6f50);
    }
}
