// STATUS: equivalent (tools/equiv.py level 3: 16477 inputs, branch coverage 305/312, incomplete)
// FEMemCardControl::vfunc_4 @ 0x000da930
// cl-flags: /GS
// FEMemCardControl::vfunc_4 @ 0x000da930
// FEMemCardControl::vfunc_4 @ 0x000da930
#include "decls/address.h"
extern "C" double sin(double);
extern float (__cdecl *DAT_004de948)();
extern unsigned char DAT_004dd841;
extern void* DAT_004a0c88;
static const char kLabel[] = "DynamicControlButtonLabel";

class FEMemCardControl;
struct Fn1_da930 {
    void (FEMemCardControl::*fn)(int);
};
struct Fn2_da930 {
    void (FEMemCardControl::*fn)(int, int);
};

struct Item_da930 {
    char data[0x24];
    void FUN_000f79a0(int a, int b);
    void FUN_000f8500(void* a, int b, int c);
    void FUN_000f83c0(Item_da930* other);
};

struct Singleton_4dd6ec {
    void FUN_00086310();
};

struct Stage2_da930 {
    void FUN_0008ca30(int a);
    void FUN_0008c920();
    void FUN_0008c680(int a);
};

struct Stage1_da930 {
    Stage2_da930* FUN_00089a50();
    char FUN_0008b4b0(int idx, unsigned char* active, char* buf, int len, char* extra, int* out);
    void FUN_0008a8f0(int a, Singleton_4dd6ec* m);
    void FUN_00089830(const char* s);
    void FUN_000895e0(void* p);
    void FUN_00089810(const char* s);
    void FUN_00089300(const char* s);
    bool FUN_000893c0();
    int FUN_000891e0();
};

struct Obj50_da930 {
    void FUN_0008ffe0();
};

struct Label_da930 {
    char pad0[0x50];
    Obj50_da930* obj50;
    char pad54[0x1bc8 - 0x54];
    unsigned char f1bc8;
    Stage1_da930* FUN_000b5000();
    void FUN_000bc9f0(const char* name, int mode);
    void* FUN_000b4cf0(const char* name);
};

struct Delegate_da930 {
    FEMemCardControl* self;
    int pad4;
    char fnA[16];
    char fnB[16];
    int arg0;
    int arg1;
    void FUN_000d7be0(Fn1_da930 f, int a);
    void FUN_000d7c30(Fn2_da930 f, int a, int b);
    void FUN_000d7c80();
    void FUN_000d7d10();
};

struct Child_da930 { char pad[0xab9]; unsigned char flag; };
struct Parent_da930 { char pad[0x175c]; Child_da930* child; };

class Sink_da930 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(int mode);
};
struct Hub_da930 { char pad0[4]; Sink_da930* sink; };
struct Holder_da930 { char pad0[8]; Hub_da930* hub; };

struct Player_da930 { char pad0[0x9a8]; unsigned char busy; };
class UI_da930 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual int s44();
    char pad[0x2218 - 4];
    Player_da930* player;
    int status;
    void FUN_000e63a0();
};
UI_da930* __cdecl FUN_000fc3d0();
void __cdecl FUN_000fc2f0();
void __cdecl FUN_000fc300();

struct Frame_da930 {
    char pad0[2];
    char gotA, gotB;
    int outv;
    int kind0;
    int pad[1];
    char buf[0x40];
};

struct Entry_da930 {
    Item_da930 item;
    char pad24[12];
    unsigned char active;
    char pad31[7];
    unsigned char flag;
    char pad39[3];
};

struct Slot_da930 {
    int f0;
    int f4;
    int kind;
    int count;
    Item_da930 item;
    unsigned char flag;
    char pad35[3];
};

class FEMemCardControl {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11();
    virtual char vfunc_12(int cmd, int unused);
    char pad04[0x10];
    Holder_da930* holder;
    char pad18[0xa8 - 0x18];
    Parent_da930* parent;
    char pada8[0x150 - 0xac];
    Label_da930* label;
    char pad154[0x1d0 - 0x154];
    int sel;
    int sel2;
    char pad1d8[0x21c - 0x1d8];
    float f21c;
    Entry_da930 entries[5];
    Slot_da930 slots[1];
    char pad384[0x3a8 - 0x34c - 0x38];
    unsigned char f3a8;
    char pad3a9[3];
    int state;
    char pad3b0[0x3c8 - 0x3b0];
    float f3c8;
    char pad3cc[0x3e4 - 0x3cc];
    float f3e4;
    unsigned char f3e8, f3e9, f3ea, f3eb, f3ec;
    char pad3ed[3];
    const char* name;
    Item_da930 item3;
    int f418;
    int f41c;
    int f420;
    char pad424[4];
    Delegate_da930 cb;

    void FUN_000d8410();
    void FUN_000d7ec0(int a);
    void FUN_000d7ef0(int a);
    bool FUN_000d7f30();
    void FUN_000d7f60();
    void FUN_000d8150();
    int FUN_000d8170(int a, int b);
    int FUN_000d8190(int a, int b);
    int FUN_000d81c0(int a, int b);
    int FUN_000d8220(int a);
    void FUN_000d88f0(int id, char* a, char* b);
    void FUN_000d8cb0(int a, int b);
    void FUN_000d8dd0(int a);
    void FUN_000d9180(int a);
    void FUN_000d92c0(int a);
    void FUN_000d94e0(int a);
    void FUN_000d9890(int a);
    void FUN_000d9c40();
    void FUN_000d9d40();
    void FUN_000d9e80(int a);
    void FUN_000d9f80(int a);
    void FUN_000da180(int a);
    void FUN_000da230(int a);
    void FUN_000da830(int a);
    void FUN_000d8ec0(int a, int b);
    void FUN_000d8fa0(int a, int b);
    void FUN_000d9080(int a, int b);
    void FUN_000d9100(int a, int b);
    void FUN_000d95a0(int a);
    void FUN_000d9680(int a);
    void FUN_000d99a0(int a);
    void FUN_000d9a80(int a);
    void FUN_000da480(int a);
    void FUN_000da570(int a);
    void FUN_000da660(int a);
};


void FEMemCardControl::vfunc_4()
{
    Frame_da930 fr;
    char& gotA = fr.gotA;
    char& gotB = fr.gotB;
    int& outv = fr.outv;
    char* buf = fr.buf;
    {
        float t = DAT_004de948() * 6.2831855f + f3e4;
        f3c8 = (float)((sin((double)t) + 1.0f) * 0.5f);
        outv = (int)(0.15915494f * t);
        f3e4 = t - outv * 6.2831855f;
        if (*(volatile float*)&f3e4 >= 0.0f && *(volatile float*)&f3e4 <= 6.2831855f) {
        } else if (!(*(volatile float*)&f3e4 > 6.2831855f)) {
            f3e4 = 0.0f;
        } else {
            f3e4 = 6.2831855f;
        }
    }
    f21c += DAT_004de948();
    int cur = state;
    if (cur == 0)
        f3eb = 0;
    if (f3e8) {
        state = 0x1f;
        f3e9 = 1;
    } else if (!f3eb || cur == 0x10 || cur == 0x13 || cur == 0xb || cur == 0xc || cur == 9 || cur == 8 || cur == 0xd || cur == 0) {
        FUN_000d8410();
    }
    switch (state) {
    case 0:
        if (f3a8) {
            switch (slots[sel].kind) {
            case 0:
            case 7:
                FUN_000d8150();
                FUN_000d88f0(sel, &gotA, &gotB);
                if (slots[sel].kind == 7 && !gotA) {
                    FUN_000d9180(sel);
                    state = 0x1f;
                    break;
                }
                holder->hub->sink->v48(0);
                state = 2;
                break;
            case 4:
                FUN_000d92c0(sel);
                state = 0x1f;
                break;
            case 5:
                state = 0xb;
                FUN_000d7ec0(sel);
                break;
            default:
                break;
            }
        } else {
            switch (slots[sel].kind) {
            case 0:
            case 7:
                FUN_000d8150();
                FUN_000d88f0(sel, &gotA, &gotB);
                if (!gotA && !gotB) {
                    FUN_000da830(sel);
                    state = 0x1f;
                }
                holder->hub->sink->v48(0);
                state = 2;
                break;
            case 4:
                FUN_000d92c0(sel);
                state = 0x1f;
                break;
            case 5:
                state = 0xb;
                FUN_000d7ef0(sel);
                break;
            default:
                break;
            }
        }
        break;
    case 1: {
        Player_da930* p = FUN_000fc3d0()->player;
        if (p && p->busy)
            break;
        int r = FUN_000fc3d0()->status;
        if (r == 1) {
            state = 0x1f;
            f3e9 = 1;
        } else if (r == 2) {
            state = 0;
        }
        break;
    }
    case 2: {
        int i;
        for (i = 0; i < 5; ++i) {
            if (!label->FUN_000b5000()->FUN_0008b4b0(i, &entries[i].active, buf, 0x40, entries[i].pad24, &outv))
                break;
            entries[i].item.FUN_000f79a0(outv, 0);
            if (entries[i].flag) {
                entries[i].active = 1;
                entries[i].item.FUN_000f8500(DAT_004a0c88, FUN_000fc3d0()->s44(), 1);
            }
            if (!f3a8)
                FUN_000d7f60();
        }
        state = (i < 5) ? 0 : 3;
        break;
    }
    case 3: {
        if (!f3a8 && sel2 >= 0 && !entries[sel2].active)
            FUN_000d7f60();
        Player_da930* p = FUN_000fc3d0()->player;
        if (p && p->busy)
            break;
        if (sel2 < 0) {
            label->FUN_000bc9f0(kLabel, 2);
            break;
        }
        if (entries[sel2].active) {
            if (f3a8)
                label->FUN_000bc9f0(kLabel, 6);
            else
                label->FUN_000bc9f0(kLabel, 9);
        } else {
            label->FUN_000bc9f0(kLabel, 8);
        }
        break;
    }
    case 4:
        if (f21c < 0.2f)
            break;
        item3.FUN_000f83c0(&slots[sel].item);
        {
            int r = FUN_000d8190(sel, sel2);
            state = 0x1d;
            if (r == 4 || r == 3) {
                *(volatile int*)&f418 = 0xa;
                { Fn1_da930 x = { &FEMemCardControl::FUN_000da480 }; cb.FUN_000d7be0(x, sel); }
                break;
            }
            if (r == 7) {
                while (FUN_000d7f30())
                    FUN_000fc3d0()->FUN_000e63a0();
                f418 = 0x1f;
                f41c = 0x1f;
                state = 0x11;
                FUN_000d9c40();
                break;
            }
            if (r != 0) {
                *(volatile int*)&f418 = 0xa;
                { Fn2_da930 x = { &FEMemCardControl::FUN_000d8ec0 }; cb.FUN_000d7c30(x, sel, sel2); }
                break;
            }
            *(volatile int*)&f418 = 0x1f;
            { Fn2_da930 x = { &FEMemCardControl::FUN_000d9080 }; cb.FUN_000d7c30(x, sel, sel2); }
            f3e9 = 1;
            if (label->f1bc8) {
                f3ec = 1;
                DAT_004dd6ec->FUN_00086310();
                name = "end_level_already_saved";
            }
        }
        break;
    case 5:
        if (f21c < 0.2f)
            break;
        item3.FUN_000f83c0(&slots[sel].item);
        {
            int r = FUN_000d8170(sel, sel2);
            state = 0x1d;
            if (r == 4 || r == 3) {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000da570 }; cb.FUN_000d7be0(x, sel); }
                f418 = 0xa;
                break;
            }
            if (r != 0) {
                { Fn2_da930 x = { &FEMemCardControl::FUN_000d8fa0 }; cb.FUN_000d7c30(x, sel, sel2); }
                f418 = 0xa;
                break;
            }
            label->FUN_000b5000()->FUN_0008a8f0(sel2, DAT_004dd6ec);
            { Fn2_da930 x = { &FEMemCardControl::FUN_000d9100 }; cb.FUN_000d7c30(x, sel, sel2); }
            f418 = 0x1f;
            f3e9 = 1;
        }
        break;
    case 6:
        if (f21c < 0.2f)
            break;
        item3.FUN_000f83c0(&slots[sel].item);
        {
            int r = FUN_000d8220(sel);
            state = 0x1d;
            if (r == 0) {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000d95a0 }; cb.FUN_000d7be0(x, sel); }
                f418 = 0x1f;
                break;
            }
            if (r != 4 && f3eb) {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000da230 }; cb.FUN_000d7be0(x, sel); }
                f418 = 0x1a;
            } else {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000d9680 }; cb.FUN_000d7be0(x, sel); }
                f418 = 0x10;
            }
            label->FUN_000b5000()->FUN_00089a50()->FUN_0008c920();
            slots[sel].kind = 6;
            slots[sel].f4 = 6;
        }
        break;
    case 0x1c:
        if (f21c < 1.0f)
            break;
        while (FUN_000d7f30())
            FUN_000fc3d0()->FUN_000e63a0();
        state = 4;
        FUN_000d8dd0(sel);
        break;
    case 8:
    case 0x19:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status != 1) {
            state = 3;
            break;
        }
        state = 4;
        FUN_000d8dd0(sel);
        break;
    case 0x1e:
        break;
    case 7:
        if (f21c < 0.2f)
            break;
        item3.FUN_000f83c0(&slots[sel].item);
        {
            int r = FUN_000d81c0(sel, sel2);
            state = 0x1d;
            if (r == 4 || r == 3) {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000da660 }; cb.FUN_000d7be0(x, sel); }
                f418 = 0xa;
                break;
            }
            if (r != 0) {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000d9a80 }; cb.FUN_000d7be0(x, sel); }
                f418 = 3;
                break;
            }
            entries[sel2].active = 0;
            slots[sel].count -= 1;
            { Fn1_da930 x = { &FEMemCardControl::FUN_000d99a0 }; cb.FUN_000d7be0(x, sel); }
            if (!f3a8) {
                FUN_000d7f60();
                if (sel2 < 0) {
                    f418 = 0;
                    slots[sel].flag = 0;
                    break;
                }
            }
            f418 = 0;
        }
        break;
    case 9:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status != 1) {
            state = 3;
            break;
        }
        state = 5;
        FUN_000d8cb0(sel, 0);
        break;
    case 0xd:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status != 1) {
            state = 3;
            break;
        }
        state = 7;
        FUN_000d9890(sel);
        break;
    case 0x1f:
        if (FUN_000d7f30())
            break;
        label->FUN_000b5000()->FUN_00089a50()->FUN_0008ca30(0);
        if (f3e8 && f3e9) {
            label->FUN_000b5000()->FUN_00089830("c00m01");
            void* item = label->FUN_000b4cf0("c00m01");
            if (!item)
                break;
            if (!label->FUN_000b5000()->FUN_000893c0())
                label->obj50->FUN_0008ffe0();
            label->FUN_000b5000()->FUN_000895e0(item);
            label->FUN_000b5000()->FUN_00089810("c00m01");
            label->FUN_000b5000()->FUN_00089300("story");
            state = 0x20;
            break;
        }
        if (f3ea) {
            FUN_000fc300();
            state = 0x20;
            break;
        }
        FUN_000fc2f0();
        state = 0x20;
        break;
    case 0xa:
        if (FUN_000d7f30())
            break;
        state = f3eb ? 0x1f : 0;
        break;
    case 0xb:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status == 1) {
            state = 6;
            FUN_000d94e0(sel);
            break;
        }
        state = 0x1f;
        break;
    case 0xc:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status == 1) {
            state = 6;
            FUN_000d94e0(sel);
            break;
        }
        state = f3eb ? 0xf : 0x1f;
        break;
    case 0xf:
        label->FUN_000bc9f0(kLabel, 0);
        if (FUN_000d7f30())
            break;
        slots[0].flag = 0;
        state = 0x10;
        break;
    case 0x10: {
        int* kinds = &fr.kind0;
        kinds[0] = slots[0].kind;
        for (int i = 0; i < 1; ++i) {
            int kind = kinds[i];
            sel = i;
            if (kind == 4) {
                if (DAT_004dd841) {
                    state = f41c;
                } else {
                    state = 0x13;
                    FUN_000da180(0);
                }
                break;
            } else if (kind == 5 || kind == 9) {
                state = 0x14;
                FUN_000d7ef0(i);
                break;
            } else if (kind == 6) {
                state = 0x1a;
                FUN_000da230(i);
                break;
            } else if (kind == 7 || kind == 0) {
                int& found = fr.outv;
                found = 1;
                for (int j = 0; j < 5; ++j) {
                    int r = FUN_000d8170(i, j);
                    if (r == 0)
                        found = r;
                }
                if (found == 0 || found == 0xc) {
                    int k = kinds[i];
                    if (k == 0 || k == 7) {
                        if (!f3eb) {
                            state = f41c;
                        } else {
                            FUN_000d8cb0(sel, 1);
                            sel2 = label->FUN_000b5000()->FUN_000891e0();
                            state = 0x1d;
                            f418 = 5;
                        }
                    } else if (k == 0xc) {
                        state = 0x1d;
                        f418 = 0x18;
                        FUN_000d9e80(i);
                    } else {
                        state = f41c;
                    }
                    break;
                }
                if (kind == 7) {
                    state = 0x11;
                    FUN_000d9c40();
                    break;
                }
                state = f41c;
            } else if (kind == 0xa || kind == 0xb) {
                state = 0x17;
                FUN_000d9f80(i);
                break;
            }
        }
        if (!FUN_000d7f30())
            break;
        parent->child->flag = 1;
        label->FUN_000bc9f0(kLabel, 3);
        break;
    }
    case 0x11:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status == 1) {
            state = f41c;
            break;
        }
        holder->hub->sink->v48(0);
        state = 0x12;
        FUN_000d9d40();
        break;
    case 0x12:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status != 1) {
            state = 0xf;
            break;
        }
        label->FUN_000b5000()->FUN_00089a50()->FUN_0008c680(sel);
        break;
    case 0x13:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status != 1) {
            state = 0xf;
            break;
        }
        state = f420;
        break;
    case 0x14: {
        if (FUN_000d7f30())
            break;
        int r = FUN_000fc3d0()->status;
        if (r == 0) {
            state = f41c;
            break;
        }
        if (r == 1) {
            if (f3eb) {
                state = 0xf;
                break;
            }
            state = 0;
            vfunc_12(8, 0);
            break;
        }
        state = 6;
        FUN_000d94e0(sel);
        break;
    }
    case 0x16:
    case 0x17:
    case 0x1a:
        if (FUN_000d7f30())
            break;
        if (FUN_000fc3d0()->status != 1) {
            state = 0xf;
            break;
        }
        state = f41c;
        break;
    case 0x18: {
        if (FUN_000d7f30())
            break;
        int r = FUN_000fc3d0()->status;
        if (r == 0) {
            state = f41c;
            break;
        }
        if (r == 1) {
            state = 0xf;
            break;
        }
        state = 0x1b;
        FUN_000d9890(sel);
        break;
    }
    case 0x1b:
        if (f21c < 0.2f)
            break;
        item3.FUN_000f83c0(&slots[sel].item);
        {
            int r = FUN_000d81c0(sel, sel2);
            // the state is stored before the callback is registered (volatile keeps the store in front of the call)
            *(volatile int*)&state = 0x1d;
            if (r != 0) {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000d9a80 }; cb.FUN_000d7be0(x, sel); }
            } else {
                { Fn1_da930 x = { &FEMemCardControl::FUN_000d99a0 }; cb.FUN_000d7be0(x, sel); }
            }
            f418 = f3eb ? 0xf : 0;
        }
        break;
    case 0x1d:
        if (f21c < 1.0f)
            break;
        if (FUN_000d7f30())
            FUN_000fc3d0()->FUN_000e63a0();
        state = f418;
        cb.FUN_000d7c80();
        cb.FUN_000d7d10();
        break;
    default:
        break;
    }
}
