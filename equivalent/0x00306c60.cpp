// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 19/20, incomplete)
// FUN_00306c60 @ 0x00306c60
extern "C" void *__cdecl FUN_0008d690(unsigned int size);

struct Node {
};

struct Node44 { Node *FUN_00312900(); };
struct Node8c { Node *FUN_00306b40(); };
struct NodeBc { Node *FUN_00306ba0(); };
struct Node48 { Node *FUN_00306c00(); };
struct Node60 { Node *FUN_0030e700(); };

class Factory {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14(Node *n);
    Node *FUN_00306c60();
};

Node *Factory::FUN_00306c60()
{
    Node *node = 0;
    switch (vfunc_6()) {
    case 1: {
        Node44 *mem = (Node44 *)FUN_0008d690(0x44);
        if (mem == 0)
            return 0;
        node = mem->FUN_00312900();
        break;
    }
    case 2: {
        Node8c *mem = (Node8c *)FUN_0008d690(0x8c);
        if (mem == 0)
            return 0;
        node = mem->FUN_00306b40();
        break;
    }
    case 5: {
        NodeBc *mem = (NodeBc *)FUN_0008d690(0xbc);
        if (mem == 0)
            return 0;
        node = mem->FUN_00306ba0();
        break;
    }
    case 7: {
        Node48 *mem = (Node48 *)FUN_0008d690(0x48);
        if (mem == 0)
            return 0;
        node = mem->FUN_00306c00();
        break;
    }
    case 8: {
        Node60 *mem = (Node60 *)FUN_0008d690(0x60);
        if (mem == 0)
            return 0;
        node = mem->FUN_0030e700();
        break;
    }
    default:
        return 0;
    }
    if (node != 0)
        vfunc_14(node);
    return node;
}
