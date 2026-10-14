struct Matrix {
    unsigned int words[16];
};
struct Receiver {
    void FUN_002226e0(unsigned int);
};
struct Source {
    Receiver* FUN_00059a40();
};
struct Child {
    void FUN_001c4d60(Matrix*);
};
struct Node {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual unsigned int slot15();
    char pad[0x118];
    Child* child;
    void FUN_001d6b60(Matrix, unsigned int);
};
struct State {
    char pad[0x2c];
    unsigned int value;
};
struct Object {
    char pad0[0x10];
    Source* source;
    char pad1[0x108];
    State* state;
    char pad2[8];
    Node* node;
    char pad3[0x1c];
    unsigned int cached;
    char pad4[0x2194];
    unsigned char flag;
    void FUN_0003ba60(unsigned int, unsigned int);
    void FUN_000365f0(unsigned int, unsigned int);
    void FUN_00035160(Matrix*);
    void FUN_0003dc40(unsigned int, unsigned int);
};
void Object::FUN_0003dc40(unsigned int a, unsigned int b) {
    Receiver* receiver = source->FUN_00059a40();
    FUN_0003ba60(a, b);
    FUN_000365f0(a, b);
    if (node && node->child) {
        if (flag) {
            Matrix matrix;
            FUN_00035160(&matrix);
            node->FUN_001d6b60(matrix, 0);
            node->child->FUN_001c4d60(&matrix);
        } else {
            unsigned int result = node->slot15();
            receiver->FUN_002226e0(result);
        }
    }
    cached = state->value;
}
