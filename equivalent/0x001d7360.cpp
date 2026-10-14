// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001d7360 @ 0x001d7360
// Fill `out` (x, y, z, w) from the attached transform source and its parent chain, then hand it to
// the virtual transform step and finish with the result object.
struct Vec3Bits {
    int x, y, z;
};

struct Vec4Bits {
    int x, y, z, w;
};

class Source {
public:
    char pad0[0x2c];
    Vec4Bits value;
};

class Leaf {
public:
    char pad0[0x34];
    int weight;
};

class Mid {
public:
    char pad0[0x20];
    Leaf* leaf;
};

class Link {
public:
    char pad0[0x74];
    Mid* mid;
};

class Parent {
public:
    char pad0[0x10];
    Link* link;
};

class Result {
public:
    void FUN_0022c2b0();
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
    virtual Result* Transform(Vec3Bits* local, Vec4Bits* out);
    char pad4[0x9c - 4];
    Source* source;
    Parent* parent;

    bool FUN_001d7360(Vec4Bits* out);
};

bool Node::FUN_001d7360(Vec4Bits* out)
{
    Source* src = source;
    if (src != 0) {
        out->x = src->value.x;
        out->y = src->value.y;
        out->z = src->value.z;
        out->w = src->value.w;
    } else {
        out->z = 0;
        out->y = 0;
        out->x = 0;
    }

    Parent* p = parent;
    if (p != 0 && p->link != 0 && p->link->mid != 0 && p->link->mid->leaf != 0) {
        out->w = p->link->mid->leaf->weight;
    }

    Vec3Bits local;
    local.x = out->x;
    local.y = out->y;
    local.z = out->z;
    Transform(&local, out)->FUN_0022c2b0();
    return true;
}
