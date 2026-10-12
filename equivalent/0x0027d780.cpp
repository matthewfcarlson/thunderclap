// STATUS: equivalent (tools/equiv.py level 3: 415 inputs, branch coverage 60/60)
// FUN_0027d780 @ 0x0027d780
// equiv-map: ?thunk_FUN_002ee510@Cache@@QAEXPAUChoice@@@Z = 0x002ee700

struct Choice {
    char pad[0x10];
    int value;
};

struct Cache {
    void thunk_FUN_002ee510(Choice* c);
    void FUN_002ee6d0(Choice* c);
};

extern Cache* DAT_00554c14;

class Node {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(int a, int b);
    virtual void vfunc_7();
    virtual void vfunc_8(int v);
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(float v);
    virtual float vfunc_13();
    virtual void vfunc_14(float a, float b);
    virtual void vfunc_15();
    virtual void vfunc_16(int v);
    virtual void vfunc_17();
    virtual void vfunc_18(int v);
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
};

class Child {
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
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual int vfunc_15();
    void FUN_002a3b60();
};

struct Elem {
    char pad00[0xc];
    int f0c;
    char flag;
    char pad11[3];
    float lo;
    float hi;
    int f1c;
};

struct Flag16 {
    char pad00[8];
    unsigned char flag;
    char pad09[7];
};

struct Entry {
    char pad00[0x18];
    Flag16* flags;
    char pad1c[4];
    Elem* elems;
};

struct Table {
    char pad00[0x1c];
    Entry** begin;
    Entry** end;
};

struct Item12 {
    int f0;
    int f4;
    Child* child;
};

struct Group {
    char pad00[0x3c];
    Item12* begin;
    Item12* end;
    void FUN_002988e0();
    void FUN_002987d0(unsigned int i);
};

struct Nodes {
    char pad00[0x24];
    Node** begin;
    Node** end;
    void FUN_00299230(unsigned int i);
    void FUN_002989c0(unsigned int i);
};

struct Board {
    char pad00[0x44];
    Group* group;
    Nodes* nodes;
};

class Marker {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual float vfunc_7();
    char active;
};

struct Marks {
    char pad00[0x1f8];
    Marker** items;
    char pad1fc[4];
    int count;
};

struct Gadget {
    char pad00[0x70];
    Marks* marks;
    char pad74[0x84 - 0x74];
    char flag84;
    char flag85;
    void FUN_002fd4a0();
    void FUN_002fd4b0(int a, int b);
    void FUN_002fd4f0();
    void FUN_002fe2c0();
    void FUN_002fe420(Board* b);
    void FUN_002fe2e0();
};

struct Holder {
    char pad00[0x10];
    Gadget* gadget;
    void FUN_002fc670(int v);
};

struct Frame {
    float lo;
    float hi;
    float cur;
    union {
        unsigned char b;
        unsigned int w;
    } i;
    int off20;
    union {
        int off4;
        unsigned char b;
        unsigned int w;
    } j;
    Entry* x;
    Group* d;
    void* self;
};

class Scene {
public:
    virtual void vfunc_0();
    char pad04[0x40 - 4];
    int current;
    char pad44[0x98 - 0x44];
    Table* table;
    Board* board;
    Holder* holder;
    char pada4[0xac - 0xa4];
    Choice** choices;
    void FUN_0027d780();
};

void Scene::FUN_0027d780()
{
    Frame f;
    Entry* x = table->begin[current];
    Board* b = board;
    Nodes* nodes = b->nodes;
    Group* group = b->group;
    int total = nodes->end - nodes->begin;
    f.x = x;
    f.d = group;
    f.self = this;
    unsigned char n = (unsigned char)total;
    f.i.b = 0;
    if (n != 0) {
        f.off20 = 0;
        f.j.off4 = 0;
        do {
            Elem* e = (Elem*)((char*)f.x->elems + f.off20);
            Node* node = *(Node**)((char*)nodes->begin + f.j.off4);
            f.lo = e->lo;
            f.hi = e->hi;
            if (f.lo == f.hi && !e->flag) {
                nodes->FUN_00299230(f.i.w);
                node->vfunc_23();
                node->vfunc_14(f.lo, f.hi);
                node->vfunc_6(0, 1);
            } else {
                nodes->FUN_002989c0(f.i.w);
                f.cur = node->vfunc_13();
                if (!e->flag) {
                    node->vfunc_23();
                } else {
                    if ((f.cur > f.lo && f.cur > f.hi) || (f.cur < f.lo && f.cur < f.hi))
                        f.lo = f.cur;
                }
                node->vfunc_8(e->f1c);
                if (f.lo > f.hi) {
                    node->vfunc_16(3);
                    node->vfunc_14(f.hi, f.lo);
                } else {
                    node->vfunc_16(2);
                    node->vfunc_14(f.lo, f.hi);
                }
                node->vfunc_18(e->f0c);
                if (!e->flag)
                    node->vfunc_12(f.lo);
            }
            f.i.b++;
            f.off20 += 0x20;
            f.j.off4 += 4;
        } while (f.i.b < n);
        group = f.d;
    }

    group->FUN_002988e0();
    int total2 = group->end - group->begin;
    unsigned char n2 = (unsigned char)total2;
    f.j.b = 0;
    if (n2 != 0) {
        f.off20 = 0;
        int off12 = 0;
        do {
            Flag16* fl = (Flag16*)((char*)f.x->flags + f.off20);
            if (fl->flag == 1) {
                group->FUN_002987d0(f.j.w);
            } else {
                Child* child = *(Child**)((char*)group->begin + off12 + 8);
                if (child) {
                    if (child->vfunc_15() == 4)
                        child->FUN_002a3b60();
                }
            }
            f.j.b++;
            f.off20 += 0x10;
            off12 += 12;
        } while (f.j.b < n2);
    }

    Scene* self = (Scene*)f.self;
    Table* t = self->table;
    for (int k = 0; k < (int)(t->end - t->begin); k++) {
        Choice* ch = self->choices[k];
        if (ch)
            DAT_00554c14->thunk_FUN_002ee510(ch);
        t = self->table;
    }
    Choice* cc = self->choices[self->current];
    if (cc)
        DAT_00554c14->FUN_002ee6d0(cc);

    if (!self->holder)
        return;
    Gadget* g = self->holder->gadget;
    if (g->flag84) {
        g->FUN_002fd4a0();
        for (unsigned int k = 0; k < n2; k++)
            g->FUN_002fd4b0(f.d->begin[k].f4, f.x->flags[k].flag);
        Marks* m = g->marks;
        bool found = false;
        if (m) {
            for (int k = 0; k < m->count; k++) {
                Marker* mk = m->items[k];
                if (mk->active) {
                    if (mk->vfunc_7() > 0.0f) {
                        found = true;
                        break;
                    }
                }
            }
        }
        if (!found)
            self->holder->FUN_002fc670(2);
        g->FUN_002fd4f0();
    } else if (g->flag85) {
        g->FUN_002fe2c0();
        g->FUN_002fe420(self->board);
        g->FUN_002fe2e0();
    }
}
