struct CProceduralDurationAnimationAction {
    char pad[0x1c];
    void* member;
};
struct CHitAnimationAction : CProceduralDurationAnimationAction {
    float vfunc_9();
};
struct Queried {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void* get();
};
struct Result_14900 {
    char pad[0x58];
    float value;
};
extern const float zeroValue_14900;
float CHitAnimationAction::vfunc_9() {
    Result_14900* p = (Result_14900*)((Queried*)member)->get();
    if (!p)
        return zeroValue_14900;
    return p->value;
}