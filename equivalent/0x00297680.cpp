// STATUS: equivalent (tools/equiv.py level 3: 3109 inputs, branch coverage 49/51, incomplete)
// FUN_00297680 @ 0x00297680
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/data/engine/content.h"
#include "gen/pure3d.h"

void *thunk_FUN_0008d690(unsigned int size);

struct Name_297680 {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct Reader_297680 {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream_297680 {
    char pad0[0x284];
    Reader_297680 *reader;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    int FUN_00266c30();
    char *FUN_000f9600(char *out);
};

class ObjectLoader_297680 {
public:
    virtual void v0();
    virtual void v1();
};

class FrameController_297680 {
public:
    virtual void v0();
    virtual void v1();
};

class FrameControllerLoader_297680 : public ObjectLoader_297680 {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(FrameController_297680 **out, unsigned __int64 *id, Stream_297680 *s, void *ctx);
};

class SceneGraphTransformAnimationController_297680 : public FrameController_297680 {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(void *target);
};

class SceneGraphVisibilityAnimationController_297680 : public FrameController_297680 {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(void *target);
};

class Node_297680 {
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
    virtual void AddChild(Node_297680 *child);
    char pad04[4];
    Name_297680 name;
};

class NodeA_297680 : public Node_297680 {
public:
    char pad[0x28 - 0x10];
    NodeA_297680 *FUN_002972e0(int v);
};

class NodeB_297680 : public Node_297680 {
public:
    char pad[0xb0 - 0x10];
    NodeB_297680 *FUN_00297460(int v);
    int FUN_001a4990();
    void FUN_00296970(SceneGraphTransformAnimationController_297680 *c);
};

class NodeC_297680 : public Node_297680 {
public:
    char pad[0x28 - 0x10];
    bool flag28;
    char pad29[0x30 - 0x29];
    NodeC_297680 *FUN_00297560(int v);
    void FUN_00296ae0(SceneGraphVisibilityAnimationController_297680 *c);
};

class DrawableHierarchy_297680 {
public:
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual DrawableHierarchy_297680 *h4();
};

struct DrawableNode_nv_297680 {
    pure3d::scenegraph::DrawableNode *FUN_00295fd0();
    void FUN_00296b80(DrawableHierarchy_297680 *h);
};

struct HolderName_297680 {
    char pad[8];
    Name_297680 name;
};

struct Registry_297680 {
    ObjectLoader_297680 *FUN_00265310(int id);
};

DrawableHierarchy_297680 *FUN_000c0de0(void *ctx, char *name);

class SceneLoader_297680;
struct Frame_297680 {
    union {
        int x;
        FrameController_297680 *fc;
    };
    SceneLoader_297680 *self;
    unsigned __int64 id;
    char name[0x100];
};

class SceneLoader_297680 {
public:
    Node_297680 *FUN_00297680(Stream_297680 *s, void *ctx);
};

Node_297680 *SceneLoader_297680::FUN_00297680(Stream_297680 *s, void *ctx)
{
    Frame_297680 f;
    f.self = this;
    Node_297680 *node = 0;
    int id = s->FUN_00266c30();

    switch (id) {
    case 0x12010b: {
        s->reader->FUN_002647e0(&f.self, 1, 4, 1);
        s->FUN_00266a30();
        node = FUN_00297680(s, ctx);
        s->FUN_00266be0();
        return node;
    }
    case 0x12010c: {
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        s->FUN_000f9600(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        void *mem = thunk_FUN_0008d690(0x28);
        NodeA_297680 *a = 0;
        if (mem)
            a = ((NodeA_297680 *)mem)->FUN_002972e0(f.x);
        a->name.FUN_0027b040(f.name);
        node = a;
        while (s->FUN_002669f0()) {
            s->FUN_00266a30();
            node->AddChild(FUN_00297680(s, ctx));
            s->FUN_00266be0();
        }
        return node;
    }
    case 0x12010d: {
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        s->FUN_000f9600(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        void *mem = thunk_FUN_0008d690(0xb0);
        NodeB_297680 *b = 0;
        if (mem)
            b = ((NodeB_297680 *)mem)->FUN_00297460(f.x);
        b->name.FUN_0027b040(f.name);
        s->reader->FUN_002647e0((void *)b->FUN_001a4990(), 0x10, 4, 1);
        while (s->FUN_002669f0()) {
            if (s->FUN_00266a30() != 0x121201) {
                b->AddChild(FUN_00297680(s, ctx));
            } else {
                FrameControllerLoader_297680 *fl =
                    dynamic_cast<FrameControllerLoader_297680 *>((*(Registry_297680**)&DAT_00527c58)->FUN_00265310(0x121201));
                fl->v0();
                f.fc = 0;
                fl->v5(&f.fc, &f.id, s, ctx);
                if (f.fc) {
                    SceneGraphTransformAnimationController_297680 *tc =
                        dynamic_cast<SceneGraphTransformAnimationController_297680 *>(f.fc);
                    if (tc) {
                        tc->v5(b);
                        b->FUN_00296970(tc);
                    } else if (f.fc) {
                        f.fc->v1();
                        f.fc = 0;
                    }
                }
                fl->v1();
            }
            s->FUN_00266be0();
        }
        return b;
    }
    case 0x12010e: {
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        s->FUN_000f9600(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        void *mem = thunk_FUN_0008d690(0x30);
        NodeC_297680 *c = 0;
        if (mem)
            c = ((NodeC_297680 *)mem)->FUN_00297560(f.x);
        c->name.FUN_0027b040(f.name);
        s->reader->FUN_002647e0(&f.x, 1, 4, 1);
        c->flag28 = (f.x != 0);
        while (s->FUN_002669f0()) {
            if (s->FUN_00266a30() != 0x121201) {
                c->AddChild(FUN_00297680(s, ctx));
            } else {
                FrameControllerLoader_297680 *fl =
                    dynamic_cast<FrameControllerLoader_297680 *>((*(Registry_297680**)&DAT_00527c58)->FUN_00265310(0x121201));
                fl->v0();
                f.fc = 0;
                fl->v5(&f.fc, &f.id, s, ctx);
                if (f.fc) {
                    SceneGraphVisibilityAnimationController_297680 *vc =
                        dynamic_cast<SceneGraphVisibilityAnimationController_297680 *>(f.fc);
                    if (vc) {
                        vc->v5(c);
                        c->FUN_00296ae0(vc);
                    } else if (f.fc) {
                        f.fc->v1();
                        f.fc = 0;
                    }
                }
                fl->v1();
            }
            s->FUN_00266be0();
        }
        return c;
    }
    case 0x12010f: {
        s->reader->FUN_002647e0(&f.self, 1, 4, 1);
        s->reader->FUN_002647e0(&f.self, 1, 4, 1);
        bool flag = ((int)f.self != 0);
        s->FUN_000f9600(f.name);
        void *mem = thunk_FUN_0008d690(0x20);
        pure3d::scenegraph::DrawableNode *h = 0;
        if (mem)
            h = ((DrawableNode_nv_297680*)(((pure3d::scenegraph::DrawableNode *)mem)))->FUN_00295fd0();
        ((HolderName_297680 *)h)->name.FUN_0027b040(f.name);
        s->FUN_000f9600(f.name);
        DrawableHierarchy_297680 *dh = FUN_000c0de0(ctx, f.name);
        if (dh && flag == 1)
            dh = dh->h4();
        ((DrawableNode_nv_297680*)(h))->FUN_00296b80(dh);
        return (Node_297680 *)h;
    }
    default:
        return 0;
    }
}
