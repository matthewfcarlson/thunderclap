struct Vec {
    unsigned x, y, z;
};
struct Pose {
    char pad[0x30];
    Vec pos;
};
struct Child {
    char pad[0xc0];
    unsigned x, y, z;
    void FUN_002f5a20(unsigned arg);
};
struct Body {
    char pad[0x5c];
    unsigned x, y, z;
    char gap[8];
    Child* child;
};
struct Object {
    char pad[0x10];
    Body* body;
    Pose* FUN_002fc6f0();
};
struct Gate {
    bool FUN_001d4ef0();
};
struct Provider {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec* v4();
};
struct Target {
    char pad0[0xa0];
    Object* object;
    char pad1[0x48];
    Gate* gate;
    char pad2[0x24];
    unsigned state;
    char pad3[4];
    Provider* provider;
    char pad4[0x68];
    Vec position;
    char pad5[0x9c];
    float value;
    void FUN_001d7ee0(unsigned);
    void FUN_001d7510();
    bool run(unsigned arg, bool reset);
};
bool Target::run(unsigned arg, bool reset) {
    if (!gate->FUN_001d4ef0())
        return false;
    if (state)
        FUN_001d7ee0(0);
    FUN_001d7510();
    Vec* p = object ? &object->FUN_002fc6f0()->pos : provider->v4();
    position.x = p->x;
    position.y = p->y;
    position.z = p->z;
    if (reset) {
        Body* b = object ? object->body : 0;
        b->z = 0;
        b->y = 0;
        b->x = 0;
        b = object ? object->body : 0;
        Child* c = b->child;
        if (c) {
            c->z = 0;
            c->y = 0;
            c->x = 0;
        }
    }
    Body* b = object ? object->body : 0;
    if (b->child)
        b->child->FUN_002f5a20(arg);
    value = -1.0f;
    return true;
}
