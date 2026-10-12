// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 42/42)
// FUN_0029b750 @ 0x0029b750
struct Mat {
    float m[16];
};

struct V3 {
    float x, y, z;
    void FUN_0022d210(const Mat *m);
};

struct Box {
    float f[6];
};

struct RefObj {
    virtual void AddRef();
    virtual void Release();
};

struct Elem {
    Mat mat;
    RefObj *ref0;
    RefObj *ref1;
    void FUN_0022ca90(const Mat *a, const Mat *b);
};

struct Provider {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual const Mat *v18(int arg);
};

struct Cam {
    char pad[0x30];
    V3 pos;
};

struct CamHolder {
    Cam *FUN_0028faa0();
};

struct Hdr {
    char pad[0x4c];
    V3 pos;
    void FUN_0029fd20(void *arg);
};

struct Culler {
    bool FUN_001c2870(const Box *box);
};

struct Entry {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void v6(Elem *elem, unsigned int idx, int x);
    char pad04[4];
    char kind;
    char pad09[3];
    unsigned int mask;
    int key;
};

struct Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual unsigned int v5();
    char pad04[0x10];
    Box box;
    int FUN_002a50b0();
};

struct Handler {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual int v5(int key);
};

struct Item {
    Obj *obj;
    int pad[3];
};

struct Node : public RefObj {
    char pad04[0xc];
    Handler *handler;
    char pad14[0x40 - 0x14];
    int extra;
    Node *parent;
    Item *begin;
    Item *end;
};

extern Provider **DAT_0052c2ac;
extern CamHolder **DAT_0052c2b0;
extern Culler *DAT_004e2350;

class Binder {
public:
    char pad0[0x10];
    unsigned int entryCount;
    unsigned int index;
    Hdr *hdr;
    Entry **entries;
    char pad20[8];
    Elem *elems;

    int FUN_0029b750(Node *a1, const Mat *a2, RefObj *a3);
};

int Binder::FUN_0029b750(Node *a1, const Mat *a2, RefObj *a3)
{
    struct Frame {
        int count;
        unsigned int i;
        int key;
        union {
            V3 v3;
            Box box;
        } u;
        int extra;
        Obj *nodes[256];
    } fr;

    if (hdr != 0 && a1->parent == a1) {
        fr.u.v3 = (*DAT_0052c2b0)->FUN_0028faa0()->pos;
        if (a2 != 0)
            fr.u.v3.FUN_0022d210(a2);
        hdr->pos = fr.u.v3;
        hdr->FUN_0029fd20(a1->parent);
    }

    if (a2 != 0) {
        Elem *e = &elems[index];
        e->FUN_0022ca90(a2, (*DAT_0052c2ac)->v18(0));
    } else {
        Elem *e = &elems[index];
        e->mat = *(*DAT_0052c2ac)->v18(0);
    }

    RefObj **slot0 = &elems[index].ref0;
    if (a1 != 0)
        a1->AddRef();
    if (*slot0 != 0)
        (*slot0)->Release();
    *slot0 = a1;

    RefObj **slot1 = &elems[index].ref1;
    if (a3 != 0)
        a3->AddRef();
    if (*slot1 != 0)
        (*slot1)->Release();
    *slot1 = a3;

    fr.extra = a1->extra;
    fr.count = a1->end - a1->begin;
    unsigned int n;
    for (n = 0; n < (unsigned int)fr.count; n++) {
        Obj *o = a1->begin[n].obj;
        if (DAT_004e2350 != 0) {
            fr.u.box = o->box;
            if (DAT_004e2350->FUN_001c2870(&fr.u.box))
                fr.nodes[n] = o;
            else
                fr.nodes[n] = 0;
        } else {
            fr.nodes[n] = o;
        }
    }

    for (fr.i = 0; fr.i < (unsigned int)fr.count; fr.i++) {
        Obj *o = fr.nodes[fr.i];
        if (o == 0)
            continue;
        fr.key = o->FUN_002a50b0();
        if (a1->handler != 0)
            fr.key = a1->handler->v5(fr.key);
        unsigned int j;
        for (j = 0; j < entryCount; j++) {
            Entry *ent = entries[j];
            if (ent->kind == 1) {
                unsigned int m = ent->mask;
                unsigned int r = o->v5();
                if ((m & r) != 0) {
                    Entry *ent2 = entries[j];
                    if (ent2->key == fr.key)
                        ent2->v6(&elems[index], fr.i, fr.extra);
                }
            }
        }
    }
    return ++index;
}
