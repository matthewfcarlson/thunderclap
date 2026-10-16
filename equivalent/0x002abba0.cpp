// STATUS: equivalent (tools/equiv.py level 3: 189 inputs, branch coverage 18/18; run with --inputs 12000)
// FUN_002abba0 @ 0x002abba0
#include "decls/data/engine/content.h"

extern char DAT_0049c7dc[];
extern char DAT_004ce974[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern void *__cdecl FUN_00263ea0(unsigned int size);
extern void *__cdecl FUN_0008d690(unsigned int size);

class Node {
public:
    virtual void AddRef();
    char pad4[0x10];
    Node *FUN_002d2130(void *src);
};

class Item_2abba0 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad4[0x24];
    int count;
    void *FUN_00288a10(int index);
};

class Stream {
public:
    void FUN_002647e0(void *dst, int a, int b, int c);
};

class Reader {
public:
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

class Parser_2abba0 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(Item_2abba0 **out, int *flag, Reader *r, int arg);
    int FUN_00288e90();
    void FUN_00288e80(int state);
};

struct NodeVec_2abba0 {
    Node **data;
    char pad4[8];
    void FUN_002ab940(int count, int *fill);
};

class Factory_2abba0 {
public:
    void *FUN_00265310(int id);
};

class Result_2abba0 {
public:
    char pad0[0x1c];
    int used;
    char pad20[8];
    Item_2abba0 *item;
    NodeVec_2abba0 nodes;
    int a38;
    int a3c;
    int a40;
    char pad44[0x50 - 0x44];
    Result_2abba0 *FUN_002d3740();
};

struct Frame_2abba0 {
    Item_2abba0 *it;
    int count;
    int fill;
    int state;
    int flag;
    int unused;
};

Result_2abba0 *__stdcall FUN_002abba0(Reader *r, int arg)
{
    Frame_2abba0 f;
    r->stream->FUN_002647e0(&f.state, 1, 4, 1);
    void *mem = FUN_00263ea0(0x50);
    Result_2abba0 *res;
    if (mem)
        res = ((Result_2abba0 *)mem)->FUN_002d3740();
    else
        res = 0;
    r->stream->FUN_002647e0(&f.count, 1, 4, 1);
    res->a38 = f.count;
    r->stream->FUN_002647e0(&f.count, 1, 4, 1);
    res->a3c = f.count;
    r->stream->FUN_002647e0(&f.count, 1, 4, 1);
    res->a40 = f.count;

    while (r->FUN_002669f0()) {
        int id = r->FUN_00266a30();
        if (id == 0x121000) {
            Parser_2abba0 *p = (Parser_2abba0 *)FUN_00344e74((*(Factory_2abba0**)&DAT_00527c58)->FUN_00265310(id), 0, DAT_0049c7dc, DAT_004ce974, 0);
            p->AddRef();
            f.state = p->FUN_00288e90();
            p->FUN_00288e80(1);
            p->v5(&f.it, &f.flag, r, arg);
            Item_2abba0 *it = f.it;
            if (it) {
                it->AddRef();
                if (res->item)
                    res->item->Release();
                res->item = it;
                f.count = f.it->count;
                f.fill = 0;
                res->nodes.FUN_002ab940(f.count, &f.fill);
                for (int i = 0; i < f.count; i++) {
                    Node *n;
                    void *m = FUN_0008d690(0x14);
                    if (m)
                        n = ((Node *)m)->FUN_002d2130(f.it->FUN_00288a10(i));
                    else
                        n = 0;
                    res->nodes.data[res->used] = n;
                    res->nodes.data[res->used]->AddRef();
                    res->used++;
                }
            }
            p->FUN_00288e80(f.state);
            p->Release();
        }
        r->FUN_00266be0();
    }
    return res;
}
