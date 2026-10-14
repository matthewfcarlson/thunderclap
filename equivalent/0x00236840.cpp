// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00236840 @ 0x00236840
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void *thunk_FUN_0008d690(unsigned int size);
int FUN_00238190(int index);
int FUN_00266da0(int value);

struct NameHolder_236840 {
    char pad[8];
    void FUN_0027b040(const char *name);
};

struct Ring_236840 {
    char data[0x24];
    Ring_236840 *FUN_00231550(int capacity, int a, int b);
};

class Node {
public:
    virtual void AddRef();
    char pad04[4];
    NameHolder_236840 name;
    Node *FUN_0023c620();
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};
}

namespace fight {
class Context : public pure3d::Entity {
public:
    Context();
    virtual void v1();
    int f10;
    Ring_236840 ringA;
    Ring_236840 ringB;
    Node *node;
};

Context::Context()
{
    f10 = 0;
    ringA.FUN_00231550(0x200, 0x50, 100);
    ringB.FUN_00231550(0x200, 0x50, 100);
    int saved = FUN_00266da0(FUN_00238190(0));
    Node *n = (Node *)thunk_FUN_0008d690(0x28);
    if (n)
        n = n->FUN_0023c620();
    node = n;
    n->AddRef();
    node->name.FUN_0027b040("");
    FUN_00266da0(saved);
}
}
