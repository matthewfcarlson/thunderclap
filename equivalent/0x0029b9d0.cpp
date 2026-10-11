// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 24/24)
// FUN_0029b9d0 @ 0x0029b9d0
struct Mat64 {
    int w[16];
    void FUN_0022ca90(Mat64 *a, Mat64 *b);
};

class Counted {
public:
    virtual void addRef();
    virtual void release();
};

class Provider {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual Mat64 *getMatrix(int a);
};

class Source {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual unsigned getMask();
    virtual void v6();
    virtual void *getKey();
    virtual void apply(void *a);
    int FUN_002a50b0();
};

class Target {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void *v3(void *a);
    virtual void *v4(void *a);
};

struct SourceRef {
    Source *src;
    char pad[12];
};

struct Entry;

class Listener {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void onMatch(Entry *e, int idx, int extra);
    char pad04[4];
    char kind;
    char pad09[3];
    unsigned mask;
    int key;
};

struct Entry {
    Mat64 mat;
    Counted *objA;
    Counted *objB;
};

class Anim : public Counted {
public:
    char pad4[0xc];
    Target *target;
    char pad14[0x40 - 0x14];
    int f40;
    char pad44[4];
    SourceRef *sources;
};

extern Provider **DAT_0052c2ac;

class Mixer {
public:
    char pad0[0x10];
    unsigned listenerCount;
    int cur;
    char pad18[4];
    Listener **listeners;
    char pad20[8];
    Entry *entries;
    void FUN_0029b9d0(Anim *anim, int idx, Mat64 *m, Counted *q);
};

void Mixer::FUN_0029b9d0(Anim *anim, int idx, Mat64 *m, Counted *q)
{
    if (m) {
        Entry *e = &entries[cur];
        Mat64 *src = (*DAT_0052c2ac)->getMatrix(0);
        e->mat.FUN_0022ca90(m, src);
    } else {
        Entry *e = &entries[cur];
        Mat64 *src = (*DAT_0052c2ac)->getMatrix(0);
        e->mat = *src;
    }

    Counted **slotA = &entries[cur].objA;
    if (anim)
        anim->addRef();
    if (*slotA)
        (*slotA)->release();
    *slotA = anim;

    Counted **slotB = &entries[cur].objB;
    if (q)
        q->addRef();
    if (*slotB)
        (*slotB)->release();
    *slotB = q;

    int extra = anim->f40;
    Source *r = anim->sources[idx].src;
    Target *t = anim->target;
    if (t)
        r->apply(t->v3(r->getKey()));

    for (unsigned i = 0; i < listenerCount; i++) {
        Listener *l = listeners[i];
        if (l->kind == 1) {
            unsigned lm = l->mask;
            if (lm & r->getMask()) {
                int k = listeners[i]->key;
                if (k == r->FUN_002a50b0())
                    listeners[i]->onMatch(&entries[cur], idx, extra);
            }
        }
    }

    t = anim->target;
    if (t)
        r->apply(t->v4(r->getKey()));
    cur++;
}
