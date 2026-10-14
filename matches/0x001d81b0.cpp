struct Vec_1d81b0 {
    unsigned x, y, z;
};
struct Pose {
    char pad[0x30];
    Vec_1d81b0 pos;
};
struct Child_1d81b0 {
    char pad[0xc0];
    unsigned x, y, z;
    void FUN_002f5a20(unsigned arg);
};
struct Body_1d81b0 {
    char pad[0x5c];
    unsigned x, y, z;
    char gap[8];
    Child_1d81b0* child;
};
struct Object {
    char pad[0x10];
    Body_1d81b0* body;
    Pose* FUN_002fc6f0();
};
struct Gate_1d81b0 {
    bool FUN_001d4ef0();
};
struct Provider_1d81b0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec_1d81b0* v4();
};
struct Target_1d81b0 {
    char pad0[0xa0];
    Object* object;
    char pad1[0x48];
    Gate_1d81b0* gate;
    char pad2[0x24];
    unsigned state;
    char pad3[4];
    Provider_1d81b0* provider;
    char pad4[0x68];
    Vec_1d81b0 position;
    char pad5[0x9c];
    float value;
    void FUN_001d7ee0(unsigned);
    void FUN_001d7510();
    bool run(unsigned arg, bool reset);
};
bool Target_1d81b0::run(unsigned arg, bool reset) {
    if (!gate->FUN_001d4ef0())
        return false;
    if (state)
        FUN_001d7ee0(0);
    FUN_001d7510();
    Vec_1d81b0* p = object ? &object->FUN_002fc6f0()->pos : provider->v4();
    position.x = p->x;
    position.y = p->y;
    position.z = p->z;
    if (reset) {
        Body_1d81b0* b = object ? object->body : 0;
        b->z = 0;
        b->y = 0;
        b->x = 0;
        b = object ? object->body : 0;
        Child_1d81b0* c = b->child;
        if (c) {
            c->z = 0;
            c->y = 0;
            c->x = 0;
        }
    }
    Body_1d81b0* b = object ? object->body : 0;
    if (b->child)
        b->child->FUN_002f5a20(arg);
    value = -1.0f;
    return true;
}
