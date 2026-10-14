// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 42/42)
// FUN_002322f0 @ 0x002322f0
int __cdecl FUN_00238190(int id);
int __cdecl FUN_00266da0(int heap);

extern int DAT_004e5ae8;
extern int DAT_004e5aec;

class Ref_2322f0 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Item_2322f0 : public Ref_2322f0 {
public:
    virtual void v2();
    virtual bool Update(int arg, float dt);
    char pad04[4];
    Item_2322f0 *next;            // 0x08
    unsigned int flags;    // 0x0c
    float time;            // 0x10
    char pad14[4];
    float elapsed;         // 0x18
    void FUN_00232600(unsigned int mask, char set);
    void FUN_002326d0(Item_2322f0 *item);
};

class Sequence;

class Child_2322f0 {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual Sequence *Match(int a, Ref_2322f0 *b);
    Child_2322f0 *next;           // 0x04
    void FUN_00236bc0(Ref_2322f0 *ctx, Sequence *seq, Ref_2322f0 *b);
};

class Context : public Ref_2322f0 {
public:
    char pad04[0x28 - 4];
    Child_2322f0 *children;       // 0x28
};

class Sequence {
public:
    Ref_2322f0 *owner;            // 0x00
    Context *ctx;          // 0x04
    int f8;
    Ref_2322f0 *fc;               // 0x0c
    char pad10[4];
    Item_2322f0 *pending;         // 0x14
    Ref_2322f0 *f18;
    float time;            // 0x1c
    Item_2322f0 *active;          // 0x20
    Item_2322f0 *tail;            // 0x24
    void FUN_002321b0();
    void FUN_002322f0(int arg, float dt);
};

void Sequence::FUN_002322f0(int arg, float dt)
{
    int savedHeap = FUN_00266da0(FUN_00238190(3));

    if (ctx != 0) {
        FUN_002321b0();
        Child_2322f0 *c = ctx->children;
        while (c != 0) {
            if (c->Match(f8, fc) == this)
                c->FUN_00236bc0(ctx, this, fc);
            c = c->next;
        }
        Context *cx = ctx;
        if (cx != 0)
            cx->AddRef();
        if (owner != 0)
            owner->Release();
        owner = cx;
        if (fc != 0) {
            fc->Release();
            fc = 0;
        }
        f8 = 0;
        if (ctx != 0) {
            ctx->Release();
            ctx = 0;
        }
    }

    Item_2322f0 *it = pending;
    while (it != 0) {
        it->time = time + it->time;
        if (tail == 0) {
            it->AddRef();
            if (active != 0)
                active->Release();
            active = it;
        } else {
            tail->FUN_002326d0(it);
        }
        it->AddRef();
        if (tail != 0)
            tail->Release();
        tail = it;
        it = it->next;
    }

    if (f18 != 0) {
        f18->Release();
        f18 = 0;
    }
    if (pending != 0) {
        pending->Release();
        pending = 0;
    }

    float now = dt + time;
    time = now;
    Item_2322f0 *cur = active;
    if (cur != 0) {
        do {
            float t = cur->time;
            if (t <= now) {
                if (((cur->flags >> 2) & 1) != 0) {
                    cur->elapsed = dt;
                } else {
                    cur->FUN_00232600(4, 1);
                    float d = now - t;
                    cur->elapsed = d;
                    bool alive = cur->Update(arg, d);
                    DAT_004e5ae8++;
                    if (DAT_004e5ae8 > DAT_004e5aec)
                        DAT_004e5aec = DAT_004e5ae8;
                    if (!alive)
                        cur->FUN_00232600(8, 1);
                }
            }
            cur = cur->next;
        } while (cur != 0);
    }
    FUN_00266da0(savedHeap);
}
