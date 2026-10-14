struct MotionData {
    char pad[0x1e58];
    float value;
    unsigned int id;
};
struct Holder_1718f0 {
    char pad[0x14];
    unsigned int id;
};
struct Resolver_1718f0 {
    MotionData* get();
};
struct Caller_1718f0 {
    Resolver_1718f0* get();
};
struct ChargeAction {
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual bool vfunc_5(int p2, float p3);
    char pad0[0x18];
    Holder_1718f0* holder;
    Caller_1718f0* source;
    float scale;
};
bool ChargeAction::vfunc_5(int p2, float p3) {
    if (p2 == 0) {
        Resolver_1718f0* r = source->get();
        MotionData* m = r->get();
        unsigned int id = holder->id;
        if (id != m->id)
            m->value = 0.0f;
        m->id = id;
        m->value = p3 * scale + m->value;
    }
    return true;
}
