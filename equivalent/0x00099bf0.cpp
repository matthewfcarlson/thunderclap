// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00099bf0 @ 0x00099bf0
struct Vec3i {
    int x, y, z;
};

struct Placement {
    char pad[0x30];
    Vec3i pos;
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
    virtual Placement *vfunc_14();
};

struct Holder {
    char pad00[4];
    unsigned int flags;
    char pad08[8];
    Node *local;
    char pad14[0xbc - 0x14];
    Node *remote;
    void FUN_00099bf0(Vec3i *out);
};

void Holder::FUN_00099bf0(Vec3i *out)
{
    Vec3i result = { 0, 0, 0 };
    Node *node;
    if ((flags >> 5) & 1)
        node = remote;
    else
        node = local;
    if (node != 0)
        result = node->vfunc_14()->pos;
    *out = result;
}
