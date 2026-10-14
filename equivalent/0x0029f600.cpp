// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 20/20)
// FUN_0029f600 @ 0x0029f600
void *FUN_0008d690(unsigned int size);
extern int DAT_004cf730;

struct Name_29f600 {
    char data[8];
    void FUN_0027b040(const char *s);
};

struct Inner_29f600 {
    void FUN_002a1180(int arg);
};

struct Slots_29f600 {
    Inner_29f600 *first;
    char pad4[8];
    Slots_29f600 *FUN_0029ecb0(int capacity);
};

struct Lookup_29f600 {
    char pad0[0x18];
    Lookup_29f600 *FUN_0029ef40(int a, int b);
};

struct TreeNode_29f600 {
    TreeNode_29f600 *left;        // 0x00
    TreeNode_29f600 *parent;      // 0x04
    int key;               // 0x08
    char pad0c[0x20 - 0x0c];
    TreeNode_29f600 *head;        // 0x20
    int isHead;            // 0x24
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void e0();
    char pad4[4];
    Name_29f600 name;
    void FUN_0027b070();
    Entity() throw() { FUN_0027b070(); }
};

class LightsChooser : public Entity {
public:
    virtual void x1();
    virtual void x2();
    virtual void x3();
    int color;             // 0x10
    float weight;          // 0x14
    int f18;
    int maxA;              // 0x1c
    int maxB;              // 0x20
    int f24;
    char f28;
    Slots_29f600 *slots0;         // 0x2c
    Slots_29f600 *slots1;
    Slots_29f600 *slots2;
    Slots_29f600 *slots3;
    Slots_29f600 *slots4;
    Slots_29f600 *slots5;         // 0x40
    Lookup_29f600 *lookup;        // 0x44
    TreeNode_29f600 *tree;        // 0x48
    LightsChooser(int a, int b) throw();
};
}

pure3d::LightsChooser::LightsChooser(int a, int b) throw()
{
    color = DAT_004cf730;
    weight = 1.0f;
    f18 = 0;
    f24 = 0;
    f28 = 0;
    maxA = a > 0 ? a : 0;
    maxB = b > 0 ? b : 0;

    void *mem = FUN_0008d690(0xc);
    slots0 = mem ? ((Slots_29f600 *)mem)->FUN_0029ecb0(0x80) : 0;
    slots0->first->FUN_002a1180(0);

    mem = FUN_0008d690(0xc);
    slots1 = mem ? ((Slots_29f600 *)mem)->FUN_0029ecb0(0x80) : 0;
    slots1->first->FUN_002a1180(0);

    mem = FUN_0008d690(0xc);
    slots2 = mem ? ((Slots_29f600 *)mem)->FUN_0029ecb0(0x80) : 0;
    slots2->first->FUN_002a1180(0);

    mem = FUN_0008d690(0xc);
    slots3 = mem ? ((Slots_29f600 *)mem)->FUN_0029ecb0(0x80) : 0;
    slots3->first->FUN_002a1180(0);

    mem = FUN_0008d690(0xc);
    slots4 = mem ? ((Slots_29f600 *)mem)->FUN_0029ecb0(0x80) : 0;
    slots4->first->FUN_002a1180(0);

    mem = FUN_0008d690(0xc);
    slots5 = mem ? ((Slots_29f600 *)mem)->FUN_0029ecb0(maxA + 1) : 0;
    slots5->first->FUN_002a1180(0);

    mem = FUN_0008d690(0x18);
    lookup = mem ? ((Lookup_29f600 *)mem)->FUN_0029ef40(maxA, maxB) : 0;

    TreeNode_29f600 *node = (TreeNode_29f600 *)FUN_0008d690(0x28);
    if (node != 0) {
        node->isHead = 1;
        node->parent = 0;
        node->key = DAT_004cf730;
        node->head = (TreeNode_29f600 *)&node->parent;
        node->left = (TreeNode_29f600 *)&node->parent;
        tree = node;
    } else {
        tree = 0;
    }
}
