// STATUS: equivalent (tools/equiv.py level 3: 3075 inputs, branch coverage 34/36, incomplete)
// FUN_0024a9c0 @ 0x0024a9c0
#include "decls/data/engine/audio.h"
#include "gen/owners.h"

extern "C" int __cdecl _sprintf(char *buf, const char *fmt, ...);


struct Link_24a9c0 {
    Link_24a9c0 *next;
    Link_24a9c0 *prev;
};

struct Inner_24a9c0 {
    char data[4];
};

struct Sub_24a9c0 {
    char pad[0x14];
    Inner_24a9c0 inner;
};

struct Node {
    Node *left;
    Node *right;
    char pad08[8];
    unsigned int key;
    char pad14[0x3c - 0x14];
    void *poolA;
    void *poolB;
    char pad44[4];
    Link_24a9c0 *head;
    Link_24a9c0 *tail;
    Sub_24a9c0 sub;
    Node *FUN_0024a510(unsigned int key);
};

struct Tree_24a9c0 {
    Node *root;
    char nilMarker[4];
};

struct Y_24a9c0;

struct Entry_24a9c0 {
    Entry_24a9c0 *next;
    Y_24a9c0 *owner;
    void *extra;
    int f0c;
    char pad10[0x24 - 0x10];
    int f24;
    char pad28[0x30 - 0x28];
    Node *node;
    Link_24a9c0 link;
    short f3c;
};

struct Z {
    char pad[0x3c];
    unsigned int name;
    unsigned int limit;
};

struct Y_24a9c0 {
    char pad[0x10];
    Entry_24a9c0 *head;
    Entry_24a9c0 *tail;
    unsigned int count;
    Z *z;
};

struct Ctx_24a9c0 {
    char pad[0x48];
    Tree_24a9c0 tree;
};

struct Extra_24a9c0 {
};

extern "C" unsigned int __cdecl FUN_002673a0(const char *s, int flag);
void *__cdecl FUN_00247530(void *pool);
void __cdecl FUN_00247550(void *pool, void *p);
extern "C" void * __cdecl FUN_00249fc0(void *, const unsigned int *);
extern "C" char __cdecl FUN_00249ff0(void *, void *, const unsigned *);
extern "C" void __cdecl FUN_00249ec0(void *, void *);
extern "C" void __cdecl FUN_0024a450(void *);
extern "C" void __cdecl FUN_0024a4a0(void *);
void *__cdecl FUN_0025d3d0();

static Entry_24a9c0 *EntryFromLink(Link_24a9c0 *l)
{
    return (Entry_24a9c0 *)((char *)l - 0x34);
}

extern "C" void *FUN_0024a9c0(void * ctx_, void * y_)
{
    Ctx_24a9c0 * ctx = (Ctx_24a9c0 *)ctx_;
    Y_24a9c0 * y = (Y_24a9c0 *)y_;
    struct Frame {
        unsigned int tmp;
        char buf[256];
    } fr;
    Node *node;

    if (y->count >= (y->z->limit & 0x1f))
        return (Entry_24a9c0 *)0;

    unsigned int emptyHash = FUN_002673a0("", 0);
    Tree_24a9c0 *tree = &ctx->tree;
    if (y->z->name != emptyHash) {
        node = ((Node *)FUN_00249fc0((Tree_24a9c0 *)tree, &y->z->name));
        if (node == 0) {
            void *p = FUN_00247530(DAT_004e60c8);
            if (p != 0)
                node = ((Node *)p)->FUN_0024a510(y->z->name);
            else
                node = 0;
            FUN_00249ff0((Tree_24a9c0 *)tree, (Node *)node, (const unsigned *)(unsigned int *)(&node->key));
        }
    } else {
        Node *nil = (Node *)tree->nilMarker;
        fr.tmp = 0;
        bool create = true;
        for (;;) {
            _sprintf(fr.buf, "unnamed %d", fr.tmp);
            unsigned int h = FUN_002673a0(fr.buf, 0);
            Node *n = tree->root;
            while (n != nil) {
                unsigned int *kp = &n->key;
                if (h < *kp) {
                    n = n->left;
                } else if (h <= *kp) {
                    break;
                } else {
                    n = n->right;
                }
            }
            if (n == nil)
                break;
            node = n;
            if (n == 0)
                break;
            Link_24a9c0 *l = n->head;
            if (l != 0 && EntryFromLink(l) != 0) {
                Link_24a9c0 *again = n->head;
                if (again == 0 || EntryFromLink(again) == 0) {
                    create = false;
                    break;
                }
                fr.tmp++;
                continue;
            }
            FUN_00249ec0((Tree_24a9c0 *)tree, (Node *)n);
            FUN_00247550(((char*)((char*)&DAT_004e6158)), n->poolB);
            FUN_00247550(DAT_004e6110, n->poolA);
            Sub_24a9c0 *s = &n->sub;
            FUN_0024a450((Inner_24a9c0 *)(&s->inner));
            FUN_0024a4a0((Sub_24a9c0 *)s);
            FUN_00247550(DAT_004e60c8, n);
            break;
        }
        if (create) {
            void *p = FUN_00247530(DAT_004e60c8);
            if (p != 0)
                node = ((Node *)p)->FUN_0024a510(FUN_002673a0(fr.buf, 0));
            else
                node = 0;
            fr.tmp = FUN_002673a0(fr.buf, 0);
            FUN_00249ff0((Tree_24a9c0 *)tree, (Node *)node, (const unsigned *)(unsigned int *)(&fr.tmp));
        }
    }

    Entry_24a9c0 *e = (Entry_24a9c0 *)FUN_00247530(((char*)((char*)&DAT_004e6038)));
    if (e != 0) {
        int *w = (int *)e;
        for (int i = 0; i < 16; i++)
            w[i] = 0;
    }
    Link_24a9c0 *link = &e->link;
    if (node->head == 0) {
        node->head = link;
        link->prev = 0;
    } else {
        node->tail->next = link;
        link->prev = node->tail;
    }
    node->tail = link;
    link->next = 0;
    e->next = y->head;
    y->head = e;
    if (e->next == 0)
        y->tail = e;
    e->f0c = 0;
    e->f24 = 0;
    e->owner = y;
    e->node = node;
    void *pool = FUN_00247530(FUN_0025d3d0());
    if (pool != 0)
        e->extra = ((Extra_24a9c0 *)((owners::Scheduler_25df40 *)(((Extra_24a9c0 *)pool)))->FUN_0025df40((hulk_intptr)(Node *)node, (hulk_intptr)(Z *)(y->z), (hulk_intptr)(Ctx_24a9c0 *)ctx));
    else
        e->extra = 0;
    y->count++;
    e->f3c = 0;
    return (Entry_24a9c0 *)e;
}
