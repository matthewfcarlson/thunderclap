// STATUS: equivalent (tools/equiv.py level 3: 3038 inputs, branch coverage 84/95, incomplete)
// TextSelector::vfunc_12 @ 0x000e3170
class Ctl {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual char v4(int kind, int snd, int from, int to);
};

class Obj4_e3170 {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w30();
    virtual void w31();
    virtual void w32();
    virtual void w33();
    virtual void w34();
    virtual void w35();
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void v48(int n);
};

struct Obj8_e3170 {
    char pad0[4];
    Obj4_e3170 *f4;
};

struct Obj14_e3170 {
    char pad0[8];
    Obj8_e3170 *f8;
};

struct Entry_e3170 {
    void *items;
    int f4;
    int count;
    int cur;
    char rest[0x38 - 0x10];
};

class TextSelector {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual char vfunc_12(unsigned int action, int a2);
    char pad04[0x14 - 4];
    Obj14_e3170 *f14;
    char pad18[0xa8 - 0x18];
    int snd;
    char padac[0x118 - 0xac];
    Ctl *ctl[10];
    char pad140[0x154 - 0x140];
    int sel;
    char pad158[0x17c - 0x158];
    Entry_e3170 entries[127];
    char pad2[0x14];
    int total;
    int mode;
    char pad1d60[0x1d7c - 0x1d60];
    int top;
    int bottom;
    char wrap;
    void FUN_000e30a0();

    void Refresh();
};

#define BROADCAST(FROM, TO)                                  \
    for (Ctl **pp = ctl; pp != &ctl[10]; pp++) {             \
        if (*pp == 0)                                        \
            break;                                           \
        if ((*pp)->v4(4, snd, (FROM), (TO)))                 \
            (*pp)->v1();                                     \
    }

__forceinline void TextSelector::Refresh()
{
    FUN_000e30a0();
    f14->f8->f4->v48(3);
}

char TextSelector::vfunc_12(unsigned int action, int a2)
{
    switch (action) {
    case 2:
        if (mode == 2) {
            Entry_e3170 *e = &entries[sel];
            int count = e->count;
            if (count > 1) {
                int cur = e->cur;
                if (cur < count - 1) {
                    e->cur = cur + 1;
                    BROADCAST(-1, -1);
                    f14->f8->f4->v48(3);
                    return 1;
                }
            }
            return 1;
        } else {
            int cur = sel;
            if (cur == 0x7f || cur + 1 == total) {
                if (wrap) {
                    BROADCAST(cur, 0);
                    sel = 0;
                    Refresh();
                }
                return 1;
            }
            BROADCAST(cur, cur + 1);
            sel = sel + 1;
            Refresh();
            if (sel > bottom) {
                bottom = bottom + 1;
                top = top + 1;
            }
            return 1;
        }
    case 6:
        if (mode == 2) {
            Entry_e3170 *e = &entries[sel];
            if (e->count > 1) {
                int cur = e->cur;
                if (cur > 0) {
                    e->cur = cur - 1;
                    BROADCAST(-1, -1);
                    f14->f8->f4->v48(3);
                    return 1;
                }
            }
            return 1;
        } else {
            int cur = sel;
            if (cur == 0) {
                if (wrap) {
                    int last = total - 1;
                    BROADCAST(0, last);
                    sel = total - 1;
                    Refresh();
                }
                return 1;
            }
            BROADCAST(cur, cur - 1);
            sel = sel - 1;
            Refresh();
            if (sel < top) {
                bottom = bottom - 1;
                top = top - 1;
            }
            return 1;
        }
    case 0:
        if (mode != 2)
            return 0;
        {
            int cur = sel;
            if (cur == 0)
                return 0;
            BROADCAST(cur, cur - 1);
            sel = sel - 1;
            Refresh();
            if (sel < top) {
                bottom = bottom - 1;
                top = top - 1;
            }
            return 1;
        }
    case 4:
        if (mode != 2)
            return 0;
        {
            int cur = sel;
            if (cur == 0x7f)
                return 0;
            if (cur + 1 >= total)
                return 0;
            BROADCAST(cur, cur + 1);
            sel = sel + 1;
            Refresh();
            if (sel > bottom) {
                bottom = bottom + 1;
                top = top + 1;
            }
            return 1;
        }
    }
    return 0;
}
