// STATUS: equivalent (tools/equiv.py level 3: 2791 inputs, branch coverage 131/148, incomplete)
// FUN_000c31e0 @ 0x000c31e0
// equiv-map: ??_R0?AVFEObject@@@8 = 0x0049dba4
// equiv-map: ??_R0?AVTextSelector@@@8 = 0x0049dbbc
// equiv-map: ??_R0?AVImageSelector@@@8 = 0x0049f454
// equiv-map: ??_R0?AVTextLabel@@@8 = 0x0049f48c
// equiv-map: ??_R0?AVCUnlockable@@@8 = 0x0049dab8
// equiv-map: ??_R0?AVCUnlockableMove@@@8 = 0x0049db1c
// equiv-map: ??_R0?AVCUnlockableCheat@@@8 = 0x0049dafc
inline void *operator new(unsigned int, void *p) throw() { return p; }
typedef unsigned short wchar_t;

extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int cookie);

namespace pure3d { class CompositeDrawable; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }

struct Inner_c31e0 {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void v16(int a);
    virtual void v17();
    virtual void v18(int a);
};

struct Loaded_c31e0 {
    virtual void l0();
    char pad4[0x50 - 4];
    Inner_c31e0 *f50;
};

struct Inventory_c31e0 {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Loaded_c31e0 *find(void *caster, unsigned __int64 key);
};
extern Inventory_c31e0 *DAT_004dd9cc;

struct Loc_c31e0 {
    const wchar_t *FUN_00088ea0(const char *key);
};

struct Lab {
    void FUN_000f8500(const char *key, Loc_c31e0 *loc, int one);
};

class FEObject {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22();
};

class TextSelector : public FEObject {
public:
    char pad_ts[0x154 - 0x4];
    int f154;
    char pad158[0x1d58 - 0x158];
    int f1d58;
};

class ImageSelector : public FEObject {
public:
    virtual int v23();
    int FUN_000e3fe0();
};

class TextLabel : public FEObject {
public:
    char pad_tl[0x18 - 0x4];
    Lab lab;
};

class CUnlockable {
public:
    virtual void u0();
    char pad_cu[4];
    unsigned char b08;
    char FUN_00091f40();
    void FUN_00091f30(int v);
    char FUN_00091fb0();
    int FUN_00091f90();
    int FUN_00091f70();
};

class CUnlockableMove : public CUnlockable {
};

class CUnlockableCheat : public CUnlockable {
public:
    char pad_c[0x20 - 0x9];
    unsigned char b20;
};

struct Menu_c31e0 {
    const char *FUN_00092bc0(int i);
    int FUN_000932a0(int i);
    char FUN_00092860(int i);
    void FUN_000929a0(int a, int b);
    CUnlockable *FUN_00092ad0(int i);
    char FUN_00092940(int i);
    void FUN_00092870(int i, int v);
    void FUN_00093600(int i, char on);
};

struct Sound_c31e0 {
    int FUN_00090110();
    void FUN_000900a0(int v);
};

struct Flagger {
    char FUN_000893c0();
};

struct Hook_c31e0 {
    void FUN_001b8af0();
};

struct Credits_c31e0 {
    virtual void c0();
    virtual void c1(const char *a, const char *b);
};

struct Dlg_c31e0 {
    void FUN_000be230(const char *cls, const char *msg, const char *s3, const char *s4, const char *s5, int a, int b, int c);
    void FUN_000be310(const char *cls, const wchar_t *msg, const char *s3, const char *s4, const char *s5, int a, int b, int c);
};

FEObject *__cdecl FUN_000fc260(const char *name);
void __cdecl FUN_000fc280(const char *s);
Loc_c31e0 *__cdecl FUN_000fc1b0();
Dlg_c31e0 *__cdecl FUN_000fc3d0();
int __cdecl FUN_000fb720(const wchar_t *s);
void __cdecl FUN_000fb690(wchar_t *dst, const wchar_t *src, int n);
void __cdecl FUN_000964a0(char *dst, int n, const char *fmt, int v);
unsigned __int64 __cdecl FUN_0027b020(const char *s);
extern "C" int strcmp(const char *a, const char *b);

struct Frame_c31e0 {
    unsigned char pad0[3];
    unsigned char flag;              // E-0x14d
    int pad4;
    int caster;                      // E-0x148
    char buf[0x40];                  // E-0x144
    wchar_t wide[0x80];              // E-0x104
    unsigned int cookie;             // E-4
};

#define DIALOG_OK(KEY) FUN_000fc3d0()->FUN_000be230("FEGenericDialog", KEY, "", "", "TBS_MENU_ITEM_OK", 2, 0, 0)
#define DIALOG_YN(KEY) FUN_000fc3d0()->FUN_000be230("FEGenericDialog", KEY, "", "TBS_MENU_ITEM_YES", "TBS_MENU_ITEM_NO", 2, 0, 0)

class Env_c31e0 {
public:
    char pad0[0x10];
    int f10;
    char pad14[0x34 - 0x14];
    Flagger *f34;
    char pad38[0x40 - 0x38];
    Credits_c31e0 *f40;
    char pad44[0x4c - 0x44];
    Menu_c31e0 *f4c;
    Sound_c31e0 *f50;
    Hook_c31e0 *f54;
    char pad58[0x1244 - 0x58];
    int tblBase;                     // 0x1244: int table indexed by id
    char pad1248[0x1874 - 0x1248];
    int f1874;
    unsigned char b1878;
    char pad1879[3];
    int f187c;
    char pad1880[0x1a04 - 0x1880];
    unsigned char b1a04;
    unsigned char b1a05;
    char pad1a06[0x1cec - 0x1a06];
    int f1cec;

    void FUN_000c1f70(int i);
    void FUN_000c21b0(int i);
    void FUN_000ba040();
    void FUN_000be100();
    void FUN_000bb5c0();
    void FUN_000bb600();
    void FUN_000b64f0();
    void FUN_000c2c20();
    void FUN_000c31e0(const char *name);
};

void Env_c31e0::FUN_000c31e0(const char *name)
{
    Frame_c31e0 f;
    f.cookie = DAT_004d9968;
    TextSelector *ts = dynamic_cast<TextSelector *>(FUN_000fc260(name));
    ImageSelector *is = dynamic_cast<ImageSelector *>(FUN_000fc260(name));
    int idx;
    do {
        if (ts != 0 && ts->f1d58 != 0) {
            idx = ts->f154;
        } else {
            if (is == 0)
                break;
            if (is->FUN_000e3fe0() == 0)
                break;
            idx = is->v23();
        }
        if (idx == -1)
            break;
        int i;
        for (i = 0; i < 0x2fe; i++) {
            const char *p = f4c->FUN_00092bc0(i);
            if (p == 0)
                continue;
            if (strcmp(p, name) == 0) {
                idx += i;
                break;
            }
        }
        f.flag = 0;
        bool direct = false;
        if (idx >= 0x266 && idx <= 0x2c9) {
            if (f34->FUN_000893c0()) {
                if (idx == 0x266) {
                    f.flag = 1;
                    direct = true;
                } else {
                    idx = idx - 0x267;
                }
            } else {
                idx = idx - 0x266;
            }
            if (!direct)
                idx = f4c->FUN_000932a0(idx);
        }
        if (!direct) {
            if (idx >= 0x258 && idx <= 0x260)
                idx = (&tblBase)[idx];
            if (!f4c->FUN_00092860(idx)) {
                if (idx >= 0x34 && idx <= 0x51) {
                    FUN_000c1f70(idx);
                    TextLabel *tl = dynamic_cast<TextLabel *>(FUN_000fc260("dycrypting_sequence_text"));
                    if (tl != 0)
                        tl->lab.FUN_000f8500("TBS_MENU_ITEM_DECRYPTING_SEQUENCE", FUN_000fc1b0(), 1);
                    Inventory_c31e0 *inv = DAT_004dd9cc;
                    unsigned __int64 key = FUN_0027b020("decryptingProgressBar");
                    new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>();
                    Loaded_c31e0 *ld = inv->find(&f.caster, key);
                    if (ld != 0) {
                        Inner_c31e0 *in = ld->f50;
                        if (in != 0) {
                            in->v16(2);
                            in->v18(1);
                        }
                    }
                    f4c->FUN_000929a0(idx, 0);
                    FUN_000c21b0(idx);
                    FUN_000ba040();
                    FUN_000fc280("blonsky_file");
                } else if ((idx >= 0x1bf && idx <= 0x1f0) || (idx >= 0x1f1 && idx <= 0x209) ||
                           (idx >= 0x20a && idx <= 0x22d) || (idx >= 0x22e && idx <= 0x243) ||
                           (idx >= 0x244 && idx <= 0x247) || (idx >= 0x52 && idx <= 0x8d)) {
                    f187c = idx;
                    f10 = 0xc;
                    b1878 = 0;
                    b1a04 = 0;
                    b1a05 = 0;
                    break;
                } else if ((idx >= 0x248 && idx <= 0x257) || (idx >= 0x261 && idx <= 0x265) ||
                           (idx >= 0x258 && idx <= 0x260) || idx == 0x32) {
                    f1874 = idx;
                    f10 = 0xd;
                } else if (idx == 0x33) {
                    if (f54 == 0)
                        break;
                    f54->FUN_001b8af0();
                    Credits_c31e0 *c = f40;
                    f10 = 0xe;
                    c->c1("Credits", "Enter");
                    break;
                } else if (idx >= 0 && idx <= 0x1e) {
                    char r = f4c->FUN_00092940(idx);
                    f4c->FUN_00092870(idx, r == 0);
                } else if (idx == 0x1f) {
                    FUN_000bb5c0();
                    f4c->FUN_00092870(idx, 1);
                    DIALOG_OK("TBS_MENU_ITEM_BONUS_FE_CHEATS_UNLOCKED_42");
                    break;
                }
            }
            if (idx < 0x266 || idx > 0x2c9)
                break;
        }

        CUnlockableMove *mv = 0;
        if (!f.flag) {
            mv = dynamic_cast<CUnlockableMove *>(f4c->FUN_00092ad0(idx));
            if (mv == 0)
                break;
        }
        CUnlockableCheat *ch = dynamic_cast<CUnlockableCheat *>(f4c->FUN_00092ad0(0x1d));
        bool confirm = false;
        if (ch != 0 && ch->b08 == 0 && ch->b20 != 0) {
            confirm = true;
        } else if (f.flag) {
            if (!f4c->FUN_00092860(4))
                confirm = true;
        } else {
            if (mv->FUN_00091f40())
                confirm = true;
        }
        if (confirm) {
            if (mv != 0)
                mv->FUN_00091f30(1);
            FUN_000c21b0(idx);
            if (mv != 0 && mv->FUN_00091fb0()) {
                DIALOG_YN("TBS_UNLOCKABLE_MOVE_GO_TO_TUTORIAL");
                f1cec = idx;
                f10 = 0x17;
                FUN_000be100();
            } else {
                DIALOG_OK("TBS_UNLOCKABLE_MOVE_PURCHASED");
            }
            break;
        }

        if (mv != 0) {
            int c = mv->FUN_00091f90();
            if (c >= 0) {
                CUnlockableMove *m2 = dynamic_cast<CUnlockableMove *>(f4c->FUN_00092ad0(c));
                if (m2 != 0 && !m2->FUN_00091f40()) {
                    FUN_000964a0(f.buf, 0x40, "TBS_UNLOCKABLE_MOVE_%d", c - 0x265);
                    Loc_c31e0 *loc = FUN_000fc1b0();
                    int len = FUN_000fb720(loc->FUN_00088ea0("TBS_NEED_TO_BUY"));
                    wchar_t *dst2 = f.wide + len;
                    FUN_000fb690(f.wide, loc->FUN_00088ea0("TBS_NEED_TO_BUY"), len + 1);
                    int len2 = FUN_000fb720(loc->FUN_00088ea0(f.buf));
                    FUN_000fb690(dst2, loc->FUN_00088ea0(f.buf), len2 + 1);
                    FUN_000fc3d0()->FUN_000be310("FEGenericDialog", f.wide, "", "", "TBS_MENU_ITEM_OK", 2, 0, 0);
                    break;
                }
            }
        }
        if (f50 == 0)
            break;
        int xp = f50->FUN_00090110();
        int cost;
        if (f.flag)
            cost = 1000000;
        else
            cost = mv->FUN_00091f70();
        if (cost > xp) {
            DIALOG_OK("TBS_UNLOCKABLE_MOVE_NOT_ENOUGH_XP");
            break;
        }
        f50->FUN_000900a0(-cost);
        if (mv != 0)
            mv->FUN_00091f30(1);
        if (f.flag)
            f4c->FUN_00093600(4, 0);
        FUN_000c21b0(idx);
        if (mv != 0 && mv->FUN_00091fb0()) {
            DIALOG_YN("TBS_UNLOCKABLE_MOVE_PURCHASED_GO_TO_TUTORIAL");
            f1cec = idx;
            f10 = 0x17;
            FUN_000be100();
        } else {
            DIALOG_OK("TBS_UNLOCKABLE_MOVE_PURCHASED");
        }
        FUN_000bb600();
        FUN_000c21b0(idx);
        if (f.flag)
            FUN_000b64f0();
        FUN_000c2c20();
    } while (0);
    __security_check_cookie(f.cookie);
}
