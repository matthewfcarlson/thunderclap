// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000b5bf0 @ 0x000b5bf0
// equiv-map: ??_R0?AVFEObject@@@8 = 0x0049dba4
// equiv-map: ??_R0?AVTextSelector@@@8 = 0x0049dbbc

class FEObject {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24();
    virtual void f25(int v);
};

class TextSelector : public FEObject {
public:
    char pad[4];
};

struct Flags {
    bool FUN_00092de0();
};

struct Reg {
    Flags *FUN_00086340(int id);
};

struct World {
    char pad0[0x54];
    Reg *f54;
};
extern World *DAT_004dd700;

FEObject *__cdecl FUN_000fc260(const char *name);

void FUN_000b5bf0()
{
    TextSelector *sel = dynamic_cast<TextSelector *>(FUN_000fc260("cheat_gray_hulk_selector"));
    if (sel != 0)
        sel->f25(!DAT_004dd700->f54->FUN_00086340(2)->FUN_00092de0());

    sel = dynamic_cast<TextSelector *>(FUN_000fc260("cheat_invulnerability_selector"));
    if (sel != 0)
        sel->f25(!DAT_004dd700->f54->FUN_00086340(0x2e4)->FUN_00092de0());
}
