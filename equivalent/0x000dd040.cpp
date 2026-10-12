// STATUS: equivalent (tools/equiv.py level 3: 199 inputs, branch coverage 53/55, incomplete)
// FETextInput::vfunc_12 @ 0x000dd040
struct Win {
    virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3(); virtual void w4(); virtual void w5(); virtual void w6(); virtual void w7(); virtual void w8(); virtual void w9(); virtual void w10(); virtual void w11(); virtual void w12(); virtual void w13(); virtual void w14(); virtual void w15(); virtual void w16(); virtual void w17(); virtual void w18(); virtual void w19(); virtual void w20(); virtual void w21(); virtual void w22(); virtual void w23(); virtual void w24(); virtual void w25(); virtual void w26(); virtual void w27(); virtual void w28(); virtual void w29(); virtual void w30(); virtual void w31(); virtual void w32(); virtual void w33(); virtual void w34(); virtual void w35(); virtual void w36(); virtual void w37(); virtual void w38(); virtual void w39(); virtual void w40(); virtual void w41(); virtual void w42(); virtual void w43(); virtual void w44(); virtual void w45(); virtual void w46(); virtual void w47();
    virtual void w48(int v);
};

struct B {
    char pad0[4];
    Win *win;               // 0x4
};

struct A {
    char pad0[8];
    B *b;                   // 0x8
};

class FETextInput {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual bool vfunc_12(int cmd, int arg);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    char pad04[0x10];
    A *owner;               // 0x14
    char pad18[0x74 - 0x18];
    char enabled;           // 0x74
    char pad75[0x150 - 0x75];
    int count;              // 0x150
    int cursor;             // 0x154
    char *text;             // 0x158
    char pad15c[0x16c - 0x15c];
    int *slots;             // 0x16c
    char pad170[0x178 - 0x170];
    int state;              // 0x178
    char flag;              // 0x17c
    void FUN_000dc730();
    void FUN_000dca40();
    void FUN_000dc9e0();
    void FUN_000e2c90(int a, int b, int c);
};

bool FETextInput::vfunc_12(int cmd, int arg)
{
    if (!enabled)
        return false;
    switch (cmd) {
    case 8:
    case 11:
        if (state == 1) {
            state = 2;
            FUN_000dc730();
            cursor = 0;
            text[0] = 0;
            if (count > 0) {
                int i = 0;
                do {
                    slots[i] = -1;
                    i++;
                } while (i < count);
            }
            slots[0] = 0;
            owner->b->win->w48(0);
            return true;
        }
        FUN_000dca40();
        state = 1;
        FUN_000dc730();
        FUN_000e2c90(0, -1, -1);
        if (flag != 0) {
            text[0] = 0;
            if (count > 0) {
                int i = 0;
                do {
                    slots[i] = -1;
                    i++;
                } while (i < count);
            }
        }
        return true;
    case 10: {
        FUN_000dc9e0();
        int old = state;
        state = 1;
        FUN_000dc730();
        text[0] = 0;
        if (count > 0) {
            int i = 0;
            do {
                slots[i] = -1;
                i++;
            } while (i < count);
        }
        cursor = 0;
        return old != 1;
    }
    case 2: {
        if (state != 2)
            return false;
        if (slots[cursor] < 0)
            slots[cursor] = 0;
        owner->b->win->w48(2);
        int c = cursor + 1;
        cursor = c;
        if (!(c < count))
            cursor = 0;
        int *p = &slots[cursor];
        if (*p < 0)
            *p = 0;
        return true;
    }
    case 6: {
        if (state != 2)
            return false;
        cursor = cursor - 1;
        if (cursor < 0) {
            cursor = count - 1;
            if (count > 0) {
                int i = 0;
                do {
                    int *q = &slots[i];
                    if (*q < 0)
                        *q = 0;
                    i++;
                } while (i < count);
            }
        }
        owner->b->win->w48(2);
        int *p = &slots[cursor];
        if (*p < 0)
            *p = 0;
        return true;
    }
    case 0: {
        if (state != 2)
            return false;
        int *p = &slots[cursor];
        int v = *p;
        if (v > 0)
            v = v - 1;
        else
            v = 0x23;
        *p = v;
        owner->b->win->w48(3);
        return true;
    }
    case 4: {
        if (state != 2)
            return false;
        int *p = &slots[cursor];
        int v = *p + 1;
        if (!(v < 0x24))
            v = 0;
        *p = v;
        owner->b->win->w48(3);
        return true;
    }
    default:
        return false;
    }
}
