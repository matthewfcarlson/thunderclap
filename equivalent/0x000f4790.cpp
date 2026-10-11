// STATUS: equivalent (tools/equiv.py level 3: 147 inputs, branch coverage 26/26)
// FEThingsBase::vfunc_39 @ 0x000f4790
struct Node {
    Node* FUN_000fad90();
    char FUN_000f9ef0();
    void FUN_000fa0a0();
};

struct Item {
};

struct Factory {
    Item* FUN_000f28c0(Node* n);
    Item* FUN_000f2740(Node* n);
    Item* FUN_000f2860(Node* n);
    Item* FUN_000f27a0(Node* n);
    Item* FUN_000f2920(Node* n);
    Item* FUN_000f2800(Node* a, Node* b);
};

struct Message {
    virtual void m0();
    virtual unsigned int GetId();
};

class FEThingsBase {
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void vfunc_38(Node* node, Item* item);
    virtual char vfunc_39(Node* node, Factory* factory, Message* msg);
};

char FEThingsBase::vfunc_39(Node* node, Factory* factory, Message* msg)
{
    Item* item;
    Node* first;
    switch (msg->GetId()) {
    case 0xceaa8e00:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = factory->FUN_000f28c0(first);
        break;
    case 0xa6210435:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = factory->FUN_000f2740(first);
        break;
    case 0xa5b54458:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = factory->FUN_000f2860(first);
        break;
    case 0x103db79c:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = factory->FUN_000f27a0(first);
        break;
    case 0x1ed3ea80:
        first = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = factory->FUN_000f2920(first);
        break;
    case 0x2d7a823f: {
        first = node->FUN_000fad90();
        Node* second = node->FUN_000fad90();
        if (node->FUN_000f9ef0())
            node->FUN_000fa0a0();
        item = factory->FUN_000f2800(first, second);
        break;
    }
    default:
        return 0;
    }
    vfunc_38(node, item);
    return 1;
}
