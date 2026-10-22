// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 4/4)
// pure3d::OldBillboardObjectLoader::vfunc_5 @ 0x002bd300
inline void* operator new(unsigned int, void* p) throw() { return p; }
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void* thunk_FUN_0008d690(unsigned int size);

struct Chunk {
    int FUN_00266c30();
};

class DrawableContainer_2bd300 {
public:
    DrawableContainer_2bd300(int arg) throw();
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    char pad04[4];
    int idLo;           // 0x8
    int idHi;           // 0xc
    char pad10[0x58 - 0x10];
    float scale;        // 0x58
    char pad5c[4];
};

namespace pure3d {
class BillboardObject : public DrawableContainer_2bd300 {
public:
    BillboardObject(int arg) throw() : DrawableContainer_2bd300(arg) { scale = 1.0f; }
    virtual void v13();
};
}

class Builder {
public:
    void FUN_002bcf30(DrawableContainer_2bd300* obj, Chunk* chunk, int arg);
};

struct IdPair_2bd300 {
    int lo, hi;
};

class OldBillboardObjectLoader {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void vfunc_5(DrawableContainer_2bd300** out, IdPair_2bd300* id, Chunk* chunk, int arg);
    char pad04[0x14 - 4];
    Builder* builder;       // 0x14
};

// equiv-map: ??0BillboardBase@@QAE@H@Z = 0x002a4e10
void OldBillboardObjectLoader::vfunc_5(DrawableContainer_2bd300** out, IdPair_2bd300* id, Chunk* chunk, int arg)
{
    if (chunk->FUN_00266c30() != 0x17002)
        return;
    void* mem = thunk_FUN_0008d690(0x60);
    DrawableContainer_2bd300* obj = 0;
    if (mem != 0)
        obj = new (mem) pure3d::BillboardObject(1);
    builder->FUN_002bcf30(obj, chunk, arg);
    obj->v12();
    *out = obj;
    id->lo = obj->idLo;
    id->hi = obj->idHi;
}
