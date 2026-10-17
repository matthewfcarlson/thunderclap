// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 0/0)
// FUN_0028faa0 @ 0x0028faa0
struct Source {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual int v18(int flag, void *location);
};
struct Destination { void FUN_0022ca90(int value); };
struct Object {
    char pad0[4];
    Source **source;
    char pad8[0x44];
    char location[0x40];
    Destination destination;
    Destination *FUN_0028faa0();
};
Destination *Object::FUN_0028faa0() {
    int value = (*source)->v18(0, location);
    destination.FUN_0022ca90(value);
    return &destination;
}