// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 13/14, incomplete)
// FUN_001dd660 @ 0x001dd660
struct V3 { float x, y, z; };

struct Matrix {
    float r[12];
    V3 pos;
    float w;
    void FUN_0022b980();
    void FUN_0022c2b0(V3 *in, V3 *out);
};

struct Quat {
    float x, y, z, w;
    void FUN_0022b650(Matrix *m);
};

struct CompressedQuaternion6 {
    short v[3];
    void FUN_001db820(Quat *out);
};

struct Bone {
    char pad0[0x30];
    V3 pos;
    int pad3c;
};

struct BoneTable {
    char pad0[0x1c];
    Bone *bones;
};

class BoneSource {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual BoneTable *v11();
};

class BoneIndexer { public: int FUN_001d4f30(); };

class Skeleton {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual Matrix *v15();
    char pad04[0x9c - 4];
    BoneSource *source;
    char padA0[0xec - 0xa0];
    BoneIndexer *indexer;
};

struct Key { int lo; int hi; };

struct Entry {
    int keyLo;
    int keyHi;
    char pad8[8];
    CompressedQuaternion6 rot;
    char pad16[2];
    Skeleton *skel;
    char pad1c[6];
    short slot;
    char pad24[4];
};

struct Slot {
    V3 pos;
    int pad0c;
    unsigned char flags;
    char pad11[3];
};

struct Frame {
    V3 v;
    Quat q;
    Matrix m;
};

class Registry {
public:
    char pad0[0x608];
    Entry entries[0x800];
    Slot slots[1];
    bool FUN_001dd660(Key *key, V3 *out);
};

bool Registry::FUN_001dd660(Key *key, V3 *out)
{
    int lo = key->lo;
    int hi = key->hi;
    int i;
    for (i = 0; i < 0x800; i++) {
        if (entries[i].keyLo == lo && entries[i].keyHi == hi)
            break;
    }
    if (i >= 0x800)
        return false;

    Entry *e = &entries[i];
    Slot *s = &slots[e->slot];
    Frame f;
    f.v.x = 0.0f;
    f.v.y = 0.75f;
    f.v.z = 0.0f;
    if ((s->flags & 1) && e->skel) {
        int bone = e->skel->indexer->FUN_001d4f30();
        if (bone != 0xffff) {
            BoneTable *t = e->skel->source->v11();
            *out = t->bones[bone].pos;
            return true;
        }
        e->skel->v15()->FUN_0022c2b0(&f.v, out);
        return true;
    }
    f.m.FUN_0022b980();
    e->rot.FUN_001db820(&f.q);
    f.q.FUN_0022b650(&f.m);
    f.m.pos = s->pos;
    f.m.FUN_0022c2b0(&f.v, out);
    return true;
}
