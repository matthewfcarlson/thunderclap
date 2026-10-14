// STATUS: equivalent (tools/equiv.py level 3: 14593 inputs, branch coverage 28/28)
// FUN_001fa1c0 @ 0x001fa1c0
extern "C" void __fastcall __security_check_cookie(unsigned);
extern unsigned int DAT_004d9968;

struct Msg_1fa1c0 {
    int size;                 // 0x00
    int kind;                 // 0x04
    int pad08[3];
    char text[0x20];          // 0x14
    char text2[0x20];         // 0x34
    Msg_1fa1c0 *FUN_001ca020(const char *a, const char *b);
};

class Selector_1fa1c0 {
public:
    int FUN_001d2b10(int a, int b);
    bool FUN_001d1930(int v);
    void FUN_001d1a50(const char *v);
    void FUN_001d1ac0(float v);
    void FUN_001d19d0(int v);
    bool FUN_001d1ae0(unsigned char *out);
};

struct Queue_1fa1c0 {
    bool FUN_001cbc20(Msg_1fa1c0 *m);
};

struct World {
    char pad00[0x30];
    Queue_1fa1c0 *queue;             // 0x30
};
extern World *DAT_004dd700;
Selector_1fa1c0 *FUN_001d4c90();

struct Item_1fa1c0 {
    const char *FUN_001fba60();
};

struct Target_1fa1c0 {
    char pad00[0x10];
    int *data;                // 0x10
};

struct Panel_1fa1c0;

struct Copyable {
    char pad00[9];
    unsigned char index;      // 0x09
    char pad0a[6];
    void FUN_001f8940(const Copyable *src);
    Copyable(const Copyable &o) { FUN_001f8940(&o); }
};

struct Slot_1fa1c0 {
    char pad00[0x30];
    Copyable value;           // 0x30
    char pad40[0x51 - 0x40];
    unsigned char flag51;     // 0x51
    char pad52[6];
    void FUN_001f9230();
    void FUN_001f9710(Panel_1fa1c0 *owner, const char *name, int a, int b);
};

struct Entry_1fa1c0 {
    unsigned char active;
    char pad01[0x27];
};

class Panel_1fa1c0 {
public:
    char pad000[0x41c];
    char label[0x20];         // 0x41c
    int f43c;
    char pad440[0x44c - 0x440];
    int f44c;
    char pad450[0x484 - 0x450];
    Entry_1fa1c0 entries[15];        // 0x484
    char pad6dc[4];
    int entryCount;           // 0x6e0
    char pad6e4[4];
    Slot_1fa1c0 slots[16];           // 0x6e8
    int count;                // 0xc68

    void FUN_001f9fc0(Copyable value);
    void FUN_001fa1c0(Target_1fa1c0 *target, Item_1fa1c0 *item);
};

void Panel_1fa1c0::FUN_001fa1c0(Target_1fa1c0 *target, Item_1fa1c0 *item)
{
    unsigned int cookie = DAT_004d9968;
    if (count >= 16 || !item) {
        __security_check_cookie(cookie);
        return;
    }

    slots[count].FUN_001f9230();
    slots[count].FUN_001f9710(this, item->FUN_001fba60(), target->data[0], f43c);
    count++;

    Selector_1fa1c0 *sel = FUN_001d4c90();
    do {
        if (!sel)
            break;
        if (!sel->FUN_001d1930(f44c))
            break;
        sel->FUN_001d1a50(label);
        sel->FUN_001d1ac0((float)(count - 1));
        sel->FUN_001d1a50(item->FUN_001fba60());
        int r = sel->FUN_001d2b10(-4, 3);
        unsigned char ok = 1;
        unsigned char out;
        if (r == -1) {
            sel->FUN_001d19d0(1);
        } else if (r > 0) {
            if (sel->FUN_001d1ae0(&out) && out == 1)
                ok = 0;
            if (r > 1)
                sel->FUN_001d19d0(r - 1);
            if (!ok)
                break;
        }
        for (int i = 0; i < entryCount; i++) {
            if (entries[i].active) {
                slots[count].value.index = (unsigned char)i;
                FUN_001f9fc0(slots[count].value);
            }
        }
        slots[count - 1].flag51 = 0;
    } while (0);

    Queue_1fa1c0 *q = DAT_004dd700->queue;
    if (q) {
        Msg_1fa1c0 m;
        m.FUN_001ca020(label, item->FUN_001fba60());
        q->FUN_001cbc20(&m);
    }
    __security_check_cookie(cookie);
}
