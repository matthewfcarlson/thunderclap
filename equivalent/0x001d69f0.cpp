// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001d69f0 @ 0x001d69f0
struct V3 { float x, y, z; };

struct Matrix {
    void FUN_0022c2b0(V3 *in, V3 *out);
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
    void FUN_001d69f0(V3 *out);
};

// Position of the bone this skeleton tracks (or the default offset transformed by its matrix).
void Skeleton::FUN_001d69f0(V3 *out)
{
    V3 offset;
    offset.x = 0.0f;
    offset.y = 0.75f;
    offset.z = 0.0f;
    int bone = indexer->FUN_001d4f30();
    if (bone != 0xffff) {
        BoneTable *t = source->v11();
        *out = t->bones[bone].pos;
        return;
    }
    v15()->FUN_0022c2b0(&offset, out);
}
