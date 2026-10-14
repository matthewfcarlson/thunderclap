// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 20/20)
// FUN_001dec10 @ 0x001dec10
struct Quat { float x, y, z, w; };
struct Item_1dec10 {
    virtual void vfn0();
    virtual void vfn1();
    void FUN_001d7ff0();
};
struct Res {
    virtual void vfn0();
    virtual void vfn1();
};
struct Buffer {
    void FUN_00263e90();
};
struct SlotA {
    char pad[8];
    void FUN_0027b040(int v);
};
struct SlotC_1dec10 {
    char pad[6];
    void FUN_001db780(Quat *q);
};
struct Slot_1dec10 {
    SlotA a;            // 0x00
    SlotA b;            // 0x08
    SlotC_1dec10 c;            // 0x10
    short active;       // 0x16
    Res *res;           // 0x18
    int field1c;        // 0x1c
    short field20;      // 0x20
    short recIndex;     // 0x22
    short field24;      // 0x24
    char field26;       // 0x26
    char field27;       // 0x27
};
struct Rec {
    int a;
    int b;
    int c;
    float maxv;
    short s10;
    short s12;
};
class Pool_1dec10 {
public:
    char pad0[0x608];
    Slot_1dec10 slots[0x800];      // 0x608
    Rec recs[0x800];        // 0x14608
    int f1e608;
    int f1e60c;
    int f1e610;
    int recCount;           // 0x1e614
    Buffer *buffer;         // 0x1e618
    int f1e61c;
    Item_1dec10 *items[0x80];      // 0x1e620
    int itemCount;          // 0x1e820
    char pad1[0x1ec58 - 0x1e824];
    int f1ec58;
    void FUN_001dec10();
};

void Pool_1dec10::FUN_001dec10()
{
    int i;
    for (i = 0; i < itemCount; i++) {
        items[i]->FUN_001d7ff0();
        if (items[i]) {
            items[i]->vfn1();
            items[i] = 0;
        }
    }
    itemCount = 0;
    if (buffer) {
        buffer->FUN_00263e90();
        buffer = 0;
    }
    f1e61c = 0;
    Quat q;
    q.x = 0.0f;
    q.y = 0.0f;
    q.z = 0.0f;
    q.w = 1.0f;
    for (i = 0x800; i != 0; i--) {
        Slot_1dec10 *s = &slots[0x800 - i];
        if (s->active != 0) {
            Rec *r = &recs[s->recIndex];
            if (r->s10 & 1) {
                if (s->res) {
                    s->res->vfn1();
                    s->res = 0;
                }
            }
            r->a = 0;
            r->b = 0;
            r->c = 0;
            r->maxv = 3.4028235e+38f;
            r->s10 = 0;
            r->s12 = -1;
        }
        s->a.FUN_0027b040(0);
        s->b.FUN_0027b040(0);
        s->field1c = 0;
        s->c.FUN_001db780(&q);
        s->res = 0;
        s->field20 = 0;
        s->active = 0;
        s->recIndex = -1;
        s->field26 = 0;
        s->field24 = 0;
        s->field27 = 1;
    }
    for (i = 0; i < recCount; i++) {
        Rec *r = &recs[i];
        r->a = 0;
        r->b = 0;
        r->c = 0;
        r->maxv = 3.4028235e+38f;
        r->s10 = 0;
        r->s12 = -1;
    }
    recCount = 0;
    f1e608 = 0;
    f1ec58 = 0;
    f1e60c = 0;
    f1e610 = 0;
}
