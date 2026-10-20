// STATUS: equivalent (tools/equiv.py level 3: 101 inputs, branch coverage 24/24)
// FUN_000991b0 @ 0x000991b0
void *FUN_00263ea0(unsigned int size);

struct Vec3_991b0 {
    int x, y, z;
    void FUN_000a9050();
};

class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int *out1, int *out2);
    virtual void v7();
    virtual float v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual int v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30(void *owner);
    virtual void v31(void *owner);
};

class Target_991b0 {
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30(void *owner);
    void FUN_000fd8a0(void *owner, int arg, int a, float b);
};

class Helper_991b0 {
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    Helper_991b0 *FUN_000983d0();
    void FUN_00098480(void *owner);
    char FUN_000989d0(void *owner, Node *node, int zero, Node *target);
};

struct Sel {
    Target_991b0 *FUN_000fdc30();
};

struct Mgr_991b0 {
    char pad0[0x1ca0];
    Sel *sel;
};

struct Level_991b0 {
    char pad0[0x124];
    Mgr_991b0 *mgr;
};

struct Owner_991b0 {
    char pad0[0x20];
    Level_991b0 *level;
};

Vec3_991b0 *__stdcall FUN_000a9170(Node *a, Node *b);

class Controller_991b0 {
public:
    char pad0[4];
    int flags;
    char pad8[8];
    Node *target;
    char pad14[0xbc - 0x14];
    Helper_991b0 *helper;
    void FUN_000991b0(Owner_991b0 *owner, Node *node, Node *tgt, bool arg4, bool arg5);
};

void Controller_991b0::FUN_000991b0(Owner_991b0 *owner, Node *node, Node *tgt, bool arg4, bool arg5)
{
    int out1, out2;
    Vec3_991b0 v;

    if (node == tgt || !tgt)
        return;

    if (arg4) {
        Mgr_991b0 *mgr = owner->level->mgr;
        if (mgr) {
            Target_991b0 *cur = mgr->sel->FUN_000fdc30();
            if (cur) {
                node->v6(&out1, &out2);
                float f = node->v8();
                cur->FUN_000fd8a0(owner, node->v14(), out1, f);
            }
        }
    }

    v.FUN_000a9050();
    if (node) {
        Vec3_991b0 *p = FUN_000a9170(node, tgt);
        v = *p;
        if (!arg5 && v.x != 0) {
            int fl = flags | 0x20;
            Helper_991b0 *h = helper;
            flags = fl;
            if (!h) {
                Helper_991b0 *mem = (Helper_991b0 *)FUN_00263ea0(0x1b8);
                if (mem)
                    h = mem->FUN_000983d0();
                else
                    h = 0;
                helper = h;
                h->v0();
                helper->v28();
            }
            if (!helper->FUN_000989d0(owner, node, 0, tgt)) {
                helper->FUN_00098480(owner);
                flags &= ~0x20;
            }
        } else {
            if (arg5)
                v.x = 0;
            if (helper)
                helper->FUN_00098480(owner);
            flags &= ~0x20;
            node->v31(owner);
        }
    }
    target = tgt;
    tgt->v30(owner);
}
