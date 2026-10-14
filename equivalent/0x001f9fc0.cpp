// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 2/2)
// FUN_001f9fc0 @ 0x001f9fc0
struct S8_1f9fc0 {
    int a;
    int b;
    void FUN_0027af50();
};
struct SlotKey_1f9fc0 {
    S8_1f9fc0 name;
    char flagA;
    char flagB;
    char pad[6];
};
struct Node { char pad[16]; S8_1f9fc0 value; };
struct Allocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void release(Node *n);
};
void FUN_001f92f0();
struct Container_1f9fc0 {
    char pad[24];
    Allocator *allocator;
    Node *FUN_00230ba0(void (*fn)(), SlotKey_1f9fc0 *key);
    void FUN_00230de0(Node *n);
};
class Mixer {
public:
    char pad000[0xc6c];
    Container_1f9fc0 *container;
    bool FUN_001f9fc0(SlotKey_1f9fc0 key);
};
bool Mixer::FUN_001f9fc0(SlotKey_1f9fc0 key)
{
    Container_1f9fc0 *c = container;
    Node *n = c->FUN_00230ba0(FUN_001f92f0, &key);
    if (n != 0) {
        c->FUN_00230de0(n);
        n->value.FUN_0027af50();
        c->allocator->release(n);
        key.name.FUN_0027af50();
        return true;
    }
    key.name.FUN_0027af50();
    return false;
}
