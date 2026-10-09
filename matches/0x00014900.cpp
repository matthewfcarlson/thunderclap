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
struct Result {
    char pad[0x58];
    float value;
};
extern const float zeroValue;
float CHitAnimationAction::vfunc_9() {
    Result* p = (Result*)((Queried*)member)->get();
    if (!p)
        return zeroValue;
    return p->value;
}