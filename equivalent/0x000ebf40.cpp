// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 39/42, incomplete)
// MenuSelector::vfunc_12 @ 0x000ebf40
struct ItemNode {
    char pad0[0xab8];
    unsigned char selected;     // 0xab8
};

struct Registry_ebf40 {
    ItemNode *FUN_000e6410(const char *name);
};

struct Inner_ebf40 {
    char pad0[4];
    Registry_ebf40 *registry;
};

struct Outer_ebf40 {
    char pad0[8];
    Inner_ebf40 *inner;
};

class Listener_ebf40 {
public:
    virtual void v0();
    virtual void notifyChanged();
    virtual void v2();
    virtual void v3();
    virtual bool v4(int kind, int id, int oldIndex, int newIndex);
};

struct Scroller {
    void FUN_000f8b90(int index);
};

class MenuSelector {
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
    virtual bool vfunc_12(int msg, int arg);

    char pad04[0x10];
    Outer_ebf40 *outer;               // 0x14
    char pad18[0xa8 - 0x18];
    int id;                     // 0xa8
    char padac[0x118 - 0xac];
    Listener_ebf40 *listeners[10];    // 0x118
    char pad140[0x154 - 0x140];
    int sel;                    // 0x154
    char pad158[0x1d58 - 0x158];
    int count;                  // 0x1d58
    char pad1d5c[0x1d84 - 0x1d5c];
    unsigned char wrap;         // 0x1d84
    char pad1d85[0x1d94 - 0x1d85];
    Scroller *scroller;         // 0x1d94
    char pad1d98[0x1da9 - 0x1d98];
    char items[0x80][0x40];     // 0x1da9

    void FUN_000e30a0();
};

bool MenuSelector::vfunc_12(int msg, int arg)
{
    if (msg == 2) {
        int cur = sel;
        if (cur != 0x7f && items[cur + 1][0] != 0) {
            Registry_ebf40 *reg = outer->inner->registry;
            reg->FUN_000e6410(items[cur])->selected = 0;
            reg = outer->inner->registry;
            reg->FUN_000e6410(items[sel + 1])->selected = 1;
            int old = sel;
            for (int i = 0; i < 10 && listeners[i] != 0; i++) {
                if (listeners[i]->v4(4, id, old, old + 1))
                        listeners[i]->notifyChanged();
            }
            sel = sel + 1;
            FUN_000e30a0();
            return true;
        }
        if (!wrap)
            return true;
        Registry_ebf40 *reg = outer->inner->registry;
        reg->FUN_000e6410(items[cur])->selected = 0;
        reg = outer->inner->registry;
        reg->FUN_000e6410(items[0])->selected = 1;
        int old = sel;
        for (int i = 0; i < 10 && listeners[i] != 0; i++) {
            if (listeners[i]->v4(4, id, old, 0))
                    listeners[i]->notifyChanged();
        }
        sel = 0;
        if (scroller != 0)
            scroller->FUN_000f8b90(0);
        vfunc_0();
        return true;
    }
    if (msg != 6)
        return false;

    int cur = sel;
    if (cur == 0) {
        if (!wrap)
            return true;
        Registry_ebf40 *reg = outer->inner->registry;
        reg->FUN_000e6410(items[0])->selected = 0;
        reg = outer->inner->registry;
        reg->FUN_000e6410(items[count - 1])->selected = 1;
        int last = count - 1;
        int old = sel;
        for (int i = 0; i < 10 && listeners[i] != 0; i++) {
            if (listeners[i]->v4(4, id, old, last))
                    listeners[i]->notifyChanged();
        }
        sel = count - 1;
        FUN_000e30a0();
        return true;
    }
    Registry_ebf40 *reg = outer->inner->registry;
    reg->FUN_000e6410(items[cur])->selected = 0;
    reg = outer->inner->registry;
    reg->FUN_000e6410(items[sel - 1])->selected = 1;
    int old = sel;
    for (int i = 0; i < 10 && listeners[i] != 0; i++) {
        if (listeners[i]->v4(4, id, old, old - 1))
                listeners[i]->notifyChanged();
    }
    int next = sel - 1;
    sel = next;
    if (scroller != 0)
        scroller->FUN_000f8b90(next);
    vfunc_0();
    return true;
}
