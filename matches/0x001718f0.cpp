struct MotionData {
    char pad[0x1e58];
    float value;
    unsigned int id;
};
struct Holder {
    char pad[0x14];
    unsigned int id;
};
struct Resolver {
    MotionData* get();
};
struct Caller {
    Resolver* get();
};
struct ChargeAction {
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual bool vfunc_5(int p2, float p3);
    char pad0[0x18];
    Holder* holder;
    Caller* source;
    float scale;
};
bool ChargeAction::vfunc_5(int p2, float p3) {
    if (p2 == 0) {
        Resolver* r = source->get();
        MotionData* m = r->get();
        unsigned int id = holder->id;
        if (id != m->id)
            m->value = 0.0f;
        m->id = id;
        m->value = p3 * scale + m->value;
    }
    return true;
}
