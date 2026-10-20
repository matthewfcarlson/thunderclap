// STATUS: equivalent (tools/equiv.py level 3: 3075 inputs, branch coverage 37/37)
// FUN_00297ba0 @ 0x00297ba0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "compat/ptr.h"
void *thunk_FUN_0008d690(unsigned int size);

struct Name_297ba0 {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct Reader {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    int FUN_00266c30();
    char *FUN_000f9600(char *out);
};

class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void AddChild(Node *child);
    char pad04[4];
    Name_297ba0 name;
};

class NodeA_297ba0 : public Node {
public:
    char pad[0x28 - 0x10];
    NodeA_297ba0 *FUN_002972e0(int v);
};

class NodeB_297ba0 : public Node {
public:
    char pad[0xb0 - 0x10];
    NodeB_297ba0 *FUN_00297460(int v);
    hulk_intptr FUN_001a4990();
};

class NodeC_297ba0 : public Node {
public:
    char pad[0x28 - 0x10];
    bool flag28;
    char pad29[0x30 - 0x29];
    NodeC_297ba0 *FUN_00297560(int v);
};

namespace pure3d {
class DrawableHierarchy {
public:
    virtual void h0();
    virtual void h1();
};
class DrawableContainer : public DrawableHierarchy {
public:
    virtual void c0();
};
}

struct Holder_297ba0 {
    char pad00[0x18];
    void *child18;
    Holder_297ba0 *FUN_00295fd0();
    char pad1c[4];
    char name8[0];
    void FUN_00296b80(pure3d::DrawableHierarchy *h);
};

struct HolderName_297ba0 {
    char pad[8];
    Name_297ba0 name;
};

pure3d::DrawableHierarchy *FUN_000c0de0(void *ctx, char *name);

struct Frame_297ba0 {
    int x;
    char name[0x100];
};

class SceneLoader_297ba0 {
public:
    Node *FUN_00297ba0(Stream *s, void *ctx);
};

Node *SceneLoader_297ba0::FUN_00297ba0(Stream *s, void *ctx)
{
    Frame_297ba0 f;
    Node *node = 0;
    int id = s->FUN_00266c30();

    switch (id - 0x120101) {
    case 0: {
        s->FUN_00266a30();
        node = FUN_00297ba0(s, ctx);
        s->FUN_00266be0();
        return node;
    }
    case 1: {
        s->FUN_000f9600(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        void *mem = thunk_FUN_0008d690(0x28);
        NodeA_297ba0 *a = 0;
        if (mem)
            a = ((NodeA_297ba0 *)mem)->FUN_002972e0(f.x);
        a->name.FUN_0027b040(f.name);
        node = a;
        break;
    }
    case 2: {
        s->FUN_000f9600(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        void *mem = thunk_FUN_0008d690(0xb0);
        NodeB_297ba0 *b = 0;
        if (mem)
            b = ((NodeB_297ba0 *)mem)->FUN_00297460(f.x);
        b->name.FUN_0027b040(f.name);
        s->reader->FUN_002647e0((void *)b->FUN_001a4990(), 0x10, 4, 1);
        node = b;
        break;
    }
    case 3: {
        s->FUN_000f9600(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        void *mem = thunk_FUN_0008d690(0x30);
        NodeC_297ba0 *c = 0;
        if (mem)
            c = ((NodeC_297ba0 *)mem)->FUN_00297560(f.x);
        c->name.FUN_0027b040(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        c->flag28 = (f.x != 0);
        node = c;
        break;
    }
    case 6: {
        void *mem = thunk_FUN_0008d690(0x20);
        Holder_297ba0 *h = 0;
        if (mem)
            h = ((Holder_297ba0 *)mem)->FUN_00295fd0();
        s->FUN_000f9600(f.name);
        ((HolderName_297ba0 *)h)->name.FUN_0027b040(f.name);
        s->FUN_000f9600(f.name);
        pure3d::DrawableHierarchy *dh = FUN_000c0de0(ctx, f.name);
        h->FUN_00296b80(dh);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        while (s->FUN_002669f0()) {
            if (s->FUN_00266a30() == 0x12010a) {
                s->reader->FUN_002647e0(&f.x, 1, 4, 1);
                dynamic_cast<pure3d::DrawableContainer *>(dh);
            }
            s->FUN_00266be0();
        }
        return (Node *)h;
    }
    default:
        return 0;
    case 4:
    case 5:
        return 0;
    }

    while (s->FUN_002669f0()) {
        s->FUN_00266a30();
        node->AddChild(FUN_00297ba0(s, ctx));
        s->FUN_00266be0();
    }
    return node;
}
