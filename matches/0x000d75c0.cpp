// FUN_000d75c0 @ 0x000d75c0
#include "decls/data/game/global.h"

#include "compat/ptr.h"
#include "decls/data/script.h"
void *operator new(hulk_uintptr) throw();
char FUN_001d04d0(const void *) throw();

struct MessageOverlay_d75c0 {
    char pad[0x810];
    MessageOverlay_d75c0 *FUN_000d6640();
};
struct HUDOverlay_d75c0 {
    char pad[0x510];
    HUDOverlay_d75c0 *FUN_000d1720();
};
// CSimOverlayManager and the members it binds to Lua (their types are the game's Closure1<CSimOverlayManager, ...>
// instantiations); the class is complete before any pointer to its members is formed, so the pointer is one code
// pointer on every build (docs/native-build.md sh2).
class CSimOverlayManager {
public:
    CSimOverlayManager();
    virtual void v0();
    MessageOverlay_d75c0 *panel;
    HUDOverlay_d75c0 *overlays;
    int f0c;
    void FUN_000d6fb0(bool);  // hud_ShowOverlays
    void FUN_000d6f80(bool);  // hud_ShowHUD
    void FUN_000d6f90(bool);  // hud_ShowMessages
    void FUN_000d7250(int);   // hud_Show
    void FUN_000d72b0(int);   // hud_Hide
    void FUN_000d7030(int);   // hud_SetVisibility
    int FUN_000d6f50();       // hud_GetVisibility
};
// Function's fields (include/decls/data/script.h) after the vftable; Method1 keeps the bound member-function pointer.
class Base_d75c0 : public ScriptFunctionFields {
public:
    virtual void v();
    Base_d75c0(const char *, int) throw();
};
template <class C, class R, class A>
class Method1 : public Base_d75c0 {
public:
    R (C::*f)(A);
    Method1(const char *n, R (C::*x)(A), const void *r, const void *a) : Base_d75c0(n, 1)
    {
        f = x;
        retType = FUN_001d04d0(r);
        argTypes[0] = FUN_001d04d0(a);
    }
    virtual void v();
};
template <class C, class R, class A>
class Closure1 : public Method1<C, R, A> {
public:
    C *owner;
    Closure1(const char *n, C *o, R (C::*f)(A), const void *r, const void *a) : Method1<C, R, A>(n, f, r, a)
    {
        owner = o;
    }
    virtual void v();
};
struct Registry_d75c0 {
    void FUN_001d3b70(const char *name, void *obj);
    void FUN_000d7550(const char *name, CSimOverlayManager *mgr, int (CSimOverlayManager::*fn)());
};
extern "C" Registry_d75c0 *FUN_001d4c90();
CSimOverlayManager::CSimOverlayManager()
{
    MessageOverlay_d75c0 *p = new MessageOverlay_d75c0;
    panel = p ? p->FUN_000d6640() : 0;
    HUDOverlay_d75c0 *o = new HUDOverlay_d75c0;
    overlays = o ? o->FUN_000d1720() : 0;
    f0c = 0;
    Registry_d75c0 *r = FUN_001d4c90();
    if (r) {
        r->FUN_001d3b70("hud_ShowOverlays", new Closure1<CSimOverlayManager, void, bool>("hud_ShowOverlays", this, &CSimOverlayManager::FUN_000d6fb0, ((char*)&DAT_0048e100), &DAT_0048e0e4));
        r->FUN_001d3b70("hud_ShowHUD", new Closure1<CSimOverlayManager, void, bool>("hud_ShowHUD", this, &CSimOverlayManager::FUN_000d6f80, ((char*)&DAT_0048e100), &DAT_0048e0e4));
        r->FUN_001d3b70("hud_ShowMessages", new Closure1<CSimOverlayManager, void, bool>("hud_ShowMessages", this, &CSimOverlayManager::FUN_000d6f90, ((char*)&DAT_0048e100), &DAT_0048e0e4));
        r->FUN_001d3b70("hud_Show", new Closure1<CSimOverlayManager, void, int>("hud_Show", this, &CSimOverlayManager::FUN_000d7250, ((char*)&DAT_0048e100), ((char*)&DAT_0048e134)));
        r->FUN_001d3b70("hud_Hide", new Closure1<CSimOverlayManager, void, int>("hud_Hide", this, &CSimOverlayManager::FUN_000d72b0, ((char*)&DAT_0048e100), ((char*)&DAT_0048e134)));
        r->FUN_001d3b70("hud_SetVisibility", new Closure1<CSimOverlayManager, void, int>("hud_SetVisibility", this, &CSimOverlayManager::FUN_000d7030, ((char*)&DAT_0048e100), ((char*)&DAT_0048e134)));
        r->FUN_000d7550("hud_GetVisibility", this, &CSimOverlayManager::FUN_000d6f50);
    }
}
