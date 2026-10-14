// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 16/16)
// pure3d::CompositeDrawable::vfunc_9 @ 0x00298e60
// pure3d::CompositeDrawable::vfunc_9: run the update hook of every child (in order), then of the two extra drawables
struct Node {
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
};

struct Group_298e60 {
    char pad00[0x20];
    unsigned char count;
    char pad21[0xf];
    unsigned char *order;
    char pad34[8];
    struct Slot_298e60 *slots;
    void FUN_00298870();
};

struct Slot_298e60 {
    char pad00[8];
    Node *node;
};

struct Alt {
    char pad00[8];
    unsigned char count;
    char pad09[0xf];
    unsigned char *order;
    char pad1c[8];
    Node **nodes;
};

class CompositeDrawable {
public:
    char pad00[0x44];
    Group_298e60 *group;
    Alt *alt;
    Node *extraA;
    Node *extraB;

    void FUN_00298e60();
};

void CompositeDrawable::FUN_00298e60()
{
    if (alt == 0) {
        if (group != 0) {
            group->FUN_00298870();
            unsigned char n = group->count;
            for (unsigned int i = 0; i < n; i++)
                group->slots[group->order[i]].node->v9();
        }
        if (extraA != 0)
            extraA->v23();
        if (extraB != 0)
            extraB->v23();
    } else {
        unsigned char n = alt->count;
        for (unsigned int i = 0; i < n; i++)
            alt->nodes[alt->order[i]]->v23();
    }
}
