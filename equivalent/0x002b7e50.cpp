// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 42/42)
// FUN_002b7e50 @ 0x002b7e50
void* FUN_0008d690(unsigned int size);

struct RefObj {
    virtual void AddRef();
    virtual void Release();
};

namespace pure3d {
class DrawablePrimitive {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int GetKind();
    DrawablePrimitive* FUN_002df7e0();
};
class PrimGroupSkinnedOptimized : public DrawablePrimitive {
public:
    void FUN_002e01a0(void* arg);
};
class PrimGroupSkinnedStreamed : public DrawablePrimitive {
public:
    void FUN_002e05f0(void* arg);
};
}

struct SkinInfo : RefObj {
    char pad04[0x10];
    SkinInfo(void* src);
    SkinInfo* FUN_002e17c0(void* src);
};

struct Binder : RefObj {
    char pad04[0x14];
    Binder* FUN_002d0fa0(void* owner);
};

struct LinkedA : RefObj {
    virtual void a2();
    virtual void a3();
    virtual LinkedA* Clone();
    void FUN_002a9f30(void* owner);
};

struct LinkedB : RefObj {
    virtual void b2();
    virtual void b3();
    virtual LinkedB* Clone();
    void FUN_002a6a20(void* owner);
};

struct Part {
    pure3d::DrawablePrimitive* prim;
    char pad04[12];
};

class PolySkin;

class __declspec(novtable) DrawableContainerBase {
public:
    virtual void v0();
    char pad04[0x44];
    Part* partsBegin;
    Part* partsEnd;
    char pad50[8];
    void FUN_002a4e40(const PolySkin* src);
    DrawableContainerBase(const PolySkin* src) { FUN_002a4e40(src); }
};

class PolySkin : public DrawableContainerBase {
public:
    virtual void v0();
    SkinInfo* info;
    RefObj* shared;
    int field60;
    RefObj* binderShared;
    Binder* binder;
    LinkedA* linkA;
    LinkedB* linkB;
    PolySkin(const PolySkin* src);
};

PolySkin::PolySkin(const PolySkin* src) : DrawableContainerBase(src)
{
    info = 0;
    shared = 0;
    field60 = 0;
    binderShared = 0;
    binder = 0;
    linkA = 0;
    linkB = 0;
    RefObj* s = src->shared;
    if (s != 0) {
        s->AddRef();
        if (shared != 0)
            shared->Release();
        shared = s;
        if (src->info != 0) {
            void* mem = FUN_0008d690(0x14);
            SkinInfo* n = 0;
            if (mem != 0) {
                n = (SkinInfo*)mem;
                n = n->FUN_002e17c0(src->info);
            }
            info = n;
            n->AddRef();
            for (unsigned int i = 0; i < (unsigned int)(partsEnd - partsBegin); i++) {
                pure3d::DrawablePrimitive* p = partsBegin[i].prim;
                if (p->GetKind() == 0x40)
                    p = p->FUN_002df7e0();
                pure3d::PrimGroupSkinnedOptimized* o = dynamic_cast<pure3d::PrimGroupSkinnedOptimized*>(p);
                if (o != 0) {
                    static_cast<pure3d::PrimGroupSkinnedOptimized*>(p)->FUN_002e01a0(info);
                } else {
                    pure3d::PrimGroupSkinnedStreamed* st = dynamic_cast<pure3d::PrimGroupSkinnedStreamed*>(p);
                    if (st != 0)
                        static_cast<pure3d::PrimGroupSkinnedStreamed*>(p)->FUN_002e05f0(info);
                }
            }
        }
    }
    RefObj* b = src->binderShared;
    if (b != 0)
        b->AddRef();
    if (binderShared != 0)
        binderShared->Release();
    binderShared = b;
    if (src->binder != 0) {
        void* mem = FUN_0008d690(0x18);
        Binder* n = 0;
        if (mem != 0) {
            n = (Binder*)mem;
            n = n->FUN_002d0fa0(this);
        }
        binder = n;
        n->AddRef();
    }
    if (src->linkA != 0) {
        LinkedA* c = src->linkA->Clone();
        if (c != 0)
            c->AddRef();
        if (linkA != 0)
            linkA->Release();
        linkA = c;
        if (c != 0)
            c->FUN_002a9f30(this);
    }
    if (src->linkB != 0) {
        LinkedB* c = src->linkB->Clone();
        if (c != 0)
            c->AddRef();
        if (linkB != 0)
            linkB->Release();
        linkB = c;
        if (c != 0)
            c->FUN_002a6a20(this);
    }
}
