// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000f8840 @ 0x000f8840
extern float DAT_0040cc38;
struct Item {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual void a4(); virtual void a5(); virtual void a6(); virtual float a7();
    virtual void a8(); virtual float a9(int);
};
struct Root { char pad[0x24]; Item *items[1]; };
struct Context;
struct Choice { int slot; int FUN_000f83f0(Root *, Context *); };
struct Context {
    Root *root;
    char pad0[4];
    struct Entry { float value; char pad[12]; } entries[8];
    int index;
    float FUN_000f8840(Choice *choice);
};
float Context::FUN_000f8840(Choice *choice) {
    int slot = choice->slot;
    int argument = choice->FUN_000f83f0(root, this);
    int current = index;
    Item *selected = root->items[slot];
    float divisor = root->items[0]->a7();
    float factor = DAT_0040cc38 / divisor;
    float value = selected->a9(argument);
    return value * factor * entries[current].value;
}